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
vector<string> gArgRegsFloat({REGISTER_XMM0,REGISTER_XMM1, REGISTER_XMM2, REGISTER_XMM3, REGISTER_XMM4, REGISTER_XMM5, REGISTER_XMM6, REGISTER_XMM7});
vector<string> regNamesFloat({REGISTER_XMM0,REGISTER_XMM1, REGISTER_XMM2, REGISTER_XMM3, REGISTER_XMM4, REGISTER_XMM5, REGISTER_XMM6, REGISTER_XMM7, REGISTER_XMM8,REGISTER_XMM9, REGISTER_XMM10, REGISTER_XMM11, REGISTER_XMM12, REGISTER_XMM13, REGISTER_XMM14, REGISTER_XMM15});
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
    if(varValue[n-1] == globalTempNameSuffix[0]) return true;
    else return false;
}

string getGlobalFloatAddr() {
    string globalTempName = globalTempNamePrefix + to_string(globalFloatTempCounter) + globalTempNameSuffix;
    globalFloatTempCounter++;
    return globalTempName;
}

void sendFloatToGlobal(string varValue, string globalTempName){
    globalData *gData = new globalData();
    gData->varName = globalTempName;
    gData->value = varValue;
    gData->valueType = TYPE_FLOAT;
    globalDataPair.push_back(gData);
    return;
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

void asmOpGeqFloat(int quadNo) {
    asmOpCompFloat(quadNo, "setge");
}

void asmOpLeqFloat(int quadNo) {
    asmOpLessFloat(quadNo);
}

void asmOpGreaterFloat(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
  
    if(isFloatConstant(quad->arg1)){
        //emitAsm("movsd", {"$" + hexString(quad->arg1), REGISTER_XMM1});
        if(isFloatConstant(quad->arg2)){
            emitAsm("movsd", {"$" + hexString(quad->arg2), REGISTER_XMM1});
        } else {
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("movsd", {argAddr, REGISTER_XMM1});
        }
        emitAsm("movsd", {"$" + hexString(quad->arg1), REGISTER_XMM0});
        emitAsm("comisd", {REGISTER_XMM0, REGISTER_XMM1});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("movsd", {argAddr, REGISTER_XMM0});
        if(isFloatConstant(quad->arg2)){
            emitAsm("comisd", {"$" + hexString(quad->arg2), REGISTER_XMM0});
        } else {
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("comisd", {argAddr, REGISTER_XMM0});
        }
    }
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm("seta", {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    return;
}

void asmOpLessFloat(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
  
    if(isFloatConstant(quad->arg1)){
        //emitAsm("movsd", {"$" + hexString(quad->arg1), REGISTER_XMM1});
        if(isFloatConstant(quad->arg2)){
            emitAsm("movsd", {"$" + hexString(quad->arg2), REGISTER_XMM1});
        } else {
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("movsd", {argAddr, REGISTER_XMM1});
        }
        emitAsm("movsd", {"$" + hexString(quad->arg1), REGISTER_XMM0});
        emitAsm("comisd", {REGISTER_XMM1, REGISTER_XMM0});
    } else {
        if(isFloatConstant(quad->arg2)){
            emitAsm("movsd", {"$" + hexString(quad->arg2), REGISTER_XMM0});
        } else {
            string argAddr = getVariableAddr(quad->arg2, st);
            emitAsm("movsd", {argAddr, REGISTER_XMM0});
        }
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("comisd", {argAddr, REGISTER_XMM0});
    }
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm("seta", {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    return;
}

void asmOpEqFloat(int quad) {
    asmOpCompFloat(quad, "sete");
}

void asmOpNeqFloat(int quad) {
    asmOpCompFloat(quad, "setne");
}


void asmOpCompFloat(int quadNo, string asm_comp) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    if (isConstant(quad->result) || isFloatConstant(quad->result))
        errorAsm(quad->result, ASSIGNMENT_TO_CONSTANT_ERROR);
    string resultAddr = getVariableAddr(quad->result, st);
    if (isFloatConstant(quad->arg1)) {
        emitAsm("movsd", {"$" + hexString(quad->arg1), REGISTER_XMM0});
    } else {
        string argAddr = getVariableAddr(quad->arg1, st);
        emitAsm("movsd", {argAddr, REGISTER_XMM0});
    }
    if (isConstant(quad->arg2)) {
        emitAsm("comisd", {"$" + hexString(quad->arg2), REGISTER_XMM0});
    } else {
        string argAddr = getVariableAddr(quad->arg2, st);
        emitAsm("comisd", {argAddr, REGISTER_XMM0});
    }
    int regInd = getReg(quadNo, quad->arg1);
    string regName = regVec[regInd]->regName;
    string regNameOneByte = regVec[regInd]->regNameOneByte;
    emitAsm("seta", {regNameOneByte});
    emitAsm("movzbl", {regNameOneByte, regName});
    emitAsm("movq", {regName, resultAddr});
    freeReg(regInd);
    return;
}