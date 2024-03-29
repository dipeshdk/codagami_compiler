#include "headers/allInclude.h"
using namespace std;

/* 
******** Integer global pasted here so that it is easy for everyone to use them here *********

vector<reg*> regVec;
vector<pair<string, vector<string>>> gAsm;
vector<string> gArgRegs({REGISTER_RDI, REGISTER_RSI, REGISTER_RDX, REGISTER_RCX, REGISTER_R8, REGISTER_R9});
vector<string> regNames({REGISTER_R10, REGISTER_R11, REGISTER_RCX, REGISTER_RAX, REGISTER_RDX, REGISTER_RBX, REGISTER_RSI, REGISTER_RDI});
vector<string> regNamesOneByte({"%r10b", "%r11b", "%cl", "%al", "%dl", "%bl", "%bpl", "%sil", "%dil"});
stack<string> funcNameStack;
stack<int> funcSizeStack;
vector<globalData*> globalDataPair;
int gQuadNo;
stack<int> ptrAssignedRegs;
set<string> libraryFunctions{"printf", "scanf", "malloc"};
*/

vector<reg*> regVecFloat;
vector<string> gArgRegsFloat({REGISTER_XMM0, REGISTER_XMM1, REGISTER_XMM2, REGISTER_XMM3, REGISTER_XMM4, REGISTER_XMM5, REGISTER_XMM6, REGISTER_XMM7});
vector<string> regNamesFloat({REGISTER_XMM0, REGISTER_XMM1, REGISTER_XMM2, REGISTER_XMM3, REGISTER_XMM4, REGISTER_XMM5, REGISTER_XMM6, REGISTER_XMM7, REGISTER_XMM8, REGISTER_XMM9, REGISTER_XMM10, REGISTER_XMM11, REGISTER_XMM12, REGISTER_XMM13, REGISTER_XMM14, REGISTER_XMM15});
int globalFloatTempCounter = 0;
string globalTempNamePrefix("f");
string globalTempNameSuffix("$");

int getRegFloat(int quadNo, string varValue) {
    for (int i = 0; i < NUM_REGISTER_FLOAT; i++) {
        if (regVecFloat[i]->isFree) {
            useRegFloat(i, quadNo, varValue);
            return i;
        }
    }
    int ind = getRegToFreeFloat();
    useRegFloat(ind, quadNo, varValue);
    return ind;
}

int getRegToFreeFloat() {
    // TODO: returns index of reg to free if all regs are used
    return 0;
}

void freeRegFloat(int regInd) {
    regVecFloat[regInd]->isFree = true;
}

void useRegFloat(int regInd, int quadNo, string varValue) {
    regVecFloat[regInd]->isFree = false;
    regVecFloat[regInd]->quadNo = quadNo;
    regVecFloat[regInd]->varValue = varValue;
}

float getFloatFromAddr(string varValue) {
    std::istringstream iss(varValue);
    float f;
    iss >> noskipws >> f;
    return f;
}

bool isFloatConstant(string varValue) {
    int n = varValue.size();
    if (varValue[n - 1] == globalTempNameSuffix[0])
        return true;
    else
        return false;
}

void emitAsmForFloatBinaryOperator(string asmOp, int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    // Redundant:
    // if (isConst1 && isConst2) {
    //     string eval = evaluate(op, quad->arg1, quad->arg2);
    // }

    int reg1Ind = -1;
    int reg2Ind = -1;
    reg1Ind = getRegFloat(quadNo, quad->arg1);
    reg2Ind = getRegFloat(quadNo, quad->arg2);
    if (reg1Ind < 0 || reg2Ind < 0) {
        errorAsm("For Float: ", REGISTER_ASSIGNMENT_ERROR);
    }
    string reg1Name = regNamesFloat[reg1Ind], reg2Name = regNamesFloat[reg2Ind];
    string arg1Addr = getVariableAddr(quad->arg1, st);
    string arg2Addr = getVariableAddr(quad->arg2, st);
    ;
    emitAsm("movsd", {arg1Addr, reg1Name});
    emitAsm("movsd", {arg2Addr, reg2Name});
    emitAsm(asmOp, {reg2Name, reg1Name});
    emitAsm("movsd", {reg1Name, resultAddr});
    freeRegFloat(reg1Ind);
    freeRegFloat(reg2Ind);
    return;
}

void asmOpAddF(int quadNo) {
    emitAsmForFloatBinaryOperator("addsd", quadNo);
}

void asmOpSubF(int quadNo) {
    emitAsmForFloatBinaryOperator("subsd", quadNo);
}

void asmOpMulF(int quadNo) {
    emitAsmForFloatBinaryOperator("mulsd", quadNo);
}

void asmOpDivF(int quadNo) {
    emitAsmForFloatBinaryOperator("divsd", quadNo);
}

string getGlobalFloatAddr() {
    string globalTempName = globalTempNamePrefix + to_string(globalFloatTempCounter) + globalTempNameSuffix;
    globalFloatTempCounter++;
    return globalTempName;
}

void sendStringLiteralToGlobal(string varValue, string globalTempName) {
    globalData* gData = new globalData();
    gData->varName = globalTempName;
    gData->value = varValue;
    gData->valueType = TYPE_STRING_LITERAL;
    globalDataPair.push_back(gData);
    return;
}

void sendFloatToGlobal(string varValue, string globalTempName) {
    globalData* gData = new globalData();
    gData->varName = globalTempName;
    gData->value = varValue;
    gData->valueType = TYPE_FLOAT;
    globalDataPair.push_back(gData);
    return;
}

void asmOpReturnF(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    int xmm0Ind = XMM0_REGISTER_INDEX;
    string xmm0reg = regVecFloat[xmm0Ind]->regName;
    if (quad->result != EMPTY_STR) {
        useReg(xmm0Ind, quadNo, NO_VAR_VALUE_ASSIGNED);
        if (!isConstant(quad->result)) {
            regVecFloat[xmm0Ind]->varValue = quad->result;
            string funcName = funcNameStack.top();
            symbolTableNode* funcNode = lookUp(st, funcName);
            if (!funcNode) {
                error(funcName, SYMBOL_NOT_FOUND);
            } else if (funcNode->declSp && funcNode->declSp->type.size() > 0 && (funcNode->declSp->type[0] == TYPE_STRUCT) && (funcNode->declSp->ptrLevel == 0)) {
                copyReturningStruct(quad->result, quadNo);
            } else {
                string argAddr = getVariableAddr(quad->result, st);
                emitAsm("movsd", {argAddr, xmm0reg});
            }
        } else {
            regVecFloat[xmm0Ind]->varValue = CONSTANT;
            emitAsm("movsd", {"$" + hexString(quad->result), xmm0reg});
        }
    }
    emitAsm("jmp", {"9f"});
    // emitAsm("addq", {"$" + hexString(to_string(funcSizeStack.top())), REGISTER_RSP});
    // emitAsm("popq", {REGISTER_RBP});
    // emitAsm("retq", {});
}


void asmOpUnaryMinusF(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    
    int reg1Ind = -1;
    int reg2Ind = -1;
    reg1Ind = getRegFloat(quadNo, quad->arg1);
    reg2Ind = getRegFloat(quadNo, CONSTANT);
    if (reg1Ind < 0 || reg2Ind < 0) {
        errorAsm("For Float: ", REGISTER_ASSIGNMENT_ERROR);
    }
    string resultAddr = getVariableAddr(quad->result, st);
    string reg1Name = regNamesFloat[reg1Ind], reg2Name = regNamesFloat[reg2Ind];
    string arg1Addr =  getVariableAddr(quad->arg1, st);
    emitAsm("movsd", {arg1Addr, reg1Name});
    emitAsm("xorpd", {reg2Name, reg2Name});
    emitAsm("subsd", {reg1Name, reg2Name});
    emitAsm("movsd  ", {reg2Name, resultAddr});
    freeRegFloat(reg1Ind);
    freeRegFloat(reg2Ind);
}

void initializeRegsFloat() {
    regVecFloat = vector<reg*>(NUM_REGISTER_FLOAT);
    for (int i = 0; i < NUM_REGISTER_FLOAT; i++) {
        regVecFloat[i] = new reg();
        regVecFloat[i]->isFree = true;
        regVecFloat[i]->regName = regNamesFloat[i];
    }
    return;
}

void asmOPMoveFloatFuncParam(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    string regName = quad->arg1;
    string valToMove = quad->result;
    if (find(gArgRegsFloat.begin(), gArgRegsFloat.end(), regName) == gArgRegsFloat.end()) {
        errorAsm("", REGISTER_ASSIGNMENT_ERROR);
    }

    if (isConstant(valToMove)) {
        emitAsm("movsd", {"$" + hexString(valToMove), regName});
    } else {
        string argAddr = getVariableAddr(valToMove, st);
        emitAsm("movsd", {argAddr, regName});
    }
}

void asmOpGreaterFloat(int quadNo) {
    asmOpCompGreaterFloat(quadNo, "seta");
}

void asmOpGeqFloat(int quadNo) {
    asmOpCompGreaterFloat(quadNo, "setae");
}

void asmOpCompGreaterFloat(int quadNo, string set) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    int regInd1 = getRegFloat(quadNo, quad->arg1);
    string regName1 = regVecFloat[regInd1]->regName;

    string argAddr1 = getVariableAddr(quad->arg1, st);
    emitAsm("movsd", {argAddr1, regName1});
    string argAddr = getVariableAddr(quad->arg2, st);
    emitAsm("comisd", {argAddr, regName1});

    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm(set, {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    freeRegFloat(regInd1);
    return;
}

void asmOpLessFloat(int quadNo) {
    asmOpCompLessFloat(quadNo, "seta");
}

void asmOpLeqFloat(int quadNo) {
    asmOpCompLessFloat(quadNo, "setae");
}

void asmOpCompLessFloat(int quadNo, string set) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    int regInd1 = getRegFloat(quadNo, quad->arg1);
    string regName1 = regVecFloat[regInd1]->regName;

    string argAddr2 = getVariableAddr(quad->arg2, st);
    emitAsm("movsd", {argAddr2, regName1});
    string argAddr1 = getVariableAddr(quad->arg1, st);
    emitAsm("comisd", {argAddr1, regName1});

    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm(set, {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    freeRegFloat(regInd1);
    return;
}

void asmOpEqFloat(int quad) {
    asmOpCompEqFloat(quad, "cmovne");
}

void asmOpNeqFloat(int quad) {
    asmOpCompEqFloat(quad, "cmove");
}

void asmOpCompEqFloat(int quadNo, string cmov) {

    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);

    int regInd = getRegFloat(quadNo, quad->arg1);
    string regName = regVecFloat[regInd]->regName;

    string argAddr2 = getVariableAddr(quad->arg2, st);
    emitAsm("movsd", {argAddr2, regName});
    string argAddr1 = getVariableAddr(quad->arg1, st);
    emitAsm("ucomisd", {argAddr1, regName});

    emitAsm("setnp", {"%al"});
    emitAsm("movq", {"$0", REGISTER_RDX});

    emitAsm("movsd", {argAddr2, regName});
    emitAsm("ucomisd", {argAddr1, regName});

    emitAsm(cmov, {REGISTER_RDX, REGISTER_RAX});
    emitAsm("movzbl", {"%al", REGISTER_RAX});

    if (isFloat(quad->result, st)) {
        int regInd1 = getRegFloat(quadNo, CONSTANT);
        string regName1 = regVecFloat[regInd1]->regName;
        emitAsm("cvtsi2sd", {REGISTER_RAX, regName1});
        emitAsm("movsd", {regName1, resultAddr});
        freeRegFloat(regInd1);
    } else
        emitAsm("movq", {REGISTER_RAX, resultAddr});
        
    freeReg(regInd);
    return;
}

bool isFloat(string name, symbolTable* st) {
    if (isFloatConstant(name)) {
        return true;
    }
    if (isPointer(name)) {
        name = stripPointer(name);
    }
    symbolTableNode* sym_node = lookUp(st, name);
    if ((sym_node) && ((sym_node->declSp && sym_node->declSp->type.size() > 0 && sym_node->declSp->type[0] == TYPE_FLOAT))) {
        return true;
    }
    return false;
}
