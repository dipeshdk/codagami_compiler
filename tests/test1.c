void printf(char* p, int d);
char* p = "%ld\n";

struct foo{
    int a;
    int b;
};

int main(){

    struct foo f[2];
    struct foo f1, *f2;
    int c = 9;
    f2 = &f1;
    f1.a = 8;
    f1.b = 9;
    f[0].a = 78;
    f[0].b = 79;
    f[1] = f1;
    c = f[1].a + f[0].b + f2->a + f2->b;
  
    printf(p, f[0].a);
    printf(p, f[0].b);
    printf(p, f[1].a);
    printf(p, f[1].b);
    printf(p, f1.a);
    printf(p, f1.b);
    printf(p, c);
    return 0;
}
