#include "headers/allInclude.h"
using namespace std;

vector<reg*> regVec;
vector<pair<string, vector<string>>> gAsm;
vector<string> gArgRegs({REGISTER_RDI, REGISTER_RSI, REGISTER_RDX, REGISTER_RCX, REGISTER_R8, REGISTER_R9});
vector<string> regNames({REGISTER_R10, REGISTER_R11, REGISTER_RCX, REGISTER_RAX, REGISTER_RDX, REGISTER_RBX, REGISTER_RSI, REGISTER_RDI});
vector<string> regNamesOneByte({"%r10b", "%r11b", "%cl", "%al", "%dl", "%bl", "%bpl", "%sil", "%dil"});
stack<string> funcNameStack;
stack<int> funcSizeStack;
map<string, libFunc *> gLibParamMap;
vector<globalData*> globalDataPair;
int gQuadNo;
stack<int> ptrAssignedRegs;
set<string> libraryFunctions{"fopen", "fprintf", "fscanf", "fclose", "printf", "scanf", "malloc", "free", "fabs", "exp", "exp2", "expm1", "log", "log2", "log10", "log1p", "logb", "sqrt", "cbrt", "round",
                                "sin", "cos", "tan", "asin", "acos", "atan", "trunc", "sinh", "cosh", "tanh", "asinh", "acosh", "atanh", "floor", "ceil", "erf", "erfc", "tgamma", "lgamma",
                                "abs", "labs", "fmod", "remainder", "nextafter", "copysign", "fmax", "fmin", "fdim", "hypot", "pow", "round", "atan2",
                                "signbit", "isnormal", "isnan","isinf","isfinite", "ilogb", "lround", "fma", "difftime", "clock", "ctime", "calloc", "raise", "rand", "rand_r", "realloc","time",
                                "toascii", "tolower", "toupper", "sleep", "exit", "abort"};

set<string> mathFuncs{"fabs", "exp", "exp2", "expm1", "log", "log2", "log10", "log1p", "logb", "sqrt", "cbrt", "round",
                                "sin", "cos", "tan", "asin", "acos", "atan", "trunc", "sinh", "cosh", "tanh", "asinh", "acosh", "atanh", "floor", "ceil", "erf", "erfc", "tgamma", "lgamma",
                                "abs", "labs", "fmod", "remainder", "nextafter", "copysign", "fmax", "fmin", "fdim", "hypot", "pow", "round", "atan2",
                                "signbit", "isnormal", "isnan","isinf","isfinite", "ilogb", "lround", "fma"};
set<string> varArgFunctions{"printf", "scanf", "fprintf", "fscanf"};
vector<quadruple*> gCodeWithTypecast;
set<string> singleFloatLibFunc{"fabs", "exp", "exp2", "expm1", "log", "log2", "log10", "log1p", "logb", "sqrt", "cbrt", "round",
                                "sin", "cos", "tan", "asin", "acos", "atan", "trunc", "sinh", "cosh", "tanh", "asinh", "acosh", "atanh", "floor", "ceil", "erf", "erfc", "tgamma", "lgamma"}; // 1 double arguments, returns double
set<string> singleIntLibFunc{"abs", "labs"}; // 1 int arguments, returns int
set<string> doubleFloatLibFunc{"fmod", "remainder", "nextafter", "copysign", "fmax", "fmin", "fdim", "hypot", "pow", "round", "atan2"}; // 2 double arguments, returns double
// set<string> doubleIntLibFunc{}; // 2 int arguments, returns int
set<string> singleIntFloatLibFunc{"signbit", "isnormal", "isnan","isinf","isfinite", "ilogb", "lround",  /* "fpclassify", */ }; //arg - float; returns int. 
set<string> TripleFloatLibFunc{"fma"}; // 3 double arguments, returns double
// set<string> UnusualFunc{"modf", "ldexp", "frexp", "rint", "lrint", "nearbyint", }; // Unusual functions

// div returns struct
// remquo return double, takes 2 double, 1 int*
// nan
// fpclassify : takes 1 float, returns 

void initLibParamMap() {
    gLibParamMap.insert({"fopen", new libFunc({ new libParam("filename", TYPE_CHAR, 1), new libParam("mode", TYPE_CHAR, 1) }, TYPE_INT, 1)});
    gLibParamMap.insert({"fclose", new libFunc({ new libParam("fp", TYPE_INT, 1) }, TYPE_INT, 0)});
    gLibParamMap.insert({"difftime", new libFunc({ new libParam("time_1", TYPE_INT, 0), new libParam("time_2", TYPE_INT, 0) }, TYPE_FLOAT, 0)});
    gLibParamMap.insert({"clock", new libFunc({}, TYPE_INT, 0)});
    gLibParamMap.insert({"ctime", new libFunc({new libParam("time", TYPE_INT, 1)}, TYPE_CHAR, 1)});
    gLibParamMap.insert({"calloc", new libFunc({new libParam("num", TYPE_INT, 0), new libParam("size", TYPE_INT, 0)}, TYPE_INT, 1)});
    gLibParamMap.insert({"raise", new libFunc({new libParam("sig", TYPE_INT, 0)}, TYPE_INT, 0)});
    gLibParamMap.insert({"rand", new libFunc({}, TYPE_INT, 0)});
    gLibParamMap.insert({"rand_r", new libFunc({}, TYPE_INT, 0)});
    gLibParamMap.insert({"time", new libFunc({new libParam("time_ptr", TYPE_INT, 1)}, TYPE_VOID, 0)});
    gLibParamMap.insert({"toascii", new libFunc({new libParam("c", TYPE_INT, 0)}, TYPE_INT, 0)});
    gLibParamMap.insert({"toupper", new libFunc({new libParam("c", TYPE_INT, 0)}, TYPE_INT, 0)});
    gLibParamMap.insert({"tolower", new libFunc({new libParam("c", TYPE_INT, 0)}, TYPE_INT, 0)});
    gLibParamMap.insert({"sleep", new libFunc({new libParam("seconds", TYPE_INT, 0)}, TYPE_INT, 0)});
    gLibParamMap.insert({"exit", new libFunc({new libParam("status", TYPE_INT, 0)}, TYPE_VOID, 0)});
    gLibParamMap.insert({"abort", new libFunc({new libParam("abort", TYPE_VOID, 0)}, TYPE_VOID, 0)});
}

bool isTypecasted(string name) {
    size_t pos = name.find(" ) ");
    if (pos == string::npos)
        return false;
    return true;
}

string stripTypeCastUtil(string name) {
    size_t pos = name.find(" ) ");
    if (pos == string::npos) {
        return name;
    }

    if ((pos + 2) >= name.size()) {
        return name;
    }
    return name.substr(pos + 3);
}

void stripTypeCastFromQuads() {
    for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
        quadruple* quad = gCode[quadNo];
        quad->result = stripTypeCastUtil(quad->result);
        quad->arg1 = stripTypeCastUtil(quad->arg1);
        quad->arg2 = stripTypeCastUtil(quad->arg2);
    }
}

void copyQuads() {
    gCodeWithTypecast = vector<quadruple*>(gCode.size());
    for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
        gCodeWithTypecast[quadNo] = new quadruple();
        gCodeWithTypecast[quadNo]->opCode = gCode[quadNo]->opCode;
        gCodeWithTypecast[quadNo]->result = gCode[quadNo]->result;
        gCodeWithTypecast[quadNo]->arg1 = gCode[quadNo]->arg1;
        gCodeWithTypecast[quadNo]->arg2 = gCode[quadNo]->arg2;
    }
}

void emitAssemblyFrom3AC(string asmOutputFile) {
    funcNameStack.push(GLOBAL);
    initializeRegs();
    initializeRegsFloat();
    copyQuads();
    stripTypeCastFromQuads();
    vector<int> gotoLabels;
    for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
        int op = gCode[quadNo]->opCode;
        if ((op == OP_GOTO) || (op == OP_IFGOTO) || (op == OP_IFNEQGOTO)) {
            string num = gCode[quadNo]->result;
            if (num == BLANK_STR)
                continue;
            if (!isConstant(num)) {
                errorAsm(num, GOTO_ADDR_NOT_CONST);
            }
            gotoLabels.push_back(stoi(num));
        }
    }

    sort(gotoLabels.begin(), gotoLabels.end());
    int labelSize = gotoLabels.size();
    int curr = 0;
    for (int quadNo = 0; quadNo < gCode.size(); quadNo++) {
        gQuadNo = quadNo;
        if (curr < labelSize && gotoLabels[curr] == quadNo) {
            asmLabel(quadNo);
            while (curr < labelSize && gotoLabels[curr] == quadNo) {
                curr++;
            }
        }
        emitAssemblyForQuad(quadNo);
        while (!ptrAssignedRegs.empty()) {
            freeReg(ptrAssignedRegs.top());
            ptrAssignedRegs.pop();
        }
    }
    printAsm(asmOutputFile);
}

void printAsm(string asmOutputFile) {
    freopen(asmOutputFile.c_str(), "w", stdout);
    printASMData();
    printASMText();
}

void printASMData() {
    cout << "\n.data" << endl;
    for (globalData* g : globalDataPair) {
        cout << "   " << g->varName << ": ";
        if (g->valueType == TYPE_STRING_LITERAL) {
            cout << ".asciz ";
        } else if (g->valueType == TYPE_FLOAT) {
            cout << ".double ";
        } else {
            cout << ".long ";
        }
        cout << g->value << "\n";
    }
    cout << endl;
}

void emitAssemblyForQuad(int quadNo) {
    quadruple* quad = gCode[quadNo];
    switch (quad->opCode) {
    case OP_GOTO:
        asmOpGoto(quadNo);
        break;
    case OP_ADDI:
        asmOpAddI(quadNo);
        break;
    case OP_MULI:
        asmOpMulI(quadNo);
        break;
    case OP_IFGOTO: // chinmaya ***
                    // =======================================================================================================================
                    //  ucompss, float comparison, float comparison jump,all instructions are different from the int
                    // =======================================================================================================================
        asmOpIfGoto(quadNo);
        break;
    case OP_SUBI:
        asmOpSubI(quadNo);
        break;
    case OP_ASSIGNMENT: // sarthak ***
                        // =======================================================================================================================
                        //  cvt for typecasting
                        // movss, register set for floating point
                        // =======================================================================================================================
        asmOpAssignment(quadNo);
        break;
    case OP_ASSIGNMENTF:
        asmOpAssignmentF(quadNo);
        break;
    case OP_UNARY_MINUS:
        asmOpUnaryMinus(quadNo);
        break;
    case OP_UNARY_MINUSF: // dipesh ***
                          // =======================================================================================================================
                          // https://groups.google.com/g/comp.lang.asm.x86/c/bqspF3wPQMY?pli=1
                          // Idea:1 & 2 given in above website
                          // Idea:3 multiply directly by -1
                          // final idea: subtract from 0
                          // =======================================================================================================================
        asmOpUnaryMinusF(quadNo);
        break;
    case OP_DIVI:
        asmOpDivI(quadNo);
        break;
    case OP_LEFT_SHIFT:
        asmOpLeftShift(quadNo);
        break;
    case OP_RIGHT_SHIFT:
        asmOpRightShift(quadNo);
        break;
    case OP_OR:
        asmOpLogicalOr(quadNo);
        break;
    case OP_AND:
        asmOpLogicalAnd(quadNo);
        break;
    case OP_LOGICAL_NOT:
        asmOpUnaryLogicalNot(quadNo);
        break;
    case OP_XOR:
        asmOpLogicalXor(quadNo);
        break;
    case OP_EQ: // sakshi ***
                // =======================================================================================================================
                //  jb, jp, ucomss
                // =======================================================================================================================
        asmOpEq(quadNo);
        break;
    case OP_NEQ: // sakshi ***
        asmOpNeq(quadNo);
        break;
    case OP_LEQ: // sakshi ***
        asmOpLeq(quadNo);
        break;
    case OP_GREATER: // sakshi ***
        asmOpGreater(quadNo);
        break;
    case OP_LESS: // sakshi ***
        asmOpLess(quadNo);
        break;
    case OP_EQF: // sakshi ***
        asmOpEqFloat(quadNo);
        break;
    case OP_NEQF: // sakshi ***
        asmOpNeqFloat(quadNo);
        break;
    case OP_LEQF: // sakshi ***
        asmOpLeqFloat(quadNo);
        break;
    case OP_GREATERF: // sakshi ***
        asmOpGreaterFloat(quadNo);
        break;
    case OP_LESSF: // sakshi ***
        asmOpLessFloat(quadNo);
        break;
    case OP_MOD:
        asmOpMod(quadNo);
        break;
        // binary operator standard function
    case OP_ADDF: // rythm ***
        asmOpAddF(quadNo);
        break;
    case OP_MULF: // rythm ***
        asmOpMulF(quadNo);
        break;
    case OP_SUBF: // rythm ***
        asmOpSubF(quadNo);
        break;
    case OP_DIVF: // dipesh ***
        asmOpDivF(quadNo);
        // =======================================================================================================================
        // divsd dest, src         ; dest /= src (double)
        //  change it
        // The dest and src operands must be xmm registers; src2 can be register or memory. Sizes of all operands must be the same.
        // =======================================================================================================================
        break;
    case OP_GEQ: // sakshi ***gArgRegsFloat
        asmOpGeq(quadNo);
        break;
    case OP_GEQF: // sakshi ***gArgRegsFloat
        asmOpGeqFloat(quadNo);
        break;
    case OP_ANDAND: // chinmaya ***
        asmOpAndAnd(quadNo);
        break;
    case OP_OROR: // chinmaya ***
        asmOpOrOr(quadNo);
        break;
    case OP_IFNEQGOTO: // chinmaya
        asmOpIfNeqGoto(quadNo);
        break;
    case OP_BEGINFUNC: // sarthak
                       // =======================================================================================================================
                       //  choose registers according to data type
                       // =======================================================================================================================
        asmOpBeginFunc(quadNo);
        break;
    case OP_ENDFUNC:
        asmOpEndFunc(quadNo);
        break;
    case OP_RETURN:
        asmOpReturn(quadNo);
        break;
    case OP_RETURNF: // dipesh ***
        asmOpReturnF(quadNo);
        /*  // =======================================================================================================================
        check if the return value of function is float or int
        if float then return the value in %xmm0
        else return the value in %rax
        in between calculations are not to be taken care of from your side, they are automatically handled.
        // ======================================================================================================================= */
        break;
    case OP_PUSHPARAM:
        asmOpPushparam(quadNo);
        break;
    case OP_POPPARAM:
        asmOpPopparam(quadNo);
        break;
    case OP_LCALL:
        amsOpLCall(quadNo);
        break;
    case OP_LABEL:
        asmOpLabel(quadNo);
        break;
    case OP_ADDR:
        amsOpAddr(quadNo);
        break;
    case OP_BITWISE_NOT:
        asmOpBitwiseNot(quadNo);
        break;
    case OP_MOV: // sarthak ***
                 // =======================================================================================================================
                 //  different movf in 3AC, register change, movsd
                 // =======================================================================================================================
        asmOPMoveFuncParam(quadNo);
        break;
    //NEW
    case OP_MOVF:
        asmOPMoveFloatFuncParam(quadNo);
        break;
    case OP_DUMMYPUSH:
        asmOPDummyPush(quadNo);
        break;
    default:
        break;
    }
}

void asmOPDummyPush(int quadNo) {
    emitAsm("pushq", {REGISTER_RBP});
}

void asmOpBitwiseNot(int quadNo) {
    asmOpUnaryOperator("not", quadNo);
}

void amsOpAddr(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

    if (isConstant(quad->arg1))
        errorAsm(quad->arg1, ASSIGNMENT_TO_CONSTANT_ERROR);

    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string resultAddr = getVariableAddr(quad->result, st);
    string argAddr = getVariableAddr(quad->arg1, st);
    emitAsm("leaq", {argAddr, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
}

void asmOpLabel(int quadNo) {
    string label = "\n";
    label = label + gCode[quadNo]->result + ":";
    emitAsm(label, {});
    string funcName = gCode[quadNo]->result;
    funcNameStack.push(funcName);
}

void asmLabel(int labelno) {
    string label = "\nlabel$" + to_string(labelno) + ":";
    emitAsm(label, {});
}

void asmOpReturn(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    int eaxInd = EAX_REGISTER_INDEX;
    string eaxName = regVec[EAX_REGISTER_INDEX]->regName;
    /* 
        check if the return value of function is float or int
        if float then return the value in %xmm0
        else return the value in %rax
        in between calculations are not to be taken care of from your side, they are automatically handled.
     */
    if (quad->result != EMPTY_STR) {
        freeRegAndMoveToStack(eaxInd);
        useReg(eaxInd, quadNo, NO_VAR_VALUE_ASSIGNED);

        if (!isConstant(quad->result)) {
            // location--copy the return struct to appropriate location here.
            regVec[eaxInd]->varValue = quad->result;
            // string stripped_name = quad->result;
            // if (isPointer(stripped_name)) {
            //     stripped_name = stripPointer(stripped_name);
            // }
            // symbolTableNode* sym_node = lookUp(st, stripped_name);
            // if ((sym_node) && ((sym_node->infoType == INFO_TYPE_STRUCT) || (sym_node->declSp && sym_node->declSp->type.size() > 0 && sym_node->declSp->type[0] == TYPE_STRUCT))) {
            string funcName = funcNameStack.top();
            symbolTableNode* funcNode = lookUp(st, funcName);
            if (!funcNode) {
                error(funcName, SYMBOL_NOT_FOUND);
            } else if (funcNode->declSp && funcNode->declSp->type.size() > 0 && (funcNode->declSp->type[0] == TYPE_STRUCT) && (funcNode->declSp->ptrLevel == 0)) {
                copyReturningStruct(quad->result, quadNo);
            } else {
                string argAddr = getVariableAddr(quad->result, st);
                emitAsm("movq", {argAddr, eaxName});
            }

        } else {
            regVec[eaxInd]->varValue = CONSTANT;
            emitAsm("movq", {"$" + hexString(quad->result), eaxName});
        }
    }
    emitAsm("jmp", {"9f"});
    // emitAsm("addq", {"$" + hexString(to_string(funcSizeStack.top())), REGISTER_RSP});
    // emitAsm("popq", {REGISTER_RBP});
    // emitAsm("retq", {});
}

void asmOpEndFunc(int quadNo) {
    emitAsm("\n9:", {});
    emitAsm("addq", {"$" + alignedFunctionSize(to_string(funcSizeStack.top())), REGISTER_RSP});
    emitAsm("popq", {REGISTER_RBP});
    emitAsm("retq", {});
    funcNameStack.pop();
    funcSizeStack.pop();
}

void amsOpLCall(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];
    //mov    %eax,-0x4(%rbp)
    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

    int isStruct = 0;
    int isFloat = 0;   
    if (libraryFunctions.find(quad->arg1) != libraryFunctions.end()) {
        string funcName = quad->arg1;
        symbolTableNode* funcNode = lookUp(st, funcName);
        if (!funcNode)
            error(funcName, SYMBOL_NOT_FOUND);
        
        if(varArgFunctions.find(quad->arg1) != varArgFunctions.end()){
            emitAsm("movq", {"$"+quad->arg2, REGISTER_RAX});
        }
        else{
            // if(mathFuncs.find(funcName) == mathFuncs.end()){
            //     emitAsm("movq", {"$0", REGISTER_RAX});
            // }
            isFloat = 0;
            for( auto paramTmp : funcNode->paramList){
                if((paramTmp->declSp->type[0] == TYPE_FLOAT) && (paramTmp->declSp->ptrLevel == 0)){
                    isFloat = 1;
                    break;
                }
            }
            if(isFloat){
                emitAsm("movq", {"$1", REGISTER_RAX});
            }else{
                emitAsm("movq", {"$0", REGISTER_RAX});
            }
            isFloat = 0;
            if(funcNode->declSp && funcNode->declSp->type.size() > 0 && (funcNode->declSp->type[0] == TYPE_FLOAT) && (funcNode->declSp->ptrLevel == 0)) {
                isFloat = 1;
            }
        }
    } else {
        string funcName = quad->arg1;
        symbolTableNode* funcNode = lookUp(st, funcName);
        if (!funcNode) {
            error(funcName, SYMBOL_NOT_FOUND);
        } else if (funcNode->declSp && funcNode->declSp->type.size() > 0 && (funcNode->declSp->type[0] == TYPE_STRUCT) && (funcNode->declSp->ptrLevel == 0)) {
            isStruct = 1;
            string structName = funcNode->declSp->lexeme;
            // structTableNode* struc = structLookUp(gSymTable, structName);
            symbolTableNode* tempNode = new symbolTableNode();
            tempNode->declSp->type.push_back(TYPE_STRUCT);
            tempNode->declSp->lexeme = structName;
            int size = getNodeSize(tempNode, gSymTable);
            emitAsm("subq", {"$" + hexString(to_string(size)), REGISTER_RSP});
            emitAsm("pushq", {REGISTER_RSP});
        } else if(funcNode->declSp && funcNode->declSp->type.size() > 0 && (funcNode->declSp->type[0] == TYPE_FLOAT) && (funcNode->declSp->ptrLevel == 0)) {
            isFloat = 1;
        }
    }

    emitAsm("callq", {quad->arg1});
    if (quad->result != EMPTY_STR) {
        string resultAddr = getVariableAddr(quad->result, st);
        //---location: return value movement here
        if (isStruct) {
            copyReturnStruct(quad->result, quadNo);
        } else if(isFloat) {
            emitAsm("movsd", {REGISTER_XMM0, resultAddr});
        } else {
            emitAsm("movq", {REGISTER_RAX, resultAddr});
        }
    }
}

void emitFuncStart() {
    emitAsm("endbr64", {});
    emitAsm("pushq", {REGISTER_RBP});
    emitAsm("movq", {REGISTER_RSP, REGISTER_RBP});
}

void asmOPMoveFuncParam(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    string regName = quad->arg1;
    string valToMove = quad->result;
    if (find(gArgRegs.begin(), gArgRegs.end(), regName) == gArgRegs.end()) {
        errorAsm("", REGISTER_ASSIGNMENT_ERROR);
    }

    if (isConstant(valToMove)) {
        emitAsm("movq", {"$" + hexString(valToMove), regName});
    } else {
        string argAddr = getVariableAddr(valToMove, st);
        emitAsm("movq", {argAddr, regName});
    }
}

void asmJump(int quadNo, string op) {
    quadruple* quad = gCode[quadNo];
    string result = quad->result;
    string label = "label$" + result;
    emitAsm(op, {label});
}

void asmOpPopparam(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];
    string resultAddr = quad->result;

    if (!isConstant(resultAddr)) {
        errorAsm("", POPPARAM_ARG_NOT_CONSTANT);
    }
    emitAsm("addq", {"$" + hexString(quad->result), REGISTER_RSP});
}

void asmOpBeginFunc(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (!isConstant(quad->result))
        errorAsm(quad->result, BEGIN_FUNC_ARG_NOT_CONSTANT_ERROR);
    if (funcNameStack.empty() || funcNameStack.top() == GLOBAL)
        errorAsm("", CALL_TO_GLOBAL_ERROR);

    int funcSize = getNumberFromConstAddr(quad->result);
    funcSizeStack.push(funcSize);
    symbolTableNode* funcNode = lookUp(st, funcNameStack.top());
    if (!funcNode) {
        error(funcNameStack.top(), SYMBOL_NOT_FOUND);
    }
    if (funcNode->infoType != INFO_TYPE_FUNC)
        error(funcNameStack.top(), TYPE_ERROR);

    //emit start
    emitFuncStart();

    //sub stack pointer
    emitAsm("subq", {"$" + alignedFunctionSize(quad->result), REGISTER_RSP});

    //move first 6 arguments from register to stack
    vector<struct param*> paramList = funcNode->paramList;
    int numParams = paramList.size();
    int floatInd=0, intInd=0;
    for (int i = 0; i < min(6, numParams); i++) {
        if ((paramList[i]->declSp->type.size() > 0 && paramList[i]->declSp->type[0] == TYPE_STRUCT && paramList[i]->declSp->ptrLevel == 0))
            continue;
        string argAddr = getVariableAddr(paramList[i]->paramName, st);
        if ((paramList[i]->declSp->type.size() > 0 && paramList[i]->declSp->type[0] == TYPE_FLOAT && paramList[i]->declSp->ptrLevel == 0)) {
            emitAsm("movsd", {gArgRegsFloat[floatInd], argAddr});
            floatInd++;
        } else{
            emitAsm("movq", {gArgRegs[intInd], argAddr});
            intInd++;
        }
    }
    return;
}

string alignedFunctionSize(string str){
    int x = getNumberFromConstAddr(str);
    if(!(x%16)){
        return to_string(x);
    }
    return to_string((x/16 + 1)*16);
}

void asmOpPushparam(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    string resultAddr = quad->result;

    if (isConstant(resultAddr)) {
        emitAsm("pushq", {"$" + hexString(resultAddr)});
    } else {
        string argAddr = getVariableAddr(resultAddr, st);
        emitAsm("movq", {argAddr, REGISTER_RAX});
        emitAsm("pushq", {REGISTER_RAX});
    }
}

void asmOpUnaryOperator(string op, int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

    string resultAddr = getVariableAddr(quad->result, st);
    int regInd = -1;
    string regName = CONSTANT;

    if (isConstant(quad->arg1)) {
        regInd = getReg(quadNo, CONSTANT);
        regName = regVec[regInd]->regName;
        emitAsm("movq", {"$" + quad->arg1, regName});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        regInd = getReg(quadNo, quad->arg1);
        regName = regVec[regInd]->regName;
        emitAsm("movq", {argAddr, regName});
    }
    // neg register
    if (regName == CONSTANT) {
        errorAsm("Register not assigned properly.", REGISTER_ASSIGNMENT_ERROR);
        return;
    }
    emitAsm(op, {regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
}

void asmOpUnaryMinus(int quadNo) {
    asmOpUnaryOperator("neg", quadNo);
}

void asmOpUnaryLogicalNot(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];
    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    string argString = quad->arg1;
    if (isConstant(argString)) {
        string result = evaluate("logicalNot", argString, ""); //incomp
        emitAsm("movq", {resultAddr});
    } else {
        string argAddr = getVariableAddr(argString, st);
        emitAsm("cmpl", {"$0", argAddr});
        emitAsm("sete", {"%al"});
        emitAsm("movzbl", {"%al", regNames[EAX_REGISTER_INDEX]});
        emitAsm("movq", {regNames[EAX_REGISTER_INDEX], resultAddr});
    }
}

void asmOpDivI(int quadNo) {
    /*  Refer http://www.godevtool.com/TestbugHelp/UseofIDIV.htm#:~:text=The%20IDIV%20instruction%20takes%20only,the%20dividend%20and%20the%20divisor. 
        The above website tell us all the different version of this command of which I(amigo) have used only 1 standard form. */

    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);

    freeRegAndMoveToStack(EDX_REGISTER_INDEX);
    useReg(EDX_REGISTER_INDEX, quadNo, CONSTANT);
    emitAsm("movq", {"$0x0", regVec[EDX_REGISTER_INDEX]->regName});

    freeRegAndMoveToStack(EAX_REGISTER_INDEX);
    useReg(EAX_REGISTER_INDEX, quadNo, NO_VAR_VALUE_ASSIGNED);

    string arg1Addr;
    string reg1Name = regVec[EAX_REGISTER_INDEX]->regName;

    if (isConst1) {
        regVec[EAX_REGISTER_INDEX]->varValue = CONSTANT;
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movq", {arg1Addr, reg1Name});
        emitAsm("cqo", {});
    } else {
        regVec[EAX_REGISTER_INDEX]->varValue = quad->arg1;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
        emitAsm("cqo", {});
    }

    emitAsm("cltd", {});

    string arg2Addr;
    int reg2Ind = -1;
    if (isConst2) {
        reg2Ind = getReg(quadNo, CONSTANT);
        string reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movq", {arg2Addr, reg2Name});
        emitAsm("cqo", {});
        emitAsm("idivq", {reg2Name});
    } else {
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("idivl", {arg2Addr});
    }

    emitAsm("movq", {reg1Name, resultAddr});
    freeReg(EAX_REGISTER_INDEX);
    freeReg(EDX_REGISTER_INDEX);
    if (isConst2 && reg2Ind != -1) {
        freeReg(reg2Ind);
    }
}

void asmOpLeftShift(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);

    if (isConst1 && isConst2) {
        string eval = evaluate("shl", quad->arg1, quad->arg2);
        if (eval != EMPTY_STR) {
            emitAsm("movq", {"$" + eval, resultAddr});
            return;
        }
    }

    string arg1Addr;
    string arg2Addr;
    int reg1Ind = -1;
    int reg2Ind = -1;
    string reg1Name, reg2Name;
    if (isConst1) {
        reg1Ind = getReg(quadNo, CONSTANT);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movq", {arg1Addr, reg1Name});
    } else {
        reg1Ind = getReg(quadNo, quad->arg1);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
    }

    reg2Ind = ECX_REGISTER_INDEX;
    freeRegAndMoveToStack(reg2Ind);
    useReg(reg2Ind, quadNo, NO_VAR_VALUE_ASSIGNED);

    reg2Name = CL_REGISTER;
    if (isConst2) {
        regVec[reg2Ind]->varValue = CONSTANT;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("mov", {arg2Addr, reg2Name});
    } else {
        regVec[reg2Ind]->varValue = quad->arg2;
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("mov", {arg2Addr, reg2Name});
    }

    emitAsm("shl", {reg2Name, reg1Name});
    emitAsm("movq", {reg1Name, resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
    return;
}

void asmOpRightShift(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);

    if (isConst1 && isConst2) {
        string eval = evaluate("sar", quad->arg1, quad->arg2);
        if (eval != EMPTY_STR) {
            emitAsm("movq", {"$" + eval, resultAddr});
            return;
        }
    }

    string arg1Addr;
    string arg2Addr;
    int reg1Ind = -1;
    int reg2Ind = -1;
    string reg1Name, reg2Name;
    if (isConst1) {
        reg1Ind = getReg(quadNo, CONSTANT);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movq", {arg1Addr, reg1Name});
    } else {
        reg1Ind = getReg(quadNo, quad->arg1);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
    }

    reg2Ind = ECX_REGISTER_INDEX;
    freeRegAndMoveToStack(reg2Ind);
    useReg(reg2Ind, quadNo, NO_VAR_VALUE_ASSIGNED);

    reg2Name = CL_REGISTER;
    if (isConst2) {
        regVec[reg2Ind]->varValue = CONSTANT;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("mov", {arg2Addr, reg2Name});
    } else {
        regVec[reg2Ind]->varValue = quad->arg2;
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("mov", {arg2Addr, reg2Name});
    }

    emitAsm("sar", {reg2Name, reg1Name});
    emitAsm("movq", {reg1Name, resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
    return;
}

void emitAsm(string optr, vector<string> operands) {
    gAsm.push_back({optr, operands});
}

void errorAsm(string str, int errCode) {
    string errStr;
    switch (errCode) {
    case ASSIGNMENT_TO_CONSTANT_ERROR:
        errStr = "Cannot assign value to a constant.";
        break;
    case UNDEFINED_SCOPE_STNODE_ERROR:
        errStr = "Internal Error. UNDEFINED_SCOPE_STNODE_ERROR";
        break;
    case REGISTER_ASSIGNMENT_ERROR:
        errStr = "Internal Error. REGISTER_ASSIGNMENT_ERROR";
        break;
    case POPPARAM_ARG_NOT_CONSTANT:
        errStr = "Popparam arg should be constant";
        break;
    case BEGIN_FUNC_ARG_NOT_CONSTANT_ERROR:
        errStr = "Beginfunc arg should be constant";
        break;
    case CALL_TO_GLOBAL_ERROR:
        errStr = "Internal Error. Calling global";
        break;
    case GOTO_ADDR_NOT_CONST:
        errStr = "Internal Error: Goto address should be integer";
        break;
    case DEREFERENCING_CONSTANT_ERROR:
        errStr = "Derefrencing a constant not allowed.";
        break;
    case INVALID_TYPECAST_IN_3AC:
        str = "Invalid typecast in 3AC.";
        break;
    default:
        break;
    }
    errStr += " ";
    errStr += str;
    cout << "ERROR: " << errStr << endl;
    exit(errCode);
}

int getParameterOffset(string structName, string param, symbolTable* st) {
    structTableNode* structure = nullptr;
    structure = structLookUp(st, structName);
    if (structure == nullptr) {
        error(structName, STRUCT_NOT_DECLARED);
    }
    int paramOffset = getParamOffset(structure, param, errCode, errStr);
    if (paramOffset < 0) {
        error("paramOffset Negative", DEFAULT_ERROR);
    }
    return paramOffset;
}
// TODO: This function might fail, verify this
int getOffset(string varName, symbolTable* st) {
    if (isPointer(varName))
        varName = stripPointer(varName);
    //check for foo.a
    bool dot = false;
    string identifier = varName, param, name = varName, delim_dot = ".";
    size_t pos = name.find(delim_dot);
    if (pos != string::npos) {
        dot = true;
        identifier = name.substr(0, pos);
        name.erase(0, pos + delim_dot.length());
        param = name;
    }
    symbolTableNode* sym_node = lookUp(st, identifier);
    if (sym_node == nullptr) {
        error(identifier, SYMBOL_NOT_FOUND);
    }
    int offset = sym_node->offset;
    offset += getOffsettedSize(sym_node->size);
    if (dot && (sym_node->infoType == INFO_TYPE_STRUCT || (sym_node->declSp && sym_node->declSp->type.size() > 0 && sym_node->declSp->type[0] == TYPE_STRUCT)) && sym_node->declSp->ptrLevel == 0) {
        offset -= getParameterOffset(sym_node->declSp->lexeme, param, st);
    }
    return -1 * offset;
}

bool isGlobal(string varName, symbolTable* st) {
    if (isFloatConstant(varName))
        return true;
    if (isPointer(varName))
        varName = stripPointer(varName);
    string identifier = varName, param, name = varName, delim_dot = ".";
    size_t pos = name.find(delim_dot);
    if (pos != string::npos) {
        identifier = name.substr(0, pos);
    }
    symbolTableNode* sym_node = lookUp(st, identifier);
    if (sym_node == nullptr) {
        error(varName, SYMBOL_NOT_FOUND);
    }
    if (sym_node->scope == -1)
        errorAsm("scope of variable not defined", UNDEFINED_SCOPE_STNODE_ERROR);
    return sym_node->scope == GLOBAL_SCOPE_NUM;
}

int getGlobalAddress(string varName, symbolTable* st) {
    if (isPointer(varName))
        varName = stripPointer(varName);
    symbolTableNode* sym_node = lookUp(st, varName);
    if (sym_node == nullptr) {
        error(varName, SYMBOL_NOT_FOUND);
    }
    // TODO: global offset(starting address of the program) need to be added here to get the absolute address of the variable
    return sym_node->offset;
}

bool isPointer(string name) {
    int n = name.size();
    if (n <= 3)
        return false;
    if (name[0] == '*' && name[1] == '(' && name[n - 1] == ')')
        return true;

    return false;
}

string getOffsetStr(int offset) {
    string offsetStr = "";
    if (offset < 0)
        offsetStr = "-";

    offset = abs(offset);
    offsetStr = offsetStr + hexString(to_string(offset));
    return offsetStr + "(%rbp)";
}

string stripPointer(string name) {
    int n = name.length();
    if (n > 3) {
        string varName = name.substr(2, n - 3);
        return varName;
    } else {
        error(name, INVALID_POINTER_ADDR);
    }
    return name;
}

string getVariableAddr(string varName, symbolTable* st) {
    int offset;
    string offsetStr;
    string identifier = varName, param, temp = varName, delim_ptr = "->", delim_dot = ".";
    // f->a
    bool ptrOp = false;
    size_t pos = temp.find(delim_ptr);
    if (pos != string::npos) {
        identifier = temp.substr(0, pos);
        temp.erase(0, pos + delim_ptr.length());
        param = temp;
        offset = getOffset(identifier, st);
        offsetStr = getOffsetStr(offset);
        int regAddInd = getReg(gQuadNo, identifier); 
        string regAddName = regVec[regAddInd]->regName;
        emitAsm("movq", {offsetStr, regAddName});
        int regInd = getReg(gQuadNo, identifier);
        string regName = regVec[regInd]->regName;

        symbolTableNode* sym_node = lookUp(st, identifier);
        if (sym_node == nullptr) {
            error(identifier, SYMBOL_NOT_FOUND);
        }
        int paramOffset = getParameterOffset(sym_node->declSp->lexeme, param, st);
        emitAsm("addq", {"$" + hexString(to_string(paramOffset)), regAddName});
        emitAsm("movq", {regAddName, regName});

        ptrAssignedRegs.push(regInd);
        freeReg(regAddInd);
        regVec[regInd]->isFree = false;
        return "(" + regName + ")";
    }

    // f.a
    bool dot = false;
    temp = varName;
    pos = temp.find(delim_dot);
    if (pos != string::npos) {
        dot = true;
        identifier = temp.substr(0, pos);
        temp.erase(0, pos + delim_dot.length());
        param = temp;
    }

    if (isGlobal(identifier, st)) {
        bool isStringLiteral = false;
        for (globalData* g : globalDataPair) {
            if (g->varName == identifier) {
                if (g->valueType == TYPE_STRING_LITERAL)
                    return "$" + g->varName;
                else
                    return g->varName + "(%rip)";
            }
        }
        // error("non-string globals are unsupported", UNSUPPORTED_FUNCTIONALITY);
    }
    if (!dot && isPointer(varName)) {
        string name = stripPointer(varName);
        if (isConstant(name))
            errorAsm(name, DEREFERENCING_CONSTANT_ERROR);
        offset = getOffset(name, st);
        offsetStr = getOffsetStr(offset);
        int regInd = getReg(gQuadNo, name); 
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {offsetStr, regName});
        ptrAssignedRegs.push(regInd);
        regVec[regInd]->isFree = false;
        return "(" + regName + ")";
    } else if (dot && isPointer(identifier)) { //should be a struct array
        string name = stripPointer(identifier);
        if (isConstant(name))
            errorAsm(name, DEREFERENCING_CONSTANT_ERROR);

        symbolTableNode* sym_node = lookUp(st, name);
        if (sym_node == nullptr) {
            error(name, SYMBOL_NOT_FOUND);
        } else if (sym_node->declSp->type[0] != TYPE_STRUCT) {
            error("not a pointer to a valid struct", DEFAULT_ERROR);
        }

        int paramOffset = getParameterOffset(sym_node->declSp->lexeme, param, st);
        offset = getOffset(name, st);
        offsetStr = getOffsetStr(offset);
        int regInd = getReg(gQuadNo, name); 
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {offsetStr, regName});
        ptrAssignedRegs.push(regInd);
        regVec[regInd]->isFree = false;
        return to_string(paramOffset) + "(" + regName + ")";
    }
    offset = getOffset(varName, st);
    offsetStr = getOffsetStr(offset);
    return offsetStr;
}

void initializeRegs() {
    regVec = vector<reg*>(NUM_REGISTER);
    for (int i = 0; i < NUM_REGISTER; i++) {
        regVec[i] = new reg();
        regVec[i]->isFree = true;
        regVec[i]->regName = regNames[i];
        regVec[i]->regNameOneByte = regNamesOneByte[i];
    }
}

int getReg(int quadNo, string varValue) {
    for (int i = 0; i < NUM_REGISTER; i++) {
        if (regVec[i]->isFree) {
            useReg(i, quadNo, varValue);
            return i;
        }
    }
    int ind = getRegToFree();
    freeRegAndMoveToStack(ind);
    useReg(ind, quadNo, varValue);
    return ind;
}

int getRegToFree() {
    // TODO: returns index of reg to free if all regs are used
    return 0;
}

void freeReg(int regInd) {
    regVec[regInd]->isFree = true;
}

void useReg(int regInd, int quadNo, string varValue) {
    regVec[regInd]->isFree = false;
    regVec[regInd]->quadNo = quadNo;
    regVec[regInd]->varValue = varValue;
}

void freeRegAndMoveToStack(int regInd) {
    //TODO: free a reg by moving its data to a location and then
    // if (isConstant(regVec[regInd]->varValue) && regVec[regInd]->varValue == CONSTANT)
    //     return;
    // string resultAddr = getVariableAddr(regVec[regInd]->varValue, codeSTVec[regVec[regInd]->quadNo]);
    // TODO: this line below has to be there after checking all registers are free
    // FLush register if contains useful variable

    // emitAsm("movq", {regVec[regInd]->regName, resultAddr});
}

void asmOpAssignment(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];
    quadruple* quadWithTypecast = gCodeWithTypecast[quadNo];
    //TODO: Verify
    if (isConstant(quad->result)) {
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    }

    string noPtrName = quad->result;
    bool isPtr = isPointer(noPtrName);

    if (isPtr) {
        noPtrName = stripPointer(quad->result);
    }

    symbolTableNode* stNode = lookUp(st, noPtrName); //for struct and struct array ptrs

    if (stNode && (stNode->infoType == INFO_TYPE_STRUCT || (isPtr && stNode->declSp->type[0] == TYPE_STRUCT))) {
        copyStruct(quad->arg1, quad->result, quadNo); //TODO: Check all valid cases
        return;
    }
    string resultAddr = getVariableAddr(quad->result, st);
    if (isConstant(quad->arg1) && !isTypecasted(quadWithTypecast->arg1)) {
        emitAsm("movq", {"$" + hexString(quad->arg1), resultAddr});
    } else {
        string argAddr;
        int tempRegInd=-1;
        if(isConstant(quad->arg1)) {
            tempRegInd = getReg(quadNo, quad->arg1);
            string regName = regVec[tempRegInd]->regName;
            emitAsm("movq", {"$" + hexString(quad->arg1), regName});
            argAddr = regName;
        }else {
            argAddr = getVariableAddr(quad->arg1, st);
        }
        if (stNode && stNode->declSp && stNode->declSp->type.size() > 0 && checkType(stNode->declSp, TYPE_FLOAT, 0)) {
            int regInd = getRegFloat(quadNo, quad->arg1);
            string regName = regVecFloat[regInd]->regName;
            if(isTypecasted(quadWithTypecast->arg1)) {
                emitAsm(getTypeCastOp(quadWithTypecast->arg1), {argAddr, regName});
            } else {
                emitAsm("movsd", {argAddr, regName});
            }
            emitAsm("movsd", {regName, resultAddr});
            freeRegFloat(regInd);
        } else {
            int regInd = getReg(quadNo, quad->arg1);
            string regName = regVec[regInd]->regName;
            if(isTypecasted(quadWithTypecast->arg1)) {
                emitAsm(getTypeCastOp(quadWithTypecast->arg1), {argAddr, regName});
            } else {
                emitAsm("movq", {argAddr, regName});
            }
            emitAsm("movq", {regName, resultAddr});
            freeReg(regInd);
        }
        if(tempRegInd != -1) {
            freeReg(tempRegInd);
        }
    }
}

void asmOpAssignmentF(int quadNo){
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    //TODO: Verify
    if (isConstant(quad->result)) {
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    }

    string noPtrName = quad->result;
    bool isPtr = isPointer(noPtrName);

    if (isPtr) {
        noPtrName = stripPointer(quad->result);
    }

    symbolTableNode* stNode = lookUp(st, noPtrName); //for struct and struct array ptrs

    if (stNode && (stNode->infoType == INFO_TYPE_STRUCT || (isPtr && stNode->declSp->type[0] == TYPE_STRUCT))) {
        copyStruct(quad->arg1, quad->result, quadNo); //TODO: Check all valid cases
        return;
    }
    string resultAddr = getVariableAddr(quad->result, st);
    string argAddr = getVariableAddr(quad->arg1, st);
    int regInd = getRegFloat(quadNo, quad->arg1);
    string regName = regVecFloat[regInd]->regName;
    emitAsm("movsd", {argAddr, regName});
    emitAsm("movsd", {regName, resultAddr});
    freeRegFloat(regInd);
}

string getTypeString(string typeCast){
    int len = typeCast.length();
    string retStr = "";
    int i = 0;
    while(i < len && typeCast[i] != '(') i++;
    i++;
    i++;
    while(i < len && typeCast[i] != ' ') {
        retStr = retStr + typeCast[i];
        i++;
    }
    return retStr;
}

int getTypeFromSting(string typeStr) {
    int n = typeStr.size();
    if(typeStr == "FLOAT") {
        return TYPE_FLOAT;
    }
    //return int for char, int and all pointers
    return TYPE_INT;
}

string getFromString(string str){
    size_t found = str.find("_TO");
    if(found == string::npos){
        errorAsm(str, INVALID_TYPECAST_IN_3AC);
    }
    string retStr = str.substr(0, found);
    return retStr; 
}

string getToString(string str){
    size_t found = str.find("TO_");
    if(found == string::npos){
        errorAsm(str, INVALID_TYPECAST_IN_3AC);
    }
    string retStr = str.substr(found+3, str.length()-found-3);
    return retStr;
}

string getTypeCastOp(string name) {
    string typeString = getTypeString(name);
    int toType = getTypeFromSting(getToString(typeString));
    int fromType = getTypeFromSting(getFromString(typeString));
    if(fromType == TYPE_FLOAT && toType == TYPE_INT) {
        return "cvttsd2si";
    }else if(fromType == TYPE_INT && toType == TYPE_FLOAT) {
        return "cvtsi2sd";
    }else if(fromType == TYPE_INT && toType == TYPE_INT) {
        return "movq";
    }else if(fromType == TYPE_FLOAT && toType == TYPE_FLOAT) {
        return "movsd";
    }
    errorAsm(name, INVALID_TYPECAST_IN_3AC);
    return EMPTY_STR;
}

void asmOpMod(int quadNo) {
    //    8:	8b 45 f8             	mov    -0x8(%rbp),%eax (Move arg1)
    //    b:	99                   	cltd
    //    c:	f7 7d fc             	idivl  -0x4(%rbp) (arg2)
    //    f:	89 55 f8             	mov    %edx,-0x8(%rbp) (result)
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    freeRegAndMoveToStack(EAX_REGISTER_INDEX);
    regVec[EAX_REGISTER_INDEX]->isFree = false;
    string regName = regVec[EAX_REGISTER_INDEX]->regName;

    if (isConstant(quad->arg1)) {
        emitAsm("movq", {"$" + hexString(quad->arg1), regName});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {argAddr, regName});
    }
    emitAsm("cltd", {});
    string arg2Addr;
    int reg2Ind = -1;
    if (isConstant(quad->arg2)) {
        reg2Ind = getReg(quadNo, CONSTANT);
        string reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movq", {arg2Addr, reg2Name});
        emitAsm("idivq", {reg2Name});
        freeReg(reg2Ind);
    } else {
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("idivq", {arg2Addr});
    }

    freeRegAndMoveToStack(EDX_REGISTER_INDEX);
    regVec[EDX_REGISTER_INDEX]->isFree = false;
    string regNamerdx = regVec[EDX_REGISTER_INDEX]->regName;
    emitAsm("movq", {regNamerdx, resultAddr});
    freeReg(EAX_REGISTER_INDEX);
    freeReg(EDX_REGISTER_INDEX);
    return;
}

string evaluate(string op, string arg1, string arg2) {
    if (op == "addq") {
        int result = getNumberFromConstAddr(arg1) + getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "imulq") {
        int result = getNumberFromConstAddr(arg1) * getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "subq") {
        int result = getNumberFromConstAddr(arg1) - getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "xor") {
        int result = getNumberFromConstAddr(arg1) ^ getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "or") {
        int result = getNumberFromConstAddr(arg1) | getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "and") {
        int result = getNumberFromConstAddr(arg1) & getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "shl") {
        int result = getNumberFromConstAddr(arg1) << getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    if (op == "sar") {
        int result = getNumberFromConstAddr(arg1) >> getNumberFromConstAddr(arg2);
        return hexString(to_string(result));
    }
    return EMPTY_STR;
}

void asmOpComp(int quadNo, string asm_comp) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    if (isConstant(quad->arg1)) {
        emitAsm("movq", {"$" + hexString(quad->arg1), REGISTER_RAX});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {argAddr, REGISTER_RAX});
    }
    if (isConstant(quad->arg2)) {
        emitAsm("cmp", {"$" + hexString(quad->arg2), REGISTER_RAX});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {argAddr, REGISTER_RAX});
    }
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm(asm_comp, {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    return;
}

void asmOpGeq(int quad) {
    asmOpComp(quad, "setge");
}

void asmOpLeq(int quad) {
    asmOpComp(quad, "setle");
}

void asmOpGreater(int quad) {
    asmOpComp(quad, "setg");
}

void asmOpLess(int quad) {
    asmOpComp(quad, "setl");
}

void asmOpEq(int quad) {
    asmOpComp(quad, "sete");
}

void asmOpNeq(int quad) {
    asmOpComp(quad, "setne");
}

void asmOpAndAnd(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    if (isFloat(quad->arg1, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("pxor", {regName, regName});
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("ucomisd", {argAddr, regName});
        emitAsm("jp", {"3f"});
        emitAsm("pxor", {regName, regName});
        emitAsm("ucomisd", {argAddr, regName});
        freeRegFloat(regInd);
    } else {
        if (isConstant(quad->arg1)) {
            emitAsm("cmp", {"$0", "$" + hexString(quad->arg1)});
        } else {
            string argAddr = getVariableAddr(quad->arg1, st);
            emitAsm("cmp", {"$0", argAddr});
        }
    }
    emitAsm("je", {"1f"}); // Jump to mov 0x0

    emitAsm("\n3:", {});
    if (isFloat(quad->arg2, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("pxor", {regName, regName});
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("ucomisd", {argAddr, regName});
        emitAsm("jp", {"4f"});
        emitAsm("pxor", {regName, regName});
        emitAsm("ucomisd", {argAddr, regName});
        freeRegFloat(regInd);
    } else if (isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0", "$" + hexString(quad->arg2)});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("je", {"1f"}); // Jump to mov 0x0
    emitAsm("\n4:", {});

    emitAsm("movq", {"$1", REGISTER_RAX});
    emitAsm("jmp", {"2f"});
    emitAsm("\n1:", {});
    emitAsm("movq", {"$0", REGISTER_RAX});
    emitAsm("\n2:", {});

    if (isFloat(quad->result, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("cvtsi2sd", {REGISTER_RAX, regName});
        emitAsm("movsd", {regName, resultAddr});
        freeRegFloat(regInd);
    } else
        emitAsm("movq", {REGISTER_RAX, resultAddr});
    return;
}

void asmOpOrOr(int quadNo) {

    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    if (isFloat(quad->arg1, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("pxor", {regName, regName});
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("ucomisd", {argAddr, regName});
        emitAsm("jp", {"1f"});
        emitAsm("pxor", {regName, regName});
        emitAsm("ucomisd", {argAddr, regName});
        freeRegFloat(regInd);
    } else if (isConstant(quad->arg1)) {
        emitAsm("cmp", {"$0", "$" + hexString(quad->arg1)});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("jne", {"1f"}); // Jump to mov 0x0

    if (isFloat(quad->arg2, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("pxor", {regName, regName});
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("ucomisd", {argAddr, regName});
        emitAsm("jp", {"1f"});
        emitAsm("pxor", {regName, regName});
        emitAsm("ucomisd", {argAddr, regName});
        freeRegFloat(regInd);
    } else if (isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0", "$" + hexString(quad->arg2)});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0", argAddr});
    }
    emitAsm("je", {"2f"}); // Jump to mov 0x0

    emitAsm("\n1:", {});
    emitAsm("movq", {"$1", REGISTER_RAX});
    emitAsm("jmp", {"3f"});
    emitAsm("\n2:", {});
    emitAsm("movq", {"$0", REGISTER_RAX});
    emitAsm("\n3:", {});

    if (isFloat(quad->result, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("cvtsi2sd", {REGISTER_RAX, regName});
        emitAsm("movsd", {regName, resultAddr});
        freeRegFloat(regInd);
    } else
        emitAsm("movq", {REGISTER_RAX, resultAddr});
    return;
}

void asmOpGoto(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (quad->result == BLANK_STR) {
        return;
    }

    if (!isConstant(quad->result)) {
        errorAsm(quad->result, GOTO_ADDR_NOT_CONST);
    }
    asmJump(quadNo, "jmp");
}

void asmOpIfGoto(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (quad->result == BLANK_STR) {
        return;
    }

    if (isFloat(quad->arg1, st)) {
        int regInd = getRegFloat(quadNo, CONSTANT);
        string regName = regVecFloat[regInd]->regName;
        emitAsm("pxor", {regName, regName});
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("ucomisd", {argAddr, regName});
        asmJump(quadNo, "jp");
        emitAsm("pxor", {regName, regName});
        emitAsm("ucomisd", {argAddr, regName});
        freeRegFloat(regInd);

    } else {
        if (isConstant(quad->arg1)) {
            int regInd = getReg(quadNo, CONSTANT);
            string regName = regVec[regInd]->regName;
            emitAsm("mov", {"$" + hexString(quad->arg1), regName});
            emitAsm("cmp", {"$0", regName});
            freeReg(regInd);
        } else {
            string argAddr1 = getVariableAddr(quad->arg1, st);
            int regInd = getReg(quadNo, quad->arg1);
            string regName = regVec[regInd]->regName;
            emitAsm("mov", {argAddr1, regName});
            emitAsm("cmp", {"$0", regName});
            freeReg(regInd);
        }
    }
    asmJump(quadNo, "jne");
}

void asmOpIfNeqGoto(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->arg1)) {
        if (isConstant(quad->arg2)) {
            int regInd = getReg(quadNo, quad->arg1);
            string regName = regVec[regInd]->regName;
            emitAsm("movq", {"$" + hexString(quad->arg2), regName});
            emitAsm("cmp", {"$" + hexString(quad->arg1), regName});
            freeReg(regInd);
        } else {
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("cmp", {"$" + hexString(quad->arg1), argAddr});
        }
    } else if (isConstant(quad->arg2)) {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$" + hexString(quad->arg2), argAddr});
    } else {
        string argAddr1 = getVariableAddr(quad->arg1, st);
        string argAddr2 = getVariableAddr(quad->arg2, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {argAddr1, regName});
        emitAsm("cmp", {regName, argAddr2});
        freeReg(regInd);
    }
    asmJump(quadNo, "jne");

    return;
}

void emitAsmForBinaryOperator(string op, int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    bool isConst1 = isConstant(quad->arg1), isConst2 = isConstant(quad->arg2);

    if (isConst1 && isConst2) {
        string eval = evaluate(op, quad->arg1, quad->arg2);
        if (eval != EMPTY_STR) {
            emitAsm("movq", {"$" + eval, resultAddr});
            return;
        }
    }

    string arg1Addr;
    string arg2Addr;
    int reg1Ind = -1;
    int reg2Ind = -1;
    string reg1Name, reg2Name;
    if (isConst1) {
        reg1Ind = getReg(quadNo, CONSTANT);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = "$" + hexString(quad->arg1);
        emitAsm("movq", {arg1Addr, reg1Name});
    } else {
        reg1Ind = getReg(quadNo, quad->arg1);
        reg1Name = regVec[reg1Ind]->regName;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
    }

    if (isConst2) {
        reg2Ind = getReg(quadNo, CONSTANT);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movq", {arg2Addr, reg2Name});
    } else {
        reg2Ind = getReg(quadNo, quad->arg2);
        reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("movq", {arg2Addr, reg2Name});
    }
    emitAsm(op, {reg1Name, reg2Name});
    emitAsm("movq", {reg2Name, resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
    return;
}

void asmOpLogicalOr(int quadNo) {
    emitAsmForBinaryOperator("or", quadNo);
}

void asmOpLogicalAnd(int quadNo) {
    emitAsmForBinaryOperator("and", quadNo);
}

void asmOpLogicalXor(int quadNo) {
    emitAsmForBinaryOperator("xor", quadNo);
}

void asmOpAddI(int quadNo) {
    emitAsmForBinaryOperator("addq", quadNo);
}

void asmOpMulI(int quadNo) {
    emitAsmForBinaryOperator("imulq", quadNo);
}

void asmOpSubI(int quadNo) {
    swap(gCode[quadNo]->arg1, gCode[quadNo]->arg2);
    emitAsmForBinaryOperator("subq", quadNo);
}

void asmOpCompareEqual(int quadNo) {
    emitAsmForBinaryOperator("cmp", quadNo);
}

void copyStruct(string from, string to, int quadNo) {
    symbolTable* st = codeSTVec[quadNo];
    //pointers only for arrays
    bool isFromPtr = isPointer(from);
    bool isToPtr = isPointer(to);
    string fromNoPtr = from;
    string toNoPtr = to;
    if (isPointer(from))
        fromNoPtr = stripPointer(from);
    if (isPointer(to))
        toNoPtr = stripPointer(to);

    symbolTableNode* fromNode = lookUp(st, fromNoPtr);
    if (!fromNode)
        error(from, SYMBOL_NOT_FOUND);
    if (fromNode->infoType != INFO_TYPE_STRUCT && (isFromPtr && fromNode->declSp->type[0] != TYPE_STRUCT))
        error(from, TYPE_ERROR);

    structTableNode* fromStructNode = nullptr;
    fromStructNode = structLookUp(st, fromNode->declSp->lexeme);
    if (!fromStructNode) {
        error(fromNode->declSp->lexeme, STRUCT_NOT_DECLARED);
    }

    symbolTableNode* toNode = lookUp(st, toNoPtr);
    if (!toNode)
        error(to, SYMBOL_NOT_FOUND);
    if (toNode->infoType != INFO_TYPE_STRUCT && (isToPtr && toNode->declSp->type[0] != TYPE_STRUCT))
        error(to, TYPE_ERROR);

    structTableNode* toStructNode = nullptr;
    toStructNode = structLookUp(st, toNode->declSp->lexeme);
    if (!toStructNode) {
        error(toNode->declSp->lexeme, STRUCT_NOT_DECLARED);
    }

    if ((toNode->infoType == INFO_TYPE_STRUCT && toNode->declSp->ptrLevel == 1) && !isToPtr) {
        string fromParamAddr = getVariableAddr(from, st);
        string toParamAddr = getVariableAddr(to, st);
        int regInd = getReg(quadNo, from);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {fromParamAddr, regName});
        emitAsm("movq", {regName, toParamAddr});
        freeReg(regInd);
        return;
    }

    for (structParam* p : fromStructNode->paramList) {
        string fromParam = from + "." + p->name;
        string fromParamAddr = getVariableAddr(fromParam, st);

        string toParam = to + "." + p->name;
        string toParamAddr = getVariableAddr(toParam, st);

        if(p->declSp->type[0] == TYPE_FLOAT){
            int regIndF = getRegFloat(quadNo, fromParam);
            string regNameF = regVecFloat[regIndF]->regName;
            emitAsm("movsd", {fromParamAddr, regNameF});
            emitAsm("movsd", {regNameF, toParamAddr});
            freeRegFloat(regIndF);
        } else {
            int regInd = getReg(quadNo, fromParam);
            string regName = regVec[regInd]->regName;
            emitAsm("movq", {fromParamAddr, regName});
            emitAsm("movq", {regName, toParamAddr});
            freeReg(regInd);
        }
        if (isToPtr) {
            regVec[ptrAssignedRegs.top()]->isFree = true;
            ptrAssignedRegs.pop();
        }
        if (isFromPtr) {
            regVec[ptrAssignedRegs.top()]->isFree = true;
            ptrAssignedRegs.pop();
        }
    }
}

void copyReturnStruct(string to, int quadNo) {
    symbolTable* st = codeSTVec[quadNo];
    //pointers only for arrays
    bool isToPtr = isPointer(to);
    string toNoPtr = to;
    if (isPointer(to))
        toNoPtr = stripPointer(to);

    symbolTableNode* toNode = lookUp(st, toNoPtr);

    if (!toNode)
        error(to, SYMBOL_NOT_FOUND);
    if (toNode->infoType != INFO_TYPE_STRUCT && (isToPtr && toNode->declSp->type[0] != TYPE_STRUCT))
        error(to, TYPE_ERROR);

    structTableNode* toStructNode = nullptr;

    toStructNode = structLookUp(st, toNode->declSp->lexeme);
    if (!toStructNode)
        error(toNode->declSp->lexeme, STRUCT_NOT_DECLARED);

    for (structParam* p : toStructNode->paramList) {
        int fromOff = getParameterOffset(toNode->declSp->lexeme, p->name, st);

        string toParam = to + "." + p->name;
        string toParamAddr = getVariableAddr(toParam, st);

        if(p->declSp->type[0] == TYPE_FLOAT){
            int regIndF = getRegFloat(quadNo, CONSTANT);
            string regNameF = regVecFloat[regIndF]->regName;
            emitAsm("movsd", {hexString(to_string(fromOff)) + "(" + REGISTER_RAX + ")", regNameF});
            emitAsm("movsd", {regNameF, toParamAddr});
            freeRegFloat(regIndF);
        } else {
            int regInd = getReg(quadNo, CONSTANT);
            string regName = regVec[regInd]->regName;
            emitAsm("movq", {hexString(to_string(fromOff)) + "(" + REGISTER_RAX + ")", regName});
            emitAsm("movq", {regName, toParamAddr});
            freeReg(regInd);
        }

        if (isToPtr) {
            regVec[ptrAssignedRegs.top()]->isFree = true;
            ptrAssignedRegs.pop();
        }
    }
}

void copyReturningStruct(string from, int quadNo) {
    symbolTable* st = codeSTVec[quadNo];
    //pointers only for arrays
    bool isFromPtr = isPointer(from);
    string fromNoPtr = from;
    if (isPointer(from))
        fromNoPtr = stripPointer(from);

    symbolTableNode* fromNode = lookUp(st, fromNoPtr);
    if (!fromNode)
        error(from, SYMBOL_NOT_FOUND);
    if (fromNode->infoType != INFO_TYPE_STRUCT && (isFromPtr && fromNode->declSp->type[0] != TYPE_STRUCT))
        error(from, TYPE_ERROR);

    structTableNode* fromStructNode = nullptr;
    fromStructNode = structLookUp(st, fromNode->declSp->lexeme);
    if (!fromStructNode)
        error(fromNode->declSp->lexeme, STRUCT_NOT_DECLARED);

    int regIndPtr = getReg(quadNo, CONSTANT);
    string regPtrName = regVec[regIndPtr]->regName;

    emitAsm("movq", {hexString(to_string(16)) + "(" + REGISTER_RBP + ")", regPtrName});

    for (structParam* p : fromStructNode->paramList) {
        string fromParam = from + "." + p->name;
        string fromParamAddr = getVariableAddr(fromParam, st);

        int toOff = getParameterOffset(fromNode->declSp->lexeme, p->name, st);


        if(p->declSp->type[0] == TYPE_FLOAT){
            int regIndF = getRegFloat(quadNo, CONSTANT);
            string regNameF = regVecFloat[regIndF]->regName;
            emitAsm("movsd", {fromParamAddr, regNameF}); //return register for struct ??
            emitAsm("movsd", {regNameF, hexString(to_string(toOff)) + "(" + regPtrName + ")"});
            freeRegFloat(regIndF);
        } else {
            int regInd = getReg(quadNo, fromParam);
            string regName = regVec[regInd]->regName;
            emitAsm("movq", {fromParamAddr, regName});
            emitAsm("movq", {regName, hexString(to_string(toOff)) + "(" + regPtrName + ")"});
            freeReg(regInd);
        }
        if (isFromPtr) {
            regVec[ptrAssignedRegs.top()]->isFree = true;
            ptrAssignedRegs.pop();
        }
    }

    emitAsm("movq", {regPtrName, REGISTER_RAX}); // Value to be returned, need to free RAX?
    freeReg(regIndPtr);
}