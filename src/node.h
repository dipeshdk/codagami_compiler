typedef struct node{
	// int type;
	int id;
	char* name;
	char* lexeme;
	int isLeaf;
	struct node* next;
	struct node* childList;
}node;