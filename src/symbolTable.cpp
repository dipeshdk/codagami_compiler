#include "headers/allInclude.h" 

int temp_num = 0;
int gScope=0;
int id = 0;
symbolTable* gTempSymbolMap;
symbolTable* gSymTable;
set<int> validTypes = {TYPE_CHAR, TYPE_INT, TYPE_FLOAT, TYPE_VOID, TYPE_STRUCT, TYPE_STRING_LITERAL};
vector<struct quadruple*> gCode;
vector<symbolTable*> codeSTVec;
symbolTable* globalScopeSymTable;

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
    if(st->symbolTableMap.find(name) != st->symbolTableMap.end()) {
        return SYMBOL_ALREADY_EXISTS;
    }
    symbolTableNode* node = new symbolTableNode();
    if(!node) {
        return ALLOCATION_ERROR;
    }
    st->symbolOrder.push_back(name);
    node->name = name;
    node->lineNo = lineNo;
    node->scope = st->scope;
    st->symbolTableMap[name] = node;
    return 0;
}

void addIVal(node* temp, string s) {
    size_t p;
    temp->valType = TYPE_INT;
    temp->ival = (int)stod(s, &p);
}

void addFVal(node* temp, string s) {
    size_t p;
    temp->valType = TYPE_FLOAT;
    temp->fval = (float)stod(s, &p);
}

struct symbolTable* addChildSymbolTable(struct symbolTable *parent){
    symbolTable* node = new symbolTable();
    if(!node)
        return nullptr;
    node->scope = gScope++;
    node->parent = parent;
    parent->childList.push_back(node);
    return node;
}


int addTypeToDeclSpec(node *temp, vector<int>&v){
    if(!temp || !temp->declSp) {
        return INVALID_ARGS;
    }
    for(int i = 0; i < v.size() ; i++) {
        temp->declSp->type.push_back(v[i]);
    }
    return checkValidType(temp->declSp->type);
}

// int checkValidStorageClass(node *temp) {
//     if(temp->declSp->storageClassSpecifier.size() > 1
//         || (temp->infoType == INFO_TYPE_FUNC && temp->declSp->storageClassSpecifier.size() > 0 
//         && temp->declSp->storageClassSpecifier[0] != TYPE_EXTERN))
//         return INVALID_STORAGE_CLASS;
//     return 0;
// }

// int addStorageClassToDeclSpec(node *temp, vector<int>&v){
//     if(!temp || !temp->declSp) {
//         return INVALID_ARGS;
//     }
//     for(int i = v.size()-1; i >=0; i--) {
//         temp->declSp->storageClassSpecifier.push_back(v[i]);
//     }
//     return checkValidStorageClass(temp);
// }



int addFunctionSymbol(node* declaration_specifiers, node* declarator) {
    string name = declarator->lexeme;

    currFunc = name;
    int retVal = insertSymbol(gSymTable, declarator->lineNo, name);
    if(retVal == SYMBOL_ALREADY_EXISTS) {
        struct symbolTableNode* funcNode = lookUp(gSymTable, name);
        if(funcNode->infoType != INFO_TYPE_FUNC)
            error("Symbol "+name+" not a function", DEFAULT_ERROR);      
        if(funcNode->isDefined)
            error("Function "+name+" already definded", DEFAULT_ERROR);      
        //check function type
        if(declaration_specifiers) {
            if(!declaration_specifiers->declSp || !funcNode->declSp || funcNode->declSp->type.size() != 1)
                error(declaration_specifiers->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
            //check return type of function
            // if(
                // !checkType(declaration_specifiers->declSp, funcNode->declSp->type[0], funcNode->declSp->ptrLevel)
                // (funcNode->declSp->type[0] == TYPE_STRUCT && funcNode->declSp->lexeme != declaration_specifiers->declSp->lexeme)) 
                // error(name, MISMATCH_DEFINITION_DECLARATION);
        }
        //check paramlist
        if(declarator->paramList.size() != funcNode->paramList.size()) 
            error("different number of parameters in function " + name, MISMATCH_DEFINITION_DECLARATION);
        for(int i = 0; i < funcNode->paramList.size(); i++) {
            if(funcNode->paramList[i]->declSp->type != declarator->paramList[i]->declSp->type
            || funcNode->paramList[i]->declSp->ptrLevel != declarator->paramList[i]->declSp->ptrLevel
            || (funcNode->paramList[i]->declSp->type[0] == TYPE_STRUCT 
                 && funcNode->paramList[i]->declSp->lexeme != declarator->paramList[i]->declSp->lexeme))
               error("different parameter types in function " + name, MISMATCH_DEFINITION_DECLARATION);
            funcNode->paramList[i]->paramName = declarator->paramList[i]->paramName;
        }

        funcNode->isDefined=true;
        return 0;
    }else if(retVal) {
        //error checks
        error(name, retVal);
    }
    symbolTableNode* sym_node = gSymTable->symbolTableMap[name];
    if(!sym_node) return ALLOCATION_ERROR;
    sym_node->infoType = INFO_TYPE_FUNC;

    if(declaration_specifiers){
        sym_node->declSp = declSpCopy(declaration_specifiers->declSp);
    }
    else{
        declSpec* ds = new declSpec();
        ds->type.push_back(TYPE_INT); //default function types if no type specified
        sym_node->declSp = ds;
    }
    sym_node->paramList = declarator->paramList;
    sym_node->isDefined = true;

    sym_node->declSp->ptrLevel = declarator->declSp->ptrLevel;
    return 0;
}

declSpec* declSpCopy(declSpec* ds) {
    declSpec* newds = new declSpec();
    for(auto &a : ds->type) 
        newds->type.push_back(a);
    newds->ptrLevel = ds->ptrLevel;
    newds->lexeme = ds->lexeme;
    for(auto &a : ds->storageClassSpecifier) {
        newds->storageClassSpecifier.push_back(a);
    }
    newds->isConst = ds->isConst;
    newds->isVolatile = ds->isVolatile;
    return newds;
}

int removeSymbol(symbolTable* st, string name) {
    if(!st) 
        return INVALID_ARGS;
    auto it = st->symbolTableMap.find(name);
    if(it == st->symbolTableMap.end()) 
        return SYMBOL_NOT_FOUND;
    st->symbolTableMap.erase(it);
    return 0;
}
 

int checkVoidSymbol(symbolTableNode* root){
    if(!root -> declSp)
        return INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    if(checkType(root->declSp, TYPE_VOID, 0)) return 0;
    return TYPE_ERROR;

}

structTableNode* structLookUp(symbolTable* st, string name) {
    symbolTable* curr = st;
    while(curr) {
        if(curr->structMap.find(name) != curr->structMap.end()) {
            return curr->structMap[name];
        }
        curr = curr->parent;
    }
    return nullptr;
}

structParam* structureParamLookup(structTableNode* node, string paramName, int& err, string& errStr){
    //returns 0 if struct node has a param named paramName
    setErrorParams(err, 0, errStr, "structHasParam");
    if(!node || !paramName.size()) {
        err = INVALID_ARGS;
        return nullptr;
    }
    
    for(structParam* p : node->paramList) {
        if(p->name == paramName) 
            return p;
    }
    setErrorParams(err, INVALID_STRUCT_PARAM, errStr, paramName);
    return nullptr;
}

