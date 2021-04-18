#include<bits/stdc++.h>
using namespace std;

#define TEMP_LINE_NO -301

#define NOT_GOTO_IN_BACKPATCH 401

#define OP_GOTO 1
#define OP_ADDI 2
#define OP_MULI 3 
#define OP_IFGOTO 4
#define OP_SUBI 5
#define OP_ASSIGNMENT 6
#define OP_UNARY_MINUS 7
#define OP_DIVI 8
#define OP_CALL 9
#define OP_LEFT_SHIFT 10
#define OP_RIGHT_SHIFT 11
#define OP_NOR 12
#define OP_OR 13
#define OP_AND 14
#define OP_NOT 15
#define OP_XOR 16
#define OP_EQ 17
#define OP_NEQ 18
#define OP_LEQ 19
#define OP_GREATER 20
#define OP_LESS 21
#define OP_MOD 22
#define OP_ADDF 23
#define OP_MULF 24
#define OP_SUBF 25
#define OP_DIVF 26


struct quadruple {
    int opCode;
    string arg1, arg2, result;
};

// struct symbol {
//     int variabletype;
//     symbol(int varType) {
//         variabletype = varType;
//     }
// };

vector<int> makelist(int i);

vector<int> makelist();

vector<int> mergelist(vector<int> &list1,vector<int> &list2);

int backpatch(vector<int> &list, int i);

void emit(int opCode, string arg1, string arg2, string result);

int nextQuad();

string generateTemp();