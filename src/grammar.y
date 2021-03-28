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
%union{ty* nodes; char* id;}
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


// Prototypes
%{
	#include <stdio.h>
	#include <string.h>
  #include <stdlib.h>
  #include "symbolTable.h"

extern "C"
{
	// int yyparse (void);
	int yylex(void);  
	int yywrap();
	void yyset_in  ( FILE * _in_str  );
}

void yyerror(const char *s);
// int yylex();
extern char yytext[];
// typedef struct node{
// 	// int type;
// 	int id;
// 	char* name;
// 	char* lexeme;
// 	int isLeaf;
// 	struct node* next;
// 	struct node* childList;
// }node;

node* root;
  node* makeNode(char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);
	void makeSibling(node* root, node* childList);
	void addChild(node* parent, node* child);
%}

%%

primary_expression
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| CONSTANT	{$$ = makeNode(strdup("CONSTANT"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| STRING_LITERAL {$$ = makeNode(strdup("STRING_LITERAL"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '(' expression ')' { $$ = $2; }
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' {addChild($1,$3);$$ = $1;}
	| postfix_expression '(' ')' {$$ = $1;}
	| postfix_expression '(' argument_expression_list ')' {addChild($1,$3);$$ = $1;}
	| postfix_expression '.' IDENTIFIER { $$ = makeNode(strdup("."), strdup(""), 0, $1, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
	| postfix_expression PTR_OP IDENTIFIER {$$ = makeNode(strdup("PTR_OP"), strdup(""), 0, $1, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL);}
	| postfix_expression INC_OP {addChild($1, makeNode(strdup("INC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL));$$ = $1;}
	| postfix_expression DEC_OP {addChild($1, makeNode(strdup("DEC_OP"), strdup(""), 1, NULL, NULL, NULL, NULL)); $$ = $1;}
	;

argument_expression_list
	: assignment_expression { $$ = $1; }
	| argument_expression_list ',' assignment_expression { if($1){makeSibling($3, $1); $$ = $1;} else $$ = $3; }
	;

unary_expression
	: postfix_expression {$$ = $1; }
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
	| '(' type_name ')' cast_expression { if($2){makeSibling($4, $2); $$ = $2;} else {$$ = $4;} }
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
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression { $$ = makeNode(strdup("EQ_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
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
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression { $$ = makeNode(strdup("OR_OP"), strdup(""), 0, $1, $3, (node*)NULL, (node*)NULL); }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { $$ = makeNode(strdup("?:"), strdup(""), 0, $1, $3, $5, (node*)NULL); }
	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression { addChild($2, $1); addChild($2, $3); $$ = $2; }
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
		if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;
		// Add details to symbol table entries corresponding to init_declarator_list
		// Symbol table entry to be made in init_declarator


		}
	;

declaration_specifiers
	: storage_class_specifier {$$ = $1;}
	| storage_class_specifier declaration_specifiers {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
	| type_specifier {$$ = $1;}
	| type_specifier declaration_specifiers {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
	| type_qualifier {$$ = $1;}
	| type_qualifier declaration_specifiers {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
	;

init_declarator_list
	: init_declarator { $$ = $1;  }
	| init_declarator_list ',' init_declarator { if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;} 
	;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer { $$ = makeNode(strdup("="), strdup("="), 0, $1, $3, (node*)NULL, (node*)NULL);}
	;

storage_class_specifier
	: TYPEDEF {$$ = makeNode(strdup("TYPEDEF"), strdup("typedef"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| EXTERN {$$ = makeNode(strdup("EXTERN"), strdup("extern"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| STATIC {$$ = makeNode(strdup("STATIC"), strdup("static"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| AUTO {$$ = makeNode(strdup("AUTO"), strdup("auto"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| REGISTER {$$ = makeNode(strdup("REGISTER"), strdup("register"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

type_specifier
	: VOID {$$ = NULL;}
	| CHAR {$$ = NULL;}
	| SHORT {$$ = NULL;}
	| INT {$$ = NULL;}
	| LONG {$$ = NULL;}
	| FLOAT {$$ = NULL;}
	| DOUBLE {$$ = NULL;}
	| SIGNED {$$ = NULL;}
	| UNSIGNED {$$ = NULL;}
	| struct_or_union_specifier {$$ = $1;}
	| enum_specifier {$$ = $1;}
	| TYPE_NAME {$$ = NULL;}
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
	| struct_declaration_list struct_declaration { if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';' {$$ = NULL;}
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
	| type_specifier { $$ = $1; }
	| type_qualifier specifier_qualifier_list {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
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
	| enumerator_list ',' enumerator { if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;} 
	;

enumerator
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| IDENTIFIER '=' constant_expression {$$ = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $3, (node*)NULL, (node*)NULL);}
	;

type_qualifier
	| VOLATILE {$$ = makeNode(strdup("VOLATILE"), strdup("volatile"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	: CONST {$$ = makeNode(strdup("CONST"), strdup("const"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	;

declarator
	: pointer direct_declarator  { $$ = $2; }
	| direct_declarator { $$ = $1; }
	;

direct_declarator
	: IDENTIFIER { $$ = makeNode(strdup("IDENTIFIER"), strdup(""), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL); }
	| '(' declarator ')' { $$ = $2;}
	| direct_declarator '[' constant_expression ']' { $$ = $1; }
	| direct_declarator '[' ']' {$$ = $1; }
	| direct_declarator '(' parameter_type_list ')' { $$ = $1; }
	| direct_declarator '(' identifier_list ')' { $$ = $1; }
	| direct_declarator '(' ')' { $$ = $1; }
	;

pointer
	: '*' { $$ = makeNode(strdup("*"), strdup("*"), 0, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL);}
	| '*' type_qualifier_list { $$ = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL); }
	| '*' pointer { $$ = makeNode(strdup("*"), strdup("*"), 0, $2, (node*)NULL, (node*)NULL, (node*)NULL); }
	| '*' type_qualifier_list pointer { $$ = makeNode(strdup("*"), strdup("*"), 0, $2, $3, (node*)NULL,(node*)NULL );}
	;

type_qualifier_list
	: type_qualifier { $$ = $1; }
	| type_qualifier_list type_qualifier { if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
	;


parameter_type_list
	: parameter_list { $$ = $1; }
	| parameter_list ',' ELLIPSIS { makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, (node*)NULL, (node*)NULL, (node*)NULL, (node*)NULL), $1); $$ = $1;}
	;

parameter_list
	: parameter_declaration { $$ = $1; }
	| parameter_list ',' parameter_declaration { if($1){makeSibling($3,$1);$$ = $1;} else $$ = $3;}
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
	| specifier_qualifier_list abstract_declarator {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; }
	;

abstract_declarator
	: pointer { $$ = $1; }
	| direct_abstract_declarator { $$ = $1; }
	| pointer direct_abstract_declarator {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2;}
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
	: '{' '}' { $$ = (node*)NULL; }
	| '{' statement_list '}' { $$ = $2; }
	| '{' declaration_list '}' { $$ = $2; }
	| '{' declaration_list statement_list '}' { if($2){$$ = makeNode(strdup("BODY"), strdup(""), 0, $2, $3, (node*)NULL, (node*)NULL);} else{
		$$ = $3;	} }
	;

declaration_list
	: declaration { $$ = $1; }
	| declaration_list declaration { if(!strcmp(($1 -> name), "DECL_LIST")){$$ = makeNode(strdup("DECL_LIST"), strdup(""), 0, $1 -> childList, $2, (node*)NULL, (node*)NULL);} else $$ = makeNode(strdup("DECL_LIST"), strdup(""), 0, $1, $2, (node*)NULL, (node*)NULL);}
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
	| translation_unit external_declaration {if($1){makeSibling($2,$1);$$ = $1;} else $$ = $2; root = $$; }
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

int main(int ac, char **av) {
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
        
		yyparse();
		root = makeNode(strdup("ROOT"), strdup("root"), 0 ,root,  (node*) NULL,  (node*) NULL, (node*) NULL);
		char * fileName = strdup("graph.dot");
		if(ac == 3) fileName = av[2];

		generateDot(root,fileName);

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
