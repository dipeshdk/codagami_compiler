int main(){
    int *ptr, n = 10, i=0;
    ptr = calloc(n, sizeof(int)) + (n-1)*sizeof(int);
    
   /*  if (ptr == 0) {
        printf("Memory not allocated.\n");
        return -1;
    } */
    printf("Memory successfully allocated by calloc\n");
    for(i = 0; i<n; i++){
        printf("%d, ", ptr[i]);
    }
    printf("\n");
    for(i = 0; i<n; i++){
        ptr[i] = i*2;
        printf("%d, ", ptr[i]);
    }
    printf("\n");

    return 0;
}