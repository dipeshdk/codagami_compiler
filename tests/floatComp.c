void printf(char* str, int x);
char* str = "%d\n";

/* int g = 6; */
float f1 = 8.906453;
float f2 = 8.906453;
int main() {
    float pp = 66.6;
    float pq = 90.77;
    int a,b,c,d;

    a =  pp < pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp < 9.089;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 < pq;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = 78.090 < f2;
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

    a =  90.890 > pq;
    if(a) printf(str, 901);
    else printf(str, 900);

    b =  pp > f1;
    if(b) printf(str, 901);
    else printf(str, 900);

    c =  f1 > 90.009;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 > f2;
    if(d) printf(str, 901);
    else printf(str, 900);

    d = 9.088 > 78.099;
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

    c = 0.00 == 0.0012;
    if(c) printf(str, 901);
    else printf(str, 900);

    d = f1 != f2;
    if(d) printf(str, 901);
    else printf(str, 900);
 
    return 0;
}