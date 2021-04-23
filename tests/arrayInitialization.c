void foo(int a[5]) {
    int b=a[2];
}

int main() {
    int a[5] = {1,2,3,4,5};
    foo(a);
    return 0;
}