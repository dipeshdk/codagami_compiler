#include<stdio.h>

struct node{
    int val;
    struct node* right;
    struct node* left;
};

void trav(struct node* root){
    if(!root) return;
    printf("%d\n",root->val);
    trav(root->left);
    trav(root->right);
}

int main(){
    struct node* root;
    struct node* lchild;
    struct node* rchild;
    root->val = 0;
    lchild->val=1;
    rchild->val= -1;
    lchild->right = NULL;
    lchild->left = NULL;
    rchild->left = NULL;
    rchild->right = NULL;
    root->left = lchild;
    root->right = rchild;

    
}