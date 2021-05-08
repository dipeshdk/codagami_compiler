void printf(char* str, int x);
char* str = "%d\n";

int main() {
    int arr[10];
    int x,y;
    arr[5] =7;
    printf(str, arr[5]);
    arr[2] = 2;
    printf(str, arr[2]);
    arr[4] = arr[5]-arr[2];
    printf(str, arr[4]);
    return 0;
}