int main(){
    int *arr = malloc(100*sizeof(int));
    *arr = 10;
    arr[99] = 898;
    printf("%d\n", *arr);
    free(arr);
    printf("%d\n", *arr);
    *arr = 10;
    arr[99] = 898;
    printf("%d\n", arr[99]);
    return 0;
}