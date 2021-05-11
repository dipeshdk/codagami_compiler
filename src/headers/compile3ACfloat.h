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
void asmOpGeqFloat(int quad);
void asmOpLeqFloat(int quad);
void asmOpGreaterFloat(int quad);
void asmOpLessFloat(int quad);
void asmOpEqFloat(int quad);
void asmOpNeqFloat(int quad);
void asmOpCompGreaterFloat(int quadNo, string set);
void asmOpCompLessFloat(int quadNo, string set);
void asmOpCompEqFloat(int quadNo, string set);
#endif