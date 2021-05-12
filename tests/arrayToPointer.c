char* str = "%d\n";

void foo(int *a) {
    int b=a[2];
    a[0] = 99;
    printf(str, a[2]);
    printf(str, b);
    a = malloc(4*sizeof(int));
    a[0] = 5;
    printf(str, a[0]);
    return;
}

void foob(int a[90]) {
    a[40] = 90;
    printf(str, a[40]);
    return;
}

int main() {
    int a[5]= {1,2,3,4,5};
    int aaaa[90];
    int *b = malloc(4*sizeof(int));
    b[0] = 5;
    printf(str, b[0]);
    printf(str, a[0]);
    printf(str, a[1]);
    printf(str, a[2]);
    printf(str, a[3]);
    printf(str, a[4]);
    foo(b);
    foob(aaaa);
    printf(str,a[0]);
    printf(str, aaaa[40]);
    return 0;
}