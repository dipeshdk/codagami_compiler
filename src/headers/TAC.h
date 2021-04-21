#ifndef TACHeader
#define TACHeader
#include "constants.h"  
#include "structures.h" 

vector<int> makelist(int i);
vector<int> makelist();

vector<int> mergelist(vector<int> &list1,vector<int> &list2);

int backpatch(vector<int> &list, int i);

void emit(int opCode, string arg1, string arg2, string result);

int nextQuad();

string generateTemp(int &errCode);

void setAddr(node* n, string addr);

int getOpMulType(node* temp, int &errCode, string &errStr);
int getOpAddType(node* temp, int &errCode, string &errStr);
int getOpDivType(node* temp, int &errCode, string &errStr);
int getOpSubType(node* temp, int &errCode, string &errStr);
void emitRelop(node* n1, node* n2, node* temp, int opCode, int& errCode, string &errStr);
void emitOperationAssignment(node* unary_expression, node* assignment_expression, int opCode, string resultAddr, int &errCode, string &errStr);
string emitTypeCast(node* node, declSpec *toDs, int &errCode, string &errStr);
int getOpcodeFromAssignStr(string s);
string getArrayIndexWithEmit(node *postfix_expression , node *expression, int &errCode, string &errStr);
#endif