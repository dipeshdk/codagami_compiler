void printf(char* str, int x);
char* str = "%d\n";

int main(){
    int a = 90, b = 56, c = 90;
    int x = 89, y = 65, z = 57;
    char p = 'a',q = 'b',r = 'c';

    a = -9;
    b = 10;
    x = -9;
    y = a * 1  + b * 7 - 24;
    p = 'c';
    q = 90;

    c = a * b;
    printf(str,c);
    c = -a * b;
    printf(str,c);
    c = -a + b;
    printf(str,c);
    c = a + b;
    printf(str,c);
    c = -a/b;
    printf(str,c);
    c = a/b;
    printf(str,c);
    c = a - b;
    printf(str,c);
    c = -a - b;
    printf(str,c);
    
    
    z = x * y;
    printf(str,z);
    z = -x * y;
    printf(str,z);
    z = -x + y;
    printf(str,z);
    z = x + y;
    printf(str,z);
    z = -x/y;
    printf(str,z);
    z = x/y;
    printf(str,z);
    z = 34/y;
    printf(str,z);
    z = x/34;
    printf(str,z);
    z = -x/34;
    printf(str,z);
    z = -34/y;
    printf(str,z);
    z = x/(-34);
    printf(str,z);
    z = x - y;
    printf(str,z);
    z = -x - y;
    printf(str,z);

    /* garbage value is expected here from GCC as it overflows there  */
    /* r = p * q;
    printf(str,r);
    r = -p * q;
    printf(str,r); */
    r = -p + q;
    printf(str,r);
    /* r = p + q;
    printf(str,r); */
    r = -p/q;
    printf(str,r);
    r = p/q;
    printf(str,r);
    r = p - q;
    printf(str,r);
    /* r = -p - q;
    printf(str,r); */
    return 0;
}