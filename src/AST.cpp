#include "headers/allInclude.h" 

node* makeNode(char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = new node();
	newNode->id = id++;
	newNode->name = (char*)malloc(sizeof(char)*(strlen(name)+1));
	newNode->lexeme = (char*)malloc(sizeof(char)*(strlen(lexeme)+1));
	strcpy(newNode->name, name);
	strcpy(newNode->lexeme, lexeme);
	newNode->isLeaf = isLeaf;
	newNode->childList = c1;
	makeSibling(c2,newNode->childList);
	makeSibling(c3,newNode->childList);
	makeSibling(c4,newNode->childList);
	return newNode;
}

node* makeDeadNode(){
	node* newNode = new node();
	newNode->isLeaf=DEAD_NODE;
	newNode->declSp = new declSpec();
    newNode->childList = NULL;
    newNode->next = NULL;
	newNode->name = strdup("Dead Node");	
	return newNode;
}

node* makeTypeNode(int tp){
	node* newNode = makeDeadNode();
	newNode->declSp->type.push_back(tp); //TODO: check validity of type
	return newNode;
}

node* makeStorageClassNode(int storageClass, char* name, char* lexeme, int isLeaf, 
			node*c1, node*c2, node*c3, node* c4){
	node* newNode = makeNode(name, lexeme, isLeaf, 
			c1,c2, c3, c4);
	newNode->declSp = new declSpec();
	newNode->declSp->storageClassSpecifier.push_back(storageClass); //TODO: check validity of storage class
	newNode->name = strdup("Storage Node");
	return newNode;
}

void makeSibling(node* root, node* childList){
	if(!root) return;
	if(!childList) return;
	node* curr  = childList;
	node* prev  = (node*)NULL;
	while(curr){
		prev = curr;
		curr = curr->next;
	}
	prev->next = root;
}

void addChild(node* parent, node* child){
	if(parent->childList == (node*)NULL){
		parent->childList = child;
	}
	else{
		makeSibling(child, parent->childList);
	}
}

