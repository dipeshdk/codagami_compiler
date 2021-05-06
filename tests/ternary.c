void printf(char* p, int d);
char* str = "%d\n";

int main(){
    int a, x = 9, y = 0, z =90;
    a = x*y == ( 2*x >= 3*y+z? 3*z : x*y) ? 3+x*y+z : 4*7+x + y + z;
    printf(str,a);
    return 0;
}