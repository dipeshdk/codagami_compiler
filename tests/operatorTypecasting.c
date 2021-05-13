int main(){
    int a, b, c;
    double x, y, z;
    char p,q,r;

    a = -9;
    b = 10;
    x = -9.8;
    y = a * 1.4  + b * 7.5 - 24;
    p = 'c';
    q = 90;

    /* int = int op int */
    c = a * b;
    c = -a * b;
    c = -a + b;
    c = a + b;
    c = -a/b;
    c = a/b;
    c = a - b;
    c = -a - b;

    /* double = double op double*/
    z = x * y;
    z = -x * y;
    z = -x + y;
    z = x + y;
    z = -x/y;
    z = x/y;
    z = x - y;
    z = -x - y;

    /* char = char op char*/
    r = p * q;
    r = -p * q;
    r = -p + q;
    r = p + q;
    r = -p/q;
    r = p/q;
    r = p - q;
    r = -p - q;

    /* double = int op double */
    z = a * y;
    z = -a * y;
    z = -a + y;
    z = a + y;
    z = -a/y;
    z = a/y;
    z = a - y;
    z = -a - y;

    /* char = int op double */
    r = a * y;
    r = -a * y;
    r = -a + y;
    r = a + y;
    r = -a/y;
    r = a/y;
    r = a - y;
    r = -a - y;

    /* double = char op double */
    z = p * y;
    z = -p * y;
    z = -p + y;
    z = p + y;
    z = -p/y;
    z = p/y;
    z = p - y;
    z = -p - y;

    /*int = char op double */
    c = p * y;
    c = -p * y;
    c = -p + y;
    c = p + y;
    c = -p/y;
    c = p/y;
    c = p - y;
    c = -p - y;
    
    return 0;
}