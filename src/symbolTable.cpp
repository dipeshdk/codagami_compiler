#include<bits/stdc++.h>
#include "symbolTable.h"
using namespace std;

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


