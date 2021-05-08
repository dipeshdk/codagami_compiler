#include "headers/allInclude.h"
using namespace std;

vector<reg*> regVec;
vector<pair<string, vector<string>>> gAsm;
vector<string> gArgRegs({REGISTER_RDI, REGISTER_RSI, REGISTER_RDX, REGISTER_RCX, REGISTER_R8, REGISTER_R9});
vector<string> regNames({REGISTER_R10, REGISTER_R11, REGISTER_RCX, REGISTER_RAX, REGISTER_RDX, REGISTER_RBX, REGISTER_RSP, REGISTER_RBP, REGISTER_RSI, REGISTER_RDI});
vector<string> regNamesOneByte({"%r10b", "%r11b", "%cl", "%al", "%dl", "%bl", REGISTER_RSP, "%bpl", "%sil", "%dil"});
stack<string> funcNameStack;
stack<int> funcSizeStack;
vector<globalData*> globalDataPair;
int gQuadNo;
stack<int> ptrAssignedRegs;
set<string> libraryFunctions{"printf", "scanf", "malloc"};

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

void emitAssemblyFrom3AC(string asmOutputFile) {
    funcNameStack.push(GLOBAL);
    initializeRegs();
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
    case OP_IFGOTO:
        asmOpIfGoto(quadNo);
        break;
    case OP_SUBI:
        asmOpSubI(quadNo);
        break;
    case OP_ASSIGNMENT:
        asmOpAssignment(quadNo);
        break;
    case OP_UNARY_MINUS:
        asmOpUnaryMinus(quadNo);
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
    case OP_EQ:
        asmOpEq(quadNo);
        break;
    case OP_NEQ:
        asmOpNeq(quadNo);
        break;
    case OP_LEQ:
        asmOpLeq(quadNo);
        break;
    case OP_GREATER:
        asmOpGreater(quadNo);
        break;
    case OP_LESS:
        asmOpLess(quadNo);
        break;
    case OP_MOD:
        asmOpMod(quadNo);
        break;
    /* case OP_ADDF: 
        break;
    case OP_MULF: 
        break;
    case OP_SUBF: 
        break;
    case OP_DIVF: 
        break; */
    case OP_GEQ:
        asmOpGeq(quadNo);
        break;
    case OP_ANDAND:
        asmOpAndAnd(quadNo);
        break;
    case OP_OROR:
        asmOpOrOr(quadNo);
        break;
    case OP_IFNEQGOTO:
        asmOpIfNeqGoto(quadNo);
        break;
    case OP_BEGINFUNC:
        asmOpBeginFunc(quadNo);
        break;
    case OP_ENDFUNC:
        asmOpEndFunc(quadNo);
        break;
    case OP_RETURN:
        asmOpReturn(quadNo);
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
    case OP_MOV:
        asmOPMoveFuncParam(quadNo);
        break;
    default:
        break;
    }
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

    if (quad->result != EMPTY_STR) {
        freeRegAndMoveToStack(eaxInd);
        useReg(eaxInd, quadNo, NO_VAR_VALUE_ASSIGNED);

        if (!isConstant(quad->result)) {
            // location--copy the return struct to appropriate location here.
            regVec[eaxInd]->varValue = quad->result;
            symbolTableNode* sym_node = lookUp(st, quad->result);
            if ((sym_node->infoType == INFO_TYPE_STRUCT) || (sym_node->declSp && sym_node->declSp->type[0] == TYPE_STRUCT)) {
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
}

void asmOpEndFunc(int quadNo) {
    emitAsm("addq", {"$" + hexString(to_string(funcSizeStack.top())), REGISTER_RSP});
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
    if (libraryFunctions.find(quad->arg1) != libraryFunctions.end()) {
        emitAsm("xor", {REGISTER_RAX, REGISTER_RAX});
    } else {
        string funcName = quad->arg1;
        symbolTableNode* funcNode = lookUp(st, funcName);
        if (!funcNode) {
            //TODO: Error
        }
        if (funcNode->declSp && (funcNode->declSp->type[0] == TYPE_STRUCT)) {
            isStruct = 1;
            string structName = funcNode->declSp->lexeme;
            // structTableNode* struc = structLookUp(gSymTable, structName);
            symbolTableNode* tempNode = new symbolTableNode();
            tempNode->declSp->type.push_back(TYPE_STRUCT);
            tempNode->declSp->lexeme = structName;
            int size = getNodeSize(tempNode, gSymTable);
            emitAsm("subq", {"$" + hexString(to_string(size)), REGISTER_RSP});
            emitAsm("pushq", {REGISTER_RSP});
        }
    }

    emitAsm("callq", {quad->arg1});
    if (quad->result != EMPTY_STR) {
        string resultAddr = getVariableAddr(quad->result, st);
        //---location: return value movement here
        if (isStruct) {
            copyReturnStruct(quad->result, quadNo);
        } else
            emitAsm("movq", {REGISTER_RAX, resultAddr});
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
    //TODO: funcNameStack is the the stack containing active function names, starting with global
    symbolTableNode* funcNode = lookUp(st, funcNameStack.top());
    if (!funcNode) {
        error(funcNameStack.top(), SYMBOL_NOT_FOUND);
    }
    if (funcNode->infoType != INFO_TYPE_FUNC)
        error(funcNameStack.top(), TYPE_ERROR);

    //emit start
    emitFuncStart();

    //sub stack pointer
    emitAsm("subq", {"$" + hexString(quad->result), REGISTER_RSP});

    //move first 6 arguments from register to stack
    vector<struct param*> paramList = funcNode->paramList;
    int numParams = paramList.size();
    for (int i = 0; i < min(6, numParams); i++) {
        if ((paramList[i]->declSp->type.size() > 0 && paramList[i]->declSp->type[0] == TYPE_STRUCT))
            continue;
        string argAddr = getVariableAddr(paramList[i]->paramName, st);
        emitAsm("movq", {gArgRegs[i], argAddr});
    }
    return;
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
        emitAsm("cmpl", {"$0x0", argAddr});
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
    } else {
        regVec[EAX_REGISTER_INDEX]->varValue = quad->arg1;
        arg1Addr = getVariableAddr(quad->arg1, st);
        emitAsm("movq", {arg1Addr, reg1Name});
    }

    emitAsm("cltd", {});

    string arg2Addr;
    int reg2Ind = -1;
    if (isConst2) {
        reg2Ind = getReg(quadNo, CONSTANT);
        string reg2Name = regVec[reg2Ind]->regName;
        arg2Addr = "$" + hexString(quad->arg2);
        emitAsm("movq", {arg2Addr, reg2Name});
        emitAsm("idivq", {reg2Name});
    } else {
        arg2Addr = getVariableAddr(quad->arg2, st);
        emitAsm("idivq", {arg2Addr});
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
        int regAddInd = getReg(gQuadNo, identifier); //TODO: Free this reg
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
        // free regAddName
        ptrAssignedRegs.push(regInd);
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
        int regInd = getReg(gQuadNo, name); //TODO: Free this reg
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {offsetStr, regName});
        ptrAssignedRegs.push(regInd);
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
        int regInd = getReg(gQuadNo, name); //TODO: Free this reg
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {offsetStr, regName});
        ptrAssignedRegs.push(regInd);
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
    // cout << 907 << regVec[regInd]->varValue << endl;
    // string resultAddr = getVariableAddr(regVec[regInd]->varValue, codeSTVec[regVec[regInd]->quadNo]);
    // TODO: this line below has to be there after checking all registers are free
    // FLush register if contains useful variable

    // emitAsm("movq", {regVec[regInd]->regName, resultAddr});
}

void asmOpAssignment(int quadNo) {
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
        copyStruct(quad->arg1, quad->result, quadNo);
        return;
    }
    string resultAddr = getVariableAddr(quad->result, st);
    if (isConstant(quad->arg1)) {
        emitAsm("movq", {"$" + hexString(quad->arg1), resultAddr});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {argAddr, regName});
        emitAsm("movq", {regName, resultAddr});
        freeReg(regInd);
    }
}

void asmOpMod(int quadNo) {
    //    8:	8b 45 f8             	mov    -0x8(%rbp),%eax (Move arg1)
    //    b:	99                   	cltd
    //    c:	f7 7d fc             	idivl  -0x4(%rbp) (arg2)
    //    f:	89 55 f8             	mov    %edx,-0x8(%rbp) (result)
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR); //does not print line number

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
    if (isConstant(quad->arg1)) {
        emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg1)});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$0x0", argAddr});
    }
    emitAsm("je", {"1f"}); // Jump to mov 0x0
    if (isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg2)});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0x0", argAddr});
    }
    emitAsm("je", {"1f"}); // Jump to mov 0x0
    emitAsm("movq", {"$0x1", REGISTER_RAX});
    emitAsm("jmp", {"2f"});
    emitAsm("\n1:", {});
    emitAsm("movq", {"$0x0", REGISTER_RAX});
    emitAsm("\n2:", {});
    emitAsm("movq", {REGISTER_RAX, resultAddr});
    return;
}

void asmOpOrOr(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);

    string resultAddr = getVariableAddr(quad->result, st);
    if (isConstant(quad->arg1)) {
        emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg1)});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("cmp", {"$0x0", argAddr});
    }
    emitAsm("jne", {"1f"}); // Jump to mov 0x0
    if (isConstant(quad->arg2)) {
        emitAsm("cmp", {"$0x0", "$" + hexString(quad->arg2)});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("cmp", {"$0x0", argAddr});
    }
    emitAsm("je", {"2f"}); // Jump to mov 0x0
    emitAsm("\n1:", {});
    emitAsm("movq", {"$0x1", REGISTER_RAX});
    emitAsm("jmp", {"3f"});
    emitAsm("\n2:", {});
    emitAsm("movq", {"$0x0", REGISTER_RAX});
    emitAsm("\n3:", {});
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

    if (isConstant(quad->arg1)) {
        emitAsm("cmpl", {"$0x0", "$" + hexString(quad->arg1)});
    } else {
        string argAddr1 = getVariableAddr(quad->arg1, st);
        int regInd = getReg(quadNo, quad->arg1);
        string regName = regVec[regInd]->regName;
        emitAsm("mov", {argAddr1, regName});
        emitAsm("cmp", {"$0x0", regName});
        freeReg(regInd);
    }
    asmJump(quadNo, "jne");
}

void asmOpIfNeqGoto(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->arg1)) {
        if (isConstant(quad->arg2)) {
            emitAsm("cmp", {"$" + hexString(quad->arg1), "$" + hexString(quad->arg2)});
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
    if (!fromStructNode)
        error(fromNode->declSp->lexeme, STRUCT_NOT_DECLARED);

    symbolTableNode* toNode = lookUp(st, toNoPtr);
    if (!toNode)
        error(to, SYMBOL_NOT_FOUND);
    if (toNode->infoType != INFO_TYPE_STRUCT && (isToPtr && toNode->declSp->type[0] != TYPE_STRUCT))
        error(to, TYPE_ERROR);

    structTableNode* toStructNode = nullptr;
    toStructNode = structLookUp(st, toNode->declSp->lexeme);
    if (!toStructNode)
        error(toNode->declSp->lexeme, STRUCT_NOT_DECLARED);

    for (structParam* p : fromStructNode->paramList) {
        string fromParam = from + "." + p->name;
        string fromParamAddr = getVariableAddr(fromParam, st);

        string toParam = to + "." + p->name;
        string toParamAddr = getVariableAddr(toParam, st);

        int regInd = getReg(quadNo, fromParam);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {fromParamAddr, regName});
        emitAsm("movq", {regName, toParamAddr});
        freeReg(regInd);
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

        int regInd = getReg(quadNo, CONSTANT);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {hexString(to_string(fromOff)) + "(" + REGISTER_RAX + ")", regName});
        emitAsm("movq", {regName, toParamAddr});
        freeReg(regInd);
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

        int regInd = getReg(quadNo, fromParam);
        string regName = regVec[regInd]->regName;
        emitAsm("movq", {fromParamAddr, regName});
        emitAsm("movq", {regName, hexString(to_string(toOff)) + "(" + regPtrName + ")"});
        freeReg(regInd);
    }

    emitAsm("movq", {regPtrName, REGISTER_RAX}); // Value to be returned, need to free RAX?
    freeReg(regIndPtr);
}