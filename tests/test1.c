void printf(char* c, int x);
char* str = "%d\n";

void bubble_sort(int *arr, int n){
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
    return;
}

int main(){
    int i;
    int n = 10;
    int arr[10] = {5, 4, 7, 2, 9, 10, 1, 3, 6, 8};
    bubble_sort(arr, n);
    printf(str,arr[0]);
    printf(str,arr[1]);
    printf(str,arr[2]);
    printf(str,arr[3]);
    printf(str,arr[4]);
    printf(str,arr[5]);
    printf(str,arr[6]);
    printf(str,arr[7]);
    printf(str,arr[8]);
    printf(str,arr[9]);
    return 0;
}

int main(){
    int arr[5];
    int b=3;
    arr[3]=5;
}