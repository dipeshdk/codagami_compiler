D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F|l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

void error() {
    printf("ERROR: line: %d column: %d\nexiting....\n", line+1, prevCol+1);
    exit(0);
}

void count();
%}

%%
"/*"			{ comment(); }

"auto"			{ count(); return(AUTO); }
"break"			{ count(); return(BREAK); }
"case"			{ count(); return(CASE); }
"char"			{ count(); return(CHAR); }
"const"			{ count(); return(CONST); }
"continue"		{ count(); return(CONTINUE); }
"default"		{ count(); return(DEFAULT); }
"do"			{ count(); return(DO); }
"double"		{ count(); return(DOUBLE); }
"else"			{ count(); return(ELSE); }
"enum"			{ count(); return(ENUM); }
"extern"		{ count(); return(EXTERN); }
"float"			{ count(); return(FLOAT); }
"for"			{ count(); return(FOR); }
"goto"			{ count(); return(GOTO); }
"if"			{ count(); return(IF); }
"int"			{ count(); return(INT); }
"long"			{ count(); return(LONG); }
"register"		{ count(); return(REGISTER); }
"return"		{ count(); return(RETURN); }
"short"			{ count(); return(SHORT); }
"signed"		{ count(); return(SIGNED); }
"sizeof"		{ count(); return(SIZEOF); }
"static"		{ count(); return(STATIC); }
"struct"		{ count(); return(STRUCT); }
"switch"		{ count(); return(SWITCH); }
"typedef"		{ count(); return(TYPEDEF); }
"union"			{ count(); return(UNION); }
"unsigned"		{ count(); return(UNSIGNED); }
"void"			{ count(); return(VOID); }
"volatile"		{ count(); return(VOLATILE); }
"while"			{ count(); return(WHILE); }

{L}({L}|{D})*		{ count(); return(check_type()); }

0[xX]{H}+{IS}?		{ count(); return(CONSTANT); }
0{D}+{IS}?		{ count(); return(CONSTANT); }
{D}+{IS}?		{ count(); return(CONSTANT); }
L?'(\\.|[^\\'])+'	{ count(); return(CONSTANT); }

{D}+{E}{FS}?		{ count(); return(CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count(); return(CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count(); return(CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count(); return(STRING_LITERAL); }

"..."			{ count(); return(ELLIPSIS); }
">>="			{ count(); return(RIGHT_ASSIGN); }
"<<="			{ count(); return(LEFT_ASSIGN); }
"+="			{ count(); return(ADD_ASSIGN); }
"-="			{ count(); return(SUB_ASSIGN); }
"*="			{ count(); return(MUL_ASSIGN); }
"/="			{ count(); return(DIV_ASSIGN); }
"%="			{ count(); return(MOD_ASSIGN); }
"&="			{ count(); return(AND_ASSIGN); }
"^="			{ count(); return(XOR_ASSIGN); }
"|="			{ count(); return(OR_ASSIGN); }
">>"			{ count(); return(RIGHT_OP); }
"<<"			{ count(); return(LEFT_OP); }
"++"			{ count(); return(INC_OP); }
"--"			{ count(); return(DEC_OP); }
"->"			{ count(); return(PTR_OP); }
"&&"			{ count(); return(AND_OP); }
"||"			{ count(); return(OR_OP); }
"<="			{ count(); return(LE_OP); }
">="			{ count(); return(GE_OP); }
"=="			{ count(); return(EQ_OP); }
"!="			{ count(); return(NE_OP); }
";"			{ count(); return(';'); }
("{"|"<%")		{ count(); return('{'); }
("}"|"%>")		{ count(); return('}'); }
","			{ count(); return(','); }
":"			{ count(); return(':'); }
"="			{ count(); return('='); }
"("			{ count(); return('('); }
")"			{ count(); return(')'); }
("["|"<:")		{ count(); return('['); }
("]"|":>")		{ count(); return(']'); }
"."			{ count(); return('.'); }
"&"			{ count(); return('&'); }
"!"			{ count(); return('!'); }
"~"			{ count(); return('~'); }
"-"			{ count(); return('-'); }
"+"			{ count(); return('+'); }
"*"			{ count(); return('*'); }
"/"			{ count(); return('/'); }
"%"			{ count(); return('%'); }
"<"			{ count(); return('<'); }
">"			{ count(); return('>'); }
"^"			{ count(); return('^'); }
"|"			{ count(); return('|'); }
"?"			{ count(); return('?'); }

[ \t\v\n\f]		{ count(); }
.			{ count(); error(); }

%%

yywrap()
{
	return(1);
}


comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		putchar(c);

	if ((c1 = input()) != '/' && c != 0)
	{
		unput(c1);
		goto loop;
	}

	if (c != 0)
		putchar(c1);
}

int prevCol = 0;
int column = 0;
int line = 0;

void count()
{
	int i;
    prevCol = column;
	for (i = 0; yytext[i] != '\0'; i++) {
		if (yytext[i] == '\n'){
			column = prevCol = 0;
            line++;
        }
		else if (yytext[i] == '\t') {
			column += 8 - (column % 8);
        }
		else {
			column++;
        }
        if(yytext[i] == ' ' || yytext[i] == '\t') {
            prevCol = column;
        }
    }

	// ECHO;
}


int check_type()
{
/*
* pseudo code --- this is what it should check
*
*	if (yytext == type_name)
*		return(TYPE_NAME);
*
*	return(IDENTIFIER);
*/

/*
*	it actually will only return IDENTIFIER
*/

	return(IDENTIFIER);
}

void getTokenName(int ind, char c[]) {
    switch(ind) {
        case IDENTIFIER: strcpy(c, "IDENTIFIER\0"); break;
        case CONSTANT: strcpy(c, "CONSTANT\0"); break;
        case STRING_LITERAL: strcpy(c, "STRING_LITERAL\0"); break;
        case SIZEOF: strcpy(c, "SIZEOF\0"); break;
        case PTR_OP: strcpy(c, "PTR_OP\0"); break;
        case INC_OP: strcpy(c, "INC_OP\0"); break;
        case DEC_OP: strcpy(c, "DEC_OP\0"); break;
        case LEFT_OP: strcpy(c, "LEFT_OP\0"); break;
        case RIGHT_OP: strcpy(c, "RIGHT_OP\0"); break;
        case LE_OP: strcpy(c, "LE_OP\0"); break;
        case GE_OP: strcpy(c, "GE_OP\0"); break;
        case EQ_OP: strcpy(c, "EQ_OP\0"); break;
        case NE_OP: strcpy(c, "NE_OP\0"); break;
        case AND_OP: strcpy(c, "AND_OP\0"); break;
        case OR_OP: strcpy(c, "OR_OP\0"); break;
        case MUL_ASSIGN: strcpy(c, "MUL_ASSIGN\0"); break;
        case DIV_ASSIGN: strcpy(c, "DIV_ASSIGN\0"); break;
        case MOD_ASSIGN: strcpy(c, "MOD_ASSIGN\0"); break;
        case ADD_ASSIGN: strcpy(c, "ADD_ASSIGN\0"); break;
        case SUB_ASSIGN: strcpy(c, "SUB_ASSIGN\0"); break;
        case LEFT_ASSIGN: strcpy(c, "LEFT_ASSIGN\0"); break;
        case RIGHT_ASSIGN: strcpy(c, "RIGHT_ASSIGN\0"); break;
        case AND_ASSIGN: strcpy(c, "AND_ASSIGN\0"); break;
        case XOR_ASSIGN: strcpy(c, "XOR_ASSIGN\0"); break;
        case OR_ASSIGN: strcpy(c, "OR_ASSIGN\0"); break;
        case TYPE_NAME: strcpy(c, "TYPE_NAME\0"); break;
        case TYPEDEF: strcpy(c, "TYPEDEF\0"); break;
        case EXTERN: strcpy(c, "EXTERN\0"); break;
        case STATIC: strcpy(c, "STATIC\0"); break;
        case AUTO: strcpy(c, "AUTO\0"); break;
        case REGISTER: strcpy(c, "REGISTER\0"); break;
        case CHAR: strcpy(c, "CHAR\0"); break;
        case SHORT: strcpy(c, "SHORT\0"); break;
        case INT: strcpy(c, "INT\0"); break;
        case LONG: strcpy(c, "LONG\0"); break;
        case SIGNED: strcpy(c, "SIGNED\0"); break;
        case UNSIGNED: strcpy(c, "UNSIGNED\0"); break;
        case FLOAT: strcpy(c, "FLOAT\0"); break;
        case DOUBLE: strcpy(c, "DOUBLE\0"); break;
        case CONST: strcpy(c, "CONST\0"); break;
        case VOLATILE: strcpy(c, "VOLATILE\0"); break;
        case VOID: strcpy(c, "VOID\0"); break;
        case STRUCT: strcpy(c, "STRUCT\0"); break;
        case UNION: strcpy(c, "UNION\0"); break;
        case ENUM: strcpy(c, "ENUM\0"); break;
        case ELLIPSIS: strcpy(c, "ELLIPSIS\0"); break;
        case CASE: strcpy(c, "CASE\0"); break;
        case DEFAULT: strcpy(c, "DEFAULT\0"); break;
        case IF: strcpy(c, "IF\0"); break;
        case ELSE: strcpy(c, "ELSE\0"); break;
        case SWITCH: strcpy(c, "SWITCH\0"); break;
        case WHILE: strcpy(c, "WHILE\0"); break;
        case DO: strcpy(c, "DO\0"); break;
        case FOR: strcpy(c, "FOR\0"); break;
        case GOTO: strcpy(c, "GOTO\0"); break;
        case CONTINUE: strcpy(c, "CONTINUE\0"); break;
        case BREAK: strcpy(c, "BREAK\0"); break;
        case RETURN: strcpy(c, "RETURN\0"); break;
        default: c[0]=ind; c[1] = '\0';
    }
}

void printTable(int token) {
    char c[20];
    getTokenName(token,c);
    printf("    %-10s\t\t %-12s\t\t %8d\t %8d\n", c, yytext, line+1, prevCol+1);
}

int main(int ac, char **av) {
    int val;
    FILE    *fd;
     if (ac == 2)
    {
        if (!(fd = fopen(av[1], "r")))
        {
            perror("Error: ");
            return (-1);
        }
        yyset_in(fd);
        printf("    %-10s\t\t %-12s\t\t %8s\t %8s\n\n", "Token", "Lexeme", "Line#", "Column#");
        while((val=yylex()) > 0) {
            printTable(val);
        }
        fclose(fd);
    }
    else
        printf("Usage: a.out filename\n");
    return (0);
    
}