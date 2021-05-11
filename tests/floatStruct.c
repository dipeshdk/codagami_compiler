void printf(char* str, double x);
char* str = "%f\n";

struct foo{
    int a, b;
    double f1, f2;
    char c, d;
};

int main(){
    struct foo froo1, froo2;
    froo1.a = 819;
    froo1.b = 2398;
    froo1.f1 = 37982.7218;
    froo1.f2 = 7189693.189;
    froo1.c = 'g';
    froo1.d = 'k';

    printf(str, froo1.a);
    printf(str, froo1.b);
    printf(str, froo1.f1);
    printf(str, froo1.f2);
    printf(str, froo1.c);
    printf(str, froo1.d);

    froo2 = froo1;

    printf(str, froo2.a);
    printf(str, froo2.b);
    printf(str, froo2.f1);
    printf(str, froo2.f2);
    printf(str, froo2.c);
    printf(str, froo2.d);    

    return 0;
}