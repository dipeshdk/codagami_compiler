void bubble_sort(int arr[], int n){
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
    int n = 10;
    int arr[n] = {5, 4, 7, 2, 9, 10, 1, 3, 6, 8};
    bubble_sort(arr, n);
    return 0;
}