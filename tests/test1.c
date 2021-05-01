
void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d\n";

struct foo{
    int a;
    int b;
    float c;
};

int main() {
    struct foo *f;
    int c;
    f->a = 1; 
    f->b = 2;
    c = f->a + f->b;
    printf(p,c);
    return 0;
}
