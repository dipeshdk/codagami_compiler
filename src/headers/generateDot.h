#ifndef generateHeader
#define generateHeader

#include "constants.h"
#include "structures.h"

void printDeclarations(node* root, FILE* fp);
void printEdges(node* root, FILE* fp);
void generateDot(node* root, char* fileName);

#endif