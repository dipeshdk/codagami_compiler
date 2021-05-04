void scanf(char c, int* d);
void printf(char *c, int d); 
char *p = "%ld\n\0";

int main() {
    int arr[6];
    arr[2]=4;
    printf(p,arr[2]);
    printf(p,arr[2]);
    return 0;
}