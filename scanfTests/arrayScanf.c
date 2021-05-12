
int main(){
    double arr[5];
    int i = 0;
    for(i =0; i<4;++i ){
        printf("value for index i = %d\n", i);
        scanf("%lf", &arr[i]);
        printf("value for arr = %lf\n", arr[i]);
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