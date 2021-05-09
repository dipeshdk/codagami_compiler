void scanf(char *c, int* d);
void printf(char *c, int d); 
char *p = "%d \n";

int main() {
    int x = 12 + 90;
    printf(p,x);
    x = 90 - 12;
    printf(p,x);
    x = 12 * 90;
    printf(p,x);
    x = 90 / 12;
    printf(p,x);
    x = 12 - 90 + 89;
    printf(p,x);
    x = 12 - 90 / 23;
    printf(p,x);
    x = 12*10 - 90;
    printf(p,x);
    x = 12 >> 2;
    printf(p,x);
    x = 12 << 2;
    printf(p,x);
    x = 12%5;
    printf(p,x);
    x = 12 | 2;
    printf(p,x);
    x = 12 & 2;
    printf(p,x);
    x = 13 ^ 34;
    printf(p,x);
    x = 12 || 2;
    printf(p,x);
    x = 78 + -12;
    printf(p,x);
    /* x = 12 >> -2;
    printf(p,x); */
    return 0;
}