#ifndef printSymbolTableHeader
#define printSymbolTableHeader
#include "constants.h"  
#include "structures.h" 

void printDeclSp(declSpec* ds);
void printElem(symbolTableNode* elem, string str);

int getTypeSize(vector<int> &type);

void printToCsvFile(symbolTable *st);
void printSymbolTableJSON(symbolTable *st, int numTab);
void printStructTable(map<string, struct structTableNode*> &structMap, int scope);
void printSymbolTable(symbolTable *st);

string getOpName(int opCode);
void printCode();
#endif