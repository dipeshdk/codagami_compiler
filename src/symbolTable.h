#include<bits/stdc++.h>

#define FNode 100
#define SYMBOL_ALREADY_EXISTS 102
#define ALLOCATION_ERROR 103
#define INVALID_ARGS 104
#define CONFLICTING_TYPES 105
#define UNDECLARED_SYMBOL 106
#define TYPE_ERROR 107
#define ARRAY_SIZE_NOT_CONSTANT 108
#define ARRAY_SIZE_SHOULD_BE_INT 109
#define INVALID_STORAGE_CLASS 110
#define SYMBOL_NOT_FOUND 111

#define TYPE_CHAR 1
#define TYPE_SHORT 2
#define TYPE_INT 3 
#define TYPE_LONG 4
#define TYPE_FLOAT 5
#define TYPE_DOUBLE 6
#define TYPE_SIGNED 7
#define TYPE_UNSIGNED 8
#define TYPE_VOID 9
#define TYPE_STRUCT 10
#define TYPE_UNION 11
#define TYPE_ENUM 12
#define TYPE_TYPEDEF 13
#define TYPE_EXTERN 14
#define TYPE_STATIC 15
#define TYPE_AUTO 16
#define TYPE_REGISTER 17

#define DEAD_NODE 2

#define INFO_TYPE_NORMAL 201
#define INFO_TYPE_FUNC 202
#define INFO_TYPE_ARRAY 203
#define INFO_TYPE_STRUCT 204

#define INF_PARAM_LIST INT_MAX

using namespace std;

// extern int gScope=0;
// gScope = 0;
// struct symbolTable* gSymTable; 

// struct param{
//     struct declSpec *declSp;
//     string paramName;
//     param() {
//         declSp = new declSpec();
//     }
// };

struct symbolTableNode {
    int infoType; // normal, func, array, struct/union
    int lineNo;
    int arraySize;
    int paramSize;
    int isDefined; //for functions
    vector<struct param*> paramList; //for functions, struct and union
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

    declSpec() : ptrLevel(0), isConst(0), isVolatile(0)  { }
} declSpec;

struct param{
    struct declSpec *declSp;
    string paramName;
    param() {
        declSp = new declSpec();
    }
};

typedef struct node
{
    int id;
    char *name;
    char *lexeme;
    int valType; //in which variable is constant stored
    long lval;
    int ival;
    float fval;
    double dval;
    int isLeaf; // DEAD_NODE if declaration node so not ot be printed in AST
    struct node *next;
    struct node *childList;
    struct declSpec *declSp;

    // symtable node
    int infoType = INFO_TYPE_NORMAL;
    int lineNo;
    int arraySize = 0;
    int paramSize = 0;
    vector<struct param*> paramList;
} node;

void insert_into_sets();
int addIVal(node* temp, string s);

int addFVal(node* temp, string s);

struct symbolTableNode* lookUp(symbolTable* st, string name);

int insertSymbol(symbolTable* st, int lineNo, string name);

struct symbolTable* addChildSymbolTable(struct symbolTable *parent);

int addTypeToDeclSpec(node *temp, vector<int>&v);

void printSymbolTable(symbolTable *st);

int mergeConstVolatile(node* temp, node* from);

int incrementPointerLevel(node* temp, node* from);

int copyPtrLevel(node* temp, node* from);

int addFunctionSymbol(node* declaration_specifiers, node* declarator);

declSpec* declSpCopy(declSpec* ds);

int checkValidType(declSpec* declSp);

int check_type_array(vector<int> &v);

int addStorageClassToDeclSpec(node *temp, vector<int>&v);

int removeSymbol(symbolTable* st, string name);