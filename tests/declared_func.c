void printf(char* s, int x);
char* str = "%d\n";
/* int foo(int*, float); */

int foo(int a[10], int b) {
    int x = 9;
    printf(str,a[0]);
    printf(str,a[1]);
    printf(str,a[2]);
    x = x + a[0] - a[1];
    return x;
}

int main() {
    int x = 90;
    int a[10];
    a[0]= 90;
    a[1] = 89;
    a[2] = 94;
    x = foo(a, x);
    printf(str,x);
    return 0;
}