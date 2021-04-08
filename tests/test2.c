/*check function args
  should not work properly
*/ 

int foo(int a, float b) {
    int c = 4;
    return c;
}

int main() {
    int p=1, q=2;
    float r;
    /*incorrect*/
    foo(p,q);
    foo(p,q,r);
    foo(r,p);
    /*correct*/
    foo(p,r);
    return 0;
}

