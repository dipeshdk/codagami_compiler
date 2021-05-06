#include "headers/allInclude.h"

void printDeclarations(node *root, FILE *fp)
{
    if (!root || root->isLeaf == DEAD_NODE)
        return;
    string s1(root->name), s2(root->lexeme);
    string s = "n: " + s1 + " , l: " + s2 + "\0";
    if (root->isLeaf)
    {
        fprintf(fp, "%d [label=\"%s\"];\n", root->id, s.c_str());
    }
    else
    {
        fprintf(fp, "%d [label=\"%s\"];\n", root->id, s.c_str());
    }
    node *childList = root->childList;
    while (childList)
    {
        printDeclarations(childList, fp);
        childList = childList->next;
    }
}

void printEdges(node *root, FILE *fp)
{
    if (root->isLeaf == DEAD_NODE)
        return;
    node *child = root->childList;
    while (child)
    {
        if (child->isLeaf == DEAD_NODE)
        {
            child = child->next;
            continue;
        }
        fprintf(fp, "%d -> %d\n", root->id, child->id);
        printEdges(child, fp);
        child = child->next;
    }
}

void generateDot(node *root, char *fileName)
{
    FILE *fp;
    fp = fopen(fileName, "w");
    fprintf(fp, "strict digraph AST {\n");
    printDeclarations(root, fp);
    printEdges(root, fp);
    fprintf(fp, "}\n");
    fclose(fp);
}