void printf(char* str, double x);
char* str = "%lf\n";

/* int g = 6; */
double foo(double arg1, int g, double pp, int k){
    return 45.56 + arg1;
}

int main() {
    double f = -8.906453;
    double g = foo(f, 5, 600.78, 555);
    printf(str, g);
    /* float pp = 66.6; */
    return 0;
}
