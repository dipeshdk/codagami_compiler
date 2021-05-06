int* malloc(int s);
void printf(char* str, int x);
char* str = "%d\n";

int main() {
    int a = 23,b = 3973 ,c = 10,d=2728, *e, *f;
    char x = 'd', y = '(', z = '}';
    e = malloc(8);
    a = -1;
    printf(str, a);
    a=-5;
    printf(str, a);
    b=-a;
    printf(str, b);
    printf(str, a);
    b=!a;
    printf(str, b);
    printf(str, a);
    
    
    x= ~y;
    printf(str, x);
    printf(str, y);
    x= ~y + z;
    printf(str, x);
    printf(str, y);
    printf(str, z);
    y = ~z;
    printf(str, y);
    printf(str, z);
    b = ~x;
    printf(str, b);
    printf(str, x);
    b= ~a;
    printf(str, b);
    printf(str, a);
    b = ~'c';
    printf(str, b);
    b = ~5;
    printf(str, b);
    b = ~(a+5*7-9);
    printf(str, b);
    printf(str, a);

    *e = c;
    printf(str, *e);
    printf(str, c);
    f = &d;
    printf(str, f == &d);
    printf(str, d);

    printf(str, *f);
    return 0;
}