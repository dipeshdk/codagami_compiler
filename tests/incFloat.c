char *str = "%lf\n";

int main() {
    double x=2.7;
    printf(str, x++);
    printf(str, x);
    printf(str, ++x);
    printf(str, x);
    x = x++ + ++x - x++ + ++x;
    printf(str, x);
    return 0;
}
