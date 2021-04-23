int main(){
    int a, b, c;
    float x, y, z;
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

    /* float = float op float*/
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

    /* float = int op float */
    z = a * y;
    z = -a * y;
    z = -a + y;
    z = a + y;
    z = -a/y;
    z = a/y;
    z = a - y;
    z = -a - y;

    /* char = int op float */
    r = a * y;
    r = -a * y;
    r = -a + y;
    r = a + y;
    r = -a/y;
    r = a/y;
    r = a - y;
    r = -a - y;

    /* float = char op float */
    z = p * y;
    z = -p * y;
    z = -p + y;
    z = p + y;
    z = -p/y;
    z = p/y;
    z = p - y;
    z = -p - y;

    /*int = char op float */
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