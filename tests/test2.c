int foo(int a, int b) {
    int c, d;
    c=a;
    d=b;
    foo(d,c);
}

struct foo {
    int a,b,c;
};

int main() {
    struct foo f;
    f.a = 6;
    int c,d=5;
    foo(c,d);
}