#ifndef typeCastHeader
#define typeCastHeader

#include "constants.h"  
#include "structures.h" 

string getTypeName(int type);
string getTypeString(vector<int> type);

int checkValidType(vector<int> &v);
bool checkType(declSpec *ds, int typeName, int ptrLevel);
int canTypecast(declSpec* to_ds,  declSpec* from_ds);
int checkTypeArray(vector<int> &v);
bool requiresTypeCasting(declSpec* n1, declSpec* n2);


int checkIntOrCharOrPointer(node* root);
int checkIntOrChar(node* root);

int checkPointer(node* root);

int giveTypeCastRankUnary(node* n1, node* n2);
int getTypeRank(vector<int> &type);
int giveTypeCastRank(node* n1, node* n2);

void typeCastLexeme(node* temp, declSpec* dp);
int typeCastByRank(node*n1, node*n2, int rank);

int implicitTypecastingNotPointerNotStringLiteral(node*n1, node*n2, string& var);
int implicitTypecastingNotStringLiteral(node*n1, node*n2, string& var);

// Deprecated
int checkStringLiteralDecl(declSpec* root);

node* makeNodeForExpressionByRank(node* n1, node* n2, string lexeme, string name, int rank, int& errCode, string& errStr);
node* makeNodeForExpressionNotPointerNotString(node* n1, node* n2, string name, int& errCode, string& errStr);


#endif