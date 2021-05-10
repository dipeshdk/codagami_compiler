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

void asmOpReturnF(int quadNo) {
    quadruple* quad = gCode[quadNo];
    symbolTable* st = codeSTVec[quadNo];

    string xmm0Ind = XMM0_REGISTER_INDEX;
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
    emitAsm("addq", {"$" + hexString(to_string(funcSizeStack.top())), REGISTER_RSP});
    emitAsm("popq", {REGISTER_RBP});
    emitAsm("retq", {});
}
