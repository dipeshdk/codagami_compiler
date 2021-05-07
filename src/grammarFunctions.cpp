#include "headers/allInclude.h"

extern int rbp_size;
extern int offset;

structTableNode* getRightMostStructFromPostfixExpression(node* postfix_expression, bool isPtrOp, int& errCode, string& errString) {
    structTableNode* structure = nullptr;
    node* curr = postfix_expression;
    while (curr != NULL) {
        string s = curr->name;
        if (s == "IDENTIFIER")
            break;
        else {
            curr = curr->childList;
            if (curr)
                curr = curr->next;
        }
    }

    if (curr == NULL) {
        setErrorParams(errCode, VARIABLE_NOT_A_STRUCT, errString, "");
        return nullptr;
    }

    string rightMostStructName;
    if (curr->infoType == INFO_NESTED_STRUCT) {
        // declSp allocated so look in structure table
        if (curr->declSp) {
            if (isPtrOp && curr->declSp->ptrLevel != 1) {
                setErrorParams(errCode, INVALID_REFERENCE, errString, curr->lexeme);
                return nullptr;
            }
            rightMostStructName = curr->declSp->lexeme;
            structure = structLookUp(gSymTable, rightMostStructName);
        }
    } else {
        // look in symbol table
        symbolTableNode* n = lookUp(gSymTable, curr->lexeme);
        int isStruct = 0;
        if (n->declSp) {
            for (int t : n->declSp->type) {
                if (t == TYPE_STRUCT) {
                    isStruct = 1;
                    break;
                }
            }
            if (isStruct) {
                if (isPtrOp && n->declSp->ptrLevel != 1) {
                    setErrorParams(errCode, INVALID_REFERENCE, errString, n->name);
                    return nullptr;
                }
                rightMostStructName = n->declSp->lexeme;
                structure = structLookUp(gSymTable, rightMostStructName);
            }
        }
    }
    if (!structure)
        setErrorParams(errCode, VARIABLE_NOT_A_STRUCT, errString, rightMostStructName);
    return structure;
}

node* primary_expression_identifier(char* lexeme, int& errCode, string& errStr) {
    symbolTableNode* stNode = lookUp(gSymTable, lexeme);
    if (!stNode) {
        errCode = UNDECLARED_SYMBOL;
        errStr = lexeme;
        return nullptr;
    }
    node* temp = makeNode(strdup("IDENTIFIER"), strdup(lexeme), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
    temp->declSp = new declSpec();
    for (auto i : stNode->declSp->type) {
        temp->declSp->type.push_back(i);
    }
    for (auto i : stNode->declSp->storageClassSpecifier)
        temp->declSp->storageClassSpecifier.push_back(i);

    temp->declSp->ptrLevel = stNode->declSp->ptrLevel;
    temp->declSp->lexeme = stNode->declSp->lexeme;
    temp->declSp->isConst = stNode->declSp->isConst;
    temp->declSp->isVolatile = stNode->declSp->isVolatile;
    return temp;
}

node* struct_or_union_specifier(node* struct_or_union, string name) {
    int type = TYPE_STRUCT;
    node* temp = makeTypeNode(type);
    if (!temp->declSp)
        temp->declSp = new declSpec();
    temp->declSp->lexeme = name;
    temp->infoType = struct_or_union->infoType;
    temp->lineNo = line + 1;
    return temp;
}

node* struct_declaration(node* specifier_qualifier_list, node* struct_declarator_list) {
    node* curr = struct_declarator_list;
    while (curr) {
        node* temp = curr;
        string s(curr->name);
        if (s == "=") {
            temp = curr->childList;
        }
        if (!temp)
            continue;
        for (auto& u : temp->structParamList) {
            int ptrLevel = 0;
            if (u->declSp)
                ptrLevel = u->declSp->ptrLevel;
            u->declSp = specifier_qualifier_list->declSp;
            u->declSp->ptrLevel = ptrLevel;
            specifier_qualifier_list->structParamList.push_back(u);
        }
        curr = curr->next;
    }
    return specifier_qualifier_list;
}

node* declaration_list(node* declaration_list, node* declaration) {
    node* temp = NULL;
    string s(declaration_list->name);
    bool c1 = (s == "DECL_LIST");
    if (c1) {
        temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, declaration_list->childList, declaration, (node*)NULL, (node*)NULL);
    } else {
        temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, declaration_list, declaration, (node*)NULL, (node*)NULL);
    }
    for (auto& u : declaration->paramList) {
        temp->paramList.push_back(u);
    }
    for (auto& u : declaration_list->paramList) {
        temp->paramList.push_back(u);
    }
    return temp;
}

node* parameter_declaration(node* declaration_specifiers, node* declarator) {
    param* parameter = new param();
    if (!parameter->declSp) {
        parameter->declSp = new declSpec();
    }
    if (declaration_specifiers->declSp) {
        parameter->declSp = declSpCopy(declaration_specifiers->declSp);
    }
    if (declarator->declSp) {
        parameter->declSp->ptrLevel = declarator->declSp->ptrLevel;
    }
    vector<int> arrayIndicesTmp;
    for (auto& x : declarator->arrayIndices) {
        int asizeTmp = getValueFromConstantExpression(x, errCode);
        if (asizeTmp < 0 || errCode) {
            error(x->lexeme, ARRAY_SIZE_NOT_CONSTANT);
        }
        arrayIndicesTmp.push_back(asizeTmp);
    }
    parameter->arraySize = declarator->arraySize;
    parameter->arrayIndices = arrayIndicesTmp;
    parameter->infoType = declarator->infoType;
    parameter->paramName = declarator->lexeme;
    declarator->paramList.push_back(parameter);
    return declarator;
}

string checkFuncArgValidityWithParamEmit(node* postfix_expression, node* argument_expression_list, int& errCode, string& errString) {
    string func_name = postfix_expression->lexeme;
    string name = postfix_expression->lexeme;
    symbolTableNode* stNode = lookUp(gSymTable, name);

    if (!stNode || stNode->infoType != INFO_TYPE_FUNC || !stNode->declSp) {
        setErrorParams(errCode, SYMBOL_NOT_FOUND, errString, name);
        return EMPTY_STR;
    }

    // if(!stNode->isDefined) {
    //     setErrorParams(errCode, UNDEFINED_FUNCTION, errString, name);
    //     return;
    // }

    vector<struct param*> paramList = stNode->paramList;
    int maxSize = paramList.size();
    int idx = 0;
    node* curr = argument_expression_list;
    int paramSize = 0;
    string newTemp = EMPTY_STR;
    vector<node*> arguments;
    while (curr) {
        node* temp = curr;
        string s = curr->name;
        if (s == "=")
            temp = curr->childList;
        if (!temp)
            continue;
        if (idx >= maxSize) {
            setErrorParams(errCode, INVALID_ARGS_IN_FUNC_CALL, errString, temp->lexeme);
            return EMPTY_STR;
        }
        if (!temp->declSp || !paramList[idx]->declSp) {
            setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errString, temp->lexeme);
            return EMPTY_STR;
        }
        int retval = canTypecast(temp->declSp, paramList[idx]->declSp);
        if (retval) {
            setErrorParams(errCode, INVALID_ARGS_IN_FUNC_CALL, errString, temp->lexeme);
            return EMPTY_STR;
        }
        //if valid but different types then typcast temp to paramList[idx]'s type
        if (requiresTypeCasting(temp->declSp, paramList[idx]->declSp)) {
            retval = canTypecast(paramList[idx]->declSp, temp->declSp);
            if (retval) {
                setErrorParams(errCode, retval, errString, temp->lexeme);
                return EMPTY_STR;
            }
            typeCastLexemeWithEmit(temp, paramList[idx]->declSp);
        }
        temp->infoType = paramList[idx]->infoType;
        arguments.push_back(temp);
        // emit(OP_PUSHPARAM, BLANK_STR, BLANK_STR, temp->addr);
        // paramSize+= getTypeSize(temp->declSp->type);
        idx++;
        curr = curr->next;
    }
    if (idx != paramList.size()) {
        setErrorParams(errCode, INVALID_ARGS_IN_FUNC_CALL, errString, func_name);
        return EMPTY_STR;
    }
    if (!postfix_expression->declSp) {
        error(postfix_expression->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
    }

    // Doing this in LCall
    // Assuming no required value in regs
    for (int i = 0; i < min(6, maxSize); i++) {
        //mov to reg
        emit(OP_MOV, gArgRegs[i], EMPTY_STR, arguments[i]->addr);
    }

    for (int i = maxSize - 1; i >= 6; i--) {
        //push param
        emit(OP_PUSHPARAM, EMPTY_STR, EMPTY_STR, arguments[i]->addr);
        paramSize += getTypeSize(arguments[i]->declSp->type);
    }

    if (postfix_expression->declSp->type[0] != TYPE_VOID) {
        newTemp = generateTemp(errCode);
        if (errCode)
            error("Internal Error: Cannot generate Temp", DEFAULT_ERROR);
        emit(OP_LCALL, func_name, BLANK_STR, newTemp);
        addTempDetails(newTemp, gSymTable, postfix_expression);
    } else {
        emit(OP_LCALL, func_name, EMPTY_STR, EMPTY_STR);
    }

    paramSize = stNode->paramWidth;
    if (paramSize)
        emit(OP_POPPARAM, EMPTY_STR, EMPTY_STR, to_string(paramSize));
    stNode->callPopSize = paramSize;
    return newTemp;
}

void setOverSixParamOffset(node* declarator, symbolTable* curr, symbolTableNode* funcNode) {
    int tempOffset = rbp_size;
    int param_num = 0;
    int extra = 0;
    if (funcNode->declSp && (funcNode->declSp->type[0] == TYPE_STRUCT)) {
        string structName = funcNode->declSp->lexeme;
        // structTableNode* struc = structLookUp(gSymTable, structName);
        symbolTableNode* tempNode = new symbolTableNode();
        tempNode->declSp->type.push_back(TYPE_STRUCT);
        tempNode->declSp->lexeme = structName;
        extra = getNodeSize(tempNode, gSymTable) + 8;
        tempOffset += extra;
    }
    for (auto& p : declarator->paramList) {
        param_num++;
        int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
        if (retVal) {
            error(p->paramName, retVal);
        }
        string lex = p->paramName;

        struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
        if (!sym_node) {
            error(lex, ALLOCATION_ERROR);
        }
        if (p->declSp->type[0] == TYPE_STRUCT) {
            sym_node->infoType = INFO_TYPE_STRUCT;
        }
        sym_node->arraySize = p->arraySize;
        sym_node->arrayIndices = p->arrayIndices;
        sym_node->declSp = declSpCopy(p->declSp);
        sym_node->infoType = p->infoType;
        sym_node->size = getNodeSize(sym_node, gSymTable);
        if (param_num > 6) {
            tempOffset += getOffsettedSize(sym_node->size);
            sym_node->offset = (-1 * tempOffset);
        }
    }

    funcNode->paramWidth = tempOffset - rbp_size; // -extra??

    return;
}

void setFirstSixParamOffset(node* declarator, symbolTable* gSymTable) {
    offset += 8;
    int param_num = 0;
    symbolTable* curr = gSymTable->childList[(gSymTable->childList.size()) - 1];

    for (auto& p : declarator->paramList) {
        param_num++;
        if (param_num > 6)
            break;
        string lex = p->paramName;
        struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
        if (!sym_node) {
            error(lex, ALLOCATION_ERROR);
        }
        sym_node->offset = offset;
        offset += getOffsettedSize(sym_node->size);
    }
    return;
}

bool checkGlobalInitializerDFSUtil(node* a) {
    if (!a)
        return true;
    if (a->isLeaf) {
        return a->isConstant;
    }

    node* temp = a->childList;
    while (temp) {
        if (!checkGlobalInitializerDFSUtil(temp))
            return false;
        temp = temp->next;
    }

    return true;
}

bool checkGlobalInitializer(node* initializer) {
    //performs dfs and checks if any leaf node is not constant
    return checkGlobalInitializerDFSUtil(initializer);
}

int addArrayParamToStack(int& offset, string addr, int& errCode, string& errString) {
    string newTmp = generateTemp(errCode);
    if (errCode) {
        setErrorParams(errCode, errCode, errString, "");
        return -1;
    }
    symbolTableNode* sym_node;
    sym_node = lookUp(gSymTable, newTmp);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp = new declSpec();
    sym_node->declSp->type.push_back(TYPE_VOID);
    sym_node->declSp->ptrLevel++;
    offset += 8;

    emit(OP_ADDR, addr, EMPTY_STR, newTmp);
    string newTmp1 = generateTemp(errCode);
    if (errCode) {
        setErrorParams(errCode, errCode, errString, "");
        return -1;
    }

    sym_node = lookUp(gSymTable, newTmp1);
    sym_node->size = 8;
    sym_node->offset = offset;
    sym_node->declSp = new declSpec();
    sym_node->declSp->type.push_back(TYPE_VOID);
    sym_node->declSp->ptrLevel++;
    offset += 8;

    emit(OP_SUBI, newTmp, "8", newTmp1);
    emit(OP_ASSIGNMENT, newTmp1, EMPTY_STR, addr);
    return 0;
}