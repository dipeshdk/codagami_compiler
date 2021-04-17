int foo(int a, char* b) {
    int c, d;
    c=a;
    d=b;
    foo(d,c);
}

int main() {
    int c,d=5;
    char xxx = 'p';
    float f = 4.5;
    foo(c,xxx);
}