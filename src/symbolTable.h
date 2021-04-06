#include<bits/stdc++.h>

#define FNode 1
#define SYMBOL_ALREADY_EXISTS 2
#define ALLOCATION_ERROR 3
using namespace std;

extern int gScope=0;
extern symbolTable* gSymTable; 

struct param{
    struct declSpec *declSp;
    // string paramName;
};

struct symbolTableNode {
    int infoType; // normal, func, array
    int lineNo;
    int arraySize;
    int paramSize;
    vector<param> paramList; //in lookup, search the paramList also
    // or add parameters to corresponding symbol table, helpful in lookup
    // also verify whether params come in symbol table or not
    string name;
    struct declSpec *declSp;
};

typedef struct symbolTable{
    map<string, struct symbolTableNode*> symbolTableMap; // <lexeme, struct>
    struct symbolTable *parent;
    int scope;
    vector<struct symbolTable *> childList;
} symbolTable;

// TODO: write a function in grammar.y to check types like int double should not come together
typedef struct declSpec
{
    vector<int> type; // check validity of vector short double 
    int ptrLevel; // **a =2
    string lexeme; // union or struct or enum
    vector<int> storageClassSpecifier; // int or vector<int> ? check later
    bool isConst; //bool
    bool isVolatile; //bool
} declSpec;

typedef struct node
{
    int id;
    char *name;
    char *lexeme;
    int isLeaf;
    struct node *next;
    struct node *childList;
    struct declSpec *declSp;
} node;


struct symbolTableNode* lookUp(symbolTable* st, string name);

int insertSymbol(symbolTable* st, int lineNo, string name);

struct symbolTable* addChildSymbolTable(struct symbolTable *parent);

