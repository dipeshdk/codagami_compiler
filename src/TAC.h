#include<bits/stdc++.h>
using namespace std;

#define TYPE_CHAR 1
#define TYPE_SHORT 2
#define TYPE_INT 3 
#define TYPE_LONG 4
#define TYPE_FLOAT 5
#define TYPE_DOUBLE 6
#define TYPE_SIGNED 7
#define TYPE_UNSIGNED 8
#define TYPE_VOID 9
#define TYPE_STRUCT 10
#define TYPE_UNION 11
#define TYPE_ENUM 12
#define TYPE_TYPEDEF 13
#define TYPE_EXTERN 14
#define TYPE_STATIC 15
#define TYPE_AUTO 16
#define TYPE_REGISTER 17
#define TYPE_STRING_LITERAL 18


#define GOTO 1
#define ADD 2
#define MULTIPLY 3 
#define IFGOTO 4
#define SUBTRACT 5
#define ASSIGNMENT 6
#define UNARY_MINUS 7
#define DIVISION 8
#define CALL 9
#define LEFT_SHIFT 10
#define RIGHT_SHIFT 11
#define NOR 12
#define OR 13
#define AND 14
#define NOT 15
#define XOR 16
#define EQUALITY 17
#define NEQ 18
#define LEQ 19
#define GREATER 20
#define LESS 21


struct quadruple {
    int opCode;
    string arg1, arg2, result;
};

struct symbol {
    int variabletype;
    symbol(int varType) {
        variabletype = varType;
    }
};