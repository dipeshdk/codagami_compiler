#include "headers/allInclude.h" 

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
    if (!temp->declSp)
        temp->declSp = new declSpec();
    if(from && from->declSp && from->declSp->ptrLevel)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    temp->declSp->ptrLevel++;
    return 0;
}

int copyPtrLevel(node* temp, node* from) {
    if(!temp->declSp) 
        temp->declSp = new declSpec();
    if(from->declSp)
        temp->declSp->ptrLevel = from->declSp->ptrLevel;
    return 0;
}

// TODO: might be buggy (input type char)
int getValueFromConstantExpression(node* constant_expression, int &err) {
    err=0;
    int val = 0;
    if(!constant_expression) {
        err = INVALID_ARGS;
        return val;
    }
    switch(constant_expression->valType){
        case TYPE_INT: 
            val = constant_expression->ival;
            break;
        case TYPE_FLOAT:
            err = TYPE_ERROR;
            break;
        default:
            break; 
    }
    return val;
}



void setErrorParams(int &errCode, int code, string &errString, string str) {
    errCode=code;
    errString=str;
    return;
}