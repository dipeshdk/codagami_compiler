#include "headers/allInclude.h"

extern int offset;

vector<int> makelist(int i)
{
    return vector<int>{i};
}

vector<int> makelist()
{
    return vector<int>(0);
}

vector<int> mergelist(vector<int> &list1, vector<int> &list2)
{
    list1.insert(list1.begin(), list2.begin(), list2.end());
    return list1;
}

int backpatch(vector<int> &list, int i)
{
    int sizeOfList = gCode.size();
    for (int index : list)
    {
        if (index > sizeOfList ||
            ((gCode[index]->opCode != OP_GOTO) &&
             (gCode[index]->opCode != OP_IFGOTO) && (gCode[index]->opCode != OP_IFNEQGOTO)))
            return NOT_GOTO_IN_BACKPATCH;
        gCode[index]->result = to_string(i);
    }
    return 0;
}

int backpatchAssignment(vector<int> &list, string operand)
{
    int sizeOfList = gCode.size();
    for (int index : list)
    {
        if (index > sizeOfList ||
            (gCode[index]->arg1 != BLANK_STR))
            return NOT_GOTO_IN_BACKPATCH;
        gCode[index]->arg1 = operand;
    }
    return 0;
}

int backpatchBeginFunc(int funcBeginQuad, int offset)
{
    if (funcBeginQuad < 0 || funcBeginQuad > gCode.size() ||
        (gCode[funcBeginQuad]->result != BLANK_STR))
        return NOT_GOTO_IN_BACKPATCH;
    gCode[funcBeginQuad]->result = to_string(offset);
    return 0;
}

void emit(int opCode, string arg1, string arg2, string result)
{
    quadruple *quad = new quadruple();
    quad->opCode = opCode;
    quad->arg1 = arg1;
    quad->arg2 = arg2;
    quad->result = result;
    gCode.push_back(quad);
    codeSTVec.push_back(gSymTable);
}

int nextQuad()
{
    return gCode.size();
}

string generateTemp(int &errCode)
{
    errCode = 0;
    temp_num++;
    string name = to_string(temp_num) + "t";
    int retval = insertSymbol(gSymTable, TEMP_LINE_NO, name);
    // int retval = insertSymbol(gTempSymbolMap, TEMP_LINE_NO, name);
    if (retval)
        errCode = retval;
    return name;
}

void setAddr(node *n, string addr)
{
    n->addr = addr;
}

int getOpMulType(node *temp, int &errCode, string &errStr)
{
    if (!temp || !temp->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkValidType(temp->declSp->type))
    {
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if (type == TYPE_INT || type == TYPE_CHAR)
        return OP_MULI;
    if (type == TYPE_FLOAT)
        return OP_MULF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpAddType(node *temp, int &errCode, string &errStr)
{
    if (!temp || !temp->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkValidType(temp->declSp->type))
    {
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if (type == TYPE_INT || type == TYPE_CHAR)
        return OP_ADDI;
    if (type == TYPE_FLOAT)
        return OP_ADDF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpDivType(node *temp, int &errCode, string &errStr)
{
    if (!temp || !temp->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkValidType(temp->declSp->type))
    {
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if (type == TYPE_INT || type == TYPE_CHAR)
        return OP_DIVI;
    if (type == TYPE_FLOAT)
        return OP_DIVF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

int getOpSubType(node *temp, int &errCode, string &errStr)
{
    if (!temp || !temp->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, temp->lexeme);
        return -INTERNAL_ERROR_DECL_SP_NOT_DEFINED;
    }
    if (checkValidType(temp->declSp->type))
    {
        setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
        return -TYPE_ERROR;
    }

    int type = temp->declSp->type[0];
    if (type == TYPE_INT || type == TYPE_CHAR)
        return OP_SUBI;
    if (type == TYPE_FLOAT)
        return OP_SUBF;
    setErrorParams(errCode, TYPE_ERROR, errStr, temp->lexeme);
    return -TYPE_ERROR;
}

void emitRelop(node *n1, node *n2, node *temp, int opCode, int &errCode, string &errStr)
{
    temp->truelist = makelist(nextQuad() + 1);
    temp->falselist = makelist(nextQuad() + 2);
    string newTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, temp->name);
        return;
    }
    symbolTableNode *tempNode = lookUp(gSymTable, newTmp);
    tempNode->declSp = new declSpec();
    tempNode->declSp->type.push_back(TYPE_INT);
    temp->addr = newTmp;
    temp->declSp = declSpCopy(tempNode->declSp);
    emit(opCode, n1->addr, n2->addr, temp->addr);
    emit(OP_IFGOTO, temp->addr, EMPTY_STR, BLANK_STR);
    emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
    symbolTableNode *sym_node = lookUp(gSymTable, newTmp);
    sym_node->size = 8;
    sym_node->offset = offset;
    offset += 8;
    return;
}

string emitTypeCast(node *node, declSpec *toDs, int &errCode, string &errStr)
{
    string newTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "new temp not generated");
        return BLANK_STR;
    }
    symbolTableNode *tempNode = lookUp(gSymTable, newTmp);
    tempNode->declSp = declSpCopy(toDs);
    if (!node->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, node->lexeme);
        return BLANK_STR;
    }
    string from_type = getTypeName(node->declSp->type[0]);
    if (node->declSp->ptrLevel > 0)
        from_type += "*";
    string to_type = getTypeName(toDs->type[0]);
    if (toDs->ptrLevel > 0)
        to_type += "*";
    string typeCastAddr = "( " + from_type + "_TO_" + to_type + " ) " + node->addr;
    emit(OP_ASSIGNMENT, typeCastAddr, EMPTY_STR, newTmp);
    tempNode->size = getNodeSize(tempNode, gSymTable);
    tempNode->offset = offset;
    offset += tempNode->size;
    return newTmp;
}

void emitOperationAssignment(node *unary_expression, node *assignment_expression, int opCode, string resultAddr, int &errCode, string &errStr)
{

    string newTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "Cannot generate Temp");
        return;
    }
    symbolTableNode *tempNode = lookUp(gSymTable, newTmp);
    int rank = giveTypeCastRank(unary_expression, assignment_expression);
    if (rank < 0)
    {
        setErrorParams(errCode, -rank, errStr, "get Rank error");
        return;
    }
    if (rank == 2)
    {
        tempNode->declSp = declSpCopy(assignment_expression->declSp);
    }
    else
    {
        tempNode->declSp = declSpCopy(unary_expression->declSp);
    }

    emit(opCode, unary_expression->addr, assignment_expression->addr, newTmp);
    emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, resultAddr);
    tempNode->size = getNodeSize(tempNode, gSymTable);
    tempNode->offset = offset;
    offset += tempNode->size;
}

int getOpcodeFromAssignStr(string s)
{
    if (s == "AND_ASSIGN")
        return OP_AND;
    else if (s == "OR_ASSIGN")
        return OP_OR;
    else if (s == "XOR_ASSIGN")
        return OP_XOR;
    else if (s == "LEFT_ASSIGN")
        return OP_LEFT_SHIFT;
    else if (s == "RIGHT_ASSIGN")
        return OP_RIGHT_SHIFT;
    else if (s == "MOD_ASSIGN")
        return OP_MOD;
    return -INVALID_ARGS;
}

string emitArrayIndexGetAddr(string arr, string ind, string sizeTemp, int &errCode, string &errStr)
{
    string indexTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    emit(OP_MULI, sizeTemp, ind, indexTmp);
    symbolTableNode *sym_node = lookUp(gSymTable, indexTmp);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp->type.push_back(TYPE_INT);
    offset += 8;

    string pointerTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }

    emit(OP_ADDI, arr, indexTmp, pointerTmp);
    sym_node = lookUp(gSymTable, pointerTmp);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp->ptrLevel = 1;
    sym_node->declSp->type.push_back(TYPE_INT);
    offset += 8;

    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    string pointerAddr = "*(" + pointerTmp + ")";
    return pointerAddr;
}

string getIndexStr(node *root, int &errCode, string &errStr)
{
    if (!root)
    {
        setErrorParams(errCode, INVALID_ARGS, errStr, "");
        return EMPTY_STR;
    }
    int countRoot = root->arrayIndices.size();
    symbolTableNode *symNode = lookUp(gSymTable, root->lexeme);
    if (!symNode)
    {
        setErrorParams(errCode, SYMBOL_NOT_FOUND, errStr, root->lexeme);
        return EMPTY_STR;
    }
    int countSymNode = symNode->arrayIndices.size();
    if (countSymNode != countRoot)
    {
        cout << "countSymNode : " << countSymNode << " countRoot : " << countRoot << endl;
        setErrorParams(errCode, INVALID_REFERENCE, errStr, root->lexeme);
        return EMPTY_STR;
    }
    string prev = generateTemp(errCode);
    addIntTemp(prev, gSymTable);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    emit(OP_ASSIGNMENT, root->arrayIndices[0]->addr, EMPTY_STR, prev);
    string newTmp;

    for (int i = 0; i < countRoot - 1; i++)
    {
        // 1tn+1 = tn muli sai[i+1]
        // 2tn+1 = 1tn+1 addi rai[i+1];
        // var = RAi[i] * SAi[i+1] + RAi[i+1];
        newTmp = generateTemp(errCode);
        addIntTemp(newTmp, gSymTable);
        if (errCode)
        {
            setErrorParams(errCode, errCode, errStr, "error in temp generation");
            return EMPTY_STR;
        }
        emit(OP_MULI, prev, to_string(symNode->arrayIndices[i + 1]), newTmp);
        prev = newTmp;
        newTmp = generateTemp(errCode);
        addIntTemp(newTmp, gSymTable);
        if (errCode)
        {
            setErrorParams(errCode, errCode, errStr, "error in temp generation");
            return EMPTY_STR;
        }
        emit(OP_ADDI, prev, root->arrayIndices[i + 1]->addr, newTmp);
        prev = newTmp;
    }
    return prev;
}

void addIntTemp(string name, symbolTable *st)
{
    symbolTableNode *sym_node = lookUp(st, name);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp->type.push_back(TYPE_INT);
    offset += 8;
}

string getArrayIndexWithEmit(node *postfix_expression, int &errCode, string &errStr)
{
    errCode = 0;
    for (auto &x : postfix_expression->arrayIndices)
    {
        if (x->declSp)
        {
            checkTypeArrayWithTypecast(x, errCode, errStr);
            if (errCode)
            {
                setErrorParams(errCode, errCode, errStr, errStr);
                return EMPTY_STR;
            }
        }
        else
        {
            setErrorParams(errCode, ARRAY_INDEX_SHOULD_BE_INT, errStr, x->lexeme);
            return EMPTY_STR;
        }
    }
    string expAddr = getIndexStr(postfix_expression, errCode, errStr);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, errStr);
        return EMPTY_STR;
    }
    if (!postfix_expression->declSp)
    {
        setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errStr, "postfix_expression declSp not allocated for array");
        return EMPTY_STR;
    }
    int size = getTypeSize(postfix_expression->declSp->type);
    if (size < 0)
    {
        setErrorParams(errCode, -size, errStr, "invalid array type");
        return EMPTY_STR;
    }
    string sizeTmp = generateTemp(errCode);
    if (errCode)
    {
        setErrorParams(errCode, errCode, errStr, "error in temp generation");
        return EMPTY_STR;
    }
    emit(OP_ASSIGNMENT, to_string(size), EMPTY_STR, sizeTmp);
    symbolTableNode *sym_node = lookUp(gSymTable, sizeTmp);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp->type.push_back(TYPE_INT);
    offset += 8;
    return emitArrayIndexGetAddr(postfix_expression->addr, expAddr, sizeTmp, errCode, errStr);
}

int getParamOffset(structTableNode *node, string paramName, int &err, string &errStr)
{
    setErrorParams(err, 0, errStr, "structHasParam");
    if (!node || !paramName.size())
    {
        err = INVALID_ARGS;
        return -err;
    }
    int size = 0;
    int paramOffset = 0;
    for (structParam *p : node->paramList)
        size += getTypeSize(p->declSp->type);
    for (structParam *p : node->paramList)
    {
        int size1 = getTypeSize(p->declSp->type);
        paramOffset += getOffsettedSize(size1); // doubt : considering offset inside struct?
        if (p->name == paramName)
            return size - paramOffset;
    }
    setErrorParams(err, INVALID_STRUCT_PARAM, errStr, paramName);
    return -err;
}

int getStructSizeFromAstNode(node *astNode) {
    string varName = astNode->addr;
    symbolTableNode* stNode = lookUp(gSymTable, varName);
    if(!stNode)
        error(varName, SYMBOL_NOT_FOUND);
    if(stNode->infoType != INFO_TYPE_STRUCT)
        error(varName, TYPE_ERROR);

    structTableNode* structNode = nullptr;
    structNode = structLookUp(gSymTable, stNode->declSp->lexeme);
    if(!structNode)
        error(stNode->declSp->lexeme, STRUCT_NOT_DECLARED);
    return getStructSize(structNode);
}

int getStructSize(structTableNode* node){
    if(!node) {
        return -INVALID_ARGS;
    }
    int size = 0;
    for(structParam* p : node->paramList) 
        size +=  getTypeSize(p->declSp->type);

    return size;
}