/* void scanf(char *c, int* d); */
void printf(char *c, int d);
char *p = "%d \n";

int main(){
    int a[1][2];
    a[0][1] = 90;
    printf(p,a[0][1]);
    return 0;
}