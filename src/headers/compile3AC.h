#ifndef compile3ACHeader
#define compile3ACHeader

#include "constants.h"  
#include "structures.h" 

void emitAssemblyFrom3AC(string asmOutputFile);

void emitAssemblyForQuad(int quadNo);

void errorAsm(string str, int errCode);

int getOffset(string varName, symbolTable* st);

bool isGlobal(string varName, symbolTable* st);

string getVariableAddr(string varName, symbolTable* st);

void initializeRegs();

int getReg(int quadNo, string varValue);

int getRegToFree();

void freeReg(int regInd);

void useReg(int regInd, int quadNo, string varValue);

void freeRegAndMoveToStack(int regInd);

void asmOpComp(int quadNo, string asm_comp);

void asmOpGeq(int quadNo);

void asmOpLeq(int quadNo);

void asmOpEq(int quadNo);

void asmOpNeq(int quad);

void asmOpGreater(int quadNo);

void asmOpLess(int quadNo);

void asmOpAssignment(int quadNo);

void asmOpMod(int quadNo);

void asmOpAndAnd(int quadNo);

void asmOpOrOr(int quadNo);

void asmOpGoto(int quadNo);

void asmOpIfGoto(int quadNo);

void asmOpIfNeqGoto(int quadNo);

void asmOpUnaryOperator(string op, int quadNo);

void asmOpUnaryMinus(int quadNo);

void asmOpUnaryLogicalNot(int quadNo);

void asmOpDivI(int quadNo);

int getReg(int quadNo, string varValue);

int getRegToFree();

void freeReg(int regInd);

void useReg(int regInd, int quadNo, string varValue);

void freeRegAndMoveToStack(int regInd);

void asmOpAssignment(int quadNo);

string evaluate(string op, string arg1, string arg2);

void emitAsmForBinaryOperator(string op, int quadNo);

void asmOpLogicalOr(int quadNo);

void asmOpLogicalAnd(int quadNo);

void asmOpLogicalXor(int quadNo);

void asmOpAddI(int quadNo);

void asmOpMulI(int quadNo);

void asmOpSubI(int quadNo);

void asmOpCompareEqual(int quadNo);

void asmOpLeftShift(int quadNo);

void asmOpRightShift(int quadNo);

void emitAsm(string optr, vector<string> operands);

void errorAsm(string str, int errCode);

int getOffset(string varName, symbolTable* st);

bool isGlobal(string varName, symbolTable* st);

int getGlobalAddress(string varName, symbolTable* st);

string getVariableAddr(string varName, symbolTable* st) ;

void initializeRegs();

void amsOpLCall(int quadNo);

void asmOPMoveFuncParam(int quadNo);

void asmOpPushparam(int quadNo);

void asmOpPopparam(int quad);

void asmOpLabel(int quadNo);

void asmLabel(int labelno);

void asmJump(int quadNo, string op);

void asmOpReturn(int quadNo);

void asmOpEndFunc(int quadNo);

void emitFuncStart();

void asmOpBeginFunc(int quadNo);

void printAsm(string asmOutputFile);

void printASMData();

void amsOpAddr(int quadNo);

string getOffsetStr(int offset);

bool isPointer(string name);

string stripPointer(string name);

void stripTypeCastFromQuads();

string stripTypeCastUtil(string name);

int getParameterOffset(string structName, string param, symbolTable* st);

void asmOpBitwiseNot(int quadNo);

#endif