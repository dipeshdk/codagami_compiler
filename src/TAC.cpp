#include "headers/allInclude.h" 

vector<int> makelist(int i){
    return vector<int>{i};
}

vector<int> makelist(){
    return vector<int>(0);
}

vector<int> mergelist(vector<int> &list1,vector<int> &list2){
    list1.insert(list1.begin(), list2.begin(), list2.end());
    return list1;
}

int backpatch(vector<int> &list, int i){
    int sizeOfList = gCode.size();
    for(int index : list){
        if(index > sizeOfList || 
            ((gCode[index]->opCode != OP_GOTO) && 
            gCode[index]->opCode != OP_IFGOTO))
            return NOT_GOTO_IN_BACKPATCH;
        gCode[index]->arg1 = to_string(i);
    }
    return 0;
}

void emit(int opCode, string arg1, string arg2, string result){
    quadruple* quad = new quadruple();
    quad->opCode = opCode;
    quad->arg1 = arg1;
    quad->arg2 = arg2;
    quad->result = result;
    gCode.push_back(quad);
}

int nextQuad(){
    return gCode.size();
}

string generateTemp(int &errCode){
    errCode = 0;
    temp_num++;
    string name = to_string(temp_num)+"t";
    int retval = insertSymbol(gTempSymbolMap, TEMP_LINE_NO, name);
    if(retval)
        errCode = retval; 
    return name;
}

void setAddr(node* n, string addr) {
	n->addr = addr;
}

int getOpMulType(node* temp, int &errCode, string &errStr){
    if(!temp || !temp->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if(checkValidType(temp->declSp->type)){
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if(type == TYPE_INT || type == TYPE_CHAR)
        return OP_MULI;
    if(type == TYPE_FLOAT)
        return OP_MULF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpAddType(node* temp, int &errCode, string &errStr){
    if(!temp || !temp->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if(checkValidType(temp->declSp->type)){
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if(type == TYPE_INT || type == TYPE_CHAR)
        return OP_ADDI;
    if(type == TYPE_FLOAT)
        return OP_ADDF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpDivType(node* temp, int &errCode, string &errStr){
    if(!temp || !temp->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if(checkValidType(temp->declSp->type)){
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if(type == TYPE_INT || type == TYPE_CHAR)
        return OP_DIVI;
    if(type == TYPE_FLOAT)
        return OP_DIVF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpSubType(node* temp, int &errCode, string &errStr){
    if(!temp || !temp->declSp) {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if(checkValidType(temp->declSp->type)){
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if(type == TYPE_INT || type == TYPE_CHAR)
        return OP_SUBI;
    if(type == TYPE_FLOAT)
        return OP_SUBF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

void emitRelop(node* n1, node* n2, node* temp, int opCode, int& errCode, string &errStr){
    temp->truelist = makelist(nextQuad());
    temp->falselist = makelist(nextQuad() + 1);
    string newTmp = generateTemp(errCode);
    if(errCode){
        setErrorParams(errCode, errCode, errStr, temp->name);
        return;
    }
    temp->addr = newTmp;
    emit(opCode, n1->addr, n2->addr, temp->addr);
    emit(OP_IFGOTO, temp->addr, EMPTY_STR, BLANK_STR);
    emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
}