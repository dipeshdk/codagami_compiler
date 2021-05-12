
char* str = "%d\n";
int foo(int *x);

int foo(int *a) {
    int *x = malloc(8);
    *x= *a + 3;
    printf(str, *x);
    return *x;
}

int bar(int x){
    int y = 10;
    printf(str, y+x);
    return y*x;
}

int main() {
    int a = 10;
    a = foo(&a) * bar(23);
    printf(str, a);
    printf(str, foo(&a) * bar(23));
    return 0;
}