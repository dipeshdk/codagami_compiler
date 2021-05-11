void printf(char* str, double f);
void scanf(char* str, double* f1);
char* str = "%lf\n";

int main(){
    double arr[5];
    int i = 0;
    for(i =0; i<4;++i ){
        printf("value for index i = %d\n", i);
        scanf(str, &arr[i]);
    }

    /* for(i =0; i<4;++i ){
        printf(str, arr[i]);
    }

    for(i =1; i<4;++i ){
        arr[i] += arr[i-1];
    }

    for(i =0; i<4;++i ){
        printf(str, arr[i]);
    } */

    return 0;
}