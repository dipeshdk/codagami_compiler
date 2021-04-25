#ifndef compile3ACHeader
#define compile3ACHeader

#include "constants.h"  
#include "structures.h" 


#define rax "rax"
#define rbx "rbx"
#define rcx "rcx"  
#define rdx "rdx" 
#define rsi "rsi" 
#define rdi "rdi" 
#define rbp "rbp" 
#define rsp "rsp" 
#define r8 "r8" 
#define r9 "r9" 
#define r10 "r10" 
#define r11 "r11" 
#define r12 "r12" 
#define r13 "r13" 
#define r14 "r14" 
#define r15 "r15" 


#endif

void emitAssemblyFrom3AC();

void emitAssemblyForQuad(int quadNo);

void emitAsm(string optr, vector<string> operands);

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

void asmOpAssignment(int quadNo);