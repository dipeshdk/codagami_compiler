#ifndef globalsHeader
#define globalsHeader

#include <bits/stdc++.h>

#include "constants.h"
#include "structures.h"
#include <bits/stdc++.h>

using namespace std;

extern int temp_num;
extern int gScope;
extern int id;

extern int line;

extern symbolTable* gTempSymbolMap;
extern symbolTable* gSymTable;

extern string currFunc;
// extern void error(string var, int error_code);

extern int errCode;
extern string errStr;

extern vector<struct quadruple*> gCode;
extern set<int> validTypes;

extern node* root;
extern vector<symbolTable*> codeSTVec;

extern vector<reg*> regVec;
extern vector<pair<string, vector<string>>> gAsm;
extern vector<string> regNames;
extern vector<string> gArgRegs;

extern stack<string> funcNameStack;
extern stack<int> funcSizeStack;
extern vector<globalData*> globalDataPair;
extern symbolTable* globalScopeSymTable;
extern set<string> libraryFunctions;

extern vector<reg*> regVecFloat;
extern vector<string> gArgRegsFloat;
extern vector<string> regNamesFloat;
extern int globalFloatTempCounter;
extern string globalTempNamePrefix;
extern string globalTempNameSuffix;
#endif