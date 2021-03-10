%token IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
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

// %type<id> IDENTIFIER CONSTANT STRING_LITERAL SIZEOF
// 			PTR_OP INC_OP DEC_OP LEFT_OP RIGHT_OP LE_OP GE_OP EQ_OP NE_OP
// 			AND_OP OR_OP MUL_ASSIGN DIV_ASSIGN MOD_ASSIGN ADD_ASSIGN
// 			SUB_ASSIGN LEFT_ASSIGN RIGHT_ASSIGN AND_ASSIGN 
// 			XOR_ASSIGN OR_ASSIGN TYPE_NAME
// 			TYPEDEF EXTERN STATIC AUTO REGISTER
// 			CHAR SHORT INT LONG SIGNED UNSIGNED FLOAT DOUBLE CONST VOLATILE VOID
// 			STRUCT UNION ENUM ELLIPSIS
// 			CASE DEFAULT IF ELSE SWITCH WHILE DO FOR GOTO CONTINUE BREAK RETURN
// Prototypes
%{
	#include <stdio.h>
  #include <stdlib.h>
  
//   #include <node.h>
//   #include "generateDot.c"
// extern struct node;
// typedef struct node node;
extern char yytext[];
typedef struct node{
	// int type;
	int id;
	char* name;
	char* lexeme;
	int isLeaf;
	struct node* next;
	struct node* childList;
}node;

node* root;
  node* makeNode(char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);
	void makeSibling(node* root, node* childList);
	void addChild(node* parent, node* child);
%}

%%

primary_expression
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| CONSTANT	{printf("CONSTANT\n");$$ = makeNode(strdup("CONSTANT"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);printf("CONSTANT2\n");}
	| STRING_LITERAL {$$ = makeNode(strdup("STRING_LITERAL"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '(' expression ')' { $$ = $2; }
	;

postfix_expression
	: primary_expression { printf("primary_expression\n");$$ = $1; printf("primary_expression2\n");  }
	| postfix_expression '[' expression ']' {printf("postfix_expression [ \n");addChild($1,$3);$$ = $1;}
	| postfix_expression '(' ')' {$$ = $1;}
	| postfix_expression '(' argument_expression_list ')' {printf("postfix_expression ( arg )\n");addChild($1,$3);$$ = $1;}
	| postfix_expression '.' IDENTIFIER { printf("postfix_expression IDENTIFIER \n");$$ = makeNode(strdup("."), strdup(""), 0, $1, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
	| postfix_expression PTR_OP IDENTIFIER {printf("postfix_expression PTR_OP IDENTIFIER \n");$$ = makeNode(strdup("PTR_OP"), strdup(""), 0, $1, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
	| postfix_expression INC_OP {printf("postfix_expression INC_OP \n");addChild($1, makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));$$ = $1;}
	| postfix_expression DEC_OP {printf("postfix_expression DEC_OP \n");addChild($1, makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL)); $$ = $1;}
	;

argument_expression_list
	: assignment_expression { $$ = $1; }
	| argument_expression_list ',' assignment_expression { makeSibling($3, $1); $$ = $1; }
	;

unary_expression
	: postfix_expression {printf("postfix_expression\n");$$ = $1; }
	| INC_OP unary_expression {$$ = makeNode(strdup("INC_OP"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| DEC_OP unary_expression {$$ = makeNode(strdup("DEC_OP"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| unary_operator cast_expression { addChild($1, $2); $$ = $1; }
	| SIZEOF unary_expression {$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL);}
	| SIZEOF '(' type_name ')'{$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

unary_operator
	: '&' {$$ = makeNode(strdup("&"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' {$$ = makeNode(strdup("*"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '+' {$$ = makeNode(strdup("+"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '-' {$$ = makeNode(strdup("-"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '~' {$$ = makeNode(strdup("~"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '!' {$$ = makeNode(strdup("!"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

cast_expression
	: unary_expression {$$ = $1; }
	| '(' type_name ')' cast_expression { makeSibling($4, $2); $$ = $2; }
	;

multiplicative_expression
	: cast_expression {$$ = $1; }
	| multiplicative_expression '*' cast_expression { $$ = makeNode(strdup("*"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| multiplicative_expression '/' cast_expression { $$ = makeNode(strdup("/"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| multiplicative_expression '%' cast_expression { $$ = makeNode(strdup("%"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { $$ = makeNode(strdup("+"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| additive_expression '-' multiplicative_expression { $$ = makeNode(strdup("-"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { $$ = makeNode(strdup("LEFT_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| shift_expression RIGHT_OP additive_expression { $$ = makeNode(strdup("RIGHT_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { $$ = makeNode(strdup("<"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression '>' shift_expression { $$ = makeNode(strdup(">"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression LE_OP shift_expression { $$ = makeNode(strdup("LE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| relational_expression GE_OP shift_expression { $$ = makeNode(strdup("GE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

equality_expression
	: relational_expression {printf("relational_expression\n"); $$ = $1; }
	| equality_expression EQ_OP relational_expression { printf("equality_expression EQ_OP relational_expression\n");$$ = makeNode(strdup("EQ_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	| equality_expression NE_OP relational_expression { $$ = makeNode(strdup("NE_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { $$ = makeNode(strdup("&"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression { $$ = makeNode(strdup("^"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression { $$ = makeNode(strdup("|"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression { $$ = makeNode(strdup("AND_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

logical_or_expression
	: logical_and_expression { printf("logical_and_expression\n");$$ = $1; }
	| logical_or_expression OR_OP logical_and_expression { $$ = makeNode(strdup("OR_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

conditional_expression
	: logical_or_expression { printf("logical_or_expression\n");$$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { printf("logical_or_expression '?'\n");$$ = makeNode(strdup("?:"), strdup(""), 0, $1, $3, $5, (node*)NULL); }
	;

assignment_expression
	: conditional_expression { printf("cond_exp\n");$$ = $1; }
	| unary_expression assignment_operator assignment_expression { printf("assignment--unar\n");addChild($2, $1); addChild($2, $3); $$ = $2; }
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
	| expression ',' assignment_expression { makeSibling($3, $1); $$ = $1;} 
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

declaration
	: declaration_specifiers ';' { $$ = $1; }
	| declaration_specifiers init_declarator_list ';' { printf("init_decl start\n"); makeSibling($2,$1);$$ = $1; printf("init_decl\n");}
	;

declaration_specifiers
	: storage_class_specifier {$$ = $1;}
	| storage_class_specifier declaration_specifiers {makeSibling($2,$1);$$ = $1;}
	| type_specifier {printf("type_specifier\n");$$ = $1; printf("type_specifier2\n");}
	| type_specifier declaration_specifiers {makeSibling($2,$1);$$ = $1;}
	| type_qualifier {$$ = $1;}
	| type_qualifier declaration_specifiers {makeSibling($2,$1);$$ = $1;}
	;

init_declarator_list
	: init_declarator { printf("init_declarator\n");$$ = $1; printf("init_declarator2\n"); }
	| init_declarator_list ',' init_declarator { makeSibling($3, $1); $$ = $1;} 
	;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer { printf("init\n");printf("hello = %d\n",$1);$$ = makeNode(strdup("="), strdup("="), 0, $1, $3, (node*)NULL, (node*)NULL); printf("init2\n");}
	;

storage_class_specifier
	: TYPEDEF {$$ = makeNode(strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| EXTERN {$$ = makeNode(strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| STATIC {$$ = makeNode(strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| AUTO {$$ = makeNode(strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| REGISTER {$$ = makeNode(strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

type_specifier
	: VOID {$$ = makeNode(strdup("VOID"), strdup("void"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| CHAR {$$ = makeNode(strdup("CHAR"), strdup("char"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| SHORT {$$ = makeNode(strdup("SHORT"), strdup("short"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| INT {$$ = makeNode(strdup("INT"), strdup("int"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| LONG {$$ = makeNode(strdup("LONG"), strdup("long"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| FLOAT {$$ = makeNode(strdup("FLOAT"), strdup("float"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| DOUBLE {$$ = makeNode(strdup("DOUBLE"), strdup("double"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| SIGNED {$$ = makeNode(strdup("SIGNED"), strdup("signed"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| UNSIGNED {$$ = makeNode(strdup("UNSIGNED"), strdup("unsigned"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| struct_or_union_specifier {$$ = $1;}
	| enum_specifier {$$ = $1;}
	| TYPE_NAME {$$ = makeNode(strdup("TYPE_NAME"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' {$$ = NULL;} 
	| struct_or_union '{' struct_declaration_list '}' {$$ = NULL;}
	| struct_or_union IDENTIFIER {$$ = NULL;}
	;

struct_or_union
	: STRUCT {$$ = makeNode(strdup("STRUCT"), strdup("struct"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| UNION {$$ = makeNode(strdup("UNION"), strdup("union"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

struct_declaration_list
	: struct_declaration { $$ = $1; }
	| struct_declaration_list struct_declaration { makeSibling($2, $1); $$ = $1; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {$$ = NULL;}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list { makeSibling($2, $1); $$ = $1; }
	| type_specifier { $$ = $1; }
	| type_qualifier specifier_qualifier_list { makeSibling($2, $1); $$ = $1; }
	| type_qualifier { $$ = $1; }
	;

struct_declarator_list
	: struct_declarator { $$ = $1; }
	| struct_declarator_list ',' struct_declarator {$$ = NULL;}
	;

struct_declarator
	: declarator { $$ = $1; }
	| ':' constant_expression {$$ = NULL;}
	| declarator ':' constant_expression {$$ = NULL;}
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup(""), 0, $3, (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, $4, (node*)NULL, (node*)NULL, (node*)NULL), (node*)NULL, (node*)NULL, (node*)NULL);}
	| ENUM IDENTIFIER {$$ = (node*)NULL;}
	;

enumerator_list
	: enumerator { $$ = $1; }
	| enumerator_list ',' enumerator { makeSibling($3, $1); $$ = $1;} 
	;

enumerator
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| IDENTIFIER '=' constant_expression {$$ = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	;

type_qualifier
	: CONST {$$ = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| VOLATILE {$$ = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

declarator
	: pointer direct_declarator  { $$ = $2; }
	| direct_declarator { $$ = $1; }
	;

direct_declarator
	: IDENTIFIER { printf("direct_declarator\n"); $$ = makeNode(strdup("IDENTIFIER"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); printf("hi2\n"); }
	| '(' declarator ')' { $$ = $2;}
	| direct_declarator '[' constant_expression ']' { $$ = $1; }
	| direct_declarator '[' ']' {$$ = $1; }
	| direct_declarator '(' parameter_type_list ')' { $$ = $1; }
	| direct_declarator '(' identifier_list ')' { $$ = $1; }
	| direct_declarator '(' ')' { $$ = $1; }
	;

pointer
	: '*' {printf("poiner\n");$$ = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' type_qualifier_list {printf(" * type_qualifier_list\n");$$ = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL); }
	| '*' pointer {printf(" * pointer\n");$$ = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL); }
	| '*' type_qualifier_list pointer {printf(" * type_qualifier_list pointer\n");$$ = makeNode(strdup("*"), strdup("*"), 0, $2, $3, (node*)NULL,(node*)NULL );}
	;

type_qualifier_list
	: type_qualifier { $$ = $1; }
	| type_qualifier_list type_qualifier { makeSibling($2, $1); $$ = $1;}
	;


parameter_type_list
	: parameter_list { $$ = $1; }
	| parameter_list ',' ELLIPSIS { makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

parameter_list
	: parameter_declaration { $$ = $1; }
	| parameter_list ',' parameter_declaration { makeSibling($3, $1); $$ = $1;}
	;

parameter_declaration
	: declaration_specifiers declarator { $$ = $2; }
	| declaration_specifiers abstract_declarator { $$ = $2; }
	| declaration_specifiers { $$ = (node*)NULL; }
	;

identifier_list
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| identifier_list ',' IDENTIFIER { makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

type_name
	: specifier_qualifier_list { $$ = $1; }
	| specifier_qualifier_list abstract_declarator {makeSibling($2,$1); $$ = $1; }
	;

abstract_declarator
	: pointer { $$ = $1; }
	| direct_abstract_declarator { $$ = $1; }
	| pointer direct_abstract_declarator {makeSibling($2,$1); $$ = $1;}
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
	| initializer_list ',' initializer {printf("init_lis\n");makeSibling($3, $1); $$ = $1;}
	;

statement
	: labeled_statement {printf("---- labeled statement\n"); $$ = $1; }
	| compound_statement {printf("---- compound_statement\n");$$ = $1; }
	| expression_statement {printf("----- expression statement\n"); $$ = $1; }
	| selection_statement { printf("----- selection_statement\n");$$ = $1; }
	| iteration_statement { printf("iteration_statement\n");$$ = $1; }
	| jump_statement { printf("----- jump_statement\n");$$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement {$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	| CASE constant_expression ':' statement { $$ = makeNode(strdup("CASE"), strdup("case"), 0, $2, $4, (node*)NULL, (node*)NULL); }
	| DEFAULT ':' statement {$$ = makeNode(strdup(":"), strdup(":"), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	;

compound_statement
	: '{' '}' { $$ = (node*)NULL; }
	| '{' statement_list '}' { $$ = $2; }
	| '{' declaration_list '}' { $$ = $2; }
	| '{' declaration_list statement_list '}' { if($2){makeSibling($3,$2); $$ = $2;} else{
		$$ = $3;	} }
	;

declaration_list
	: declaration { $$ = $1; }
	| declaration_list declaration {if($2){ makeSibling($2, $1); $$ = $1; } else {$$ = $2;}}
	;

statement_list
	: statement { $$ = $1; }
	| statement_list statement { makeSibling($2, $1); $$ = $1; }
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
	| translation_unit external_declaration {makeSibling($2,$1);$$=$1; root = $$; }
	;

external_declaration
	: function_definition {$$ = $1;}
	| declaration {$$ = $1;}
	;

function_definition
	: declaration_specifiers declarator declaration_list compound_statement { addChild($2, $3); addChild($2, $4); $$ = $2; }
	| declaration_specifiers declarator compound_statement { addChild($2, $3); $$ = $2; }
	| declarator declaration_list compound_statement { addChild($1, $2); addChild($1, $3); $$ = $1; }
	| declarator compound_statement { addChild($1, $2); $$ = $1; }
	;


%%
#include <stdio.h>
int id = 0;


void printDeclarations(node* root, FILE *fp) {
    if(!root) return;
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
    node* child = root->childList;
    while(child) {
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
// extern struct node;
// typedef struct node{
// 	// int type;
// 	int id;
// 	char* name;
// 	char* lexeme;
// 	int isLeaf;
// 	node* next;
// 	node* childList;
// }node;



// extern void generateDot(node*, char*);
void dfs(node* root){
	if(!root) return;
	node* childList = root->childList;
	printf("%s\n", root->name );
    while(childList) {
        dfs(childList);
        childList = childList->next;
    }
}

int main(int ac, char **av) {
	printf("hhi\n");
	yyparse();
	printf("parse ended\n");
	root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
	// dfs(root);
	char * fileName = strdup("graph.dot");
	printf("parse ended1\n");
   	generateDot(root,fileName);
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

void makeSibling(node* root, node* childList){
	if(!root) return;
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
yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}