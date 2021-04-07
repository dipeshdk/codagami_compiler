#include<bits/stdc++.h>
#include "symbolTable.h"
using namespace std;
int gScope=0;
struct symbolTable* gSymTable;
// grammar.y check if nullptr then it is error.
struct symbolTableNode* lookUp(symbolTable* st, string name) {
    // goes to parent if does not find in st
    //returns node otherwise null
    symbolTable* node = st;
    while(node != nullptr){
        if(node->symbolTableMap.find(name) != node->symbolTableMap.end()){
            return node->symbolTableMap[name];
        }
        node = node->parent;
    }
    return nullptr;
}

int insertSymbol(symbolTable* st, int lineNo, string name){
    // return 0 if successful, otherwise errorCode
    if(st->symbolTableMap.find(name) != st->symbolTableMap.end()) {
        cout << "\nsymbol name: " << name << "\n";
        return SYMBOL_ALREADY_EXISTS;
    }
    symbolTableNode* node = new symbolTableNode();
    if(!node) {
        return ALLOCATION_ERROR;
    }
    node->name = name;
    node->lineNo = lineNo;
    st->symbolTableMap[name] = node;
    return 0;
}


int addIVal(node* temp, string s) {
    // size_t n = s.length();
    size_t p;
    // int i = stoi(s,&p);
    // if(p == n) {
    //     temp->ival = (int)stod(s, &p);
    //     return TYPE_INT;
    // }
    // long l = stol(s, &p);
    // if(p == n || (p == n-1 && (s[p] == 'l' || s[p] == 'L'))) {
    //     return TYPE_LONG;
    // }
    //TODO: Handle int and long separately
    temp->valType = TYPE_LONG;
    temp->lval = (long)stod(s, &p);
    return TYPE_INT;
}

int addFVal(node* temp, string s) {
    // size_t n = s.length();
    size_t p;
    // int i = stoi(s,&p);
    // if(p == n) {
    //     temp->ival = (int)stod(s, &p);
    //     return TYPE_INT;
    // }
    // long l = stol(s, &p);
    // if(p == n || (p == n-1 && (s[p] == 'l' || s[p] == 'L'))) {
    //     return TYPE_LONG;
    // }
    //TODO: Handle int and long separately
    temp->valType = TYPE_DOUBLE;
    temp->dval = (double)stod(s, &p);
    return TYPE_FLOAT;
    // return TYPE_ERROR;
}


struct symbolTable* addChildSymbolTable(struct symbolTable *parent)
{
    symbolTable* node = new symbolTable();
    if(!node)
        return nullptr;
    node->scope = gScope++;
    node->parent = parent;
    parent->childList.push_back(node);
    return node;
}

int checkValidType(declSpec* declSp) {
    // TODO: Check valid types
    // Error code : CONFLICTING_TYPES
    return 0;
}

int addTypeToDeclSpec(node *temp, vector<int>&v){
    if(!temp || !temp->declSp) {
        return INVALID_ARGS;
    }
    for(int i = 0; i < v.size(); i++) {
        temp->declSp->type.push_back(v[i]);
    }
    return checkValidType(temp->declSp);
}

string getTypeName(int type) {
    switch(type) {
        case TYPE_CHAR: return "CHAR";
        case TYPE_SHORT: return "SHORT";
        case TYPE_INT: return "INT";
        case TYPE_LONG: return "LONG";
        case TYPE_FLOAT: return "FLOAT";
        case TYPE_DOUBLE: return "DOUBLE";
        case TYPE_SIGNED: return "SIGNED";
        case TYPE_UNSIGNED: return "UNSIGNED";
        case TYPE_VOID: return "VOID";
        case TYPE_STRUCT: return "STRUCT";
        case TYPE_UNION: return "UNION";
        case TYPE_ENUM: return "ENUM";
    }
    return "INVALID TYPE";
}

void printDeclSp(declSpec* ds) {
    cout << "   Printing Decl Sp\n";
    if(!ds) {
        cout << "   Decl Sp: NULL\n";
        return;
    }
    cout << "   ptrLevel: " << ds->ptrLevel << " \n"
        << "    lexeme: " <<ds->lexeme << "  \n"
        << "    isConst: " <<ds->isConst << "  \n"
        << "    isVolatile: " <<ds->isVolatile << "  \n";
    cout << "\n     type: \n    ";
    for(int t : ds->type) 
        cout << getTypeName(t) << " ";
    cout << "\n     storageClassSpecifier: \n   ";
    for(int t : ds->storageClassSpecifier) 
       cout << t << " ";
    cout << "\n";
}

void printSymbolTable(symbolTable *st) {
    cout << "\n\n=============Printing symbol table (scope: " << st->scope << ")====================\n\n";

    for(auto elem : st->symbolTableMap) {
        cout << "\n---------------------------------------\n";
        cout << elem.first << " \n" 
            << "name: " << elem.second->name << " \n"
            << "infoType: " << elem.second->infoType << " \n"
            << "arraySize: " << elem.second->arraySize << " \n"
            << "paramSize: " << elem.second->paramSize << " \n"
            << "isDefined: " << elem.second->isDefined << " \n";

        cout << "declSp: \n";
        printDeclSp(elem.second->declSp);
        cout << "paramList: \n   ";
        for(param* t : elem.second->paramList) {
            printDeclSp(t->declSp);
        }
        cout << "\n---------------------------------------\n";
    }
    cout << "\n=================================================\n";
    for(symbolTable *child : st->childList) {
        printSymbolTable(child);
    }   
}

int mergeConstVolatile(node* temp, node* from) {
    if(!temp->declSp) {
        temp->declSp = new declSpec();
    }
    if(from->declSp) {
        temp->declSp->isConst = temp->declSp->isConst || from->declSp->isConst;
        temp->declSp->isVolatile = temp->declSp->isVolatile || from->declSp->isVolatile;
    }
    return 0;
}

int incrementPointerLevel(node* temp, node* from) {
    if (!temp->declSp){
        temp->declSp = new declSpec();
    } 
    if(from->declSp && from->declSp->ptrLevel){
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    }else{
        temp->declSp->ptrLevel = 0;
    }
    temp->declSp->ptrLevel++;
    return 0;
}