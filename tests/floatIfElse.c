void printf(char* str, double x);
char* str = "%lf\n";

int main(){
    double a = 3.0, b = 0.0, c, d= 8293.792, e = 0.00037;
    if((c  = (a || b))){
        printf(str, c);
        c = 10.198;
        printf(str, c);
    }
    else{
        printf(str, c);
        c = 1879.72;
        printf(str, c);
    }

    if((c  = (a && b))){
        printf(str, c);
        c = 10.198;
        printf(str, c);
    }
    else{
        printf(str, c);
        c = 1879.72;
        printf(str, c);
    }
    
    if((c  = (b || e))){
        printf(str, c);
        c = 10.198;
        printf(str, c);
    }
    else{
        printf(str, c);
        c = 1879.72;
        printf(str, c);
    }
    if((c  = (e && b))){
        printf(str, c);
        c = 10.198;
        printf(str, c);
    }
    else{
        printf(str, c);
        c = 1879.72;
        printf(str, c);
    }
    if((c  = (a || e))){
        printf(str, c);
        c = 10.198;
        printf(str, c);
    }
    else{
        printf(str, c);
        c = 1879.72;
        printf(str, c);
    }
    return 0;

}