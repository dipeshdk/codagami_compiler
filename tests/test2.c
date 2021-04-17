int foo(int a, int b) {
    int c, d;
    c=a;
    d=b;
    foo(d,c);
}

int main() {
    int c,d=5;
    foo(c,d);
}