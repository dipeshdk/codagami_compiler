void printf(char* s, int x);
char* str = "%d\n";
/* int foo(int*, float); */

int foo(int a[10], int b) {
    int x = 9, i=0;
    printf(str, x);
    for(i = 0; i<10; ++i){
        printf(str, a[i]);
    }
    x = x + a[0] - a[1];
    printf(str, x);
    return x;
}

int main() {
    int x = 90, i=0;
    int a[10];
    for(i = 0; i<10; ++i){
        a[i] = 90+i;
        printf(str, a[i]);
    }
    x = foo(a, x);
    printf(str,x);
    return 0;
}