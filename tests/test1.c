void printf(char* str, double d);
char *str = "%lf\n";

int main() {
    double x=1.5;
    printf(str, x++);
    printf(str, x);
    printf(str, ++x);
    printf(str, x);
    return 0;
}
