void scanf(char *c, int* d);
void printf(char *c, int d);
int *malloc(int s);
char *p = "%d\n";
int main() {
    int a,sz = 15;
    int *pf;
    pf = malloc(sz * 8);
    pf[5]=6;
    printf(p,pf[5]);
    return 0;
}
