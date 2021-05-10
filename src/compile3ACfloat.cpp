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

void isFloatConstant(string varValue){
        
}

void sendFloatToGlobal(string varValue){

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
    string reg1Name = regNamesFloat[reg1Ind], reg2Name = regNames[reg2Ind];
    string arg1Addr =  getVariableAddr(quad->arg1, st);
    string arg2Addr =  getVariableAddr(quad->arg2, st);;
    emitAsm("movsd", {arg1Addr, reg1Name});
    emitAsm("movsd", {arg2Addr, reg2Name});
    emitAsm(asmOp, {reg1Name, reg2Name});
    emitAsm("movsd", {reg2Name, resultAddr});
    freeReg(reg1Ind);
    freeReg(reg2Ind);
    return;
}

void asmOpAddF(int quadNo){
    emitAsmForFloatBinaryOperator("addsd", quadNo);
}

void asmOpSubF(int quadNo){
    emitAsmForFloatBinaryOperator("subsd", quadNo);
}

void asmOpAddF(int quadNo){
    emitAsmForFloatBinaryOperator("mulsd", quadNo);
}