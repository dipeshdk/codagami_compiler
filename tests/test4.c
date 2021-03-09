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
    struct node* head = NULL;
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