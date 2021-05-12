/* void printf(char *c, int d);
int* malloc(int a);
char* arr = "x = %d\n";

struct foo{
    int a, b, c, d, e, f, g, h, i;
};

struct foo fun(int a, int b, int c, int d, int e, int f, int g, int h, int i){
    struct foo *out = malloc(sizeof(struct foo));
    struct foo x;
    (*out).a = a;
    (*out).b = b;
    (*out).c = c;
    (*out).d = d;
    (*out).e = e;
    (*out).f = f;
    (*out).g = g;
    (*out).h = h;
    (*out).i = i;
    printf(arr, (*out).a);
    printf(arr, (*out).b);
    printf(arr, (*out).c);
    printf(arr, (*out).d);
    printf(arr, (*out).e);
    printf(arr, (*out).f);
    printf(arr, (*out).g);
    printf(arr, (*out).h);
    printf(arr, (*out).i);
    x = *out;
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    printf(arr, x.e);
    printf(arr, x.f);
    printf(arr, x.g);
    printf(arr, x.h);
    printf(arr, x.i);
    return *out;
}

int main() {
    struct foo x;
    int a;
    x.a = 1;
    x.b = 2;
    x.c = 3;
    x.d = 4;
    x.e = 5;
    x.f = 6;
    x.g = 7;
    x.h = 8;
    x.i = 9;
    
    
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    printf(arr, x.e);
    printf(arr, x.f);
    printf(arr, x.g);
    printf(arr, x.h);
    printf(arr, x.i);
    x = fun(10, 11, 12, 13, 14, 15, 16, 17, 18);
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    printf(arr, x.e);
    printf(arr, x.f);
    printf(arr, x.g);
    printf(arr, x.h);
    printf(arr, x.i);
    return 0;
} */

/* struct foo{
    int a;
};

struct foo fun(int a){
    struct foo out;
    out.a = 4;
    return out;
}

int main() {
    struct foo x;
    int a;
    x.a = 1;
    
    printf(arr, x.a);
    x = fun(a);
    printf(arr, x.a);
    return 0;
} */

/* struct foo{
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
} */

/* struct foo{
    int a, b, c, d;
};

struct foo fun(int a, int b, int c, int d){
    struct foo out;
    out.a = a;
    out.b = b;
    out.c = c;
    out.d = d;
    return out;
}

int main() {
    struct foo x;
    int a;
    x.a = 1;
    x.b = 2;
    x.c = 3;
    x.d = 4;
    
    
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    x = fun(10, 11, 12, 13);
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    return 0;
} */

/* void printf(char *c, int d);
int* malloc(int a);
char* arr = "x = %d\n";

struct foo{
    int a, b, c, d;
};

struct foo* fun(int a, int b, int c, int d){
    struct foo *out = malloc(sizeof(struct foo));
    struct foo x;
    (*out).a = a;
    (*out).b = b;
    (*out).c = c;
    (*out).d = d;
    printf(arr, (*out).a);
    printf(arr, (*out).b);
    printf(arr, (*out).c);
    printf(arr, (*out).d);
    x = *out;
    printf(arr, x.a);
    printf(arr, x.b);
    printf(arr, x.c);
    printf(arr, x.d);
    return out;
}

int main() {
    struct foo* x;
    int a;
    x = fun(10, 11, 12, 13);
    printf(arr, (*x).a);
    printf(arr, (*x).b);
    printf(arr, (*x).c);
    printf(arr, (*x).d);
    return 0;
} */
/* void printf(char* str, int a, int b, float c); */
int main(){
    int a = 5;
    double b = 12.0;
    double x = 90.56;
    scanf("%d %f %f\n", &a, &b, &x);
    printf("a = %d, b = %f, c = %f\n", a, b, x);
    return 0;
}