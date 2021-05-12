char* str = "%lf\n";

int main(){
    double a = 3.0, b = 0.0, c, d= 8293.792, e = 0.00037;
    int dd = 5, ee = 2;
    if((c  = (a || b))){
        printf("8: %f\n", c);
        c = 10.198;
        printf("10: %f\n", c);
    }
    else{
        printf("13: %f\n", c);
        c = 1879.72;
        printf("15: %f\n", c);
    }

    if((c  = (a && b))){
        printf("19: %f\n", c);
        c = 10.198;
        printf("21: %f\n", c);
    }
    else{
        printf("24: %f\n", c);
        c = 1879.72;
        printf("26: %f\n", c);
    }
    
    if((c  = (b || e))){
        printf("30: %f\n", c);
        c = 10.198;
        printf("32: %f\n", c);
    }
    else{
        printf("35: %f\n", c);
        c = 1879.72;
        printf("37: %f\n", c);
    }
    if((c  = (e && b))){
        printf("40: %f\n", c);
        c = 10.198;
        printf("42: %f\n", c);
    }
    else{
        printf("45: %f\n", c);
        c = 1879.72;
        printf("47: %f\n", c);
    }
    if((c  = (a || e))){
        printf("50: %f\n", c);
        c = 10.198;
        printf("52: %f\n", c);
    }
    else{
        printf("55: %f\n", c);
        c = 1879.72;
        printf("57: %f\n", c);
    }
    return 0;

}