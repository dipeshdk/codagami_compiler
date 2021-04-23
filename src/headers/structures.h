#ifndef structuresHeader
#define structuresHeader

#include<bits/stdc++.h>
#include "constants.h"

using namespace std;

struct declSpec
{
    vector<int> type; // check validity of vector short double 
    int ptrLevel; // **a =2
    string lexeme; // union or struct or enum
    vector<int> storageClassSpecifier; // int or vector<int> ? check later
    bool isConst; //bool
    bool isVolatile; //bool

    declSpec() : ptrLevel(0), isConst(0), isVolatile(0)  {
        lexeme="empty";
     }
};

struct param{
    struct declSpec *declSp;
    string paramName;
    int infoType;
    param() {
        declSp = new declSpec();
        paramName="empty";
        infoType = INFO_TYPE_NORMAL;
    }
};

struct structParam{
    struct declSpec *declSp;
    string name;
    int bit;
    structParam():bit(NO_BIT_ASSIGNED) {
        declSp = new declSpec();
        name="empty";
    }
};

struct symbolTableNode {
    int infoType; // normal, func, array, struct/union
    int lineNo;
    int arraySize;
    int paramSize;
    int isDefined; //for functions
    int size;
    int paramWidth;
    int offset;
    vector<struct param*> paramList; //for functions, struct and union
    string name;
    struct declSpec *declSp;

    symbolTableNode() {
        infoType = INFO_TYPE_NORMAL;
        arraySize=0;
        paramSize=0;
        isDefined=0;
        declSp = new declSpec();
    }
};

struct symbolTable{
    vector<string> symbolOrder;
    map<string, struct symbolTableNode*> symbolTableMap; // <lexeme, struct>
    struct symbolTable* parent;
    int scope; //name for scope : global, main, function name
    vector<struct symbolTable *> childList;
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
        name="empty";
    }
};

struct node
{
    int id;
    char *name = NULL;
    char *lexeme = NULL;
    int valType; //in which variable is constant stored
    int ival;
    float fval;
    int isLeaf; // DEAD_NODE if declaration node so not ot be printed in AST
    struct node *next;
    struct node *childList = nullptr;
    struct declSpec *declSp;
 
    // symtable node
    int infoType = INFO_TYPE_NORMAL;
    int lineNo;
    int arraySize = 0;
    int paramSize = 0;
    vector<struct param*> paramList;
    vector<struct structParam*> structParamList;

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
    }
}; 

struct quadruple {
    int opCode;
    string arg1, arg2, result;
};

#endif