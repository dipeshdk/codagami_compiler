void scanf(char *c, int* d);
void printf(char *c, int d);
char *p = "%d\n";
int main() {
    int x = 6;
    scanf(p, &x);
    printf(p,x);
}