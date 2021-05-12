int main() {
    int a = 10, b= 12323,c = 29831924;
    double f = 2413.123, g = 6756.342;

    b /= a;
    printf("%d\n", a);

    c -= b;
    printf("%d\n", a);

    g *= f;
    printf("%lf\n", g);

    c %= b;
    printf("%d\n", b);

    g += f;
    printf("%lf\n", f);
    printf("%lf\n", g);
    printf("%lf\n", f);
    printf("%lf\n", g);

    a <<= b;
    printf("%d\n", a);

    c >>= b;
    printf("%d\n", c);

    a &= b;
    printf("%d\n", a);

    c ^= a;
    printf("%d\n", c);

    c |= 123214;
    printf("%d\n", c);
    
    return 0;
}