/*  Test case containing all the minimum features required. */
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

    int n = 0;
    scanf("%d",&n);
    char a[n];
    int step = 5;
    while(n > 0){
        for(int i = 0 ; i < n ;i += step){
            a[i] = (int)'a'+(((int)a[i] + i - (int)'a') % 26);
        }
        n-=10;
    }

    int x = 9;
    int y = sqrt(9);

    char s1[] = "coda";
    char s2[] = "gami";
    char s3[] = strcat(s1,s2);
    if(s3[1] = 'o'){
        printf("YES\n");
    }else{
        printf("NO");
    }
    return 0;
    
}