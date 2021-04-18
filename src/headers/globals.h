#ifndef globalsHeader
#define globalsHeader

#include<bits/stdc++.h>
#include "constants.h"
#include "structures.h"

using namespace std;

int temp_num = 0;
int gScope=0;
int id = 0;

extern int line;

struct symbolTable* gTempSymbolMap;
struct symbolTable* gSymTable;

vector<struct quadruple*> gCode;

set<int> validTypes = {TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_VOID, TYPE_STRUCT};

#endif