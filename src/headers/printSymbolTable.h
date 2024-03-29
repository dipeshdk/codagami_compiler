#ifndef printSymbolTableHeader
#define printSymbolTableHeader
#include "constants.h"
#include "structures.h"

void printDeclSp(declSpec* ds);
void printElem(symbolTableNode* elem, string str, int printTemps);

int getTypeSize(vector<int>& type);
int getNodeSize(symbolTableNode* elem, symbolTable* st);
int getOffsettedSize(int size);
void addTempDetails(string name, symbolTable* symtab, node* node);

void printSymbolTableJSON(string filePrefix, symbolTable* st, int numTab, int printTemps);
void printStructTable(map<string, struct structTableNode*>& structMap, int scope);
void printSymbolTable(symbolTable* st);
int getArraySize(symbolTableNode* sym_node, symbolTable* st);

string getOpName(int opCode);
void printCode(char* filename);
void printASMText();
#endif