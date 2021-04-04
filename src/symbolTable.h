#include<bits/stdc++.h>

#define FNode 1
using namespace std;

struct param{
    struct declSpec *declSp;
    string paramName;
};

struct symbolTableNode {
    int infoType; // normal, func, array
    int lineNo;
    int scope; // global variable
    int arraySize;
    int paramSize;
    param* paramList;
    string name;
    struct declSpec *declSp;
    vector<string> argList; //C compatible
};

typedef struct symbolTable
{
    map<string, struct symbolTableNode> symbolTable;
    struct symbolTable *parent;
    vector<struct symbolTable *> childList;
} symbolTable;


int insertSymbol(symbolTable* st, int lineNo, string name, string attr, vector<string> argList);
    // return 0 if successful, otherwise errorCode


struct symbolTableNode* lookUp(symbolTable* st, string name, int &errorCode) {
    // goes to parent if does not find in st
    //returns node otherwise null
}

struct symbolTableNode *getNewSymbolTable(struct symbolTableNode *parent)
{
    // malloc
}

struct symbolTableNode *insertSymbolTableChild(symbolTable *st)
{
    //return st->childList.push_back(getNewSymbolTable(st));
}

// TODO: write a function in grammar.y to check types like int double should not come together
typedef struct declSpec
{
    vector<int> type;
    int ptrLevel; // **a =2
    string lexeme; // union or struct or enum
    vector<int> storageClassSpecifier;
    bool isConst; //bool
    bool isVolatile; //bool
} declSpec;

//changes
typedef struct node
{
    int id;
    char *name;
    char *lexeme;
    int isLeaf;
    struct node *next;
    struct node *childList;
    struct symbolTableNode *st;
    struct declSpec *declSp;
} node;