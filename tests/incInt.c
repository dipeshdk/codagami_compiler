char *str = "%ld\n";

int main() {
    int x=1;
    printf(str, x++);
    printf(str, x);
    printf(str, ++x);
    printf(str, x);
    x = x++ + ++x - x++ + ++x;
    printf(str, x);
    return 0;
}
