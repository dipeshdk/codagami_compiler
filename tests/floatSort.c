void printf(char* str, double x);
char* str = "%f\n";

void bubble_sort(double arr[6], double n){
    int i, j;
    for(i = 0; i < n-2; ++i){
        for(j = 0; j < n-i-1; ++j){
            if(arr[j] < arr[j+1]){
                double temp = arr[j];
                printf(str, temp);
                arr[j] = arr[j+1];
                printf(str, arr[j]);
                arr[j+1] = temp;
                printf(str, arr[j+1]);
            }
        }
    }
    for(i = 0; i< 6; ++i){
        printf(str, arr[i]);
    }
    return;
}

double main(){
    int n = 6;
    double arr[6] = {89.927, 56.2786, 78.19, 90, 90.19, 345};
    /* arr[0] = 90;
    arr[1] = 23;
    arr[2] = 45;
 */
    bubble_sort(arr, n);
    for(n = 0; n < 6; ++n){
        printf(str,arr[n]);
    }
    return 0;
}