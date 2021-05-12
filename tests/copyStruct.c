char *arr = "%d\n";

struct foo{
    int a, b, c;
};


int main() {
    struct foo x, y;
    int a;
    x.a = 1;
    printf(arr, x.a);
    x.b = 2;
    printf(arr, x.b);
    x.c = 3;
    printf(arr, x.c);
    y.a = 4;
    printf(arr, y.a);
    y.b = 5;
    printf(arr, y.b);
    y.c = 6;
    printf(arr, y.c);
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, y.a);
    printf(arr, y.b);
    printf(arr, y.c);
    x = y;
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    return 0;
}