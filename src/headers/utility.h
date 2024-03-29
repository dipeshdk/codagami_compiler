#ifndef utilityHeader
#define utilityHeader

#include "constants.h"
#include "structures.h"

int mergeConstVolatile(node* temp, node* from);

int incrementPointerLevel(node* temp, node* from);

int copyPtrLevel(node* temp, node* from);

int getValueFromConstantExpression(node* constant_expression, int& err);

void setErrorParams(int& errCode, int code, string& errString, string str);

void error(string var, int error_code);

void copyList(node* n1, node* n2);

bool isConstant(string s);

string hexString(string decStr);

int getNumberFromConstAddr(string s);

string extractFileName(string str);

string removeExtension(string str);

void typeCastWarning(string from, string to);

#endif