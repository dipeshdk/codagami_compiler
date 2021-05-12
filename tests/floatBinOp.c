char* str = "%lf\n";

int main(){
    int x = 90;
    double a = 236789.137, b = 19672349.928, c = 58492.83821, d, e, f, g;
    printf(str, a);
    printf(str, b);
    printf(str, c);
    d = a+b;
    printf(str, d);
    e = c-b;
    printf(str, e);
    f = a/c;
    printf(str, f);
    g = a*c;
    printf(str, g);
    d = a*b/c+d-e;
    printf(str, d);
    return 0;
}