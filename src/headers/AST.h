#ifndef ASTHeader
#define ASTHeader

#include "constants.h"
#include "structures.h"

node *makeNode(char *name, char *lexeme, int isLeaf, node *c1, node *c2, node *c3, node *c4);
node *makeDeadNode();
node *makeTypeNode(int type);

void makeSibling(node *root, node *childList);
void addChild(node *parent, node *child);

bool isConstantNode(node *node);
bool isStringLiteral(node *node);
#endif