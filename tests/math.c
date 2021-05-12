/* void printf(char* str, double f);
double sin(double x);
double cos(double x);
double tan(double x);
double sqrt(double x);
double fabs(double x);
double fmax( double x, double y );
double fmin( double x, double y ); */
char *str = "%lf\n";

int main() {
    double d = 1.57, x = 0.0, y = 0.78, z = 3.14, w = 4.788;
    double dd;
    dd = sin(d);
    dd = dd/cos(d);
    printf(str, dd);
    dd = tan(d);
    printf(str, dd);

    dd = sin(x);
    dd = dd/cos(x);
    printf(str, dd);
    dd = tan(x);
    printf(str, dd);

    dd = sin(y);
    dd = dd/cos(y);
    printf(str, dd);
    dd = tan(y);
    printf(str, dd);

    dd = sin(z);
    dd = dd/cos(z);
    printf(str, dd);
    dd = tan(z);
    printf(str, dd);

    dd = sin(w);
    dd = dd/cos(w);
    printf(str, dd);
    dd = tan(w);
    printf(str, dd);

    dd = sqrt(4.0);
    printf(str, dd);

    dd = -9.789;
    dd = fabs(dd);
    printf(str, dd);

    dd = fabs(-9.789);
    printf(str, dd);

    dd = fmax(89.8787, 45.90);
    printf(str, dd);
    dd = fmax(89.8787, 198.90);
    printf(str, dd);

    dd = fmin(89.8787, 45.90);
    printf(str, dd);
    dd = fmin(89.8787, 198.90);
    printf(str, dd);
    
    return 0;
}
