%token IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL SIZEOF
%token PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
%token AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
%token SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN
%token XOR_ASSIGN OR_ASSIGN TYPE_NAME

%token TYPEDEF EXTERN STATIC AUTO REGISTER
%token CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
%token STRUCT UNION ENUM ELLIPSIS

%token CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN

%start translation_unit
%union{struct node* nodes; char* id;}
%type<nodes> primary_expression postfix_expression argument_expression_list unary_expression unary_operator
			cast_expression  multiplicative_expression additive_expression shift_expression relational_expression
			equality_expression and_expression exclusive_or_expression inclusive_or_expression logical_and_expression
			logical_or_expression conditional_expression assignment_expression assignment_operator expression constant_expression
			declaration declaration_specifiers init_declarator_list init_declarator storage_class_specifier type_specifier
			struct_or_union_specifier struct_or_union struct_declaration_list struct_declaration specifier_qualifier_list 
			struct_declarator_list struct_declarator enum_specifier enumerator_list  enumerator type_qualifier declarator direct_declarator
			pointer type_qualifier_list parameter_type_list parameter_list parameter_declaration identifier_list type_name abstract_declarator
			direct_abstract_declarator initializer initializer_list statement labeled_statement compound_statement declaration_list statement_list
			expression_statement selection_statement iteration_statement jump_statement translation_unit external_declaration function_definition
			constant inden_marker 
// Prototypes
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "symbolTable.h"
    extern int gScope;
    extern symbolTable* gSymTable;
    extern int line;
	extern char* previ;
	int funcDecl = 0;


extern "C"
{
	int yylex(void);  
	int yywrap();
	void yyset_in  ( FILE * _in_str  );
}

void yyerror(const char *s);
extern char yytext[];

node* root;
node* makeNode(char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);
void makeSibling(node* root, node* childList);
void addChild(node* parent, node* child);
node* makeTypeNode(int type);
node* makeDeadNode();
node* makeStorageClassNode(int storageClass, char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);

void error(string var, int error_code) {
	string str;
	switch(error_code) {
		case SYMBOL_ALREADY_EXISTS:
			str = "SYMBOL_ALREADY_EXISTS";
			break;
		case ALLOCATION_ERROR:
			str = "ALLOCATION_ERROR";
			break;
		case INVALID_ARGS:
			str = "Invalid arguments passed to the function ";
			break;
		case CONFLICTING_TYPES:
			str = "Conflicting type of declaration ";
			break;
		case UNDECLARED_SYMBOL:
			str = "Undeclared symbol ";
			break;		
		case TYPE_ERROR:
			str = "TYPE_ERROR";
			break;
		case ARRAY_SIZE_NOT_CONSTANT:
			str = "Array size should be a constant ";
			break;
		case ARRAY_SIZE_SHOULD_BE_INT:
			str = "Array size should be a integer ";
			break;
		case ARRAY_INDEX_SHOULD_BE_INT:
			str = "Array index should be a integer ";
			break;
		case INVALID_ARGS_IN_FUNC_CALL:
			str = "Array index should be a integer ";
			break;
		case INVALID_STORAGE_CLASS:
			str = "Conflicting type of storage class ";
			break;
		case SYMBOL_NOT_FOUND:
			str = "Symbol used before declaration ";
			break;
		case STRUCT_NOT_DECLARED:
			str = "Undeclared struct ";
			break;
		case INVALID_SYNTAX:
			str = "Invalid Syntax ";
			break;
		case VARIABLE_NOT_A_STRUCT:
			str = "Not a struct ";
			break;
		case INVALID_REFERENCE:
			str = "Invalid reference ";
			break;
		case INVALID_STRUCT_PARAM:
			str = "Invalid struct param ";
			break;
		case INTERNAL_ERROR_DECL_SP_NOT_DEFINED:
			str = "INTERNAL_ERROR_DECL_SP_NOT_DEFINED";
			break;
		case POINTER_ERROR:
			str = "Invalid Operand Of Type Pointer";
			break;
		case STRING_LITERAL_ERROR:
			str = "Invalid Operand Of Type String";
			break;
		default:
			break;
	}
	str+=var;
	cout << "\nERROR: " << str << " on line number: " << line+1 << endl;
	exit(error_code);
}



%}

%%

primary_expression
	// assuming identifier is not included in declaration. It must be declared before
	: IDENTIFIER { if(!lookUp(gSymTable, previ)) { error(previ, UNDECLARED_SYMBOL);	}; $$ = makeNode(strdup("IDENTIFIER"), strdup(previ), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| constant	{$$ = $1;}
	| STRING_LITERAL {
		node* temp = makeNode(strdup("STRING_LITERAL"), strdup(previ), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_STRING_LITERAL);
		$$ = temp;
	}
	| '(' expression ')' { $$ = $2; }
	;

constant
	: I_CONSTANT {
		string s = previ;
		node* temp = makeNode(strdup("CONSTANT"), strdup(previ), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_INT);
		addIVal(temp, previ);
		$$ = temp;
	}
	| F_CONSTANT {
		string s = previ;
		node* temp = makeNode(strdup("CONSTANT"), strdup(previ), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->declSp->type.push_back(TYPE_FLOAT);
		addFVal(temp, previ);
		$$ = temp;}
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' {
		if($3->declSp) {
			int err = check_type_array($3->declSp->type);
			error($3->lexeme, err);
		}
		else {
			error($3->lexeme, ARRAY_INDEX_SHOULD_BE_INT);
		}
		addChild($1,$3);
		$1->infoType = INFO_TYPE_ARRAY;
		$$ = $1;
		}
	| postfix_expression '(' ')' { // Check with function paramlist111NoParamName111
		node* postfix_expression  = $1;
		string func_name(postfix_expression->lexeme);
		if(postfix_expression -> paramList.size() > 0){
			error(func_name, INVALID_ARGS_IN_FUNC_CALL);
		}
		postfix_expression->infoType = INFO_TYPE_FUNC;
		$$ = postfix_expression;	
	}
	| postfix_expression '(' argument_expression_list ')' {
		// TODO: Error check for argument validity and function name
		node* postfix_expression  = $1;
		string func_name(postfix_expression->lexeme);
		vector<struct param*> paramList = postfix_expression -> paramList; 
		int idx = 0;
		node* curr = $3;
		while(curr){
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			if(!temp) continue;
			if(!temp->declSp || !paramList[idx]->declSp){
				error(temp->lexeme, INVALID_ARGS_IN_FUNC_CALL);
				break;
			}
			int retval = compareTypes(temp->declSp, paramList[idx]->declSp);
			if(retval){
				error(temp->lexeme, INVALID_ARGS_IN_FUNC_CALL);
			}
			idx++;
			curr = curr -> next;
		}
		postfix_expression->infoType = INFO_TYPE_FUNC;
		addChild(postfix_expression,$3);
		$$ = postfix_expression;
	}
	| postfix_expression '.' IDENTIFIER { 
		// TODO: Check if IDENTIFIER is valid field in struct
		// x.y.z
		node* curr = $1;
		while(curr != NULL){
			string s(curr->name);
			if(s == "IDENTIFIER"){
				break;
			}
			else{
				curr = curr->childList;
				if(curr){
 					curr = curr->next;
				}
			}
		}

		if(curr == NULL){
			// Error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		
		string rightMostStructName;	
		structTableNode* structure = nullptr;
		if(curr->infoType == INFO_NESTED_STRUCT){
			// declSp allocated so look in structure table
			if(curr->declSp) {
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
					rightMostStructName = n->declSp->lexeme;
					structure = structLookUp(gSymTable, rightMostStructName);
				}
			}
			
		}
		if(structure == nullptr) {
			//error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		// rightMostStructName = curr->lexeme;
		string identifierName(previ);
		// structure = structLookUp(gSymTable, rightMostStructName);
		int err = 0;
		structParam* param = structureParamLookup(structure, identifierName, err);
		if(err) error("structHasParam", err);
		if(!param) error(identifierName, INVALID_STRUCT_PARAM);
		
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL);
		temp->declSp = param->declSp;
		temp->infoType = INFO_NESTED_STRUCT;
		
		$$ = makeNode(strdup("."), strdup("."), 0, $1, temp , NULL, NULL);
		}
	| postfix_expression PTR_OP IDENTIFIER {
		// TODO: Struct field check
		node* curr = $1;
		while(curr != NULL){
			string s(curr->name);
			if(s == "IDENTIFIER"){
				break;
			}
			else{
				curr = curr->childList;
				if(curr){
 					curr = curr->next;
				}
			}
		}

		if(curr == NULL){
			// Error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		
		string rightMostStructName;	
		structTableNode* structure = nullptr;
		if(curr->infoType == INFO_NESTED_STRUCT){
			// declSp allocated so look in structure table
			if(curr->declSp)
				if(curr->declSp->ptrLevel != 1){
					// Error
					error(curr->lexeme, INVALID_REFERENCE);
				}
				rightMostStructName = curr->declSp->lexeme;
				structure = structLookUp(gSymTable, rightMostStructName);
			
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
					if(n->declSp->ptrLevel != 1){
						// Error
						error(n->name, INVALID_REFERENCE);
					}
					rightMostStructName = n->declSp->lexeme;
					structure = structLookUp(gSymTable, rightMostStructName);
				}
			}
			
		}
		if(structure == nullptr) {
			//error
			error("",VARIABLE_NOT_A_STRUCT);
		}
		string identifierName(previ);
		int err = 0;
		structParam* param = structureParamLookup(structure, identifierName, err);
		if(err) error("structHasParam", err);
		if(!param) error(identifierName, INVALID_STRUCT_PARAM);
		
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL);
		temp->declSp = param->declSp;
		temp->infoType = INFO_NESTED_STRUCT;
		
		$$ = makeNode(strdup("PTR_OP"), strdup(""), 0, $1, temp , NULL, NULL);
	}
	| postfix_expression INC_OP {
		// TODO: Should be integer
		int retval  = checkIntLongShort($1);
		if(retval){
			error($1->lexeme, retval);
		}
		addChild($1, makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));
		$$ = $1;
		}
	| postfix_expression DEC_OP {
		// TODO: postfix_expression should be integer
		int retval  = checkIntLongShort($1);
		if(retval){
			error($1->lexeme, retval);
		}
		addChild($1, makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));
		$$ = $1;
		}
	;

argument_expression_list
	: assignment_expression { $$ = $1; }
	| argument_expression_list ',' assignment_expression {if($1){makeSibling($3, $1); $$ = $1;} else $$ = $3;}
	;

unary_expression
	: postfix_expression {$$ = $1;}
	| INC_OP unary_expression {
		// TODO: Integer check
		int retval  = checkIntLongShort($2);
		if(retval){
			error($2->lexeme, retval);
		}
		$$ = makeNode(strdup("INC_OP"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| DEC_OP unary_expression {
		// TODO: Integer check
		int retval  = checkIntLongShort($2);
		if(retval){
			error($2->lexeme, retval);
		}
		$$ = makeNode(strdup("DEC_OP"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| unary_operator cast_expression { 
		// TODO: Type checking and typecasting based on the unary_operatory
		node* unary_operator = $1;
		node* cast_expression = $2;
		string name(unary_operator->name);
		
		int retval = checkStringLiteral(cast_expression);
		if(!retval){
			error(cast_expression->name, TYPE_ERROR);
		}

		if(name == "*"){
			if(!(cast_expression -> infoType == INFO_TYPE_ARRAY ||(cast_expression -> declSp && cast_expression -> declSp->ptrLevel > 0)) ){
				return TYPE_ERROR;	
			}
		}
		unary_operator->declSp = cast_expression->declSp;
		addChild(unary_operator, cast_expression);
		$$ = unary_operator;
	}
	| SIZEOF unary_expression {$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| SIZEOF '(' type_name ')'{
		// TODO: Check validity of type_name 
		$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

unary_operator
	: '&' {$$ = makeNode(strdup("&"), strdup("&"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' {
		// TODO: Check ptrLevel>0 or array..
		$$ = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '+' {
		// TODO: String Literal check
		$$ = makeNode(strdup("+"), strdup("+"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '-' {$$ = makeNode(strdup("-"), strdup("-"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '~' {$$ = makeNode(strdup("~"), strdup("~"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '!' {$$ = makeNode(strdup("!"), strdup("!"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

cast_expression
	: unary_expression {$$ = $1; }
	| '(' type_name ')' cast_expression { 
		// Append typename to front of lexeme
		string strType = "(to_";
		node* type_name = $2;
		node* cast_expression = $4;
		int err = checkValidTypeCast(cast_expression->declSp, type_name->declSp);;
		if(err) error("", err);
		strType = strType + getTypeString(type_name->declSp->type) + ")";
		cast_expression->declSp->type = type_name->declSp->type;
		string s = strType + string(cast_expression->lexeme); 
		strcpy(cast_expression->lexeme, s.c_str());
		$$ = cast_expression;
	}
	;

multiplicative_expression
	: cast_expression {$$ = $1; }
	| multiplicative_expression '*' cast_expression { 
		//  no pointer & no string literal
		int retval1 = checkPointer($1);
		int retval2 = checkPointer($3);
		if(!retval1){
			error($1->lexeme, POINTER_ERROR);
		}
		if(!retval2){
			error($3->lexeme, POINTER_ERROR);
		}
		retval1 = checkStringLiteral($1);
		retval2 = checkStringLiteral($3);
		if(!retval1){
			error($1->lexeme, STRING_LITERAL_ERROR);
		}
		if(!retval2){
			error($3->lexeme, STRING_LITERAL_ERROR);
		}
		int rank = giveTypeCastRank($1, $3);
		if(rank){
			error("typecast rank error", rank);
		}
		$$ = makeNode(strdup("*"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| multiplicative_expression '/' cast_expression { 
		int retval1 = checkPointer($1);
		int retval2 = checkPointer($3);
		if(!retval1){
			error($1->lexeme, POINTER_ERROR);
		}
		if(!retval2){
			error($3->lexeme, POINTER_ERROR);
		}
		retval1 = checkStringLiteral($1);
		retval2 = checkStringLiteral($3);
		if(!retval1){
			error($1->lexeme, STRING_LITERAL_ERROR);
		}
		if(!retval2){
			error($3->lexeme, STRING_LITERAL_ERROR);
		}
		int rank = giveTypeCastRank($1, $3);
		if(rank){
			error("typecast rank error", rank);
		}
		$$ = makeNode(strdup("/"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| multiplicative_expression '%' cast_expression { 
		int retval1 = checkPointer($1);
		int retval2 = checkPointer($3);
		if(!retval1){
			error($1->lexeme, POINTER_ERROR);
		}
		if(!retval2){
			error($3->lexeme, POINTER_ERROR);
		}
		retval1 = checkStringLiteral($1);
		retval2 = checkStringLiteral($3);
		if(!retval1){
			error($1->lexeme, STRING_LITERAL_ERROR);
		}
		if(!retval2){
			error($3->lexeme, STRING_LITERAL_ERROR);
		}
		int rank = giveTypeCastRank($1, $3);
		if(rank){
			error("typecast rank error", rank);
		}
		$$ = makeNode(strdup("%"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { 
		// TODO: Check implicit typecasting
		$$ = makeNode(strdup("+"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| additive_expression '-' multiplicative_expression { 
		// TODO: Check implicit typecasting
		$$ = makeNode(strdup("-"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { 
		// TODO: Both should be integers
		$$ = makeNode(strdup("LEFT_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| shift_expression RIGHT_OP additive_expression { 
		// TODO: Both should be integers
		$$ = makeNode(strdup("RIGHT_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { 
		// TODO: String Literal check,  implicit typecasting
		$$ = makeNode(strdup("<"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression '>' shift_expression { 
		// TODO: String Literal check, implicit typecasting
		$$ = makeNode(strdup(">"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression LE_OP shift_expression { // TODO: String Literal check
	$$ = makeNode(strdup("LE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression GE_OP shift_expression { 
		// TODO: String Literal check, implicit typecasting
		$$ = makeNode(strdup("GE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression { 
		// TODO: String Literal check, implicit typecasting
		$$ = makeNode(strdup("EQ_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| equality_expression NE_OP relational_expression { 
		// TODO: String Literal check, implicit typecasting
		$$ = makeNode(strdup("NE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { 
		$$ = makeNode(strdup("&"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression { 
		int retval = checkIntLongShort($1);
		int retval2 = checkIntLongShort($3);
		if(retval || retval2){
			error("expression", TYPE_ERROR);
		}
		$$ = makeNode(strdup("^"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression { $$ = makeNode(strdup("|"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression { 
		//TODO: Strings Literals allowed
		$$ = makeNode(strdup("AND_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression { 
		//TODO: Strings Literals allowed
		$$ = makeNode(strdup("OR_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { 
		
		$$ = makeNode(strdup("?:"), strdup(""), 0, $1, $3, $5, (node*)NULL); }
	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression { addChild($2, $1); addChild($2, $3); $$ = $2; }//TODO: Implicit typecasting
	;

assignment_operator
	: '=' {$$ = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| MUL_ASSIGN { $$ = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| DIV_ASSIGN { $$ = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| MOD_ASSIGN { $$ = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| ADD_ASSIGN { $$ = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| SUB_ASSIGN { $$ = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| LEFT_ASSIGN { $$ = makeNode(strdup("LEFT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| RIGHT_ASSIGN { $$ = makeNode(strdup("RIGHT_ASSIGN"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| AND_ASSIGN { $$ = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| XOR_ASSIGN { $$ = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| OR_ASSIGN { $$ = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	;

expression
	: assignment_expression { $$ = $1; }
	| expression ',' assignment_expression { if($1){makeSibling($3, $1); $$ = $1;} else $$ = $3;} 
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

declaration
	: declaration_specifiers ';' { $$ = $1; }
	| declaration_specifiers init_declarator_list ';' {
		node* curr = $2;
		while(curr){
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			
			if(!temp) continue;
			string lex = temp->lexeme;
			int retVal = insertSymbol(gSymTable, temp->lineNo, lex);
			if(retVal) {
				error(temp->lexeme, retVal);
			}
			
			struct symbolTableNode* sym_node = gSymTable->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			if(funcDecl){
				param* paramter = new param();
				paramter-> declSp = declSpCopy($1->declSp);
				paramter->paramName = lex;
				$1->paramList.push_back(paramter);
			}
			if(temp->infoType == INFO_TYPE_ARRAY){
				sym_node->infoType = INFO_TYPE_ARRAY;
				sym_node->arraySize = temp->arraySize;
				sym_node->declSp = declSpCopy($1->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			}
			else {
				sym_node->declSp = declSpCopy($1->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			} 
			
			curr = curr->next;
		}
		if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;   
	}
	;

declaration_specifiers
	: storage_class_specifier {$$ = $1;}
	| storage_class_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		vector<int> v = $1->declSp->storageClassSpecifier;
		int err = addStorageClassToDeclSpec(temp, v);
		if(err) error("addStorageClassToDeclSpec", err); //Error handling according to error code passed
		$$ = temp;
	}
	| type_specifier {$$ = $1;} 
	| type_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		vector<int> v = $1->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		$$ = temp;
	}
	| type_qualifier {$$ = $1;}
	| type_qualifier declaration_specifiers {
		node *temp = $2;
		//TODO: Verify correctness, code to merge types commented out
		// vector<int> v = $1->declSp->type;
		// int err = addTypeToDeclSpec(temp, v);
		// if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		mergeConstVolatile(temp, $1);
		$$ = temp;
	}
	;

init_declarator_list
	: init_declarator {  $$ = $1;  }
	| init_declarator_list ',' init_declarator { 
		if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;
	} 
	;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer { 
		$$ = makeNode(strdup("="), strdup("="), 0, $1, $3, (node*)NULL, (node*)NULL);
	}
	;
// do not handle
storage_class_specifier
	: TYPEDEF {$$ = makeStorageClassNode(TYPE_TYPEDEF, strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| EXTERN {$$ = makeStorageClassNode(TYPE_EXTERN, strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| STATIC {$$ = makeStorageClassNode(TYPE_STATIC, strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| AUTO {$$ = makeStorageClassNode(TYPE_AUTO, strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| REGISTER {$$ = makeStorageClassNode(TYPE_REGISTER, strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

type_specifier
	: VOID { $$ = makeTypeNode(TYPE_VOID);	}
	| CHAR {$$ = makeTypeNode(TYPE_CHAR);}
	| SHORT {$$ = makeTypeNode(TYPE_SHORT);}
	| INT {$$ = makeTypeNode(TYPE_INT);}
	| LONG {$$ = makeTypeNode(TYPE_LONG);}
	| FLOAT {$$ = makeTypeNode(TYPE_FLOAT);}
	| DOUBLE {$$ = makeTypeNode(TYPE_DOUBLE);}
	| SIGNED {$$ = makeTypeNode(TYPE_SIGNED);}
	| UNSIGNED {$$ = makeTypeNode( TYPE_UNSIGNED);}
	| struct_or_union_specifier {$$ = $1;}
	| enum_specifier {$$ = $1;}
	| TYPE_NAME { $$ = NULL;} //TODO: unknown use -- struct name
	;

inden_marker
	: {
		node* temp = makeDeadNode();
		temp->lexeme = previ;
		$$ =temp;		
	}
	;
	
struct_or_union_specifier
	: struct_or_union IDENTIFIER inden_marker '{' struct_declaration_list '}' {
		structTableNode* structNode = new structTableNode();
		string name = $3->lexeme;
		structNode->infoType = $1->infoType;
		structNode->lineNo = line+1;
		structNode->name = name;
		for(auto &u : $5->structParamList){
			structNode->paramList.push_back(u);
		} 
		
		int type = ($1->infoType == INFO_TYPE_STRUCT) ? TYPE_STRUCT : TYPE_UNION;
		node * temp = makeTypeNode(type);
		if(!temp->declSp)
			temp->declSp = new declSpec();
		temp->declSp->lexeme = name;
		temp->infoType = $1->infoType;
		temp->lineNo = line +1;

		gSymTable->structMap[$3->lexeme] = structNode;
		$$ = temp;
	} 
	| struct_or_union '{' struct_declaration_list '}' {cout << "488 feature not included"<< endl; $$ = NULL;} // segfault will come whenever this will be running
	| struct_or_union  IDENTIFIER {
		string name(previ); //TODO: wrong name, uses previ
		if(!structLookUp(gSymTable, name)) { //Recursive lookup
			error(name, STRUCT_NOT_DECLARED);
		}
		int type = ($1->infoType == INFO_TYPE_STRUCT) ? TYPE_STRUCT : TYPE_UNION;
		node * temp = makeTypeNode(type);
		if(!temp->declSp)
			temp->declSp = new declSpec();
		temp->declSp->lexeme = name;
		temp->infoType = $1->infoType;
		temp->lineNo = line +1;
		$$ = temp;
	}
	;

struct_or_union
	: STRUCT {
		node* temp = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_STRUCT;
		$$ = temp;}
	| UNION {
		node* temp = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->infoType = INFO_TYPE_UNION;
		$$ = temp;}
	;

struct_declaration_list
	: struct_declaration { $$ = $1; }
	| struct_declaration_list struct_declaration {  
		for(auto &u : $2->structParamList)
			$1->structParamList.push_back(u);
		$$ = $1;
	}
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {
		node* specifier_qualifier_list = $1;
		node* struct_declarator_list = $2;
		node* curr = struct_declarator_list;
		while(curr) {
			node* temp = curr;
			string s(curr->name);
			if(s == "="){
				temp = curr->childList;
			}
			if(!temp) continue;
			for(auto &u : temp->structParamList) {
				u->declSp = specifier_qualifier_list->declSp;
				specifier_qualifier_list->structParamList.push_back(u);
			}
			curr = curr -> next;
		}
		$$ = specifier_qualifier_list;
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {
		if($1){makeSibling($2,$1);}
		node *temp = $2;
		vector<int> v = $1->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		$$ = temp;
		}
	| type_specifier { $$ = $1; }
	| type_qualifier specifier_qualifier_list {
		node *temp = $2;
		mergeConstVolatile(temp, $1);
		$$ = temp;
	}
	| type_qualifier { $$ = $1; }
	;

struct_declarator_list
	: struct_declarator { $$ = $1; }
	| struct_declarator_list ',' struct_declarator {
		node* struct_declarator = $3; 
		node* struct_declarator_list = $1; 
		for(auto &u : struct_declarator->structParamList)
			struct_declarator_list->structParamList.push_back(u);
		$$ = struct_declarator_list;
	}
	;

struct_declarator
	: declarator { 
		node* declarator = $1; 
		structParam* param = new structParam();
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		declarator->structParamList.push_back(param);
		$$ = declarator;
	}
	| ':' constant_expression {$$ = NULL;} //TODO: Later, don't know meaning
	| declarator ':' constant_expression {
		node* declarator = $1; 
		structParam* param = new structParam();
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		int err = 0;
		int ret = getValueFromConstantExpression($3, err);
		if(err) error("getValueFromConstantExpression", err);
		param->bit = ret;
		declarator->structParamList.push_back(param);
		$$ = declarator;
	}
	;

// not to be handled
enum_specifier
	: ENUM '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup(""), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER '{' enumerator_list '}' { $$ = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, $4, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER { $$ = (node*)NULL;}
	;

enumerator_list
	: enumerator { $$ = $1; }
	| enumerator_list ',' enumerator { if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;} 
	;

enumerator
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| IDENTIFIER '=' constant_expression {$$ = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(previ), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	;

type_qualifier
	: CONST {
		node* temp = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isConst = true;
		$$ = temp;
	}
	| VOLATILE {
		node* temp = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		temp->declSp = new declSpec();
		temp->declSp->isVolatile = true;
		$$ = temp;
	}
	;

declarator
	: pointer direct_declarator  { 
		node *temp = $2;
		mergeConstVolatile(temp, $1);
		copyPtrLevel(temp, $1);

		$$ = temp;
	}
	| direct_declarator { $$ = $1; }
	;

direct_declarator
	// can be both in struct, or a declaration
	: IDENTIFIER { 
		$$ = makeNode(strdup("IDENTIFIER"), strdup(previ), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		$$-> infoType = INFO_TYPE_NORMAL;
		$$->lineNo = line+1;
	}
	| '(' declarator ')' { $$ = $2;}
	| direct_declarator '[' constant_expression ']' {
		node* temp = $1;
		int err;
		int asize = getValueFromConstantExpression(temp, err);
		if(err){
			error(temp->lexeme, err);
		}
		temp->infoType = INFO_TYPE_ARRAY;
		temp->arraySize = asize;
		$$ = temp;
	}
	| direct_declarator '[' ']' {$$ = $1; }
	| direct_declarator '(' parameter_type_list ')' { 
		node* direct_declarator = $1;	
		node* parameter_type_list = $3;	
		// Done: Add parameters to symbol table with appropriate types, also add to function arguments

		direct_declarator->paramList = parameter_type_list->paramList;
		direct_declarator->paramSize = parameter_type_list->paramSize;
		direct_declarator->infoType = INFO_TYPE_FUNC;
		$$=direct_declarator;
	}
	| direct_declarator '(' identifier_list ')' { 
		// Not handled: Add to symbol table with appropriate type??, also add to function arguments
		$$ = $1;
	}
	| direct_declarator '(' ')' { $$ = $1; }
	;

pointer
	: '*' { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		incrementPointerLevel(temp, NULL);
		$$ = temp;
	}
	| '*' type_qualifier_list { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, $2);
		mergeConstVolatile(temp, $2);
		$$ =  temp;
		}
	| '*' pointer { 
		node* temp = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		int retval = incrementPointerLevel(temp, $2);
		mergeConstVolatile(temp, $2);
		$$ = temp;
	}
	| '*' type_qualifier_list pointer { 
		node* temp  = makeNode(strdup("*"), strdup("*"), 0, $2, $3, (node*)NULL,(node*)NULL );
		int retval = incrementPointerLevel(temp, $3);
		mergeConstVolatile($3,$2);
		mergeConstVolatile(temp, $3);
		$$ = temp;
		}
	;

type_qualifier_list
	: type_qualifier { $$ = $1; }
	| type_qualifier_list type_qualifier { 
		// if($1){ makeSibling($2,$1);$$ = $1;} else $$ = $2;
		node* temp = $1;
		mergeConstVolatile(temp, $2);
		$$ = temp;
	}
	;


parameter_type_list
	: parameter_list { 
		node* parameter_list = $1;
		parameter_list->paramSize = parameter_list->paramList.size();
		$$ = parameter_list;
	 }
	| parameter_list ',' ELLIPSIS { 
		makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1);
		node* parameter_list = $1;
		parameter_list->paramSize = INF_PARAM_LIST;
		$$ = parameter_list;
	}
	;


parameter_list
	: parameter_declaration { $$ = $1; }
	| parameter_list ',' parameter_declaration { 
		if($1){makeSibling($3,$1);}
		node* parameter_list = $1;
		node* parameter_declaration = $3;
		for(auto& u: parameter_declaration->paramList)
			parameter_list->paramList.push_back(u);
		$$ = parameter_list;
	}
	;

parameter_declaration
	: declaration_specifiers declarator { 
		node* declaration_specifiers = $1;
		node* declarator = $2;

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

		$$ = declarator; 
	}
	| declaration_specifiers abstract_declarator { 
		//TODO: difference in abstract_declarator and declarator
		node* declaration_specifiers = $1;
		node* declarator = $2;

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

		$$ = declarator; 
	 }
	| declaration_specifiers { 
		node* declaration_specifiers = $1;

		param *parameter = new param();
		if(!parameter->declSp) {
			parameter->declSp = new declSpec();
		}
		if(declaration_specifiers->declSp) {
			parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		}
		parameter->paramName = "111NoParamName111";
		declaration_specifiers->paramList.push_back(parameter);

		$$ = declaration_specifiers; 
	}
	;

identifier_list
	: IDENTIFIER { 
		 $$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| identifier_list ',' IDENTIFIER { 
		makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

type_name
	: specifier_qualifier_list { $$ = $1; }
	| specifier_qualifier_list abstract_declarator {
		if($1){makeSibling($2,$1);}
		node *temp = $1;
		if($2->declSp) {
			int err = addTypeToDeclSpec(temp, $2->declSp->type);
			if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
			err = addStorageClassToDeclSpec(temp, $2->declSp->storageClassSpecifier);
			mergeConstVolatile(temp, $2);
			copyPtrLevel(temp, $2);
		}
		$$ = temp;
	}
	;

abstract_declarator
	: pointer { $$ = $1; }
	| direct_abstract_declarator { $$ = $1; }
	| pointer direct_abstract_declarator {
		//assuming ptr level of direct_abstract_declarator is zero
		node* temp = $2;
		mergeConstVolatile(temp, $1);
		copyPtrLevel(temp, $1);
		$$ = temp;
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;
	}
	;

// not to be handled anything below it, everything is checked by DIPESH and SAKSHI
direct_abstract_declarator
	: '(' abstract_declarator ')' {$$ = $2;}
	| '[' ']' {$$ = (node*)NULL;}
	| '[' constant_expression ']' {$$ = $2;}
	| direct_abstract_declarator '[' ']' {$$ = $1;}
	| direct_abstract_declarator '[' constant_expression ']' {$$ = $1;}
	| '(' ')' {$$ = (node*)NULL;}
	| '(' parameter_type_list ')' {$$ = $2;}
	| direct_abstract_declarator '(' ')' { $$ = $1; }
	| direct_abstract_declarator '(' parameter_type_list ')' { $$ = $1; }
	;

initializer
	: assignment_expression { $$ = $1; }
	| '{' initializer_list '}' { $$ = $2; }
	| '{' initializer_list ',' '}' { $$ = $2; }
	;

initializer_list
	: initializer { $$ = $1; }
	| initializer_list ',' initializer {if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;}
	;

statement
	: labeled_statement { $$ = $1; }
	| compound_statement {$$ = $1; }
	| expression_statement { $$ = $1; }
	| selection_statement { $$ = $1; }
	| iteration_statement { $$ = $1; }
	| jump_statement { $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement {$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	| CASE constant_expression ':' statement { $$ = makeNode(strdup("CASE"), strdup("case"), 0, $2, $4, (node*)NULL, (node*)NULL); }
	| DEFAULT ':' statement {$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	;

compound_statement
	: scope_marker '{' '}' { $$ = (node*)NULL; gSymTable = gSymTable->parent;}
	| scope_marker '{' statement_list '}' { $$ = $3; gSymTable = gSymTable->parent;}
	| scope_marker '{' declaration_list '}' {  $$ = $3; gSymTable = gSymTable->parent;}
	| scope_marker '{' declaration_list statement_list '}' { if($3){$$ = makeNode(strdup("BODY"), strdup(""), 0, $3, $4, (node*)NULL, (node*)NULL);} else{
		$$ = $4;} gSymTable = gSymTable->parent;}
	;

scope_marker
    : { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}

declaration_list
	: declaration { $$ = $1;}
	| declaration_list declaration {
		node* temp = NULL;
		string s($1->name);
		bool c1  = (s == "DECL_LIST");
		if( c1 ){ 
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, $1->childList, $2, (node*)NULL, (node*)NULL);
		} else {
			temp = makeNode(strdup("DECL_LIST"), strdup(""), 0, $1, $2, (node*)NULL, (node*)NULL);
		}
		for(auto &u : $2->paramList){
			temp->paramList.push_back(u);
		}
		for(auto &u : $1->paramList){
			temp->paramList.push_back(u);
		}
		$$ = temp;
	}
	;

statement_list
	: statement { $$ = $1; }
	| statement_list statement { if(!strcmp(($1 -> name), "STMT_LIST")){$$ = makeNode(strdup("STMT_LIST"), strdup(""), 0, $1 -> childList, $2, (node*)NULL, (node*)NULL);} else $$ = makeNode(strdup("STMT_LIST"), strdup(""), 0, $1, $2, (node*)NULL, (node*)NULL);}
	;

expression_statement
	: ';' {$$ = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| expression ';' {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

selection_statement
	: IF '(' expression ')' statement {$$ = makeNode(strdup("IF"), strdup("if"),0, $3, $5, (node*)NULL, (node*)NULL);}
	| IF '(' expression ')' statement ELSE statement {$$ = makeNode(strdup("IF_ELSE"), strdup(""),0, $3, $5, $7, (node*)NULL);}
	| SWITCH '(' expression ')' statement {$$ = makeNode(strdup("SWITCH"), strdup(""),0, $3, $5, (node*)NULL, (node*)NULL);}
	;

iteration_statement
	: WHILE '(' expression ')' statement {$$ = makeNode(strdup("WHILE"), strdup(""), 0, $3, $5, (node*)NULL, (node*)NULL);}
	| DO statement WHILE '(' expression ')' ';' {$$ = makeNode(strdup("DO WHILE"), strdup(""), 0, $2, $5, (node*)NULL, (node*)NULL);}
	| FOR '(' expression_statement expression_statement ')' statement {$$ = makeNode(strdup("FOR"), strdup(""),0, $3, $4, $6, (node*)NULL);}
	| FOR '(' expression_statement expression_statement expression ')' statement {$$ = makeNode(strdup("FOR"), strdup(""),0, $3, $4, $5, $7);}
	;

jump_statement
	: GOTO IDENTIFIER ';' {$$ = makeNode(strdup("GOTO"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
	| CONTINUE ';'{ $$ = makeNode(strdup("CONTINUE"), strdup(""),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| BREAK ';' { $$ = makeNode(strdup("BREAK"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| RETURN ';' { $$ = makeNode(strdup("RETURN"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| RETURN expression ';' { $$ = makeNode(strdup("RETURN"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

translation_unit
	: external_declaration { $$ = $1; root = $$; }
	| translation_unit external_declaration {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; root = $$;}
	;

external_declaration
	: function_definition {$$ = $1;}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers declarator func_marker declaration_list compound_statement { 
		addChild($2, $4); 
		addChild($2, $5); 
	 	
		node* declaration_specifiers = $1; // type
		node* declarator = $2; // func , param list
		
		
		for(auto &u: $4->paramList){
			$2->paramList.push_back(u);
		}
		addFunctionSymbol( declaration_specifiers, declarator);
		$$ = $2;
	}
	| declaration_specifiers declarator func_marker compound_statement { 
		addChild($2, $4);
		node* declaration_specifiers = $1; // type
		node* declarator = $2; // func , param list
		addFunctionSymbol(declaration_specifiers, declarator); 
		// Adding params to symtab
		symbolTable* curr;
		for(auto s: gSymTable->childList){
			curr = s;
		}

		for(auto &p: declarator->paramList){
			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
			if(retVal) {
				error(p->paramName, retVal);
			}
			string lex = p->paramName;
			
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			
			// if(temp->infoType == INFO_TYPE_ARRAY){
			// 	sym_node->infoType = INFO_TYPE_ARRAY;
				
			// 	sym_node->declSp = declSpCopy(p->declSp);
			// 	if(p->declSp)
			// 		sym_node->declSp->ptrLevel = p->declSp->ptrLevel;
			// }
			// else {
			sym_node->declSp = declSpCopy(p->declSp);
			// if(temp->declSp)
			// 		sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			// } 
		}

		$$ = $2;
	}
	| declarator func_marker declaration_list compound_statement { 
		addChild($1, $3); 
		addChild($1, $4);
		node* declarator = $1; // func , param list
		
		for(auto &u: $3->paramList){
			$1->paramList.push_back(u);
		}
		addFunctionSymbol(NULL, declarator);
		$$ = $1;
	}
	| declarator func_marker compound_statement { 
		addChild($1, $3);
		node* declarator = $1; // func , param list
		addFunctionSymbol(NULL, declarator);

		// Adding params to symtab
		symbolTable* curr;
		for(auto s: gSymTable->childList){
			curr = s;
		}

		for(auto &p: declarator->paramList){
			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
			if(retVal) {
				error(p->paramName, retVal);
			}
			string lex = p->paramName;
			
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			
			// if(temp->infoType == INFO_TYPE_ARRAY){
			// 	sym_node->infoType = INFO_TYPE_ARRAY;
				
			// 	sym_node->declSp = declSpCopy(p->declSp);
			// 	if(p->declSp)
			// 		sym_node->declSp->ptrLevel = p->declSp->ptrLevel;
			// }
			// else {
			sym_node->declSp = declSpCopy(p->declSp);
			// if(temp->declSp)
			// 		sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			// } 
		}
		
		$$ = $1;
	}
	;

func_marker
	: {
		// TODO: Send type from declaration specifier to function name
		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
	}
%%
#include <stdio.h>
int id = 0;



void printDeclarations(node* root, FILE *fp) {
    if(!root || root->isLeaf == DEAD_NODE ) return;
	if(root->isLeaf){
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, root->name);
	} else {
		fprintf(fp, "%d [label=\"%s\"];\n", root->id, root->name);
	}
    node* childList = root->childList;
    while(childList) {
        printDeclarations(childList, fp);
        childList = childList->next;
    }
}        

void printEdges(node* root, FILE *fp) {
	if(root->isLeaf == DEAD_NODE) return;
    node* child = root->childList;
    while(child) {
		if(child->isLeaf == DEAD_NODE) {
			child = child->next;
			continue;
		}
        fprintf(fp, "%d -> %d\n", root->id, child->id);
        printEdges(child, fp);
        child = child->next;
    }
}

void generateDot(node* root, char* fileName) {
    FILE *fp;
    fp = fopen(fileName, "w");
    fprintf(fp,"strict digraph AST {\n");
    printDeclarations(root, fp);
    printEdges(root, fp);
    fprintf(fp,"}\n");
    fclose(fp);
}


using namespace std;

int main(int ac, char **av) {
	cout << "I am in main" << endl;
	insert_into_sets();
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        
        // Make the first symbol table with global scope
		gSymTable = new symbolTable();
		if(!gSymTable) {
			printf("ERROR: Cannot allocate global symbol table\n");
			return 1;
		}
		gSymTable->scope = gScope++;
		gSymTable->parent = nullptr;
		
        yyparse();
		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
		char * fileName = strdup("graph.dot");
		if(ac == 3) fileName = av[2];

		generateDot(root,fileName);

		printSymbolTable(gSymTable);

        fclose(fd);
    }
    else
        printf("Usage: a.out input_filename [optional]ouput.dot \n");

	return 0; 
}

node* makeNode(char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->id = id++;
	newNode->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
	newNode->lexeme = (char*)malloc(sizeof(char)*(strlen(lexeme)+1));
	strcpy(newNode->name, name);
	strcpy(newNode->lexeme, lexeme);
	newNode->isLeaf = isLeaf;
	newNode->childList = c1;
	makeSibling(c2,newNode->childList);
	makeSibling(c3,newNode->childList);
	makeSibling(c4,newNode->childList);
	return newNode;
}

node* makeDeadNode(){
	node* newNode = new node();
	newNode->isLeaf=DEAD_NODE;
	newNode->declSp = new declSpec();
    newNode->childList = NULL;
    newNode->next = NULL;
	newNode->name = strdup("Dead Node");
	return newNode;
}

node* makeTypeNode(int tp){
	node* newNode = makeDeadNode();
	newNode->declSp->type.push_back(tp); //TODO: check validity of type
	return newNode;
}

node* makeStorageClassNode(int storageClass, char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = makeNode(name, lexeme, isLeaf, 
			c1,c2, c3, c4);
	newNode->declSp = new declSpec();
	newNode->declSp->storageClassSpecifier.push_back(storageClass); //TODO: check validity of storage class
	newNode->name = strdup("Storage Node");
	return newNode;
}

void makeSibling(node* root, node* childList){
	if(!root) return;
	if(!childList) return;
	node* curr  = childList;
	node* prev  = (node*)NULL;
	while(curr){
		prev = curr;
		curr = curr->next;
	}
	prev->next = root;
}

void addChild(node* parent, node* child){
	if(parent->childList == (node*)NULL){
		parent->childList = child;
	}
	else{
		makeSibling(child, parent->childList);
	}
}


extern int column;
void yyerror(const char* s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
