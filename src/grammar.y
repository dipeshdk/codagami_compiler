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
// Prototypes
%{
	#include<stdio.h>
  #include<stdlib.h>
  #include "generateDot.c"
  node* makeNode(char* name, char* lexeme, int isLeaf, node*c1, node*c2, node*c3, node* c4);
	void makeSibling(node* node, node* childList);
	void addChild(node* parent, node* child);
%}

%%

primary_expression
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| CONSTANT	{$$ = makeNode(strdup("CONSTANT"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| STRING_LITERAL {$$ = makeNode(strdup("STRING_LITERAL"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| '(' expression ')' { $$ = $2; }
	;

postfix_expression
	: primary_expression { $$ = $1; }
	| postfix_expression '[' expression ']' 
	| postfix_expression '(' ')'
	| postfix_expression '(' argument_expression_list ')'
	| postfix_expression '.' IDENTIFIER
	| postfix_expression PTR_OP IDENTIFIER
	| postfix_expression INC_OP
	| postfix_expression DEC_OP
	;

argument_expression_list
	: assignment_expression { $$ = $1; }
	| argument_expression_list ',' assignment_expression { makeSibling($3, $1); $$ = $1; }
	;

unary_expression
	: postfix_expression {$$ = $1; }
	| INC_OP unary_expression {$$ = makeNode(strdup("INC_OP"), strdup(""), 0, $2, NULL, NULL, NULL);}
	| DEC_OP unary_expression {$$ = makeNode(strdup("DEC_OP"), strdup(""), 0, $2, NULL, NULL, NULL);}
	| unary_operator cast_expression { addChild($1, $2); $$ = $1; }
	| SIZEOF unary_expression {$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $2, NULL, NULL, NULL);}
	| SIZEOF '(' type_name ')'{$$ = makeNode(strdup("SIZEOF"), strdup(""), 0, $3, NULL, NULL, NULL);}
	;

unary_operator
	: '&' {$$ = makeNode(strdup("&"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	| '*' {$$ = makeNode(strdup("*"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	| '+' {$$ = makeNode(strdup("+"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	| '-' {$$ = makeNode(strdup("-"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	| '~' {$$ = makeNode(strdup("~"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	| '!' {$$ = makeNode(strdup("!"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	;

cast_expression
	: unary_expression {$$ = $1; }
	| '(' type_name ')' cast_expression { makeSibling($2, $1); $$ = $1; }
	;

multiplicative_expression
	: cast_expression {$$ = $1; }
	| multiplicative_expression '*' cast_expression { $$ = makeNode(strdup("*"), strdup(""), 0, $1, $3, NULL, NULL); }
	| multiplicative_expression '/' cast_expression { $$ = makeNode(strdup("/"), strdup(""), 0, $1, $3, NULL, NULL); }
	| multiplicative_expression '%' cast_expression { $$ = makeNode(strdup("%"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

additive_expression
	: multiplicative_expression { $$ = $1; }
	| additive_expression '+' multiplicative_expression { $$ = makeNode(strdup("+"), strdup(""), 0, $1, $3, NULL, NULL); }
	| additive_expression '-' multiplicative_expression { $$ = makeNode(strdup("-"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

shift_expression
	: additive_expression { $$ = $1; }
	| shift_expression LEFT_OP additive_expression { $$ = makeNode(strdup("LEFT_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	| shift_expression RIGHT_OP additive_expression { $$ = makeNode(strdup("RIGHT_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

relational_expression
	: shift_expression { $$ = $1; }
	| relational_expression '<' shift_expression { $$ = makeNode(strdup("<"), strdup(""), 0, $1, $3, NULL, NULL); }
	| relational_expression '>' shift_expression { $$ = makeNode(strdup(">"), strdup(""), 0, $1, $3, NULL, NULL); }
	| relational_expression LE_OP shift_expression { $$ = makeNode(strdup("LE_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	| relational_expression GE_OP shift_expression { $$ = makeNode(strdup("GE_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

equality_expression
	: relational_expression { $$ = $1; }
	| equality_expression EQ_OP relational_expression { $$ = makeNode(strdup("EQ_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	| equality_expression NE_OP relational_expression { $$ = makeNode(strdup("NE_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

and_expression
	: equality_expression { $$ = $1; }
	| and_expression '&' equality_expression { $$ = makeNode(strdup("&"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

exclusive_or_expression
	: and_expression {$$ = $1;}
	| exclusive_or_expression '^' and_expression { $$ = makeNode(strdup("^"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

inclusive_or_expression
	: exclusive_or_expression { $$ = $1; }
	| inclusive_or_expression '|' exclusive_or_expression { $$ = makeNode(strdup("|"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

logical_and_expression
	: inclusive_or_expression {$$ = $1;}
	| logical_and_expression AND_OP inclusive_or_expression { $$ = makeNode(strdup("AND_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

logical_or_expression
	: logical_and_expression { $$ = $1; }
	| logical_or_expression OR_OP logical_and_expression { $$ = makeNode(strdup("OR_OP"), strdup(""), 0, $1, $3, NULL, NULL); }
	;

conditional_expression
	: logical_or_expression { $$ = $1; }
	| logical_or_expression '?' expression ':' conditional_expression { $$ = makeNode(strdup("?:"), strdup(""), 0, $1, $3, $5, NULL); }
	;

assignment_expression
	: conditional_expression { $$ = $1; }
	| unary_expression assignment_operator assignment_expression { addChild($2, $1); addChild($2, $3); $$ = $2; }
	;

assignment_operator
	: '=' {$$ = makeNode(strdup("="), strdup("="), 0, NULL, NULL, NULL, NULL);}
	| MUL_ASSIGN { $$ = makeNode(strdup("MUL_ASSIGN"), strdup("*="), 0, NULL, NULL, NULL, NULL); }
	| DIV_ASSIGN { $$ = makeNode(strdup("DIV_ASSIGN"), strdup("/="), 0, NULL, NULL, NULL, NULL); }
	| MOD_ASSIGN { $$ = makeNode(strdup("MOD_ASSIGN"), strdup("%="), 0, NULL, NULL, NULL, NULL); }
	| ADD_ASSIGN { $$ = makeNode(strdup("ADD_ASSIGN"), strdup("+="), 0, NULL, NULL, NULL, NULL); }
	| SUB_ASSIGN { $$ = makeNode(strdup("SUB_ASSIGN"), strdup("-="), 0, NULL, NULL, NULL, NULL); }
	| LEFT_ASSIGN { $$ = makeNode(strdup("LEFT_ASSIGN"), strdup(""), 0, NULL, NULL, NULL, NULL); }
	| RIGHT_ASSIGN { $$ = makeNode(strdup("RIGHT_ASSIGN"), strdup(""), 0, NULL, NULL, NULL, NULL); }
	| AND_ASSIGN { $$ = makeNode(strdup("AND_ASSIGN"), strdup("&="), 0, NULL, NULL, NULL, NULL); }
	| XOR_ASSIGN { $$ = makeNode(strdup("XOR_ASSIGN"), strdup("^="), 0, NULL, NULL, NULL, NULL); }
	| OR_ASSIGN { $$ = makeNode(strdup("OR_ASSIGN"), strdup(""), 0, NULL, NULL, NULL, NULL); }
	;

expression
	: assignment_expression { $$ = $1; }
	| expression ',' assignment_expression { makeSibling($3, $1); $$ = $1;} 
	;

constant_expression
	: conditional_expression { $$ = $1; }
	;

declaration
	: declaration_specifiers ';' { $$ = NULL }
	| declaration_specifiers init_declarator_list ';' { $$ = $2; }
	;

declaration_specifiers
	: storage_class_specifier 
	| storage_class_specifier declaration_specifiers
	| type_specifier 
	| type_specifier declaration_specifiers
	| type_qualifier 
	| type_qualifier declaration_specifiers
	;

init_declarator_list
	: init_declarator { $$ = $1; }
	| init_declarator_list ',' init_declarator { makeSibling($3, $1); $$ = $1;} 
	;

init_declarator
	: declarator { $$ = $1; }
	| declarator '=' initializer { $$ = makeNode(strdup("="), strdup("="), 0, $1, $3, NULL, NULL); }
	;

storage_class_specifier
	: TYPEDEF
	| EXTERN
	| STATIC
	| AUTO
	| REGISTER
	;

type_specifier
	: VOID {$$ = makeNode(strdup("VOID"), strdup("void"), 0, NULL, NULL, NULL, NULL);}
	| CHAR {$$ = makeNode(strdup("CHAR"), strdup("char"), 0, NULL, NULL, NULL, NULL);}
	| SHORT {$$ = makeNode(strdup("SHORT"), strdup("short"), 0, NULL, NULL, NULL, NULL);}
	| INT {$$ = makeNode(strdup("INT"), strdup("int"), 0, NULL, NULL, NULL, NULL);}
	| LONG {$$ = makeNode(strdup("LONG"), strdup("long"), 0, NULL, NULL, NULL, NULL);}
	| FLOAT {$$ = makeNode(strdup("FLOAT"), strdup("float"), 0, NULL, NULL, NULL, NULL);}
	| DOUBLE {$$ = makeNode(strdup("DOUBLE"), strdup("double"), 0, NULL, NULL, NULL, NULL);}
	| SIGNED {$$ = makeNode(strdup("SIGNED"), strdup("signed"), 0, NULL, NULL, NULL, NULL);}
	| UNSIGNED {$$ = makeNode(strdup("UNSIGNED"), strdup("unsigned"), 0, NULL, NULL, NULL, NULL);}
	| struct_or_union_specifier {$$ = NULL;}
	| enum_specifier {$$ = $1;}
	| TYPE_NAME {$$ = makeNode(strdup("TYPE_NAME"), strdup(""), 0, NULL, NULL, NULL, NULL);}
	;

struct_or_union_specifier
	: struct_or_union IDENTIFIER '{' struct_declaration_list '}' 
	| struct_or_union '{' struct_declaration_list '}'
	| struct_or_union IDENTIFIER
	;

struct_or_union
	: STRUCT {$$ = makeNode(strdup("STRUCT"), strdup("struct"), 0, NULL, NULL, NULL, NULL);}
	| UNION {$$ = makeNode(strdup("UNION"), strdup("union"), 0, NULL, NULL, NULL, NULL);}
	;

struct_declaration_list
	: struct_declaration { $$ = $1; }
	| struct_declaration_list struct_declaration { makeSibling($2, $1); $$ = $1; }
	;

struct_declaration
	: specifier_qualifier_list struct_declarator_list ';'
	;

specifier_qualifier_list
	: type_specifier specifier_qualifier_list { makeSibling($2, $1); $$ = $1; }
	| type_specifier { $$ = $1; }
	| type_qualifier specifier_qualifier_list { makeSibling($2, $1); $$ = $1; }
	| type_qualifier { $$ = $1; }
	;

struct_declarator_list
	: struct_declarator { $$ = $1; }
	| struct_declarator_list ',' struct_declarator
	;

struct_declarator
	: declarator { $$ = $1; }
	| ':' constant_expression
	| declarator ':' constant_expression
	;

enum_specifier
	: ENUM '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup(""), 0, $3, NULL, NULL, NULL);}
	| ENUM IDENTIFIER '{' enumerator_list '}' {$$ = makeNode(strdup("ENUM"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 0, $4, NULL, NULL, NULL), NULL, NULL, NULL);}
	| ENUM IDENTIFIER {$$ = NULL}
	;

enumerator_list
	: enumerator { $$ = $1; }
	| enumerator_list ',' enumerator { makeSibling($3, $1); $$ = $1;} 
	;

enumerator
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| IDENTIFIER '=' constant_expression {$$ = makeNode(strdup("="),strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), $3, NULL, NULL);}
	;

type_qualifier
	: CONST
	| VOLATILE
	;

declarator
	: pointer direct_declarator  { $$ = $1; }
	| direct_declarator { $$ = $1; }
	;

direct_declarator
	: IDENTIFIER { $$ = makeNode(strdup("IDENTIFIER"), strdup(""), 0, NULL, NULL, NULL, NULL); }
	| '(' declarator ')' { $$ = $2;}
	| direct_declarator '[' constant_expression ']' { $$ = $1; }
	| direct_declarator '[' ']' {$$ = $1; }
	| direct_declarator '(' parameter_type_list ')' { $$ = $1; }
	| direct_declarator '(' identifier_list ')' { $$ = $1; }
	| direct_declarator '(' ')' { $$ = $1; }
	;

pointer
	: '*' {$$ = makeNode(strdup("*"), strdup("*"), 1, NULL, NULL, NULL, NULL);}
	| '*' type_qualifier_list {$$ = makeNode(strdup("*"), strdup("*"), 0, $2, NULL, NULL, NULL); }
	| '*' pointer {$$ = makeNode(strdup("*"), strdup("*"), 0, $2, NULL, NULL, NULL); }
	| '*' type_qualifier_list pointer 
	;

type_qualifier_list
	: type_qualifier { $$ = $1; }
	| type_qualifier_list type_qualifier { makeSibling($2, $1); $$ = $1;}
	;


parameter_type_list
	: parameter_list { $$ = $1; }
	| parameter_list ',' ELLIPSIS { makeSibling(makeNode(strdup("ELLIPSIS"), strdup("..."), 1, NULL, NULL, NULL, NULL), $1); $$ = $1;}
	;

parameter_list
	: parameter_declaration { $$ = $1; }
	| parameter_list ',' parameter_declaration { makeSibling($3, $1); $$ = $1;}
	;

parameter_declaration
	: declaration_specifiers declarator { $$ = $2; }
	| declaration_specifiers abstract_declarator { $$ = $2; }
	| declaration_specifiers { $$ = NULL; }
	;

identifier_list
	: IDENTIFIER {$$ = makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| identifier_list ',' IDENTIFIER { makeSibling(makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), $1); $$ = $1;}
	;

type_name
	: specifier_qualifier_list { $$ = $1; }
	| specifier_qualifier_list abstract_declarator 
	;

abstract_declarator
	: pointer { $$ = $1; }
	| direct_abstract_declarator { $$ = $1; }
	| pointer direct_abstract_declarator
	;

direct_abstract_declarator
	: '(' abstract_declarator ')' {$$ = $2;}
	| '[' ']'
	| '[' constant_expression ']' {$$ = $2;}
	| direct_abstract_declarator '[' ']' 
	| direct_abstract_declarator '[' constant_expression ']'
	| '(' ')'
	| '(' parameter_type_list ')'
	| direct_abstract_declarator '(' ')'
	| direct_abstract_declarator '(' parameter_type_list ')'
	;

initializer
	: assignment_expression { $$ = $1; }
	| '{' initializer_list '}' { $$ = $2; }
	| '{' initializer_list ',' '}' { $$ = $2; }
	;

initializer_list
	: initializer { $$ = $1; }
	| initializer_list ',' initializer {makeSibling($2, $1); $$ = $1;}
	;

statement
	: labeled_statement { $$ = $1; }
	| compound_statement { $$ = $1; }
	| expression_statement { $$ = $1; }
	| selection_statement { $$ = $1; }
	| iteration_statement { $$ = $1; }
	| jump_statement { $$ = $1; }
	;

labeled_statement
	: IDENTIFIER ':' statement {$$ = makeNode(strdup(":"), strdup(:), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), $3, NULL, NULL);}
	| CASE constant_expression ':' statement { $$ = makeNode(strdup("CASE"), strdup("case"), 0, $2, $4, NULL, NULL); }
	| DEFAULT ':' statement {$$ = makeNode(strdup(":"), strdup(:), 0, makeNode(strdup("DEFAULT"), strdup("default"), 1, NULL, NULL, NULL, NULL), $3, NULL, NULL);}
	;

compound_statement
	: '{' '}' { $$ = NULL; }
	| '{' statement_list '}' { $$ = $2; }
	| '{' declaration_list '}' { $$ = NULL; }
	| '{' declaration_list statement_list '}' { $$ = $3; }
	;

declaration_list
	: declaration { $$ = $1; }
	| declaration_list declaration {makeSibling($2, $1); $$ = $1; }
	;

statement_list
	: statement { $$ = $1; }
	| statement_list statement { makeSibling($2, $1); $$ = $1; }
	;

expression_statement
	: ';' {$$ = makeNode(strdup(";"), strdup(";"), 0, NULL, NULL, NULL, NULL);}
	| expression ';' {makeSibling(makeNode(strdup(";"), strdup(";"), 0, NULL, NULL, NULL, NULL), $1); $$ = $1;}
	;

selection_statement
	: IF '(' expression ')' statement {$$ = makeNode(strdup("IF"), strdup("if"),0, $3, $5, NULL, NULL);}
	| IF '(' expression ')' statement ELSE statement {$$ = makeNode(strdup("IF_ELSE"), strdup(""),0, $3, $5, $7, NULL);}
	| SWITCH '(' expression ')' statement {$$ = makeNode(strdup("SWITCH"), strdup(""),0, $3, $5, NULL, NULL);}
	;

iteration_statement
	: WHILE '(' expression ')' statement {$$ = makeNode(strdup("WHILE"), strdup(""), 0, $1, $2, NULL, NULL);}
	| DO statement WHILE '(' expression ')' ';' {$$ = makeNode(strdup("DO WHILE"), strdup(""), 0, $1, $2, NULL, NULL);}
	| FOR '(' expression_statement expression_statement ')' statement {$$ = makeNode(strdup("FOR"), strdup(""),0, $3, $4, $6, NULL);}
	| FOR '(' expression_statement expression_statement expression ')' statement {$$ = makeNode(strdup("FOR"), strdup(""),0, $3, $4, $5, $7);}
	;

jump_statement
	: GOTO IDENTIFIER ';' {$$ = makeNode(strdup("GOTO"), strdup(""), 0, makeNode(strdup("IDENTIFIER"), strdup(""), 1, NULL, NULL, NULL, NULL), NULL, NULL, NULL);}
	| CONTINUE ';'{ $$ = makeNode(strdup("CONTINUE"), strdup(""), NULL, NULL, NULL, NULL);}
	| BREAK ';' { $$ = makeNode(strdup("BREAK"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| RETURN ';' { $$ = makeNode(strdup("CONTINUE"), strdup(""), 1, NULL, NULL, NULL, NULL);}
	| RETURN expression ';' { $$ = makeNode(strdup("RETURN"), strdup(""), 0, $1, NULL, NULL, NULL);}
	;

translation_unit
	: external_declaration { $$ = $1;}
	| translation_unit external_declaration {makeSibling($1,$2); $$=$1;}
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

start
	: translation_unit { $$ = makeNode(strdup("ROOT"), strdup("root"), 0, $1, NULL, NULL, NULL);  root = $$; }
%%
#include <stdio.h>
int id = 0;

typedef struct node{
	// int type;
	int id;
	char* name;
	char* lexeme;
	int isLeaf;
	node* next;
	node* childList;
}node;

node* root;

node* makeNode(char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = (node*) malloc(sizeof(node));
	newNode->id = id++;
	newNode->name = (char*)malloc(sizeof(char*(strlen(name)+1)));
	newNode->lexeme = (char*)malloc(sizeof(char*(strlen(lexeme)+1)));
	strcpy(newNode->name, name);
	strcpy(newNode->lexeme, lexeme);
	newNode->isLeaf = isLeaf;
	newNode->childList = c1;
	makeSibling(c2,newNode->childList);
	makeSibling(c3,newNode->childList);
	makeSibling(c4,newNode->childList);
	return newNode;
}

void makeSibling(node* node, node* childList){
	if(!node) return;
	node* curr  = childList;
	node* prev  = NULL;
	while(curr){
		prev = curr;
		curr = curr->next;
	}
	prev->next = node;
}

void addChild(node* parent, node* child){
	if(parent->childList == NULL){
		parent->childList = child;
	}
	else{
		makeSibling(child, parent->childList);
	}
}

extern char yytext[];
extern int column;
yyerror(s)
char *s;
{
	fflush(stdout);
	printf("\n%*s\n%*s\n", column, "^", column, s);
}