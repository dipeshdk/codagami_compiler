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
            (gCode[index]->opCode != OP_IFGOTO) && (gCode[index]->opCode != OP_IFNEQGOTO)))
            return NOT_GOTO_IN_BACKPATCH;
        gCode[index]->result = to_string(i);
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
    int retval = insertSymbol(gSymTable, TEMP_LINE_NO, name);
    // int retval = insertSymbol(gTempSymbolMap, TEMP_LINE_NO, name);
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
    temp->truelist = makelist(nextQuad() + 1);
    temp->falselist = makelist(nextQuad() + 2);
    string newTmp = generateTemp(errCode);
    if(errCode){
        setErrorParams(errCode, errCode, errStr, temp->name);
        return;
    }
    symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
    tempNode->declSp = new declSpec();
    tempNode->declSp->type.push_back(TYPE_INT);
    temp->addr = newTmp;
    temp->declSp = declSpCopy(tempNode->declSp);
    emit(opCode, n1->addr, n2->addr, temp->addr);
    emit(OP_IFGOTO, temp->addr, EMPTY_STR, BLANK_STR);
    emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
}


string emitTypeCast(node* node, declSpec *toDs, int &errCode, string &errStr) {
    string newTmp = generateTemp(errCode);
    if(errCode){
        setErrorParams(errCode, errCode, errStr, "new temp not generated");
        return BLANK_STR;
    }
    // symbolTableNode* tempNode= lookUp(gTempSymbolMap, newTmp);
    symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
    tempNode->declSp = declSpCopy(toDs);
    if(!node->declSp){
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, node->lexeme);
        return BLANK_STR;
    }
    string typeCastAddr = "( " +getTypeName(node->declSp->type[0]) + "_TO_" + getTypeName(toDs->type[0]) + " ) " + node->addr; 
    emit(OP_ASSIGNMENT, typeCastAddr , EMPTY_STR, newTmp);
    return newTmp;
}

void emitOperationAssignment(node* unary_expression, node* assignment_expression, int opCode, string resultAddr, int &errCode, string &errStr) {
    string newTmp = generateTemp(errCode);
    if(errCode){
        setErrorParams(errCode, errCode, errStr, "Cannot generate Temp");
        return;
    }
    symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
    // symbolTableNode* tempNode= lookUp(gTempSymbolMap, newTmp);
    int rank = giveTypeCastRank(unary_expression, assignment_expression);
    if(rank < 0) {
        setErrorParams(errCode, -rank, errStr, "get Rank error");
        return;
    }
    if(rank == 2) {
        tempNode->declSp = declSpCopy(assignment_expression->declSp);
    }else {
        tempNode->declSp = declSpCopy(unary_expression->declSp);
    }

    emit(opCode, unary_expression->addr, assignment_expression->addr, newTmp);
    emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, resultAddr);
}  

int getOpcodeFromAssignStr(string s){
    if (s == "AND_ASSIGN") return OP_AND;
    else if(s == "OR_ASSIGN") return OP_OR;
    else if(s == "XOR_ASSIGN") return OP_XOR;
    else if(s == "LEFT_ASSIGN") return OP_LEFT_SHIFT;
    else if(s == "RIGHT_ASSIGN") return OP_RIGHT_SHIFT;
    else if(s == "MOD_ASSIGN") return OP_MOD;
    return -INVALID_ARGS;
}

string emitArrayIndexGetAddr(string arr, string ind, string sizeTemp, int &errCode, string &errStr) {
    //_t2 = _t1 * n;
    string indexTmp = generateTemp(errCode);
    if(errCode) {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    emit(OP_MULI, sizeTemp, ind, indexTmp);

    //_t3 = arr + _t2;
    string pointerTmp = generateTemp(errCode);
    if(errCode) {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    emit(OP_ADDI, arr, indexTmp, pointerTmp);

    if(errCode){
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    string pointerAddr = "*(" + pointerTmp + ")";
    return pointerAddr;
}

string getArrayIndexWithEmit(node *postfix_expression , node *expression, int &errCode, string &errStr){
    if(expression->declSp) 
		{
			checkTypeArrayWithTypecast(expression, errCode, errStr);
			if(errCode){
                setErrorParams(errCode, errCode, errStr, errStr);
                return EMPTY_STR;
            }
		}else{ 
			setErrorParams(errCode, ARRAY_INDEX_SHOULD_BE_INT, errStr, expression->lexeme);
            return EMPTY_STR;
		}

        if(!postfix_expression->declSp){
            setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, "postfix_expression declSp not allocated for array");
            return EMPTY_STR;
        }
        int size = getTypeSize(postfix_expression->declSp->type);
        if(size < 0){
            setErrorParams(errCode, -size, errStr, "invalid array type");
            return EMPTY_STR;
        }
        //_t1 = 4;
        string sizeTmp = generateTemp(errCode);
        if(errCode){
            setErrorParams(errCode, errCode, errStr, "error in temp generation");
            return EMPTY_STR;
        }
        emit(OP_ASSIGNMENT, to_string(size), EMPTY_STR ,sizeTmp);

        return emitArrayIndexGetAddr(postfix_expression->addr, expression->addr, sizeTmp, errCode, errStr);
}