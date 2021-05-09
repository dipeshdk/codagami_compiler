void printf(char* s, int x);
char* str = "%d\n";
/* int foo(int*, float); */

int foo(int a[10][9], int b) {
    int x = 9;
    printf(str,a[0][8]);
    printf(str,a[1][3]);
    printf(str,a[2][6]);
    x = x + a[0][5] - a[1][7];
    printf(str,x);
    return x;
}

int main() {
    int x = 90;
    int i,j;
    int a[10][9];
    for(i = 0; i < 10; ++i){
        for(j = 0; j < 9; ++j){
            a[i][j] = i+ j;
            printf(str,a[i][j]);
        }
    }
    x = foo(a, x);
    printf(str,x);
    return 0;
}