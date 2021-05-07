void printf(char* s, int x);
char* str = "%d\n";
/* int foo(int*, float); */

int foo(int a[10], int b) {
    int x;
    int cc[10];
    x = a[0] + b;
    printf(str,a[0]);
    printf(str,x);
    return x;
}

int main() {
    int a[10];
    int x;
    a[0]= 90;
    x = foo(a,5);
    return 0;
}