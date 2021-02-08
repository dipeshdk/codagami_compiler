struct node{
    int val;
    struct node* next;
}node;

void printLinkedList(struct node* head){
    if (head == NULL) {
        return;
    }
    printf("%d\n", head->val);
    printLinkedList(head->next);
}

int main() {
    int n = 10;
<<<<<<< HEAD
    struct node* head = NULL;// = (struct node*)malloc(sizeof(node));
=======
    struct node* head = NULL;
>>>>>>> 5e560e5670db387a4635a801d4ca6573c63b7468
    struct node* prev = NULL;
    for(int i = 0;i<n;i++){
        struct node* curr = (struct node*)malloc(sizeof(node));
        curr->val = i;
        curr->next = NULL;  
        if (prev == NULL) {
            head = curr;
            prev = curr;
        } else {
            prev->next = curr;
        }
        prev = curr;
    }
    printLinkedList(head);
    return 0;
}