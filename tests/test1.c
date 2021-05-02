
void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d \n";

struct foo{
    int a;
    int b;
    char c;
};

struct foo1{
    int x;
    int y;
};



int main() {
    struct foo s, *f;
    struct foo1 f1;
    int c;
    s.a = 5;
    s.c = 'a';
    f = &s;
    f->b = 100;
    f1.x = s.a;
    f1.y = s.b;
    c = s.b + f->a + f1.x + f1.y + f->c;
    /* printf(p,s.a,s.b,s.c); */
    printf(p,c);
    return 0;
}
