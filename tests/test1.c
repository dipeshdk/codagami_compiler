void printf(char* str, double x);
void scanf(char* str, double* x);
double* malloc(int x);
char* format = "%lf\n";
int main() {
    double x = 90.89;
    double *g = malloc(8);
    printf(format, x);
    scanf(format, &x);
    printf(format, x);
    return 0;
}
