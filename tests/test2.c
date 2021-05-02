
void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d\n";

struct foo{
    int a;
    int b;
    int c;
};

int main() {
    struct foo s;
    struct foo *f;
    int c;
    s.a= 5;
    f = &s;
    s.b = 6;
    s.c = 7;
    c = 2*f->c + f->a + f->b;

    printf(p,c);
    return 0;
}
