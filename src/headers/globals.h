#ifndef globalsHeader
#define globalsHeader

#include<bits/stdc++.h>
#include "constants.h"
#include "structures.h"

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

#endif