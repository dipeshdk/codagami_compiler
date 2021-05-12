#ifndef structuresHeader
#define structuresHeader

#include <bits/stdc++.h>

#include "constants.h"
#include <bits/stdc++.h>

using namespace std;

struct globalData {
    string varName;
    string value;
    int valueType;
};

struct declSpec {
    vector<int> type;                  // check validity of vector short double
    int ptrLevel;                      // **a =2
    string lexeme;                     // struct
    vector<int> storageClassSpecifier; // int or vector<int> ? check later
    bool isConst;                      //bool
    bool isVolatile;                   //bool

    declSpec() : ptrLevel(0), isConst(0), isVolatile(0) {
        lexeme = "empty";
    }
};

struct param {
    int infoType;
    vector<int> arrayIndices;
    int arraySize;
    struct declSpec* declSp;
    string paramName;
    param() {
        declSp = new declSpec();
        paramName = "empty";
        arraySize = 0;
        infoType = INFO_TYPE_NORMAL;
    }
};

struct structParam {
    int infoType;
    struct declSpec* declSp;
    string name;
    int bit;
    structParam() : bit(NO_BIT_ASSIGNED) {
        declSp = new declSpec();
        name = "empty";
    }
};

struct symbolTableNode {
    int infoType; // normal, func, array, struct/union
    int lineNo;
    int arraySize;
    int paramSize;
    int callPopSize;
    bool isDefined; //for functions
    int size;
    int paramWidth;
    int offset;
    vector<struct param*> paramList; //for functions, struct and union
    vector<int> arrayIndices;
    string name;
    struct declSpec* declSp;
    int scope;
    symbolTableNode() {
        infoType = INFO_TYPE_NORMAL;
        arraySize = 0;
        paramSize = 0;
        isDefined = true;
        declSp = new declSpec();
        scope = -1;
        callPopSize = 0;
    }
};

struct symbolTable {
    vector<string> symbolOrder;
    map<string, struct symbolTableNode*> symbolTableMap; // <lexeme, struct>
    struct symbolTable* parent;
    int scope; //name for scope : global, main, function name
    vector<struct symbolTable*> childList;
    map<string, struct structTableNode*> structMap;

    symbolTable() {
        parent = nullptr;
    }
};

struct structTableNode {
    int infoType; //struct or union
    string name;
    int lineNo;
    vector<structParam*> paramList;
    structTableNode() {
        name = "empty";
    }
};

struct node {
    int id;
    char* name = NULL;
    char* lexeme = NULL;
    int valType; //in which variable is constant stored
    int ival;
    float fval;
    int isLeaf; // DEAD_NODE if declaration node so not ot be printed in AST
    struct node* next;
    struct node* childList = nullptr;
    struct declSpec* declSp;
    bool isConstant;
    bool isStringLiteral;
    // symtable node
    int infoType = INFO_TYPE_NORMAL;
    int lineNo;
    int arraySize = 0;
    int paramSize = 0;
    vector<struct param*> paramList;
    vector<struct structParam*> structParamList;
    vector<node*> arrayIndices;

    string addr;
    int quad;
    vector<int> truelist, falselist, nextlist, continuelist, breaklist;
    node() {
        lexeme = strdup("empty");
        name = strdup("empty");
        next = childList = nullptr;
        declSp = new declSpec();
        addr = "EMPTY_ADDR";
        valType = NOT_CONSTANT;
        isConstant = false;
        isStringLiteral = false;
    }
};

struct quadruple {
    int opCode;
    string arg1, arg2, result;
};

struct reg {
    bool isFree;
    string varValue;
    int quadNo;
    string regName;
    string regNameOneByte;

    reg() {
        isFree = true;
    }
};

struct libParam{

    string paramName;
    int type, ptrLevel;

    libParam(string paramName, int type, int ptrLevel) : paramName(paramName), type(type), ptrLevel(ptrLevel) {
        
    }
};

struct libFunc{
    vector<libParam*> libParamVec;
    int type;
    int ptrLevel;

    libFunc(vector<libParam*> libParamVec,int type, int ptrLevel) : libParamVec(libParamVec), type(type), ptrLevel(ptrLevel)  {
        
    }
};

#endif