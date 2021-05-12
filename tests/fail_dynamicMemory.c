int sz = 10;

struct foo{
    int x;
    double f;
};

int main() {
    int i;
    struct foo *structArr = malloc(sz * sizeof(struct foo)) + sz * sizeof(struct foo);
    char * charArr = malloc(sz * sizeof(char)) + sz * sizeof(char);
    double *doubleArr = malloc(sz * sizeof(float)) + sz * sizeof(float);
    int *intArr = malloc(sz * sizeof(int)) + sz * sizeof(int);
    /* int intArr[10];
    int charArr[10];
    struct foo structArr[10];
    double doubleArr[10];  */
    for (i=0;i<sz;i++) {
        intArr[i] = i*10;
        doubleArr[i] = 0.5;
        structArr[i].x = i*5;
        structArr[i].f = i*100.5; 
    }
    for (i = 0;i < sz ;i++){
        char c = 'a' + i;
        charArr[i] = c;
    } 

    for(i=0;i<sz;i++) {
        char c;
        if(intArr[i] != i*10) {
            printf("intArr wrong\n");
        }
        if(doubleArr[i] - 0.5 > 0.0001) {
            printf("doubleArr wrong\n");
        }
        c = 'a' + i;
        if(charArr[i] != c) {
            printf("charArr wrong\n");
        }
        if(structArr[i].x != i*5) {
            printf("structArr[i].x wrong\n");
        }
        if(structArr[i].f - (i*100.5) > 0.0001) {
            printf("structArr[i].f wrong\n");
        }
    }

    for(i=0;i<sz;i++) {
        printf("intArr[%d] = %d\n",i, intArr[i]);
        printf("charArr[%d] = %c\n",i, charArr[i]);
        printf("doubleArr[%d] = %lf\n", i, doubleArr[i]);
        printf("%d %lf\n", structArr[i].x, structArr[i].f);
    }
    return 0;
}