
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
    int c, *x, y;
    c = 5;
    x = &c;
    y = *x;
    printf(p,y);
    return 0;
}
