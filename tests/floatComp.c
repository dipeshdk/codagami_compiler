void printf(char* str, int x);
char* str = "%d\n";

/* int g = 6; */
float f1 = 8.906453;
float f2 = 90.77;
int main() {
    float pp = 66.6;
    float pq = 90.77;
    int a,b,c,d;

    a =  pp < pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp < f1;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 < pq;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 < f2;
    if(d) printf(str, 901);
    else printf(str, 900);

    a =  pp <= pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp <= f1;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 <= pq;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 <= f2;
    if(d) printf(str, 901);
    else printf(str, 900);

    a =  pp > pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp > f1;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 > pq;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 > f2;
    if(d) printf(str, 901);
    else printf(str, 900);

    a =  pp >= pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp >= f1;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 >= pq;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 >= f2;
    if(d) printf(str, 901);
    else printf(str, 900);

    a = pp == pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b = pp != pq;
    if(b) printf(str, 901);
    else printf(str, 900);

    c = pp == f1;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = pp != f1;
    if(d) printf(str, 901);
    else printf(str, 900);

    a = f2 == pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b = f2 != pq;
    if(b) printf(str, 901);
    else printf(str, 900);

    c = f1 == f2;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 != f2;
    if(d) printf(str, 901);
    else printf(str, 900);
 
    /* a = 6.0 < pp;
    if(a) printf(str, 901);
    else printf(str, 900);
 
    a = pp < 6.0;
    if(a) printf(str, 901);
    else printf(str, 900); */
 

    /* a = pp < 6.0; */
    /* a = 6.0 < pp;
    /* a = 6.0 < 7.0; */
    /* if(a) printf(str, 901);
    else printf(str, 900); */
    return 0;
}