#ifndef grammarFunctionsHeader
#define grammarFunctionsHeader

#include "constants.h"  
#include "structures.h" 


structTableNode* getRightMostStructFromPostfixExpression(node* postfix_expression, bool isPtrOp, int &errCode, string &errString);

node* primary_expression_identifier(char* lexeme, int &errCode, string& errStr);

node* struct_or_union_specifier(node* struct_or_union, string name);

node* struct_declaration(node* specifier_qualifier_list, node* struct_declarator_list);

node* declaration_list(node* declaration_list, node* declaration);

node* parameter_declaration(node* declaration_specifiers, node* declarator);

string checkFuncArgValidityWithParamEmit(node* postfix_expression, node* argument_expression_list, int &errCode, string &errString);

void setOverSixParamOffset(node* declarator, symbolTable* curr, symbolTableNode* funcNode);

void setFirstSixParamOffset(node* declarator, symbolTable* gSymTable);

bool checkGlobalInitializerDFSUtil(node *a);
bool checkGlobalInitializer(node *initializer);
int addArrayParamToStack(int &offset, string addr, int &errCode, string &errString);
void emitPushStruct(node *astNode);
bool nodeIsStruct(node *astNode);
#endif