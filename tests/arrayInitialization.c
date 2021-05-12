char* str = "%d\n";

void foo(int a[5]) {
    int b=a[2];
    a[0] = 99;
    printf(str, a[2]);
    printf(str, b);
}

int main() {
    int a[5] = {1,2,3,4,5};
    printf(str, a[0]);
    printf(str, a[1]);
    printf(str, a[2]);
    printf(str, a[3]);
    printf(str, a[4]);
    foo(a);
    printf(str,a[0]);
    return 0;
}