%token IDENTIFIER I_CONSTANT F_CONSTANT STRING_LITERAL CHAR_LITERAL SIZEOF
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
			constant inden_marker func_marker_1 M_marker N_marker expressionJump expressionJumpStatement 
// Prototypes
%{
	#include <stdio.h>
	#include <string.h>
	#include <stdlib.h>
	#include "../src/headers/allInclude.h" 
    extern int gScope;
    extern symbolTable* gSymTable;
    extern int line;
	extern char* previ;
	struct node* currDecl;
	struct node* currDeclSpec;
	int funcDecl = 0;
	int errCode=0;
	string errStr;
	string currFunc = "#prog";
	vector<node*> case_consts;
	int offset = 0;

extern "C"
{
	int yylex(void);  
	int yywrap();
	void yyset_in  ( FILE * _in_str  );
}

void yyerror(const char *s);
extern char yytext[];

node* root;


%}

%%
/*
	struct quadruple {
		int operator, op1, op2, eq;
	}

	vector<quadruple> code;

	a = b + c;
	(+,b,c,a)
	a = -b
	(un- , b, NULL, a)

	if a < b then S1 else S2

	t = a < b

	t = x relop y	
	if x relop y then goto Z
 
	(condJump, true, false, exp)
	(condJump, s1, s2, t)  
	
	while M1 A do M2 B done

	E.true =
	E.truelist = [all statement numbers which goto ___]


	//AST node additions: place, truelist, falselist, nextlist, begin, next, ?end?//(breaklist) left as of now//, quad, ??code??
	// truelist, falselist: list stl datatype
	// new functions:
	• makelist(i): create a newlist containing only i, return a pointer to the list. 
	• merge(p1, p2): merge lists pointed to by p1 and p2 and return a pointer to the concatenated list 
	• backpatch(p, i):
	. emit()
	. string newTemp()
	//findOperatorType(operator, op1, op2);

	//#define all operators


	gramar change
	//normal statements (slide 43)
	//flow control statements
	//procedure calls :  activation record 
	//boolean expressions, short circuiting


	//global vars:
	vector<quadruple> gCode, 
	int nextStat; (gCode.size())
	//store temp variables in a new symbol table
	gNewTemp = 0;
	//symbol table of temp variables


	//string newTemp(){
		return '@t'+gNewTemp++; //@ so that names do not conflict with program variable names
	}


	a = b * c + d;
	t1 = b * c;
	a = t1 + d;


	id=>
	E -> id
	E.place = lexeme;
	E -> A + B
	E.place = newtmp();
	emit(E.place = A.place type_+ B.place);
*/
// [,,,]
primary_expression
	// assuming identifier is not included in declaration. It must be declared before
	: IDENTIFIER { 
		symbolTableNode* stNode = lookUp(gSymTable, yylval.id);
		if(!stNode) error(yylval.id, UNDECLARED_SYMBOL);
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		temp->declSp = declSpCopy(stNode->declSp);
		setAddr(temp, string(yylval.id));
		$$=temp;
	}
	| constant	{$$ = $1;}
	| STRING_LITERAL {
		$$ = NULL;
		// node* temp = makeNode(strdup("STRING_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		// if(!temp->declSp) temp->declSp = new declSpec();
		// temp->declSp->type.push_back(TYPE_STRING_LITERAL);
		error(yylval.id, STRING_LITERAL_ERROR);
		;
	}
	| CHAR_LITERAL {
		string name = yylval.id;
		if(name.size() != 3) error( yylval.id, NOT_A_CHAR);
		node* temp = makeNode(strdup("CHAR_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		if(!temp->declSp) temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_CHAR);
		temp->valType = TYPE_CHAR;
		setAddr(temp, string(yylval.id));
		$$ = temp;
	}
	| '(' expression ')' { $$ = $2; }
	;

constant
	: I_CONSTANT {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp) temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_INT);
		addIVal(temp, yylval.id);
		setAddr(temp, string(yylval.id));
		$$ = temp;
	}
	| F_CONSTANT {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp) temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_FLOAT);
		addFVal(temp, yylval.id);
		setAddr(temp, string(yylval.id));
		$$ = temp;
	}
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' {
		node *postfix_expression = $1;
		node *expression = $3;
		string arrayIndexStr = getArrayIndexWithEmit(postfix_expression, expression, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		addChild(postfix_expression, expression);
		postfix_expression->infoType = INFO_TYPE_ARRAY;
		postfix_expression->addr = arrayIndexStr;
		postfix_expression->declSp->ptrLevel++;
		$$ = postfix_expression;
	}
	| postfix_expression '(' ')' { // Check with function paramlist111NoParamName111
		string func_name($1->lexeme);
		if($1->paramList.size() > 0) error(func_name, INVALID_ARGS_IN_FUNC_CALL);
		$1->infoType = INFO_TYPE_FUNC;
		$$ = $1;	
	}
	| postfix_expression '(' argument_expression_list ')' {
		checkFuncArgValidityWithParamEmit($1, $3, errCode, errStr);
		if(errCode) error(errStr, errCode);
		$1->infoType = INFO_TYPE_FUNC;
		addChild($1,$3);
		$$ = $1;
	}
	| postfix_expression '.' IDENTIFIER { 
		node * postfix_expression = $1;
		structTableNode* structure = getRightMostStructFromPostfixExpression($1, false, errCode, errStr);
		if(errCode) error(errStr, errCode);
		
		string identifierName = yylval.id;
		structParam* param = structureParamLookup(structure, identifierName, errCode, errStr);
		if(errCode) error(errStr, errCode);
		string newAddr = postfix_expression->addr + "." + identifierName;
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, NULL, NULL, NULL, NULL);
		temp->declSp = declSpCopy(param->declSp);
		temp->infoType = INFO_NESTED_STRUCT;
		temp->addr = newAddr;
		node *newNode = makeNode(strdup("."), strdup("."), 0, $1, temp , NULL, NULL);
		newNode->declSp = declSpCopy(temp->declSp);
		newNode->infoType = INFO_NESTED_STRUCT;
		newNode->addr = newAddr;
		$$ = newNode;
	}
	| postfix_expression PTR_OP IDENTIFIER {
		structTableNode* structure = getRightMostStructFromPostfixExpression($1, true, errCode, errStr);
		if(errCode) error(errStr, errCode);
		
		string identifierName = yylval.id;
		structParam* param = structureParamLookup(structure, identifierName, errCode, errStr);
		if(errCode) error(errStr, errCode);
	
		string newAddr = $1->addr + "->" + identifierName;
		node *temp = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, NULL, NULL, NULL, NULL);
		temp->declSp = declSpCopy(param->declSp);
		temp->infoType = INFO_NESTED_STRUCT;
		temp->addr = newAddr;
		node *newNode = makeNode(strdup("PTR_OP"), strdup("->"), 0, $1, temp , NULL, NULL);
		newNode->declSp = declSpCopy(temp->declSp);
		newNode->infoType = INFO_NESTED_STRUCT;
		newNode->addr = newAddr;
		$$ = newNode;
	}
	| postfix_expression INC_OP {
		// int retval  = checkIntOrCharOrPointer($1);
		// if(retval) error($1->lexeme, retval);
		// addChild($1, makeNode(strdup("INC_OP"), strdup("++"), 1, NULL, NULL, NULL, NULL));
		errStr = "use ++" + string($1->lexeme)+ " instead of " + string($1->lexeme) + "++";
		error(errStr.c_str(), UNSUPPORTED_FUNCTIONALITY);
		$$ = $1;
	}
	| postfix_expression DEC_OP {
		// int retval  = checkIntOrCharOrPointer($1);
		// if(retval) error($1->lexeme, retval);
		// addChild($1, makeNode(strdup("DEC_OP"), strdup("--"), 1, NULL, NULL, NULL, NULL));
		errStr = "use --" + string($1->lexeme)+ " instead of " + string($1->lexeme) + "--";
		error(errStr.c_str(), UNSUPPORTED_FUNCTIONALITY);
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
		int retval  = checkIntOrCharOrPointer($2);
		if(retval) error($2->lexeme, retval);
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Cannot generate Temp",errCode);
		int opCode = getOpAddType($2, errCode, errStr);
		if(errCode)
			error("Cannot generate Temp",errCode);
        emit(opCode, $2->addr, "1", newTmp);
    	emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, $2->addr);
		$$ = makeNode(strdup("INC_OP"), strdup("++"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp = declSpCopy($2->declSp);
		$$->addr = $2->addr;
	}
	| DEC_OP unary_expression {
		int retval  = checkIntOrCharOrPointer($2);
		if(retval) error($2->lexeme, retval);
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Cannot generate Temp",errCode);
		int opCode = getOpSubType($2, errCode, errStr);
		if(errCode)
			error("Cannot generate Temp",errCode);
        emit(opCode, $2->addr, "1", newTmp);
    	emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, $2->addr);
		$$ = makeNode(strdup("DEC_OP"), strdup("--"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp = declSpCopy($2->declSp);
		$$->addr = $2->addr;
	}
	| unary_operator cast_expression {
		node* unary_operator = $1;
		node* cast_expression = $2;
		string name(unary_operator->name);
		unary_operator->declSp = cast_expression->declSp;

		if(name == "*" && 
			(!(cast_expression->infoType == INFO_TYPE_ARRAY || (cast_expression->declSp && cast_expression->declSp->ptrLevel > 0))))
				error(cast_expression->name, TYPE_ERROR);

		if(name == "&"){
			if(cast_expression->infoType ==INFO_TYPE_STRUCT){
				structTableNode* structNode = structLookUp(gSymTable, cast_expression->lexeme);
				if(!structNode){
					error(cast_expression->lexeme,INVALID_REFERENCE);
				}else{
					unary_operator->declSp->ptrLevel++;
				}
			}
			else
			{
				symbolTableNode* symNode = lookUp(gSymTable,cast_expression->lexeme);
				if(!symNode){
					error(cast_expression->lexeme,INVALID_REFERENCE);
				}else{
					unary_operator->declSp->ptrLevel++;
				}
			}
		}
		addChild(unary_operator, cast_expression);
		$$ = unary_operator;
	}
	| SIZEOF unary_expression {$$ = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| SIZEOF '(' type_name ')'{
		// TODO: Check validity of type_name 
		
		$$ = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

unary_operator
	: '&' {$$ = makeNode(strdup("&"), strdup("&"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' {
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
		string strType = "(TO_";
		node* type_name = $2;
		node* cast_expression = $4;
		int err = canTypecast(cast_expression->declSp, type_name->declSp);
		if(err) error("", err);
		typeCastLexemeWithEmit(cast_expression, type_name->declSp);
		$$ = cast_expression;
	}
	;

multiplicative_expression
	: cast_expression {$$ = $1; }
	| multiplicative_expression '*' cast_expression { 
		//  no pointer & no string literal constNode->lexeme
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "*", errCode, errStr); 
		if(errCode)
			error(errStr, errCode);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		int opCode = getOpMulType(temp, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emit(opCode, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	| multiplicative_expression '/' cast_expression { 
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "/", errCode, errStr); 
		if(errCode)
			error(errStr, errCode);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		int opCode = getOpDivType(temp, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emit(opCode, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	| multiplicative_expression '%' cast_expression { 
		int retval = checkType($3->declSp,TYPE_FLOAT,0);
		if(retval){
			error($3->lexeme, SHOULD_NOT_BE_FLOAT);
		}
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "%", errCode, errStr); 
		if(errCode)
			error(errStr, errCode);
			
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		emit(OP_MOD, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { 
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "+", errCode, errStr); 
		if(errCode)
			error(errStr, errCode);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		int opCode = getOpAddType(temp, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emit(opCode, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	| additive_expression '-' multiplicative_expression { 
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "-", errCode, errStr); 
		if(errCode)
			error(errStr, errCode);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		int opCode = getOpSubType(temp, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emit(opCode, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { 
		int retval = checkIntOrChar($3);
		if(retval)	error($3->lexeme, TYPE_ERROR);
		retval = checkIntOrChar($1);
		if(retval)	error($1->lexeme, TYPE_ERROR);
		
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "<<", errCode, errStr);
		if(errCode)
			error(errStr, errCode);
			
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		emit(OP_LEFT_SHIFT, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp; 
		}
	| shift_expression RIGHT_OP additive_expression { 
		int retval = checkIntOrChar($3);
		if(retval)	error($3->lexeme, TYPE_ERROR);
		retval = checkIntOrChar($1);
		if(retval)	error($1->lexeme, TYPE_ERROR);
		
		node* temp = makeNodeForExpressionNotPointerNotString($1, $3, ">>", errCode, errStr);
		if(errCode)
			error(errStr, errCode);
			
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
		tempNode->declSp = declSpCopy($1->declSp);
		emit(OP_RIGHT_SHIFT, $1->addr, $3->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { 
			int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
			if(retval)
				error(errStr,retval);
			node* temp = makeNode(strdup("<"), strdup("<"), 0, $1, $3, (node*)NULL, (node*)NULL); 
			emitRelop($1, $3, temp, OP_LESS, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$$ = temp;
			}
	| relational_expression '>' shift_expression { 
			int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
			if(retval)
				error(errStr,retval);
			node* temp = makeNode(strdup(">"), strdup(">"), 0, $1, $3, (node*)NULL, (node*)NULL); 
			emitRelop($1, $3, temp, OP_GREATER, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$$ = temp;
	}
	| relational_expression LE_OP shift_expression {
		int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
		if(retval)
			error(errStr,retval);
		node* temp = makeNode(strdup("LE_OP"), strdup("<="), 0, $1, $3, (node*)NULL, (node*)NULL);
		emitRelop($1, $3, temp, OP_LEQ, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		$$ = temp;
	}
	| relational_expression GE_OP shift_expression { 
		int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
		if(retval)
			error(errStr,retval);
		node* temp = makeNode(strdup("GE_OP"), strdup(">="), 0, $1, $3, (node*)NULL, (node*)NULL);
		emitRelop($1, $3, temp, OP_GEQ, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		$$ = temp;
	}
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression {
		node* equality_expression = $1;
		node* relational_expression = $3;
		int retval1 = checkPointer(equality_expression);
		int retval2 = checkPointer(relational_expression);
		int x = (retval1 == 0) + (retval2 == 0);
		if(x == 1)
			error("equality check between pointer and non pointer", POINTER_ERROR);

		int rank = giveTypeCastRank(equality_expression, relational_expression);
		if(rank < 0)
			error("typecasting error rank", rank);
		int retval = typeCastByRank(equality_expression, relational_expression, rank);
		if(retval)
			error("typecasting error rank", retval);
		node* temp = makeNodeForExpressionByRank(equality_expression, relational_expression, "EQ_OP", "==", rank, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emitRelop(equality_expression, relational_expression, temp, OP_EQ, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		$$ = temp;
	}
	| equality_expression NE_OP relational_expression { 
		node* equality_expression = $1;
		node* relational_expression = $3;
		int retval1 = checkPointer(equality_expression);
		int retval2 = checkPointer(relational_expression);
		int x = (retval1 == 0) + (retval2 == 0);
		if(x == 1)
			error("equality check between pointer and non pointer", POINTER_ERROR);

		int rank = giveTypeCastRank(equality_expression, relational_expression);
		if(rank < 0)
			error("typecasting error rank", rank);
		int retval = typeCastByRank(equality_expression, relational_expression, rank);
		if(retval)
			error("typecasting error rank", retval);
		node* temp = makeNodeForExpressionByRank(equality_expression, relational_expression, "NE_OP", "!=", rank, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		emitRelop(equality_expression, relational_expression, temp, OP_NEQ, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		$$ = temp;
	}
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { 
		node * and_expression = $1;
		node * equality_expression = $3;
		int retval = bitwiseImplicitTypecasting(and_expression, equality_expression, errCode,errStr);
		if(retval < 0){
			error(errStr, errCode);
		}
		node* temp = makeNode(strdup("&"), strdup("&"), 0, and_expression, equality_expression, (node*)NULL, (node*)NULL);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		emit(OP_AND, and_expression->addr, equality_expression->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;


exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^'  and_expression { 
		node* exclusive_or_expression = $1;
		node* and_expression = $3;
		int retval = bitwiseImplicitTypecasting(exclusive_or_expression, and_expression, errCode,errStr);
		if(retval < 0){
			error(errStr, errCode);
		}
		node* temp = makeNode(strdup("^"), strdup("^"), 0, exclusive_or_expression, and_expression, (node*)NULL, (node*)NULL);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		emit(OP_XOR, exclusive_or_expression->addr, and_expression->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
	}
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression { 
		node * inclusive_or_expression1 = $1;
		node * exclusive_or_expression = $3;
		int retval = bitwiseImplicitTypecasting(inclusive_or_expression1, exclusive_or_expression, errCode,errStr);
		if(retval < 0){
			error(errStr, errCode);
		}
		node* temp = makeNode(strdup("|"), strdup("|"), 0, inclusive_or_expression1, exclusive_or_expression, (node*)NULL, (node*)NULL);
		string newTmp = generateTemp(errCode);
		if(errCode)
			error(errStr, errCode);
		emit(OP_OR, inclusive_or_expression1->addr, exclusive_or_expression->addr, newTmp);
		temp->addr = newTmp;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
	}
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP M_marker inclusive_or_expression { 
		backpatch($1->truelist, $3->quad);
		node* temp = makeNode(strdup("AND_OP"), strdup("&&"), 0, $1, $4, (node*)NULL, (node*)NULL); 
		temp->truelist = $4->truelist;
		temp->falselist = mergelist($1->falselist, $4->falselist);
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
	}
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP M_marker logical_and_expression { 
		backpatch($1->falselist, $3->quad);
		node* temp = makeNode(strdup("OR_OP"), strdup("||"), 0, $1, $4, (node*)NULL, (node*)NULL);  
		temp->truelist = mergelist($1->truelist, $4->truelist);
		temp->falselist = $4->falselist;
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;

 
conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' M_marker expression N_marker ':' M_marker conditional_expression {
		backpatch($1->truelist, $3->quad);
		backpatch($1->falselist, $7->quad);
		node* temp = makeNode(strdup("?:"), strdup("?:"), 0, $1, $4, $8, (node*)NULL); 
		vector<int> tempVec = mergelist( $4->nextlist, $5->nextlist);
		temp->nextlist = mergelist(tempVec, $8->nextlist);
		temp->declSp = declSpCopy($1->declSp);
		$$ = temp;
		}
	;

assignment_expression
	: conditional_expression { $$ = $1;}
	| unary_expression assignment_operator assignment_expression 
	{ 
		node* unary_expression = $1;
		node* assignment_expression = $3;
		node* assignment_operator = $2;
		if (!unary_expression->declSp) 
		{
			declSpec* ds = new declSpec();
			if(!assignment_expression->declSp)
				error(assignment_expression->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
			ds->type = assignment_expression->declSp->type;
			unary_expression->declSp = ds;
		}
		else 
		{
			string s(assignment_operator->name);
			if(s == "AND_ASSIGN" || s == "OR_ASSIGN" || s == "XOR_ASSIGN" || s == "LEFT_ASSIGN" || s == "RIGHT_ASSIGN") {
				//should be only int or char
				if(checkIntOrChar(unary_expression) || checkIntOrChar(assignment_expression))
					error("expression should only be int or char", TYPE_ERROR);
			}
			if(s=="MUL_ASSIGN" || s=="DIV_ASSIGN" || s=="ADD_ASSIGN" || s=="SUB_ASSIGN" || s=="=") {
				int retval = canTypecast(assignment_expression->declSp,unary_expression->declSp);
				if(retval)
					error("invalid typecast in assignment expression", retval);
			}
			if(s == "MOD_ASSIGN") {
				if(checkType(assignment_expression->declSp, TYPE_FLOAT, 0))
					error(assignment_expression->lexeme, SHOULD_NOT_BE_FLOAT);
				//typecast by rank
				// int retval = implicitTypecastingNotPointerNotStringLiteral(unary_expression, assignment_expression, errStr);
				// if(retval)
					// error(errStr,retval);
			}
		}
		string resultAddr = unary_expression->addr;
		string s(assignment_operator->name);
		int opCode = getOpcodeFromAssignStr(s);
		if(opCode >= 0) { 
			//AND_ASSIGN or OR_ASSIGN or XOR_ASSIGN or LEFT_ASSIGN or RIGHT_ASSIGN or MOD_ASSIGN
			emitOperationAssignment(unary_expression, assignment_expression, opCode, resultAddr, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
		}
		else if(s == "=")
		{
			bool retval = typeCastRequired(assignment_expression->declSp, unary_expression->declSp, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			if(retval){
				typeCastLexemeWithEmit(assignment_expression, unary_expression->declSp);
			}
			emit(OP_ASSIGNMENT, assignment_expression->addr, EMPTY_STR, unary_expression->addr);
		}
		else
		{
			int rank = giveTypeCastRank(unary_expression, assignment_expression);
			if(rank < 0)
				error("giveTypeCastRank error",-rank);
			
			int retval = typeCastByRank(unary_expression, assignment_expression, rank);
			if(retval)
				error("typecast error",retval);
			opCode = -1;
			if(s == "MUL_ASSIGN")
				opCode = getOpMulType(unary_expression, errCode, errStr);
			else if(s == "DIV_ASSIGN")
				opCode = getOpDivType(unary_expression, errCode, errStr);
			else if(s == "SUB_ASSIGN")
				opCode = getOpSubType(unary_expression, errCode, errStr);
			else if(s == "ADD_ASSIGN")
				opCode = getOpAddType(unary_expression, errCode, errStr);
			
			if(errCode || opCode == -1)
				error(errStr, errCode);
			emitOperationAssignment(unary_expression, assignment_expression, opCode, resultAddr, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
		}
		assignment_operator->addr = unary_expression->addr;
		assignment_operator->declSp = declSpCopy(unary_expression->declSp);
		addChild(assignment_operator, unary_expression); 
		addChild(assignment_operator, assignment_expression); 
		$$ = assignment_operator;
	}
	;

assignment_operator
	: '=' {$$ = makeNode(strdup("="), strdup("="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| MUL_ASSIGN { $$ = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| DIV_ASSIGN { $$ = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| MOD_ASSIGN { $$ = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| ADD_ASSIGN { $$ = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| SUB_ASSIGN { $$ = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| LEFT_ASSIGN { $$ = makeNode(strdup("LEFT_ASSIGN"), strdup("<<="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| RIGHT_ASSIGN { $$ = makeNode(strdup("RIGHT_ASSIGN"), strdup(">>="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| AND_ASSIGN { $$ = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| XOR_ASSIGN { $$ = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| OR_ASSIGN { $$ = makeNode(strdup("OR_ASSIGN"), strdup("/="), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	;

expression
	: assignment_expression { 
		$$ = $1; 
		// if(!$$->truelist.size()) {
		// 	$$->truelist = makelist(nextQuad());
    	// 	$$->falselist = makelist(nextQuad()+1);
		// 	emit(OP_IFGOTO, $1->addr, EMPTY_STR, BLANK_STR);
    	// 	emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
		// }
	}
	| expression ',' assignment_expression { 
		if($1){makeSibling($3, $1); $$ = $1;} else $$ = $3;
		$$->truelist = mergelist($1->truelist, $3->truelist);
		$$->falselist = mergelist($1->falselist, $3->falselist);
		$$->nextlist = mergelist($1->nextlist, $3->nextlist);
		$$->breaklist = mergelist($1->breaklist, $3->breaklist);
		$$->continuelist = mergelist($1->continuelist, $3->continuelist);
		} 
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

// TODO: check typecasting here in testing, if not done then do it, Wirtten in notes by Sakshi that this might be missing
declaration
	: declaration_specifiers ';' { $$ = $1; }
	| declaration_specifiers init_declarator_list ';' {
		node* curr = $2;
		while(curr){
			node* temp = curr;
			string s(curr->name);
			node* initializer=nullptr;
			if(s == "="){
				temp = curr->childList;
				initializer = temp->next;
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
				// param* paramcheckValidTypeter = new param();
				param* paramter = new param();
				paramter->declSp = declSpCopy($1->declSp);
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
				if(initializer) {
					//variable initialized
					int retval = canTypecast(sym_node->declSp, initializer->declSp);
					if(retval)
						error("variable assignment error", retval);
					retval = areDifferentTypes(sym_node->declSp, initializer->declSp, errCode, errStr);
					if(errCode)
						error(errStr, errCode);
					if(retval) {
						typeCastLexemeWithEmit(initializer, sym_node->declSp);
					}
					emit(OP_ASSIGNMENT, initializer->addr, EMPTY_STR, temp->addr);
				}
			}

			sym_node->size = getNodeSize(sym_node, gSymTable);
			sym_node->offset = offset;
			offset += getOffsettedSize(sym_node->size);

			curr = curr->next;
		}
		// if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;   
		makeSibling($2,$1);
		$$ = $1; 
	}
	;

declaration_specifiers
	: storage_class_specifier {$$ = $1; currDeclSpec = $$;}
	| storage_class_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		// vector<int> v = $1->declSp->storageClassSpecifier;
		// int err = addStorageClassToDeclSpec(temp, v);
		// if(err) error("addStorageClassToDeclSpec", err); //Error handling according to error code passed
		$$ = temp;
		// currDeclSpec = $$;
	}
	| type_specifier {$$ = $1; currDeclSpec = $$;} 
	| type_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		vector<int> v = $1->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
		$$ = temp;
		currDeclSpec = $$;
	}
	| type_qualifier {$$ = $1; currDeclSpec = $$;}
	| type_qualifier declaration_specifiers {
		node *temp = $2;
		//TODO: Verify correctness, code to merge types commented out
		mergeConstVolatile(temp, $1);
		$$ = temp;
		currDeclSpec = $$;
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
		node* declaration_specifiers = currDeclSpec;
		node* declarator = $1;
		node* initializer = $3;
		
		if(!declarator->declSp){
			declSpec* ds = new declSpec();
			if(!initializer->declSp){
				error(initializer->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
			}
			ds->type = initializer->declSp->type;
			declarator->declSp = ds;
		}
		// emit(OP_ASSIGNMENT, initializer->addr, EMPTY_STR, declarator->addr);
		$$ = makeNode(strdup("="), strdup("="), 0, declarator, initializer, (node*)NULL, (node*)NULL);
		$$->addr=$1->addr;
	}
	;
// do not handle
storage_class_specifier
	: TYPEDEF {$$ = NULL; error("TYPEDEF", UNSUPPORTED_FUNCTIONALITY);}
	| EXTERN {$$ = NULL; error("EXTERN", UNSUPPORTED_FUNCTIONALITY);}
	| STATIC {$$ = NULL; error("STATIC", UNSUPPORTED_FUNCTIONALITY);}
	| AUTO {$$ = NULL; error("AUTO", UNSUPPORTED_FUNCTIONALITY);}
	| REGISTER {$$ = NULL; error("REGISTER", UNSUPPORTED_FUNCTIONALITY);}
	;

type_specifier
	: VOID {$$ = makeTypeNode(TYPE_VOID);	}
	| CHAR {$$ = makeTypeNode(TYPE_CHAR);}
	| INT {$$ = makeTypeNode(TYPE_INT);}
	| FLOAT {$$ = makeTypeNode(TYPE_FLOAT);}
	| struct_or_union_specifier {$$ = $1;}
	| SHORT {$$ = NULL; error("SHORT", UNSUPPORTED_FUNCTIONALITY);}
	| LONG {$$ = NULL; error("LONG", UNSUPPORTED_FUNCTIONALITY);}
	| DOUBLE {$$ = NULL; error("DOUBLE", UNSUPPORTED_FUNCTIONALITY);}
	| SIGNED {$$ = NULL; error("SIGNED", UNSUPPORTED_FUNCTIONALITY);}
	| UNSIGNED {$$ = NULL; error("UNSIGNED", UNSUPPORTED_FUNCTIONALITY);}
	| enum_specifier {$$ = NULL;error("ENUM", UNSUPPORTED_FUNCTIONALITY);}
	| TYPE_NAME { $$ = NULL;} //TODO: unknown use -- struct name
	;

inden_marker
	: {
		node* temp = makeDeadNode();
		temp->lexeme = yylval.id;
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
		gSymTable->structMap[$3->lexeme] = structNode;

		$$ = struct_or_union_specifier($1,name);	
	} 
	| struct_or_union '{' struct_declaration_list '}' {cout << "488 feature not included"<< endl; $$ = NULL;} // segfault will come whenever this will be running
	| struct_or_union  IDENTIFIER {
		string name(previ); //TODO: wrong name, uses previ
		
		if(!structLookUp(gSymTable, name)) { // Recursive lookup
			if(!structLookUp(gSymTable, string(yylval.id))){
				error(name, STRUCT_NOT_DECLARED);
			}
			else{
				name = yylval.id;
			}
		}
		$$ = struct_or_union_specifier($1, name);
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
		// node* specifier_qualifier_list = $1;
		// node* struct_declarator_list = $2;
		// $$ = specifier_qualifier_list;
		$$ = struct_declaration($1, $2);
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
	| ':' constant_expression {$$ = NULL;} //TODO: Later, dont know meaning
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
	: ENUM '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup("enum"), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER '{' enumerator_list '}' { $$ = makeNode(strdup("ENUM"), strdup("enum"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, $4, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER { $$ = (node*)NULL;}
	;

enumerator_list
	: enumerator { $$ = $1; }
	| enumerator_list ',' enumerator { if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;} 
	;

enumerator
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| IDENTIFIER '=' constant_expression {$$ = makeNode(strdup("="),strdup("="), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
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
		currDecl = $$;
	}
	| direct_declarator { $$ = $1; currDecl = $$; }
	;

direct_declarator
	// can be both in struct, or a declaration
	: IDENTIFIER { 
		$$ = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		$$-> infoType = INFO_TYPE_NORMAL;
		$$->lineNo = line+1;
		$$->addr = yylval.id;
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
		$$ = parameter_declaration($1, $2);
	}
	| declaration_specifiers abstract_declarator { 
		//TODO: difference in abstract_declarator and declarator
		$$ = parameter_declaration($1, $2);
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
		 $$ = makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| identifier_list ',' IDENTIFIER { 
		makeSibling(makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

type_name
	: specifier_qualifier_list { $$ = $1; }
	| specifier_qualifier_list abstract_declarator {
		if($1){makeSibling($2,$1);}
		node *temp = $1;
		if($2->declSp) {
			int err = addTypeToDeclSpec(temp, $2->declSp->type);
			if(err) error("addTypeToDeclSpec", err); //Error handling according to error code passed
			// err = addStorageClassToDeclSpec(temp, $2->declSp->storageClassSpecifier);
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
	: labeled_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	| compound_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	| expression_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	| selection_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	| iteration_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	| jump_statement { 
		$$ = $1;
		vector<int> tmp = mergelist($1->truelist, $1->falselist);
		$$->nextlist = mergelist(tmp, $1->nextlist);
		$$->breaklist = $1->breaklist;
		$$->continuelist = $1->continuelist;
	}
	;

labeled_statement
	: IDENTIFIER ':' statement {
		$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);
		$$->breaklist = $3->breaklist;
		$$->continuelist = $3->continuelist;
	}
	| CASE constant_expression {
		// ifgoto
		vector<int> next = makelist(nextQuad());
		emit(OP_IFNEQGOTO, case_consts[case_consts.size()-1]->addr, $2->addr, BLANK_STR);
		// This should go to next case
		$2->nextlist = mergelist($2->nextlist, next);
	} ':' statement {
		// Add goto to nextlist of $$ if not equal
		$$ = makeNode(strdup("CASE"), strdup("case"), 0, $2, $5, (node*)NULL, (node*)NULL);
		$$->nextlist = mergelist($2->nextlist, $5->nextlist);
		
		$$->breaklist = $5->breaklist;
		$$->continuelist = $5->continuelist;
	}
	| DEFAULT ':' statement {
		$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);
		$$->breaklist = $3->breaklist;
		$$->nextlist = $3->nextlist;
		$$->continuelist = $3->continuelist;
	}
	;

compound_statement
	: scope_marker '{' '}' { $$ = (node*)NULL; gSymTable = gSymTable->parent;}
	| scope_marker '{' statement_list '}' {
		$$ = $3; gSymTable = gSymTable->parent;
		$$->breaklist = $3->breaklist;	
		$$->continuelist = $3->continuelist;
	}
	| scope_marker '{' declaration_list '}' {  $$ = $3; gSymTable = gSymTable->parent;}
	| scope_marker '{' declaration_list statement_list '}' { 
		if($3){
			$$ = makeNode(strdup("BODY"), strdup("body"), 0, $3, $4, (node*)NULL, (node*)NULL);}
		else{
			$$ = $4;
		}
		gSymTable = gSymTable->parent;
		$$->breaklist = $4->breaklist;	
		$$->continuelist = $4->continuelist;
	}
	;

scope_marker
    : { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}

declaration_list
	: declaration { $$ = $1;}
	| declaration_list declaration {
		// node* temp = NULL;
		// string s($1->name);
		// bool c1  = (s == "DECL_LIST");
		// if( c1 ){ 
		// 	temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, $1->childList, $2, (node*)NULL, (node*)NULL);
		// } else {
		// 	temp = makeNode(strdup("DECL_LIST"), strdup("declaration list"), 0, $1, $2, (node*)NULL, (node*)NULL);
		// }
		// for(auto &u : $2->paramList){
		// 	temp->paramList.push_back(u);
		// }
		// for(auto &u : $1->paramList){
		// 	temp->paramList.push_back(u);
		// }
		// $$ = temp;
		$$ = declaration_list($1, $2);
	}
	;

statement_list
	: statement { $$ = $1; }
	| statement_list M_marker statement { 
		node * temp;
		if(!strcmp(($1 -> name), "STMT_LIST")){
			temp = makeNode(strdup("STMT_LIST"), strdup("statement list"), 0, $1 -> childList, $2, (node*)NULL, (node*)NULL);
		} else{ 
			temp = makeNode(strdup("STMT_LIST"), strdup("statement list"), 0, $1, $2, (node*)NULL, (node*)NULL);
		}
		backpatch($1->nextlist, $2->quad);
		
		temp->nextlist = $3->nextlist;
		temp->breaklist = mergelist($1->breaklist, $3->breaklist);
		temp->continuelist = mergelist($1->continuelist, $3->continuelist);
		$$=temp;
	}
	;

expression_statement
	: ';' {$$ = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| expression ';' {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;


expressionJump
	: expression { 
		$$ = $1; 
		if(!$$->truelist.size()) {
			$$->truelist = makelist(nextQuad());
    		$$->falselist = makelist(nextQuad()+1);
			emit(OP_IFGOTO, $1->addr, EMPTY_STR, BLANK_STR);
    		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
		}
	}
	;

expressionJumpStatement
	: ';' {$$ = makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| expressionJump ';' {makeSibling(makeNode(strdup(";"), strdup(";"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;


selection_statement
	: IF '(' expressionJump  ')' M_marker statement {
		backpatch($3->truelist, $5->quad);
		node * temp = makeNode(strdup("IF"), strdup("if"),0, $3, $6, (node*)NULL, (node*)NULL);
		temp->nextlist = mergelist($3->falselist, $6->nextlist);
		temp->breaklist = $6->breaklist;
		temp->continuelist = $6->continuelist;
		$$ = temp;
	}
	| IF  '(' expressionJump  ')' M_marker statement ELSE N_marker M_marker statement {
		backpatch($3->truelist, $5->quad);
		backpatch($3->falselist, $9->quad);
		node* temp = makeNode(strdup("IF_ELSE"), strdup("else"),0, $3, $6, $10, (node*)NULL);
		vector<int> tempVec = mergelist($6->nextlist, $8->nextlist);
		temp->nextlist = mergelist(tempVec, $10->nextlist);
		temp->breaklist = mergelist($5->breaklist, $10->breaklist);
		temp->continuelist = mergelist($5->continuelist, $10->continuelist);
		$$ = temp;
	}
	| SWITCH '(' expressionJump {case_consts.push_back($3);} ')' statement {
		$6->addr = $3->addr;
		$$ = makeNode(strdup("SWITCH"), strdup("switch"),0, $3, $6, (node*)NULL, (node*)NULL);
		$$->nextlist = mergelist($6->breaklist, $6->nextlist);
		$$->nextlist = mergelist($$->nextlist, $3->nextlist);
		$$->continuelist = $6->continuelist;
		case_consts.pop_back();
	}	
	;


iteration_statement
	: WHILE '(' M_marker expressionJump ')' M_marker statement {
		node *m1 = $3, *m2 = $6, *s1 = $7, *e1 = $4;
		backpatch(s1->nextlist, m1->quad);
		backpatch(e1->truelist, m2->quad);
		backpatch(s1->continuelist, m1->quad);

		$$ = makeNode(strdup("WHILE"), strdup("while"), 0, $4, $7, (node*)NULL, (node*)NULL);
		
		$$->nextlist = mergelist(s1->breaklist, e1->falselist);
		emit(OP_GOTO, BLANK_STR, BLANK_STR, to_string(m1->quad));
	}
	| DO M_marker statement WHILE '(' M_marker expressionJump ')' ';' {
		node* s1 = $3, *e1 = $7, *m2 = $2, *m1 = $6;
		backpatch(s1->nextlist, m1->quad);
		backpatch(e1->truelist, m2->quad);
		backpatch(s1->continuelist, m1->quad);
		
		$$ = makeNode(strdup("DO WHILE"), strdup("do while"), 0, $3, $7, (node*)NULL, (node*)NULL);
		
		$$->nextlist = mergelist(s1->breaklist, e1->falselist);
		emit(OP_GOTO, BLANK_STR, BLANK_STR, to_string(m2->quad));
	}
	| FOR '(' expression_statement M_marker expressionJumpStatement ')' M_marker statement {
		node *e1 = $3, *m1 = $4, *e2 = $5, *m3 = $7, *s1 = $8;
		emit(OP_GOTO, BLANK_STR, BLANK_STR, to_string(m1->quad));
		backpatch(e2->truelist, m3->quad);
		backpatch(s1->continuelist, m1->quad);
		backpatch(s1->nextlist, m1->quad);
		
		$$ = makeNode(strdup("FOR"), strdup("for"),0, $3, $5, $8, (node*)NULL);
		$$->nextlist = mergelist(s1->breaklist, e2->falselist);
	}
	| FOR '(' expression_statement M_marker expressionJumpStatement M_marker expression N_marker ')' M_marker statement {
		node *e1 = $3, *m1 = $4, *e2 = $5, *m2 = $6, *e3 = $7, *n1 = $8, *m3 = $10, *s1 = $11;
		emit(OP_GOTO, BLANK_STR, BLANK_STR, to_string(m2->quad));
		backpatch(n1->nextlist, m1->quad);
		backpatch(e2->truelist, m3->quad);
		backpatch(s1->continuelist, m2->quad);
		backpatch(s1->nextlist, m2->quad);

		$$ = makeNode(strdup("FOR"), strdup("for"),0, $3, $5, $7, $11);
		$$->nextlist = mergelist(s1->breaklist, e2->falselist);
	}
	;


jump_statement
	: GOTO IDENTIFIER ';' {$$ = makeNode(strdup("GOTO"), strdup("goto"), 0, makeNode(strdup("IDENTIFIER"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
	| CONTINUE ';'{ 
		$$ = makeNode(strdup("CONTINUE"), strdup("continue"),1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->continuelist = makelist(nextQuad());
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
	}
	| BREAK ';' { 
		$$ = makeNode(strdup("BREAK"), strdup("break"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->breaklist = makelist(nextQuad());
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
	}
	| RETURN ';' { 
		symbolTableNode* funcNode = lookUp(gSymTable, currFunc);
		if(funcNode == nullptr){ // Not in func
			error("Return statement not in function", DEFAULT_ERROR);
		}

		int err = checkVoidSymbol(funcNode);
		if(err){
			error("Function type not void", err);
		}
		
		$$ = makeNode(strdup("RETURN"), strdup("return"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		emit(OP_RETURN, BLANK_STR, BLANK_STR, BLANK_STR);
	}
	| RETURN expression ';' { 
		symbolTableNode* funcNode = lookUp(gSymTable, currFunc);
		if(funcNode == nullptr){ // Not in func
			error("Return statement not in function", DEFAULT_ERROR);
		}
		
		node* temp = $2;
		// symbolTableNode* n1 = funcNode;
		int err = canTypecast(funcNode->declSp, temp->declSp);;
		if(err) error("return type isnt valid", err);
		node* n1 = new node();
		n1->declSp = declSpCopy(funcNode->declSp);
		n1->addr = temp->addr;
		err = giveTypeCastRankUnary(n1, temp);
		if(err) error("error n typecasting", err);
		// temp->addr = n1->addr;
		$$ = makeNode(strdup("RETURN"), strdup("return"), 0, temp, (node*)NULL, (node*)NULL, (node*)NULL);
		emit(OP_RETURN, BLANK_STR, BLANK_STR, temp->addr);
    }
	;

translation_unit
	: external_declaration { $$ = $1; root = $$; }
	| translation_unit external_declaration {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; root = $$;}
	;

external_declaration
	: function_definition {
		$$ = $1; 
		emit(OP_ENDFUNC, BLANK_STR, BLANK_STR, BLANK_STR);}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers  declarator {
		// TODO: Send type from declaration specifier to function name
		struct node* declarator = $2; 
		struct node* declaration_specifiers = $1;
		addFunctionSymbol(declaration_specifiers, declarator);

		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		// Adding params to symtab
		symbolTable* curr = gSymTable;
		int tempOffset = 0;
		for(auto &p: declarator->paramList){
			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
			if(retVal) {
				error(p->paramName, retVal);
			}
			string lex = p->paramName;
			cout << lex << endl;
			
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			
			sym_node->declSp = declSpCopy(p->declSp);
			sym_node->size = getNodeSize(sym_node, gSymTable);
			tempOffset += getOffsettedSize(sym_node->size);
		}
		for(auto &p: declarator->paramList){
			string lex = p->paramName;	
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			sym_node->offset = (-1*tempOffset);
			tempOffset = tempOffset-getOffsettedSize(sym_node->size);
		}
		offset = 0;
	} declaration_list compound_statement { 
		addChild($2, $4); 
		addChild($2, $5); 
	 	
		node* declaration_specifiers = $1; // type
		node* declarator = $2; // func , param list
		
		for(auto &u: $4->paramList){
			$2->paramList.push_back(u);
		}

		$$ = $2;
		currFunc = "#prog"; // Back to main program
	}
	| declaration_specifiers  declarator {
		// TODO: Send type from declaration specifier to function name
		struct node* declarator = $2; 
		struct node* declaration_specifiers = $1;
		addFunctionSymbol(declaration_specifiers, declarator);

		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		// Adding params to symtab
		symbolTable* curr = gSymTable;
		int tempOffset = 0;

		for(auto &p: declarator->paramList){
			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
			if(retVal) {
				error(p->paramName, retVal);
			}
			string lex = p->paramName;
			cout << lex << endl;
			
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			if(!sym_node){
				error(lex, ALLOCATION_ERROR);
			}
			// emit(OP_PUSHPARAM, EMPTY_STR, EMPTY_STR, lex);
			sym_node->declSp = declSpCopy(p->declSp);
			sym_node->size = getNodeSize(sym_node, gSymTable);
			tempOffset += getOffsettedSize(sym_node->size);
		}
		
		string labelName = "_" + string(declarator->lexeme);
		emit(OP_LABEL, BLANK_STR, BLANK_STR, labelName);
    //TODO: backpatch 
    // emit(OP_BEGINFUNC, BLANK_STR, BLANK_STR, EMPTY_STR); // GCC will set the global variable offset
		
		for(auto &p: declarator->paramList){
			string lex = p->paramName;	
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			sym_node->offset = (-1*tempOffset);
			tempOffset = tempOffset-getOffsettedSize(sym_node->size);
		}
		offset = 0;
	} compound_statement { 
		addChild($2, $4);
		$$ = $2;
		currFunc = "#prog";
	}
	| declarator func_marker_1 declaration_list compound_statement { 
		addChild($1, $3); 
		addChild($1, $4);
		node* declarator = $1; // func , param list
		
		for(auto &u: $3->paramList){
			$1->paramList.push_back(u);
		}
		$$ = $1;
		currFunc = "#prog";
	}
	| declarator func_marker_1 compound_statement { 
		addChild($1, $3);
		$$ = $1;
		currFunc = "#prog";
	}
	;


func_marker_1
	: {
		// Send type from declaration specifier to function name
		struct node* declarator = currDecl;
		addFunctionSymbol(NULL, declarator);

		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		// Adding params to symtab
		symbolTable* curr = gSymTable;
		int tempOffset = 0;
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
			
			sym_node->declSp = declSpCopy(p->declSp);
			sym_node->size = getNodeSize(sym_node, gSymTable);
			tempOffset += getOffsettedSize(sym_node->size);
		}
    

		string labelName = "_" + string(declarator->lexeme);
		emit(OP_LABEL, labelName, BLANK_STR, BLANK_STR);
    //TODO: backpatch offset
		// emit(OP_BEGINFUNC, BLANK_STR, BLANK_STR, EMPTY_STR); // GCC will set the global variable offset 

		for(auto &p: declarator->paramList){
			string lex = p->paramName;	
			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
			sym_node->offset = (-1*tempOffset);
			tempOffset = tempOffset-getOffsettedSize(sym_node->size);
		}
		offset = 0;

	}
	;

M_marker:
 	{
		node* temp = makeDeadNode();
		temp->quad = nextQuad();
		$$ = temp;
	}
	;
N_marker:
 	{
		node* temp = makeDeadNode();
		temp->nextlist = makelist(nextQuad());
		emit(OP_GOTO, BLANK_STR, BLANK_STR, EMPTY_STR);
		$$ = temp;
	}
	;
// func_marker_2
// 	: {
// 		// TODO: Send type from declaration specifier to function name
// 		struct node* declarator = currDecl; 
// 		struct node* declaration_specifiers = currDeclSpec;
// 		addFunctionSymbol(declaration_specifiers, declarator);

// 		funcDecl = 1;
// 		gSymTable = addChildSymbolTable(gSymTable);
// 		// Adding params to symtab
// 		symbolTable* curr = gSymTable;

// 		for(auto &p: declarator->paramList){
// 			int retVal = insertSymbol(curr, declarator->lineNo, p->paramName);
// 			if(retVal) {
// 				error(p->paramName, retVal);
// 			}
// 			string lex = p->paramName;
			
// 			struct symbolTableNode* sym_node = curr->symbolTableMap[lex];
// 			if(!sym_node){
// 				error(lex, ALLOCATION_ERROR);
// 			}
			
// 			sym_node->declSp = declSpCopy(p->declSp);
// 		}
// 	}

%%
#include <stdio.h>

using namespace std;

int main(int ac, char **av) {
	// insert_into_sets();
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror(" Error: ");
            return (-1);
        }
        yyset_in(fd);
        
        // Make the first symbol table with global scope
		gSymTable = new symbolTable();
		gTempSymbolMap = new symbolTable();
		if(!gSymTable) {
			printf("ERROR: Cannot allocate global symbol table\n");
			return 1;
		}

		if(!gTempSymbolMap) {
			printf("ERROR: Cannot allocate global temp symbol table\n");
			return 1;
		}
		gSymTable->scope = gScope++;
		gSymTable->parent = nullptr;
		gTempSymbolMap->parent = nullptr;
        yyparse();
		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
		char * fileName = strdup("graph.dot");
		if(ac == 3) fileName = av[2];
		generateDot(root,fileName);
		
		// printSymbolTableJSON(gSymTable,0);
		printSymbolTable(gSymTable);
        printCode();
		fclose(fd);
    }
    else
        printf("Usage: a.out input_filename [optional]ouput.dot \n");

	return 0; 
}


extern int column;
void yyerror(const char* s)
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}
