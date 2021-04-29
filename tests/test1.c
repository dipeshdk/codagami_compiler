void printf(char *c, int d);
char *p = "%d\n";

int main() {
    char* arr;
    int a = 8;
    int x = 5;
    int y = 490;
    x = 50 >> a;
    printf(p, x);
    x =  y >> a ;    
    printf(p, x);
    x = 50 << a;
    printf(p, x);
    x = 70 << a;
    printf(p, x);
    return 0;
}