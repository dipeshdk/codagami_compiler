void printf(char* str, int x);
char* str = "%d\n";

void bubble_sort(int arr[6], int n){
    int i, j;
    for(i = 0; i < n-2; ++i){
        for(j = 0; j < n-i-1; ++j){
            if(arr[j] < arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    /* printf(str, arr[0]);
    printf(str, arr[1]); 
    printf(str, arr[2]); */
    return;
}

int main(){
    int n = 6;
    int arr[6] = {90, 56, 78, 90, 67, 345};
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