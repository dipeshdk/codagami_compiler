void printf(char* p, int d);
char* str = "%d\n";

int foo(int a, int x, int y, int z) {
    int b = 5;
    /* a = 1 ? 2 : 3; */
    /* if(1) a=4; */
    /* else a = 5; */
    /* a = x*y == ( 2*x >= 3*y+z? 3*z : (1 ? 3*z : x*y)) ? 3+x*y+z : 4*7+x + y + z; */
    return a;
}

int main(){
    int a, x = 9, y = 0, z =90;
    a = x*y == ( 2*x >= 3*y+z? 3*z : x*y) ? 3+x*y+z : 4*7+x + y + z;
    printf(str,a);
    printf(str, foo(a,x,y,z));
    return 0;
}