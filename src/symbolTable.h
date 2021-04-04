#include<bits/stdc++.h>

#define FNode 1
using namespace std;

struct param{
    int parType;
    int paramPtrLevel;
    string paramName;
};

struct symbolTableNode {
    int type;
    int infoType; // normal, func, array
    int ptrLevel: // **a = 2
    int lineNo;
    int scope; // global variable
    int arraySize;
    int paramSize;
    param* paramList;
    string name;
    vector<int> attribute; // CONST, EXTERN
    vector<string> argList; //C compatible
};

typedef struct symbolTable {
    map<string, struct symbolTableNode> symbolTable;
    struct symbolTable* parent;
    vector<struct symbolTable*> childList;
}symbolTable;


int insertSymbol(symbolTable* st, int lineNo, string name, string attr, vector<string> argList);
    // return 0 if successful, otherwise errorCode


struct symbolTableNode* lookUp(symbolTable* st, string name, int &errorCode) {
    // goes to parent if does not find in st
    //returns node otherwise null
}

struct symbolTableNode* getNewSymbolTable(struct symbolTableNode* parent){
    // malloc
}

struct symbolTableNode* insertSymbolTableChild(symbolTable* st){
    //return st->childList.push_back(getNewSymbolTable(st));
}



//changes
typedef struct node{
	// int type;
	int id;
	char* name;
	char* lexeme;
	int isLeaf;
	struct node* next;
	struct node* childList;
    struct symbolTableNode* st;
}node;