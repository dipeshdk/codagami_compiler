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
			constant inden_marker func_marker_1 M_marker N_marker expressionJump expressionJumpStatement conditional_marker logical_or_expressionJumpStatement

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
	int rbp_size = 16;
	stack<string> ternaryTempStack;
	int funcBeginQuad = -1;
	#include <sys/stat.h>
	#include <sys/types.h>
	stack<string> arrayInFuncParam;
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

primary_expression
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
		if(gSymTable->scope != GLOBAL_SCOPE_NUM)
			error(yylval.id, NON_GLOBAL_STRING_LITERAL);
		node* temp = makeNode(strdup("STRING_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		if(!temp->declSp) temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_STRING_LITERAL);
		temp->addr = string(yylval.id);
		temp->isConstant = true;
		temp->isStringLiteral=true;
		$$ = temp;
		;
	}
	| CHAR_LITERAL {
		string name = yylval.id;
		char c;
		if(name.size() == 4 && name[1] == '\\') {
			switch (name[2])
            {
            case '\\':
				c = '\\';
				break;

            case 'r':
				c = '\r';
				break;

            case 'n':
				c = '\n';
				break;

            case 't':
				c = '\t';
				break;

            case 'v':
				c = '\v';
				break;

            case 'a':
				c = '\a';
				break;
			case '0':
				c = '\0';
				break;
			}
		}else if(name.size() == 3) {
			c = name[1];
		}else {
			error( yylval.id, NOT_A_CHAR);
		}
		node* temp = makeNode(strdup("CHAR_LITERAL"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		if(!temp->declSp) temp->declSp = new declSpec();
		temp->declSp->type.push_back(TYPE_CHAR);
		temp->valType = TYPE_CHAR;
		setAddr(temp, to_string((int)c));
		temp->isConstant = true;
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
		temp->isConstant = true;
		$$ = temp;
	}
	| F_CONSTANT {
		string s = yylval.id;
		node* temp = makeNode(strdup("CONSTANT"), strdup(yylval.id), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
		if(!temp->declSp) temp->declSp = new declSpec();

		if(gSymTable->scope != GLOBAL_SCOPE_NUM) {
			string globalFloatAddr = getGlobalFloatAddr();
			sendFloatToGlobal(string(yylval.id), globalFloatAddr);
			setAddr(temp, globalFloatAddr);
		}else {
			addFVal(temp, yylval.id);
			setAddr(temp, string(yylval.id));
			temp->isConstant = true;
		}
		temp->declSp->type.push_back(TYPE_FLOAT);
		$$ = temp;
	}
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' {
		node *postfix_expression = $1;
		node *expression = $3;
		int asize = getValueFromConstantExpression($3, errCode);
		if(asize < 0){
			error($1->lexeme , ARRAY_INDEX_SHOULD_BE_POSITIVE);
		}
		addChild(postfix_expression, expression);
		postfix_expression->infoType = INFO_TYPE_ARRAY;
		postfix_expression->arrayIndices.push_back($3);
		$$ = postfix_expression;
	}
	| postfix_expression '(' ')' {
		string func_name($1->lexeme);
		if(!($1->paramList.size() == 0 
			|| ($1->paramList.size()==1 && $1->paramList[0]->declSp 
				&& $1->paramList[0]->declSp->type.size() == 1
				&& $1->paramList[0]->declSp->type[0] == TYPE_VOID) ))	
			error(func_name, INVALID_ARGS_IN_FUNC_CALL);
		string name = $1->lexeme;
		symbolTableNode* stNode = lookUp(gSymTable, name);
		if(!stNode || stNode->infoType != INFO_TYPE_FUNC || !stNode->declSp) {
			error(name, SYMBOL_NOT_FOUND);
		}
		string retTemp = checkFuncArgValidityWithParamEmit($1, nullptr, errCode, errStr);
		if(errCode) error(errStr, errCode);
		$1->infoType = INFO_TYPE_FUNC;
		$$ = $1;	
		$$->addr = retTemp;
	}
	| postfix_expression '(' argument_expression_list ')' {
		string retTemp = checkFuncArgValidityWithParamEmit($1, $3, errCode, errStr);
		if(errCode) error(errStr, errCode);
		$1->infoType = INFO_TYPE_FUNC;
		addChild($1,$3);
		$$ = $1;
		$$->addr = retTemp;

	}
	| postfix_expression '.' IDENTIFIER { 
        // array of structs 
        if($1->infoType == INFO_TYPE_ARRAY){
			errCode = 0;
			string arrayIndexStr = getArrayIndexWithEmit($1, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$1->addr = arrayIndexStr;
			$1->declSp->ptrLevel--;
		}

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
		newNode->infoType = INFO_NESTED_STRUCT; //can come here even if it is an array.
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
		errStr = "use ++" + string($1->lexeme)+ " instead of " + string($1->lexeme) + "++";
		error(errStr.c_str(), UNSUPPORTED_FUNCTIONALITY);
		$$ = $1;
	}
	| postfix_expression DEC_OP {
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
	: postfix_expression {
		if($1->infoType == INFO_TYPE_ARRAY){
			errCode = 0;
			string arrayIndexStr = getArrayIndexWithEmit($1, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$1->addr = arrayIndexStr;
			$1->declSp->ptrLevel--;
		}
		$$ = $1;
	}
	| INC_OP unary_expression {
		int retval  = checkIntOrCharOrPointer($2);
		if(retval) error($2->lexeme, retval);
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Cannot generate Temp",DEFAULT_ERROR);
		int opCode = getOpAddType($2, errCode, errStr);
		if(errCode)
			error($2->lexeme,errCode);
        emit(opCode, $2->addr, "1", newTmp);
    	emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, $2->addr);
		addTempDetails(newTmp, gSymTable, $2);
		$$ = makeNode(strdup("INC_OP"), strdup("++"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp = declSpCopy($2->declSp);
		$$->addr = $2->addr;
	}
	| DEC_OP unary_expression {
		int retval  = checkIntOrCharOrPointer($2);
		if(retval) error($2->lexeme, retval);
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Cannot generate Temp",DEFAULT_ERROR);
		int opCode = getOpSubType($2, errCode, errStr);
		if(errCode)
			error($2->lexeme,errCode);
        emit(opCode, $2->addr, "1", newTmp);
    	emit(OP_ASSIGNMENT, newTmp, EMPTY_STR, $2->addr);
		addTempDetails(newTmp, gSymTable, $2);
		$$ = makeNode(strdup("DEC_OP"), strdup("--"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp = declSpCopy($2->declSp);
		$$->addr = $2->addr;
	}
	| unary_operator cast_expression {
		node* unary_operator = $1;
		node* cast_expression = $2;
		string name(unary_operator->name);
		unary_operator->declSp = cast_expression->declSp;

		if(isConstantNode(cast_expression)) {
			if(isStringLiteral(cast_expression)) {
				error("unary operations of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr(cast_expression->addr);
			int res;
			node* constTemp = makeNode(strdup("CONSTANT"), strdup("CONSTANT"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			if(name == "*"){
				error(cast_expression->name, NON_POINTER_DEFERENCE);
			}
			else if(name == "&") {
				error(cast_expression->name, NON_POINTER_DEFERENCE);
			}
			else if(name == "-") {
				res = -n1;
			}
			else if(name == "~") {
				res = ~n1;
			}
			else if(name == "!") {
				res = !n1;
				constTemp->truelist = cast_expression->falselist;
				constTemp->falselist = cast_expression->truelist;
			}
			string resStr = to_string(res);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->lexeme = (char*)resStr.c_str();
			constTemp->nextlist = cast_expression->nextlist;
			constTemp->continuelist = cast_expression->continuelist;
			constTemp->breaklist = cast_expression->breaklist;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			int opCode = -1;
			if(name == "*"){
				if(!(cast_expression->infoType == INFO_TYPE_ARRAY || (cast_expression->declSp && cast_expression->declSp->ptrLevel > 0)))
					error(cast_expression->name, NON_POINTER_DEFERENCE);
				unary_operator->addr = "*(" + cast_expression->addr + ")";
				unary_operator->declSp->ptrLevel--;
			}
			else if(name == "&") {
				opCode = OP_ADDR;
				unary_operator->declSp->ptrLevel++;
			}
			else if(name == "-") {
				if(cast_expression->declSp && cast_expression->declSp->type[0]== TYPE_FLOAT) opCode = OP_UNARY_MINUSF;
				else opCode = OP_UNARY_MINUS;
			}
			else if(name == "~") {
				opCode = OP_BITWISE_NOT;
				//type should be int or char
				bitwiseTypecastingSingleNode(cast_expression, errCode, errStr);
				if(errCode)
					error(errStr, errCode);
			}
			else if(name == "!") {
				opCode = OP_LOGICAL_NOT;
				unary_operator->truelist = cast_expression->falselist;
				unary_operator->falselist = cast_expression->truelist;
			}
			// nothing to do for unary plus

			if(opCode != -1) {
				string newTmp = generateTemp(errCode);
				if(errCode)
					error("Internal Error : Cannot generate Temp", DEFAULT_ERROR);
				emit(opCode, cast_expression->addr, EMPTY_STR, newTmp);
				unary_operator->addr = newTmp;
				addTempDetails(newTmp, gSymTable, unary_operator);
			}

			addChild(unary_operator, cast_expression);
			unary_operator->nextlist = cast_expression->nextlist;
			unary_operator->continuelist = cast_expression->continuelist;
			unary_operator->breaklist = cast_expression->breaklist;
			$$ = unary_operator;
		}
	}
	| SIZEOF unary_expression {
		if(strcmp(($2 -> name), "IDENTIFIER")){
			error("Argument to sizeof must be identifier", DEFAULT_ERROR);
		}
		symbolTableNode* sym_node = lookUp(gSymTable, $2->lexeme);
		if(!sym_node){
			error($2->lexeme, UNDECLARED_SYMBOL);
		}
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Internal Error : Cannot generate Temp",DEFAULT_ERROR);
    	emit(OP_ASSIGNMENT, to_string(getNodeSize(sym_node, gSymTable)), EMPTY_STR, newTmp);
		
		$$ = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp->type.push_back(TYPE_INT);
		sym_node = lookUp(gSymTable, newTmp);
		sym_node->size = 8;
		sym_node->offset = offset;
		sym_node->declSp->type.push_back(TYPE_INT);
		offset += 8;
		$$->addr = newTmp;
	}
	| SIZEOF '(' type_name ')'{
		string newTmp = generateTemp(errCode);
    	if(errCode)
        	error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
    	symbolTableNode* sym_node = new symbolTableNode();
		sym_node->declSp = declSpCopy($3->declSp);
		sym_node->infoType = $3->infoType;
		emit(OP_ASSIGNMENT, to_string(getNodeSize(sym_node, gSymTable)), EMPTY_STR, newTmp);
		
		$$ = makeNode(strdup("SIZEOF"), strdup("sizeof"), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);
		$$->declSp->type.push_back(TYPE_INT);
		sym_node = lookUp(gSymTable, newTmp);
		sym_node->size = 8;
		sym_node->offset = offset;
		sym_node->declSp->type.push_back(TYPE_INT);
		offset += 8;
		$$->addr = newTmp;
	}

		

	;

unary_operator
	: '&' {$$ = makeNode(strdup("&"), strdup("&"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' {$$ = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '+' {$$ = makeNode(strdup("+"), strdup("+"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
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
		if(err) error("Typecasting error", DEFAULT_ERROR);
		typeCastLexemeWithEmit(cast_expression, type_name->declSp);
		makeSibling(cast_expression, type_name);
		$$ = cast_expression;
	}
	;

multiplicative_expression
	: cast_expression {$$ = $1; }
	| multiplicative_expression '*' cast_expression { 
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("multiplication of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1*n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "*", errCode, errStr); 
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			int opCode = getOpMulType(temp, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			emit(opCode, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	| multiplicative_expression '/' cast_expression { 
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("division of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1/n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "/", errCode, errStr); 
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			int opCode = getOpDivType(temp, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			emit(opCode, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	| multiplicative_expression '%' cast_expression { 
		int retval = checkType($3->declSp,TYPE_FLOAT,0);
		if(retval){
			error($3->lexeme, SHOULD_NOT_BE_FLOAT);
		}

		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("mod of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1%n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "%", errCode, errStr); 
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			emit(OP_MOD, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { 
		
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("addition of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1+n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		} else {
			node* temp = makeNodeForExpressionNotStringForAddition($1, $3, "+", errCode, errStr); 
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy(temp->declSp);
			int opCode = getOpAddType(temp, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			emit(opCode, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			// temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, temp);
			$$ = temp;
		}
	}
	| additive_expression '-' multiplicative_expression { 
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("subtraction of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1-n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "-", errCode, errStr); 
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			int opCode = getOpSubType(temp, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			emit(opCode, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { 
		int retval = checkIntOrChar($3);
		if(retval)	error($3->lexeme, TYPE_ERROR);
		retval = checkIntOrChar($1);
		if(retval)	error($1->lexeme, TYPE_ERROR);
		
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("left shift of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1 << n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		} else {	
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, "<<", errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			emit(OP_LEFT_SHIFT, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		} 
	}
	| shift_expression RIGHT_OP additive_expression { 
		int retval = checkIntOrChar($3);
		if(retval)	error($3->lexeme, TYPE_ERROR);
		retval = checkIntOrChar($1);
		if(retval)	error($1->lexeme, TYPE_ERROR);
		
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("right shift of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1 >> n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		} else {
			node* temp = makeNodeForExpressionNotPointerNotString($1, $3, ">>", errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate Temp",DEFAULT_ERROR);
			symbolTableNode* tempNode= lookUp(gSymTable, newTmp);
			tempNode->declSp = declSpCopy($1->declSp);
			emit(OP_RIGHT_SHIFT, $1->addr, $3->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { 
			int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
			if(retval < 0)
				error(errStr,-retval);			
			node* temp = makeNode(strdup("<"), strdup("<"), 0, $1, $3, (node*)NULL, (node*)NULL); 
			emitRelop($1, $3, temp, OP_LESS, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$$ = temp;
		}
	| relational_expression '>' shift_expression { 
			int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
			if(retval < 0)
				error(errStr,-retval);
			node* temp = makeNode(strdup(">"), strdup(">"), 0, $1, $3, (node*)NULL, (node*)NULL); 
			emitRelop($1, $3, temp, OP_GREATER, errCode, errStr);
			if(errCode)
				error(errStr, errCode);
			$$ = temp;
	}
	| relational_expression LE_OP shift_expression {
		int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
		if(retval < 0)
			error(errStr,-retval);
		node* temp = makeNode(strdup("LE_OP"), strdup("<="), 0, $1, $3, (node*)NULL, (node*)NULL);
		emitRelop($1, $3, temp, OP_LEQ, errCode, errStr);
		if(errCode)
			error(errStr, errCode);
		$$ = temp;
	}
	| relational_expression GE_OP shift_expression { 
		int retval = implicitTypecastingNotStringLiteral($1, $3, errStr);
		if(retval < 0)
			error(errStr,-retval);
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
			error($3->lexeme, POINTER_ERROR);

		int rank = giveTypeCastRank(equality_expression, relational_expression);
		if(rank < 0)
			error($3->lexeme, rank);
		int retval = typeCastByRank(equality_expression, relational_expression, rank);
		if(retval)
			error($3->lexeme, retval);
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
			error($3->lexeme, POINTER_ERROR);

		int rank = giveTypeCastRank(equality_expression, relational_expression);
		if(rank < 0)
			error($3->lexeme, rank);
		int retval = typeCastByRank(equality_expression, relational_expression, rank);
		if(retval)
			error($3->lexeme, retval);
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
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("logical and of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1 & n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else{
			node* temp = makeNode(strdup("&"), strdup("&"), 0, and_expression, equality_expression, (node*)NULL, (node*)NULL);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate temp", DEFAULT_ERROR);
			emit(OP_AND, and_expression->addr, equality_expression->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
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
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("logical xor of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1 ^ n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNode(strdup("^"), strdup("^"), 0, exclusive_or_expression, and_expression, (node*)NULL, (node*)NULL);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate temp", DEFAULT_ERROR);
			emit(OP_XOR, exclusive_or_expression->addr, and_expression->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
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
		if(isConstantNode($1) && isConstantNode($3)) {
			if(isStringLiteral($1) || isStringLiteral($3)) {
				error("logical or of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($3->addr);
			int res = n1 | n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNode(strdup("|"), strdup("|"), 0, inclusive_or_expression1, exclusive_or_expression, (node*)NULL, (node*)NULL);
			string newTmp = generateTemp(errCode);
			if(errCode)
				error("Internal Error: Cannot generate temp", DEFAULT_ERROR);
			emit(OP_OR, inclusive_or_expression1->addr, exclusive_or_expression->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addTempDetails(newTmp, gSymTable, $1);
			$$ = temp;
		}
	}
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP M_marker inclusive_or_expression { 
		int retval = backpatch($1->truelist, $3->quad);
		if(retval)
			error(string($1->lexeme) + "backpatch error", retval);

		if(isConstantNode($1) && isConstantNode($4)) {
			if(isStringLiteral($1) || isStringLiteral($4)) {
				error("&& of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($4->addr);
			int res = n1 && n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->truelist = $4->truelist;
			constTemp->falselist = mergelist($1->falselist, $4->falselist);
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else {
			node* temp = makeNode(strdup("AND_OP"), strdup("&&"), 0, $1, $4, (node*)NULL, (node*)NULL); 
			temp->truelist = $4->truelist;
			temp->falselist = mergelist($1->falselist, $4->falselist);
			string newTmp = generateTemp(errCode);
			if(errCode){
				error("Internal Error: Cannot generate temp", DEFAULT_ERROR);
			}
			emit(OP_ANDAND, $1->addr, $4->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addIntTemp(newTmp, gSymTable);
			$$ = temp;
		}
	}
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP M_marker logical_and_expression { 
		int retval = backpatch($1->falselist, $3->quad);
		if(retval)
			error(string($1->lexeme) + "backpatch error", retval);
		if(isConstantNode($1) && isConstantNode($4)) {
			if(isStringLiteral($1) || isStringLiteral($4)) {
				error("|| of string literals.", UNSUPPORTED_FUNCTIONALITY);
			}
			int n1 = getNumberFromConstAddr($1->addr);
			int n2 = getNumberFromConstAddr($4->addr);
			int res = n1 && n2;
			string resStr = to_string(res);
			node* constTemp = makeNode(strdup("CONSTANT"), (char*)resStr.c_str(), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); 
			constTemp->truelist = mergelist($1->truelist, $4->truelist);
			constTemp->falselist = $4->falselist;
			constTemp->declSp = new declSpec();
			constTemp->declSp->type.push_back(TYPE_INT);
			constTemp->addr = resStr;
			constTemp->isConstant = true;
			constTemp->valType = TYPE_INT;
			$$ = constTemp;
		}else{
			node* temp = makeNode(strdup("OR_OP"), strdup("||"), 0, $1, $4, (node*)NULL, (node*)NULL);  
			temp->truelist = mergelist($1->truelist, $4->truelist);
			temp->falselist = $4->falselist;
			string newTmp = generateTemp(errCode);
			if(errCode){
				error("Internal Error: Cannot generate temp", DEFAULT_ERROR);
			}
			emit(OP_OROR, $1->addr, $4->addr, newTmp);
			temp->addr = newTmp;
			temp->declSp = declSpCopy($1->declSp);
			addIntTemp(newTmp, gSymTable);
			$$ = temp;
		}
	}
	;

logical_or_expressionJumpStatement
	: logical_or_expression {
		$$=$1;
		if(!$$->truelist.size()) {
			$$->truelist = makelist(nextQuad());
    		$$->falselist = makelist(nextQuad()+1);
			emit(OP_IFGOTO, $1->addr, EMPTY_STR, BLANK_STR);
    		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
		}
	}
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expressionJumpStatement '?' M_marker expression conditional_marker N_marker ':' M_marker conditional_expression {
		int retval = backpatch($1->truelist, $3->quad);
		if(retval)
			error(string($1->lexeme) + "backpatch error", retval);
		retval = backpatch($1->falselist, $8->quad);
		if(retval)
			error(string($1->lexeme) + "backpatch error", retval);
		node* temp = makeNode(strdup("?:"), strdup("?:"), 0, $1, $4, $8, (node*)NULL); 
		retval = backpatch($6->nextlist,nextQuad()+1);
		if(retval)
			error(string($6->lexeme) + "backpatch error", retval);
		temp->nextlist = mergelist($4->nextlist, $9->nextlist);
		temp->declSp = declSpCopy($1->declSp);
		emit(OP_ASSIGNMENT, $9->addr, EMPTY_STR, ternaryTempStack.top());
		retval  = backpatchAssignment($5->nextlist, $4->addr);
		if(retval)
			error(string($5->lexeme) + "backpatch error", retval);
		temp->addr = ternaryTempStack.top();
		$$ = temp;
		ternaryTempStack.pop();
		addTempDetails($$->addr, gSymTable, $4);
		}
	;

conditional_marker:
	{
		string ternaryTemp= generateTemp(errCode);
		if(errCode)
        	error("Cannot generate Temp",DEFAULT_ERROR);
		ternaryTempStack.push(ternaryTemp);
    		
		node* temp = makeDeadNode();
		temp->nextlist = makelist(nextQuad());
		emit(OP_ASSIGNMENT, BLANK_STR, EMPTY_STR, ternaryTemp); 
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
		if(unary_expression->name == "CONSTANT"){
			error(unary_expression->lexeme, ASSIGNMENT_TO_CONSTANT_ERROR);
		}
		if(assignment_expression->addr != EMPTY_STR) {
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
					if(checkIntOrChar(unary_expression) !=0){
						error(unary_expression->lexeme, TYPE_ERROR);
					} 
					if(checkIntOrChar(assignment_expression)!=0)
						error(assignment_expression->lexeme, TYPE_ERROR);
				}
				if(s=="MUL_ASSIGN" || s=="DIV_ASSIGN" || s=="ADD_ASSIGN" || s=="SUB_ASSIGN" || s=="=") {
					int retval = canTypecast(assignment_expression->declSp,unary_expression->declSp);
					if(retval)
						error(assignment_expression->lexeme, retval);
				}
				if(s == "MOD_ASSIGN") {
					if(checkType(assignment_expression->declSp, TYPE_FLOAT, 0))
						error(assignment_expression->lexeme, SHOULD_NOT_BE_FLOAT);
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
				if(gSymTable->scope == GLOBAL_SCOPE_NUM && !checkGlobalInitializer(assignment_expression)) {
					error(unary_expression->addr, INVALID_GLOBAL_INITIALIZER);
				}
				if(retval){
					typeCastLexemeWithEmit(assignment_expression, unary_expression->declSp);
				}
				emit(OP_ASSIGNMENT, assignment_expression->addr, EMPTY_STR, unary_expression->addr);
			}
			else
			{
				int rank = giveTypeCastRank(unary_expression, assignment_expression);
				if(rank < 0)
					error(unary_expression->lexeme,-rank);
				
				int retval = typeCastByRank(unary_expression, assignment_expression, rank);
				if(retval)
					error(unary_expression->lexeme,retval);
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
			assignment_operator->nextlist = mergelist(assignment_operator->nextlist, unary_expression->nextlist);
			assignment_operator->nextlist = mergelist(assignment_operator->nextlist, assignment_expression->nextlist);
			addChild(assignment_operator, unary_expression); 
			addChild(assignment_operator, assignment_expression); 
			$$ = assignment_operator;
		}else {
			error("Assignment of return value of a void function" ,UNSUPPORTED_FUNCTIONALITY);
		}
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
	: assignment_expression { $$ = $1; }
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

declaration
	: declaration_specifiers ';' { $$ = $1; }
	| declaration_specifiers init_declarator_list ';' {
		node* curr = $2;
		while(curr){
			node *temp = curr;
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
				param* paramter = new param();
				paramter->infoType = $2->infoType;
				paramter->declSp = declSpCopy($1->declSp);
				paramter->paramName = lex;
				$1->paramList.push_back(paramter);
			}

			if(temp->infoType == INFO_TYPE_FUNC) {
				sym_node->infoType = INFO_TYPE_FUNC;
				sym_node->isDefined = false;
				sym_node->paramSize = temp->paramSize;
				sym_node->paramList = temp->paramList;
				sym_node->declSp = declSpCopy($1->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
			}
			else if(temp->infoType == INFO_TYPE_ARRAY)
			{
				sym_node->infoType = INFO_TYPE_ARRAY;
				sym_node->arraySize = temp->arraySize;
				sym_node->declSp = declSpCopy($1->declSp);
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
				temp->declSp = sym_node->declSp;
				if(temp->arrayIndices.size() != 0){
					int asize = 1;
					vector<int> arrayIndicesTmp;
					for(auto &x: temp->arrayIndices){
						int asizeTmp =  getValueFromConstantExpression(x,errCode);
						if(asizeTmp < 0 || errCode){
							error(x->lexeme, ARRAY_SIZE_NOT_CONSTANT);
						}
						asize *= asizeTmp;
						arrayIndicesTmp.push_back(asizeTmp);
					}
					sym_node->arrayIndices = arrayIndicesTmp;
				}else{
					error(temp->lexeme,INVALID_SYNTAX);
				}
				while(!arrayInFuncParam.empty()){
					addArrayParamToStack(offset, arrayInFuncParam.top(), errCode, errStr);
					arrayInFuncParam.pop();
				}
				if(initializer) {
					//array initializtion
					node *currInit = initializer;
					int ind = 0;
					if(!temp->declSp) 
						error(temp->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);

					int size = getNodeSize(sym_node, gSymTable);
					if(size < 0){
						error(sym_node->name, -size);
					}
					// _t1 = 8;
					string sizeTmp = generateTemp(errCode);
					if(errCode) {
						error("Internal Error: Cannot generate Temp", DEFAULT_ERROR);
					}
					emit(OP_ASSIGNMENT, to_string(size), EMPTY_STR ,sizeTmp);
					symbolTableNode* sym_node = lookUp(gSymTable, sizeTmp);
					sym_node->size = 8;
					sym_node->offset = offset;
					sym_node->declSp->type.push_back(TYPE_INT);
					offset += 8;
					
					while(currInit) {
						string addr = emitArrayIndexGetAddr(temp->addr, to_string(ind), sizeTmp, errCode, errStr);
						if(errCode)
							error(errStr,errCode);
						emit(OP_ASSIGNMENT, currInit->addr, EMPTY_STR ,addr);
						currInit = currInit->next;
						ind++;
					}
				}
			} else {
				sym_node->declSp = declSpCopy($1->declSp);
				sym_node->infoType = $1->infoType;
				if(temp->declSp)
					sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
				if(initializer) {
					if(!checkStringLiteralDecl(initializer->declSp)){
						//global string literal
						sym_node->declSp = declSpCopy($1->declSp);
						if(!temp->declSp) 
							error(temp->addr,INVALID_STRING_LITERAL_ASSIGNMENT);
						sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
						if(!checkType(sym_node->declSp, TYPE_CHAR, 1))
							error(temp->addr, INVALID_STRING_LITERAL_ASSIGNMENT);
						
						globalData *gData = new globalData();
						gData->varName = temp->addr;
						gData->value = initializer->addr;
						gData->valueType = TYPE_STRING_LITERAL;
						globalDataPair.push_back(gData);
					}else {
						//variable initialized
						int retval = canTypecast(sym_node->declSp, initializer->declSp);
						if(retval)
							error(sym_node->name, retval);
						retval = areDifferentTypes(sym_node->declSp, initializer->declSp, errCode, errStr);
						if(errCode)
							error(errStr, errCode);
						if(retval) {
							typeCastLexemeWithEmit(initializer, sym_node->declSp);
						}

						if(gSymTable->scope == GLOBAL_SCOPE_NUM) {
							sym_node->declSp = declSpCopy($1->declSp);
							if(temp->declSp) 
								sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
							
							globalData *gData = new globalData();
							gData->varName = temp->addr;
							gData->value =  hexString(initializer->addr);
							if(initializer->declSp && initializer->declSp->type.size() > 0)
								gData->valueType = initializer->declSp->type[0];
							else
								gData->valueType = TYPE_INT;
							globalDataPair.push_back(gData);
						}else {
							emit(OP_ASSIGNMENT, initializer->addr, EMPTY_STR, temp->addr);
						}
					}			
				}else {
					//no initializer
					if(gSymTable->scope == GLOBAL_SCOPE_NUM) {
						sym_node->declSp = declSpCopy($1->declSp);
						if(temp->declSp) 
							sym_node->declSp->ptrLevel = temp->declSp->ptrLevel;
						
						globalData *gData = new globalData();
						gData->varName = temp->addr;
						gData->value = hexString(to_string(DEFAULT_INITIALIZATION_VALUE));
						gData->valueType = DEFAULT_INITIALIZATION_VALUE_TYPE;
						globalDataPair.push_back(gData);
					}
				}
			}
			sym_node->size = getNodeSize(sym_node, gSymTable);
			sym_node->offset = offset;
			offset += getOffsettedSize(sym_node->size);
			offset += getArraySize(sym_node, gSymTable);
			curr = curr->next;
		}
		makeSibling($2,$1);
		$$ = $1; 
	}
	;

declaration_specifiers
	: storage_class_specifier {$$ = $1; currDeclSpec = $$;}
	| storage_class_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		$$ = temp;
	}
	| type_specifier {
		$$ = $1;
		currDeclSpec = $$;
	} 
	| type_specifier declaration_specifiers {
		if($1){makeSibling($2,$1);} 
		node *temp = $2;
		vector<int> v = $1->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error(" Internal Error: addTypeToDeclSpec", DEFAULT_ERROR); //Error handling according to error code passed
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
	: init_declarator { $$ = $1; }
	| init_declarator_list ',' init_declarator { 
		if($3->infoType == INFO_TYPE_FUNC || $1->infoType == INFO_TYPE_FUNC)
			error("Cannot declare multiple functions in one line", UNSUPPORTED_FUNCTIONALITY);
		if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;
	} 
	;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer { 
		node* declaration_specifiers = currDeclSpec;
		node* declarator = $1;
		node* initializer = $3;
		
		if(declarator->infoType == INFO_TYPE_FUNC)
			error("Cannot assign to a function", UNSUPPORTED_FUNCTIONALITY);

		//TODO: Why?? Should be error?
		if(!declarator->declSp){
			declSpec* ds = new declSpec();
			if(!initializer->declSp){
				error(initializer->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
			}
			ds->type = initializer->declSp->type;
			declarator->declSp = ds;
		}

		if(gSymTable->scope == GLOBAL_SCOPE_NUM && !checkGlobalInitializer($3)) {
			error($1->addr, INVALID_GLOBAL_INITIALIZER);
		}

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
	| struct_or_union '{' struct_declaration_list '}' {$$ = NULL;}
	| struct_or_union  IDENTIFIER {
		string name(previ); // TODO: wrong name, uses previ
		
		if(!structLookUp(gSymTable, name)) {
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
		error("Union type is not supported",UNSUPPORTED_FUNCTIONALITY);
	}
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
		$$ = struct_declaration($1, $2);
	}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {
		if($1){makeSibling($2,$1);}
		node *temp = $2;
		vector<int> v = $1->declSp->type;
		int err = addTypeToDeclSpec(temp, v);
		if(err) error("Internal Error: addTypeToDeclSpec", DEFAULT_ERROR); //Error handling according to error code passed
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
        param->infoType = declarator->infoType;
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		declarator->structParamList.push_back(param);
		$$ = declarator;
	}
	| ':' constant_expression {$$ = NULL;} //TODO: Later, dont know meaning
	| declarator ':' constant_expression {
		node* declarator = $1; 
		structParam* param = new structParam();
        param->infoType = declarator->infoType;
		param->name = declarator->lexeme;
		param->declSp = declarator->declSp;
		int err = 0;
		int ret = getValueFromConstantExpression($3, err);
		if(err) error($3->lexeme, err);
		param->bit = ret;
		declarator->structParamList.push_back(param);
		$$ = declarator;
	}
	;

/* Error is being thrown down in enum specifier as it is the starting production for enum*/
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
	| direct_declarator { 
		node* temp = $1;
		if(temp->infoType == INFO_TYPE_ARRAY){
			temp->declSp->ptrLevel++;
			int asize = 1;
			vector<int> arrayIndicesTmp;
			for(auto &x: temp->arrayIndices){
				int asizeTmp =  getValueFromConstantExpression(x,errCode);
				if(asizeTmp < 0 || errCode){
					error(x->lexeme, ARRAY_SIZE_NOT_CONSTANT);
				}
				asize *= asizeTmp;
				arrayIndicesTmp.push_back(asizeTmp);
			}
			temp->arraySize = asize;
			arrayInFuncParam.push($1->addr);
		}

		currDecl = $$;
		$$ = $1;
	}
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
		int asize = getValueFromConstantExpression($3, errCode);
		if(asize < 0){
			error(temp->lexeme , ARRAY_SIZE_SHOULD_BE_POSITIVE);
		}
		if(errCode){
			error(temp->lexeme, errCode);
		}
		temp->infoType = INFO_TYPE_ARRAY;
		if(!temp->declSp){
			temp->declSp = new declSpec();
		}
		temp->arrayIndices.push_back($3);
		$$ = temp;
	}
	| direct_declarator '[' ']' {
		error($1->lexeme, ARRAY_SIZE_NOT_CONSTANT);
		$$ = NULL;
	}
	| direct_declarator '(' parameter_type_list ')' { 
		//function declaration
		node* direct_declarator = $1;	
		node* parameter_type_list = $3;	
		string funcName($1->lexeme);

		direct_declarator->paramList = parameter_type_list->paramList;
		direct_declarator->paramSize = parameter_type_list->paramSize;
		direct_declarator->infoType = INFO_TYPE_FUNC;
		direct_declarator->addr = funcName;
		$$=direct_declarator;
	}
	| direct_declarator '(' identifier_list ')' { 
		// Not handled: Add to symbol table with appropriate type??, also add to function arguments
		error("Function definition of this type is not supported.", UNSUPPORTED_FUNCTIONALITY);
		$$ = $1;
	}
	| direct_declarator '(' ')' { 
		string funcName($1->lexeme);
		$1->infoType = INFO_TYPE_FUNC;
		$1->addr = funcName;
		$$ = $1;
	}
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
		//TODO: UNHANDLED
		error("ELLIPSIS", UNSUPPORTED_FUNCTIONALITY);
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
		$$ = parameter_declaration($1, $2);
	}
	| declaration_specifiers { 
		node* declaration_specifiers = $1;
		param *parameter = new param();
		if(!declaration_specifiers->declSp) 
			error($1->lexeme, INTERNAL_ERROR_DECL_SP_NOT_DEFINED);
		parameter->declSp = declSpCopy(declaration_specifiers->declSp);
		parameter->paramName = UNNAMED_PARAM;
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
			if(err) error("Internal Error: addTypeToDeclSpec", DEFAULT_ERROR); //Error handling according to error code passed
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
	}
	;

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
		if($2->declSp && $2->declSp->type.size() > 0 && (($2->declSp->type[0] != TYPE_INT) && ($2->declSp->type[0] != TYPE_CHAR))){
			error($2->lexeme, CASE_SHOULD_BE_INT);
		}
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
		copyList($$, $3);
	}
	| scope_marker '{' declaration_list '}' {  $$ = $3; gSymTable = gSymTable->parent; copyList($$, $3);}
	| scope_marker '{' declaration_list statement_list '}' { 
		if($3){
			$$ = makeNode(strdup("BODY"), strdup("body"), 0, $3, $4, (node*)NULL, (node*)NULL);}
		else{
			$$ = $4;
		}
		gSymTable = gSymTable->parent;
		copyList($$, $4);
	}
	;

scope_marker
    : { if(funcDecl == 0) gSymTable = addChildSymbolTable(gSymTable);
		else funcDecl = 0;
	}

declaration_list
	: declaration { $$ = $1;}
	| declaration_list declaration {
		$$ = declaration_list($1, $2);
	}
	;

statement_list
	: statement { $$ = $1; }
	| statement_list M_marker statement { 
		node * temp;
		if(!strcmp(($1->name), "STMT_LIST")){
			temp = makeNode(strdup("STMT_LIST"), strdup("STMT_LIST"), 0, $1->childList, $3, (node*)NULL, (node*)NULL);
		} else{ 
			temp = makeNode(strdup("STMT_LIST"), strdup("STMT_LIST"), 0, $1, $3, (node*)NULL, (node*)NULL);
		}
		int retval = backpatch($1->nextlist, $2->quad);
		if(retval)
			error(string($1->lexeme) + " backpatch error", retval);
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
		int retval = backpatch($3->truelist, $5->quad);
		if(retval)
			error(string($3->lexeme) + " backpatch error", retval);
		node * temp = makeNode(strdup("IF"), strdup("if"),0, $3, $6, (node*)NULL, (node*)NULL);
		temp->nextlist = mergelist($3->falselist, $6->nextlist);
		temp->breaklist = $6->breaklist;
		temp->continuelist = $6->continuelist;
		$$ = temp;
	}
	| IF  '(' expressionJump  ')' M_marker statement ELSE N_marker M_marker statement {
		int retval = backpatch($3->truelist, $5->quad);
		if(retval)
			error(string($3->lexeme) + " backpatch error", retval);
		retval = backpatch($3->falselist, $9->quad);
		if(retval)
			error(string($3->lexeme) + " backpatch error", retval);
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
		int retval = backpatch(s1->nextlist, m1->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);
		retval = backpatch(e1->truelist, m2->quad);
		if(retval)
			error(string(e1->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->continuelist, m1->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);

		$$ = makeNode(strdup("WHILE"), strdup("while"), 0, $4, $7, (node*)NULL, (node*)NULL);
		
		$$->nextlist = mergelist(s1->breaklist, e1->falselist);
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, to_string(m1->quad));
	}
	| DO M_marker statement WHILE '(' M_marker expressionJump ')' ';' {
		node* s1 = $3, *e1 = $7, *m2 = $2, *m1 = $6;
		int retval = backpatch(s1->nextlist, m1->quad);
		if(retval)
			error(string(s1->lexeme)+" backpatch error", retval);
		retval = backpatch(e1->truelist, m2->quad);
		if(retval)
			error(string(e1->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->continuelist, m1->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);
		
		$$ = makeNode(strdup("DO WHILE"), strdup("do while"), 0, $3, $7, (node*)NULL, (node*)NULL);
		
		$$->nextlist = mergelist(s1->breaklist, e1->falselist);
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, to_string(m2->quad));
	}
	| FOR '(' expression_statement M_marker expressionJumpStatement ')' M_marker statement {
		node *e1 = $3, *m1 = $4, *e2 = $5, *m3 = $7, *s1 = $8;
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, to_string(m1->quad));
		int retval = backpatch(e2->truelist, m3->quad);
		if(retval)
			error(string(e2->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->continuelist, m1->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->nextlist, m1->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);
		
		$$ = makeNode(strdup("FOR"), strdup("for"),0, $3, $5, $8, (node*)NULL);
		$$->nextlist = mergelist(s1->breaklist, e2->falselist);
	}
	| FOR '(' expression_statement M_marker expressionJumpStatement M_marker expression N_marker ')' M_marker statement {
		node *e1 = $3, *m1 = $4, *e2 = $5, *m2 = $6, *e3 = $7, *n1 = $8, *m3 = $10, *s1 = $11;
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, to_string(m2->quad));
		int retval = backpatch(n1->nextlist, m1->quad);
		if(retval)
			error(string(n1->lexeme) + " backpatch error", retval);
		retval = backpatch(e2->truelist, m3->quad);
		if(retval)
			error(string(e2->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->continuelist, m2->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);
		retval = backpatch(s1->nextlist, m2->quad);
		if(retval)
			error(string(s1->lexeme) + " backpatch error", retval);

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
		if(funcNode == nullptr){
			error("Return statement not in function", DEFAULT_ERROR);
		}

		int err = checkVoidSymbol(funcNode);
		if(err){
			error("Function type not void", DEFAULT_ERROR);
		}
		
		$$ = makeNode(strdup("RETURN"), strdup("return"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);
		emit(OP_RETURN, EMPTY_STR, EMPTY_STR, EMPTY_STR);
	}
	| RETURN expression ';' { 
		symbolTableNode* funcNode = lookUp(gSymTable, currFunc);
		if(funcNode == nullptr){
			error("Return statement not in function", DEFAULT_ERROR);
		}
		
		node* temp = $2;
		int err = canTypecast(funcNode->declSp, temp->declSp);;
		if(err) error("return type isnt valid", DEFAULT_ERROR);
		node* n1 = new node();
		n1->declSp = declSpCopy(funcNode->declSp);
		n1->addr = temp->addr;
		err = giveTypeCastRankUnary(n1, temp);
		if(err) error("error in typecasting", DEFAULT_ERROR);
		if(temp->declSp && temp->declSp->type[0] == TYPE_FLOAT)
			emit(OP_RETURNF, EMPTY_STR, EMPTY_STR, temp->addr);	
		else emit(OP_RETURN, EMPTY_STR, EMPTY_STR, temp->addr);
		$$ = makeNode(strdup("RETURN"), strdup("return"), 0, temp, (node*)NULL, (node*)NULL, (node*)NULL);
		
    }
	;

translation_unit
	: external_declaration { $$ = $1; root = $$; }
	| translation_unit external_declaration {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; root = $$;}
	;

external_declaration
	: function_definition {
		$$ = $1; 
		backpatch($$->nextlist, nextQuad());
		emit(OP_ENDFUNC, EMPTY_STR, EMPTY_STR, EMPTY_STR);}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers  declarator declaration_list compound_statement { 
		// Unsupported Functionality
		error("Use function definitions of type int foo(int a, int b){...}", UNSUPPORTED_FUNCTIONALITY);
	}
	| declaration_specifiers  declarator {
		struct node* declarator = $2; 
		struct node* declaration_specifiers = $1;
		addFunctionSymbol(declaration_specifiers, declarator);
		string funcName = $2->addr;
		struct symbolTableNode* funcNode = lookUp(gSymTable, funcName);
		if(!funcNode){
			error("Func "+funcName+" not found", DEFAULT_ERROR);
		}

		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		symbolTable* curr = gSymTable;
		
		string labelName = string(declarator->lexeme);
		emit(OP_LABEL, EMPTY_STR, EMPTY_STR, labelName);
		if(funcBeginQuad != -1)
			error("Internal funcBeginQuad not -1", INVALID_ARGS_IN_FUNC_CALL);
		funcBeginQuad = nextQuad();
    	emit(OP_BEGINFUNC, EMPTY_STR, EMPTY_STR, BLANK_STR);
		while(!arrayInFuncParam.empty()){
			// Not required because we don't need to set arr address as it is passed as pointer
			// addArrayParamToStack(offset, arrayInFuncParam.top(), errCode, errStr);
			arrayInFuncParam.pop();
		}
		setOverSixParamOffset(declarator, curr, funcNode);
		offset = 0;
	} compound_statement { 
		addChild($2, $4);
		$$ = $2;
		setFirstSixParamOffset($2, gSymTable);
		int retval = backpatchBeginFunc(funcBeginQuad, offset-8 + CALLQ_PADDING);
		if(retval)
			error("backpatchBeginFunc", retval);
		funcBeginQuad = -1;
		currFunc = "#prog";
		vector<int> v1 = mergelist($4->truelist, $4->falselist);
		vector<int> v2 = mergelist(v1, $4->nextlist);
		vector<int> v3 = mergelist(v2, $4->breaklist);
		$$->nextlist = v3;
	}
	| declarator func_marker_1 declaration_list compound_statement { 
		// UNSUPPORTED_FUNCTIONALITY
		error("Use function definitions of type int foo(int a, int b){...}", UNSUPPORTED_FUNCTIONALITY);
	}
	| declarator func_marker_1 compound_statement { 
		addChild($1, $3);
		$$ = $1;
		setFirstSixParamOffset($1, gSymTable);
		int retval = backpatchBeginFunc(funcBeginQuad, offset-8 + CALLQ_PADDING);
		if(retval)
			error("backpatchBeginFunc", retval);
		funcBeginQuad = -1;
		currFunc = "#prog";
	}
	;


func_marker_1
	: {
		struct node* declarator = currDecl;
		addFunctionSymbol(NULL, declarator);
		string funcName =  declarator->addr;
		struct symbolTableNode* funcNode = lookUp(gSymTable, funcName);
		if(!funcNode){
			error("Func "+funcName+" not found", DEFAULT_ERROR);
		}
		funcDecl = 1;
		gSymTable = addChildSymbolTable(gSymTable);
		symbolTable* curr = gSymTable;
		string labelName = string(declarator->lexeme);
		emit(OP_LABEL, EMPTY_STR, EMPTY_STR,labelName);
		if(funcBeginQuad != -1)
			error("Internal funcBeginQuad not -1", INVALID_ARGS_IN_FUNC_CALL);
		funcBeginQuad = nextQuad();
		emit(OP_BEGINFUNC, EMPTY_STR, EMPTY_STR, BLANK_STR);
		setOverSixParamOffset(declarator, curr, funcNode);
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
		emit(OP_GOTO, EMPTY_STR, EMPTY_STR, BLANK_STR);
		$$ = temp;
	}
	;

%%
#include <stdio.h>
#include <unistd.h>

using namespace std;

int main(int ac, char **av) {
	int val;
    FILE    *fd;
    if (ac >= 2)
    {
		string inputFileName = string(av[1]); 
        if (!(fd = fopen(inputFileName.c_str(), "r")))
        {
            perror(" Error: ");
            return (-1);
        }
		string filePrefix = extractFileName(inputFileName);
		string currDir = get_current_dir_name();
		string directoryName = "outputs/" + filePrefix; 
		int dir = mkdir(directoryName.c_str(), 0777);
		if(dir == -1 && errno != EEXIST) {
			cerr << "Error :  " << strerror(errno) << endl;
			directoryName = currDir + "/outputs/";
		} else {
			directoryName.push_back('/');
		}
		string TACFilename =  directoryName + filePrefix +".tac"; 
        yyset_in(fd);
        
        // Make the first symbol table with global scope
		gSymTable = new symbolTable();
		gTempSymbolMap = new symbolTable();
		globalScopeSymTable = gSymTable;
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
		// char * fileName = strdup("graph.dot");
		// if(ac == 3) fileName = av[2];
		// generateDot(root,fileName);
        
		// printSymbolTable(gSymTable);
		string asmFileName = directoryName + filePrefix +".s";
		emitAssemblyFrom3AC(asmFileName);
		string jsonFileNamePrefix = directoryName + filePrefix;
		printSymbolTableJSON(jsonFileNamePrefix,gSymTable,0,1);
		printCode((char*)TACFilename.c_str());
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
