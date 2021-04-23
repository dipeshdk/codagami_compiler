#include "headers/allInclude.h" 

structTableNode* getRightMostStructFromPostfixExpression(node* postfix_expression, bool isPtrOp, int &errCode, string
 &errString) {
    structTableNode* structure = nullptr;
    node* curr = postfix_expression;
    while(curr != NULL){
        string s = curr->name;
        if(s == "IDENTIFIER") break;
        else{
            curr = curr->childList;
            if(curr) curr = curr->next;
        }
    }

    if(curr == NULL) {
        setErrorParams(errCode, VARIABLE_NOT_A_STRUCT, errString, "");
        return nullptr;
    }
    
    string rightMostStructName;	
    if(curr->infoType == INFO_NESTED_STRUCT){
        // declSp allocated so look in structure table
        if(curr->declSp) {
            if(isPtrOp && curr->declSp->ptrLevel != 1){	
                setErrorParams(errCode, INVALID_REFERENCE, errString, curr->lexeme);
                return nullptr;
            }
            rightMostStructName = curr->declSp->lexeme;
            structure = structLookUp(gSymTable, rightMostStructName);
        }
    }
    else{
        // look in symbol table
        symbolTableNode* n = lookUp(gSymTable, curr->lexeme);
        int isStruct = 0;
        if(n->declSp) {
            for(int t : n->declSp->type) {
                if(t == TYPE_STRUCT) {
                    isStruct=1;
                    break;
                }
            }
            if(isStruct) {
                if(isPtrOp && n->declSp->ptrLevel != 1){	
                    setErrorParams(errCode, INVALID_REFERENCE, errString, n->name);
                    return nullptr;
                }
                rightMostStructName = n->declSp->lexeme;
                structure = structLookUp(gSymTable, rightMostStructName);
            }
        }
    }
    if(!structure) setErrorParams(errCode, VARIABLE_NOT_A_STRUCT, errString, rightMostStructName);
    return structure;
}

node* primary_expression_identifier(char* lexeme, int &errCode, string& errStr) {
    symbolTableNode* stNode = lookUp(gSymTable, lexeme);
    if(!stNode) {
        errCode =  UNDECLARED_SYMBOL;
        errStr = lexeme;
        return nullptr;
    }
    node *temp = makeNode(strdup("IDENTIFIER"), strdup(lexeme), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
    temp->declSp = new declSpec();
    for(auto i : stNode->declSp->type){
        temp->declSp->type.push_back(i);
    }
    for(auto i : stNode->declSp->storageClassSpecifier)
        temp->declSp->storageClassSpecifier.push_back(i);

    temp->declSp->ptrLevel = stNode->declSp->ptrLevel;
    temp->declSp->lexeme = stNode->declSp->lexeme;
    temp->declSp->isConst = stNode->declSp->isConst;
    temp->declSp->isVolatile = stNode->declSp->isVolatile;
    return temp;
}

node* struct_or_union_specifier(node* struct_or_union, string name){
  int type = TYPE_STRUCT;
  node * temp = makeTypeNode(type);
  if(!temp->declSp)
    temp->declSp = new declSpec();
  temp->declSp->lexeme = name;
  temp->infoType = struct_or_union->infoType;
  temp->lineNo = line +1;
  return temp;
}

node* struct_declaration(node* specifier_qualifier_list, node* struct_declarator_list){
  node* curr = struct_declarator_list;
  while(curr) {
    node* temp = curr;
    string s(curr->name);
    if(s == "="){
      temp = curr->childList;
    }	
    if(!temp) continue;
    for(auto &u : temp->structParamList) {
      int ptrLevel = 0;
      if(u->declSp)
        ptrLevel = u->declSp->ptrLevel;
      u->declSp = specifier_qualifier_list->declSp;
      u->declSp->ptrLevel = ptrLevel;				
      specifier_qualifier_list->structParamList.push_back(u);
    }
    curr = curr -> next;
  }
  return specifier_qualifier_list;
}

node* declaration_list(node* declaration_list, node* declaration){
  node* temp = NULL;
  string s(declaration_list->name);
  bool c1  = (s == "DECL_LIST");
  if( c1 ){ 
    temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, declaration_list->childList, declaration, (node*)NULL, (node*)NULL);
  } else {
    temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, declaration_list, declaration, (node*)NULL, (node*)NULL);
  }
  for(auto &u : declaration->paramList){
    temp->paramList.push_back(u);
  }
  for(auto &u : declaration_list->paramList){
    temp->paramList.push_back(u);
  }
  return temp;
}

node* parameter_declaration(node* declaration_specifiers, node* declarator){
    param *parameter = new param();
    if(!parameter->declSp) {
        parameter->declSp = new declSpec();
    }
    if(declaration_specifiers->declSp) {
        parameter->declSp = declSpCopy(declaration_specifiers->declSp);
    }
    if(declarator->declSp) {
        parameter->declSp->ptrLevel = declarator->declSp->ptrLevel;
    }
    parameter->infoType = declaration_specifiers->infoType;
    parameter->paramName = declarator->lexeme;
    declarator->paramList.push_back(parameter);

    // cout<<"parameter_declaration: "<< parameter->paramName<< " " << parameter->declSp->type[0] <<endl;

    return declarator;
}

void checkFuncArgValidityWithParamEmit(node* postfix_expression, node* argument_expression_list, int &errCode, string &errString) {
    string func_name = postfix_expression->lexeme;
    string name = postfix_expression->lexeme;
    symbolTableNode* stNode = lookUp(gSymTable, name);
    
    if(!stNode || stNode->infoType != INFO_TYPE_FUNC || !stNode->declSp) {
        errCode = SYMBOL_NOT_FOUND;
        errString = name;
        return;
    }
    
    vector<struct param*> paramList = stNode->paramList; 
    int maxSize = paramList.size();
    int idx = 0;
    node* curr = argument_expression_list;
    int paramSize = 0;
    while(curr){
        node* temp = curr;
        string s = curr->name;
        if(s == "=") temp = curr->childList;
        if(!temp) continue;
        if(idx >= maxSize) {
            setErrorParams(errCode, INVALID_ARGS_IN_FUNC_CALL, errString, temp->lexeme);
            return;
        }
        if(!temp->declSp || !paramList[idx]->declSp){
            setErrorParams(errCode, INTERNAL_ERROR_DECL_SP_NOT_DEFINED, errString, temp->lexeme);
            return;
        }
        int retval = canTypecast(temp->declSp, paramList[idx]->declSp);
        if(retval){
            setErrorParams(errCode, INVALID_ARGS_IN_FUNC_CALL, errString, temp->lexeme);
            return;
        }
        //if valid but different types then typcast temp to paramList[idx]'s type
        if(requiresTypeCasting(temp->declSp, paramList[idx]->declSp)) {
            retval=canTypecast(paramList[idx]->declSp, temp->declSp);
            if(retval){
                setErrorParams(errCode, retval, errString, temp->lexeme);
                return;
            }
            typeCastLexemeWithEmit(temp, paramList[idx]->declSp);
        }
        emit(OP_PUSHPARAM, BLANK_STR, BLANK_STR, temp->addr);
        paramSize+= getTypeSize(temp->declSp->type);
        idx++;
        curr = curr -> next;
    }
    if(!postfix_expression->declSp){
        error(postfix_expression->lexeme,INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
    }
    if(postfix_expression->declSp->type[0]!= TYPE_VOID){
        string newTemp = generateTemp(errCode);
        if(errCode)
            error("Cannot generate Temp",errCode);
        emit(OP_LCALL, func_name, BLANK_STR ,newTemp);
    }else{
        emit(OP_LCALL, func_name, BLANK_STR ,BLANK_STR);
    }
    emit(OP_POPPARAM, BLANK_STR, BLANK_STR, to_string(paramSize));
    return;
}
