struct course {
    int marks;
    char subject[30];
};

union Data {
   int i;
   float f;
   char str[20];
} data; 

enum week{Mon, Tue, Wed, Thur, Fri, Sat, Sun}; 

int main() {
    struct course *ptr;
    union Data *ptr2;

    int i = Mon;

    ptr = (struct course *)malloc(10 * sizeof(struct course));
    for (i = 0; i < 10; ++i) {
        printf("i=%d:\n",i);
    }

    return 0;
}