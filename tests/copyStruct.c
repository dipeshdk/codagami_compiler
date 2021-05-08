void printf(char *c, int a);
char *arr = "%d\n";

struct foo{
    int a, b, c;
};


int main() {
    struct foo x, y;
    int a;
    x.a = 1;
    x.b = 2;
    x.c = 3;
    y.a = 4;
    y.b = 5;
    y.c = 6;
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    x = y;
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    return 0;
}