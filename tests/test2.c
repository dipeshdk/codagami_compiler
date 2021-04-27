int foo(int a, int b, int c, int d, int e, int f, int g, int h, int i, int j, int k) {
    int koo[1999];
    a=b;
    return c;
}

int main(){
    int a=1,b=2;
    b=foo(1,2,3,4,5,6,a+b,8,9,a,b);
    b = b + a;
}