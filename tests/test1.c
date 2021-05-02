int x;
void printf(char* c, int x);
char* str = "%d\n";
int main(){
    int n = 3;
    int arr[3];
    arr[2] = 5;
    printf(str,arr[n-1]);
    return 0;
}