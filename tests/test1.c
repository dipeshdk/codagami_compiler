void printf(char* str, double d);
char *str = "%lf\n";

int main() {
    double d = 5.5;
    int a=d;
    double dd = a;
    printf(str,dd);
    return 0;
}
