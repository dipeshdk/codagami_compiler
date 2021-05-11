#ifndef compile3ACFloatHeader
#define compile3ACFloatHeader

#include "constants.h"
#include "structures.h"
void sendFloatToGlobal(string varValue, string globalTempName);
string getGlobalFloatAddr();
bool isFloatConstant(string varValue);
float getFloatFromAddr(string varValue);
void useRegFloat(int regInd, int quadNo, string varValue);
void freeRegFloat(int regInd);
int getRegToFreeFloat();
int getRegFloat(int quadNo, string varValue);
void initializeRegsFloat();
void asmOpAddF(int quadNo);
void asmOpSubF(int quadNo);
void asmOpMulF(int quadNo);
void emitAsmForFloatBinaryOperator(string asmOp, int quadNo);
void asmOpReturnF(int quadNo);
void asmOpUnaryMinusF(int quadNo);
bool isFloat(string name, symbolTable* st);

#endif