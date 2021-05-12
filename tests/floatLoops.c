char* str = "%f\n";

int main(){
    double arr[20];
    double a = 8827.368, b = 19.273, c = 9.19, d = 234.72;
    int i = 0, j = 0;
    while(a < 8932.783 && i < 20){
        a = a+b;
        arr[i] = a;
        printf(str, arr[i]);
        ++i;
    }

    for(j = 0; j < i; ++j){
        printf(str, arr[j]);
    }
    return 0;
}