void printf(char* str, double f);
void scanf(char* str, double* f1, double* f2, double* f3, double* f4);
char* str = "%lf\n";

int main(){
    /* int x = 90; */
    double a = 236789.137, b = 19672349.928, c = 58492.83821, d, e, f, g;
    scanf("%lf %lf %lf %lf\n", &d, &e, &f, &g);
    printf(str, a);
    printf(str, b);
    printf(str, c);
    printf(str, d);
    printf(str, e);
    printf(str, f);
    printf(str, g);
    printf(str, d);
    d = a+b;
    printf(str, a);
    printf(str, b);
    printf(str, d);
    e = c-b;
    printf(str, b);
    printf(str, c);
    printf(str, e);
    f = a/c;
    printf(str, a);
    printf(str, c);
    printf(str, f);
    g = a*c;
    printf(str, a);
    printf(str, c);
    printf(str, g);
    d = a*b/c+d-e;
    printf(str, a);
    printf(str, b);
    printf(str, c);
    printf(str, d);
    printf(str, e);
    return 0;
}