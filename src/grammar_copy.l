D			[0-9]
L			[a-zA-Z_]
H			[a-fA-F0-9]
E			[Ee][+-]?{D}+
FS			(f|F)
LS          (l|L)
IS			(u|U|l|L)*

%{
#include <stdio.h>
#include "y.tab.h"

void count();
void error();
int check_type();
int comment();
char* previ;
%}

%%
"/*"			{ comment(); }

"auto"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(AUTO); }
"break"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(BREAK); }
"case"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(CASE); }
"char"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(CHAR); }
"const"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(CONST); }
"continue"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(CONTINUE); }
"default"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(DEFAULT); }
"do"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(DO); }
"double"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(DOUBLE); }
"else"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(ELSE); }
"enum"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(ENUM); }
"extern"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(EXTERN); }
"float"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(FLOAT); }
"for"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(FOR); }
"goto"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(GOTO); }
"if"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(IF); }
"int"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(INT); }
"long"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(LONG); }
"register"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(REGISTER); }
"return"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(RETURN); }
"short"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(SHORT); }
"signed"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(SIGNED); }
"sizeof"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(SIZEOF); }
"static"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(STATIC); }
"struct"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(STRUCT); }
"switch"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(SWITCH); }
"typedef"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(TYPEDEF); }
"union"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(UNION); }
"unsigned"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(UNSIGNED); }
"void"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(VOID); }
"volatile"		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(VOLATILE); }
"while"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(WHILE); }

{L}({L}|{D})*		{ count(); previ = yylval.id; yylval.id = strdup(yytext); return(check_type()); }

0[xX]{H}+{IS}?		{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }
0{D}+{IS}?		{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }
{D}+{IS}?		{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }
L?'(\\.|[^\\'])+'	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }

{D}+{E}{FS}?		{ count();previ = yylval.id; yylval.id = strdup(yytext); return(F_CONSTANT); }
{D}*"."{D}+({E})?{FS}?	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(F_CONSTANT); }
{D}+"."{D}*({E})?{FS}?	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(F_CONSTANT); }

{D}+{E}{LS}?		{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }
{D}*"."{D}+({E})?{LS}?	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }
{D}+"."{D}*({E})?{LS}?	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(I_CONSTANT); }

L?\"(\\.|[^\\"])*\"	{ count();previ = yylval.id; yylval.id = strdup(yytext); return(STRING_LITERAL); }

"..."			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(ELLIPSIS); }
">>="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(RIGHT_ASSIGN); }
"<<="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(LEFT_ASSIGN); }
"+="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(ADD_ASSIGN); }
"-="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(SUB_ASSIGN); }
"*="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(MUL_ASSIGN); }
"/="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(DIV_ASSIGN); }
"%="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(MOD_ASSIGN); }
"&="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(AND_ASSIGN); }
"^="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(XOR_ASSIGN); }
"|="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(OR_ASSIGN); }
">>"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(RIGHT_OP); }
"<<"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(LEFT_OP); }
"++"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(INC_OP); }
"--"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(DEC_OP); }
"->"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(PTR_OP); }
"&&"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(AND_OP); }
"||"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(OR_OP); }
"<="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(LE_OP); }
">="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(GE_OP); }
"=="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(EQ_OP); }
"!="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(NE_OP); }
";"			{ count(); previ = yylval.id; yylval.id = strdup(yytext); return(';'); }
("{"|"<%")		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('{'); }
("}"|"%>")		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('}'); }
","			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(','); }
":"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(':'); }
"="			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('='); }
"("			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('('); }
")"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(')'); }
("["|"<:")		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('['); }
("]"|":>")		{ count();  previ = yylval.id; yylval.id = strdup(yytext); return(']'); }
"."			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('.'); }
"&"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('&'); }
"!"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('!'); }
"~"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('~'); }
"-"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('-'); }
"+"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('+'); }
"*"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('*'); }
"/"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('/'); }
"%"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('%'); }
"<"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('<'); }
">"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('>'); }
"^"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('^'); }
"|"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('|'); }
"?"			{ count();  previ = yylval.id; yylval.id = strdup(yytext); return('?'); }

[ \t\v\n\f]		{ count();}
.			{ count();  error(); }

%%

int yywrap()
{
	return(1);
}

int prevCol = 0,  column = 0, line = 0;

void error() {
    printf("ERROR: line: %d column: %d\nexiting....\n", line+1, prevCol+1);
    exit(0);
}

int comment()
{
	char c, c1;

loop:
	while ((c = input()) != '*' && c != 0)
		//putchar(c);
        ;

	if ((c1 = input()) != '/' && c != 0)
	{
		//unput(c1);
		goto loop;
	}

	if (c != 0)
		//putchar(c1);
        ;
}



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

// TODO:
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
        // case CONSTANT: strcpy(c, "CONSTANT\0"); break;
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

// void printTable(int token) {
//     char c[20];
//     getTokenName(token,c);
//     printf("    %-15s\t\t %-35s\t\t %8d\t %8d\n", c, yytext, line+1, prevCol+1);
// }

// int yylval.id = strdup(yytext)(char id){
//     switch id{
//         case 'I':
//             yylval.ival = atoi(yytext);
//             // yylval.sval = strdup(yytext);
//             break;
//         case 'F':
//             yylval.fval = atof(yytext);
//             break;
//         case 'S':
//             yylval.sval = strdup(yytext);
//             break; 
//         default:
//             break;
//     }   
// }

// int main(int ac, char **av) {
//     int val;
//     FILE    *fd;
//      if (ac == 2)
//     {
//         if (!(fd = fopen(av[1], "r")))
//         {
//             perror("Error: ");
//             return (-1);
//         }
//         yyset_in(fd);
//         printf("    %-15s\t\t %-35s\t\t %8s\t %8s\n\n", "Token", "Lexeme", "Line#", "Column#");
//         while((val=yylex()) > 0) {
//             printTable(val);
//         }
//         fclose(fd);
//     }
//     else
//         printf("Usage: a.out filename\n");
//     return (0);
    
// }