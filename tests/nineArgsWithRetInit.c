int foo(int a, int b, int c, int d, int e, int f,int g, int h, int i) {
    int k;
    c=5;
    k = 8;
    return k+a+b+c+i;
}

int main() {
    int a,b=2,c,d,e,f,g;
    a=1;
    b = foo(a,b,c,d,e,5,g,7,6);

    return 0;
}
