#include "grammarFunctions.h"

symbolTableNode* primary_expression_identifier(char* lexeme, int &errCode, string& errStr) {
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
  int type = (struct_or_union->infoType == INFO_TYPE_STRUCT) ? TYPE_STRUCT : TYPE_UNION;
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
    parameter->paramName = declarator->lexeme;
    declarator->paramList.push_back(parameter);

    return declarator;
}