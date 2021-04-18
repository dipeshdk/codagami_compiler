int main() {
    int a,b,c;
    float f,g;
    a = b==c;
    c = f==a;
    b = f==g;

    a = b!=c;
    c = f!=a;
    b = f!=g;

    a = b<c;
    c = f<a;
    b = f<g;

    a = b>c;
    c = f>a;
    b = f>g;

    a = b<=c;
    c = f<=a;
    b = f<=g;

    a = b>=c;
    c = f>=a;
    b = f>=g;
}