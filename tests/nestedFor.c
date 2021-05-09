void printf(char *c, int a, int b);
char * p = "i=%d, j = %d\n";


int main() {
    int i,j;
    for(i=5;i < 7;++i) {
        for(j=3;j == 3;--j){
            printf(p,i,j);
            printf(p,i,j);
        }
    }
    return 0;
}