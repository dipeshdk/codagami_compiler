int foo(int *x, float f);

int foo(int *a, float f) {
    int x;
    x= *a + f;
    return x;
}

int main() {
    float f;
    int a;
    a = foo(5, f);
}