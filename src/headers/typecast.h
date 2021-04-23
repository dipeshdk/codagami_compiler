#ifndef typeCastHeader
#define typeCastHeader

#include "constants.h"  
#include "structures.h" 

string getTypeName(int type);
string getTypeString(vector<int> type);

int checkValidType(vector<int> &v);
bool checkType(declSpec *ds, int typeName, int ptrLevel);
int canTypecast(declSpec* to_ds,  declSpec* from_ds);
void checkTypeArrayWithTypecast(node* idNode, int &errCode, string &errStr);
bool requiresTypeCasting(declSpec* n1, declSpec* n2);


int checkIntOrCharOrPointer(node* root);
int checkIntOrChar(node* root);

int checkPointer(node* root);

int giveTypeCastRankUnary(node* n1, node* n2);
int getTypeRank(vector<int> &type);
int giveTypeCastRank(node* n1, node* n2);

void typeCastLexeme(node* temp, declSpec* dp);
void typeCastLexemeWithEmit(node* temp, declSpec* dp);
int typeCastByRank(node*n1, node*n2, int rank);

int bitwiseTypecastingSingleNode(node* n, int& errCode, string& errStr);
int bitwiseImplicitTypecasting(node*n1, node*n2, int& errCode, string& errStr);
int implicitTypecastingNotPointerNotStringLiteral(node*n1, node*n2, string& var);
int implicitTypecastingNotStringLiteral(node*n1, node*n2, string& var);

// Deprecated
int checkStringLiteralDecl(declSpec* root);

node* makeNodeForExpressionByRank(node* n1, node* n2, string lexeme, string name, int rank, int& errCode, string& errStr);
node* makeNodeForExpressionNotPointerNotString(node* n1, node* n2, string name, int& errCode, string& errStr);

bool areDifferentTypes(declSpec* to_ds,  declSpec* from_ds, int &errCode, string &errStr);
bool typeCastRequired(declSpec* to_ds,  declSpec* from_ds, int &errCode, string &errStr);
#endif