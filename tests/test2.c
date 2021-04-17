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
    int c = 9;
    int d = 0;
    char  xxx = 'p';
    f.a = 6;
    foo(c,d);
}