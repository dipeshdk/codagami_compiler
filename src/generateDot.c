#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
Example output:
strict digraph G {
    1 [label="A"];
    2 [label="B"];
    3 [label="B"];
    4 [label="A"];
    1 -> 2;
    2 -> 3;
    3 -> 4;
}

strict digraph GraphName {
    //Declarations 
    ...
    struct node.id [label=struct node.name]
    ...
    //Graph Edges
    struct node.id -> struct node.child.id
}
*/
//TODO: Create a separate file and import
typedef struct node{
	// int type;
	int id;
	char* name;
	char* lexeme;
	int isLeaf;
	struct node* next;
	struct node* childList;
}node;

void printDeclarations(node* root) {
    if(!root) return;
    printf("%d [label=\"%s\"];\n", root->id, root->name);
    node* childList = root->childList;
    while(childList) {
        printDeclarations(childList);
        childList = childList->next;
    }
}        

void printEdges(node* root) {
    node* child = root->childList;
    while(child) {
        printf("%d -> %d\n", root->id, child->id);
        printEdges(child);
        child = child->next;
    }
}

void generateDot(node* root) {
    printf("strict digraph AST {\n");
    printDeclarations(root);
    printEdges(root);
    printf("}\n");

}

int main() {
    FILE *fp;
    fp = fopen("/tmp/test.txt", "w+");
    // fprintf(fp, "This is testing for fprintf...\n");
    // fputs("This is testing for fputs...\n", fp);

    //example graph
    /*
               a
             /   \
            b     c
          /   \
         d     e
    */
    node *a = (node*) malloc(sizeof(node));
    node *b = (node*) malloc(sizeof(node));
    node *c = (node*) malloc(sizeof(node));
    node *d = (node*) malloc(sizeof(node));
    node *e = (node*) malloc(sizeof(node));

    a->childList = b;
    b->next = c;
    b->childList = d;
    d->next = e;

   a->id=0;
   b->id=1;
   c->id=2;
   d->id=3;
   e->id=4;

   a->name = strdup("a");
   b->name = strdup("b");
   c->name = strdup("c");
   d->name = strdup("d");
   e->name = strdup("e");

   generateDot(a);
   fclose(fp);
}