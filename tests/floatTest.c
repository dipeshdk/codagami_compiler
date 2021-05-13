char* str = "%d\n";

int main(){
    double a = 3.0, b = 0.0, c;
    int d = 5, e = 2;
    if((c  = (0.0 || 1.0))){
        d = 10;
        printf(str, d);
    }
    else{
        d = 1;
        printf(str, d);
    }
    
    return 0;

}