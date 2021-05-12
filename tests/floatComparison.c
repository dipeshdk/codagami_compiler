char* str = "%lf\n";

/* int g = 6; */
double f1 = 8.906453;
double f2 = 8.906453;
int main() {
    double pp = 66.6;
    double pq = 90.77;
    double a,b,c,d;

    a =  pp < pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

    b =  pp < 9.089;
    if(b) printf(str, b);
    else printf(str, 900.0);

    c =  f1 < pq;
    if(c) printf(str, c);
    else printf(str, 900.0);

    d = 78.090 < f2;
    if(d) printf(str, d);
    else printf(str, 900.0);

    a =  pp <= pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

    b =  pp <= f1;
    if(b) printf(str, b);
    else printf(str, 900.0);

    c =  f1 <= pq;
    if(c) printf(str, c);
    else printf(str, 900.0);

    d = f1 <= f2;
    if(d) printf(str, d);
    else printf(str, 900.0);

    a =  90.890 > pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

    b =  pp > f1;
    if(b) printf(str, b);
    else printf(str, 900.0);

    c =  f1 > 90.009;
    if(c) printf(str, c);
    else printf(str, 900.0);

    d = f1 > f2;
    if(d) printf(str, d);
    else printf(str, 900.0);

    d = 9.088 > 78.099;
    if(d) printf(str, d);
    else printf(str, 900.0);

    a =  pp >= pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

    b =  pp >= f1;
    if(b) printf(str, b);
    else printf(str, 900.0);

    c =  f1 >= pq;
    if(c) printf(str, c);
    else printf(str, 900.0);

    d = f1 >= f2;
    if(d) printf(str, d);
    else printf(str, 900.0);

    a = pp == pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

   /*  b = pp != pq;
    if(b) printf(str, b);
    else printf(str, 900.0); */

    c = pp == f1;
    if(c) printf(str, c);
    else printf(str, 900.0);

   /*  d = pp != f1;
    if(d) printf(str, d);
    else printf(str, 900.0); */

    a = f2 == pq;
    if(a) printf(str, a);
    else printf(str, 900.0);

   /*  b = f2 != pq;
    if(b) printf(str, b);
    else printf(str, 900.0); */

    c = 0.00 == 0.0012;
    if(c) printf(str, c);
    else printf(str, 900.0);

    d = f1 != f2;
    if(d) printf(str, d);
    else printf(str, 900.0);
 
    return 0;
}