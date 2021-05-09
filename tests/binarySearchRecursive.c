void printf(char* p, int d);
char* str = "%d\n";

int binaryScr(int a[5], int low, int high, int m)
{
    int mid;
    if (high >= low) {
        mid = low + (high - low) / 2;
        /* printf(str, 12345); */
        if (a[mid] == m){
            /* printf(str,mid); */
            return mid;
        }
        if(a[mid] > m)
            return binaryScr(a, low, mid - 1, m);
        return binaryScr(a, mid + 1, high, m);
    }
    printf(str, 23456);
    return -1;
}

int main(void)
{
    int a[5] = { 12, 13, 21, 36, 40 };
    int i,m;
    int n = 5;
    int result; 
    m=21;
    result = binaryScr(a, 0, n - 1, m);
    printf(str, result);
    result = (result == -1) ? -2 : result+1;
    printf(str, result);
    return 0;
}