#ifndef symbolTableHeader
#define symbolTableHeader
#include "constants.h"  
#include "structures.h" 

struct symbolTableNode* lookUp(symbolTable* st, string name);

int insertSymbol(symbolTable* st, int lineNo, string name);

void addIVal(node* temp, string s);

void addFVal(node* temp, string s);

struct symbolTable* addChildSymbolTable(struct symbolTable *parent);

structTableNode* structLookUp(symbolTable* st, string name);

structParam* structureParamLookup(structTableNode* node, string paramName, int& err, string& errStr);

int addTypeToDeclSpec(node *temp, vector<int>&v);

// int checkValidStorageClass(node *temp);

// int addStorageClassToDeclSpec(node *temp, vector<int>&v);

int addFunctionSymbol(node* declaration_specifiers, node* declarator);

int checkVoidSymbol(symbolTableNode* root);

declSpec* declSpCopy(declSpec* ds);

int removeSymbol(symbolTable* st, string name);
#endif
