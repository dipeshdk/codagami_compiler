int binaryScr(int a[5], int low, int high, int m)
{
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if (a[mid] == m)
            return mid;
        if(a[mid] > m)
        return binaryScr(a, low, mid - 1, m);
        return binaryScr(a, mid + 1, high, m);
        }
    return -1;
}

int main(void)
{
    int a[5] = { 12, 13, 21, 36, 40 };
    int i,m;
    int n = 4;
    int result; 
    m=21;
    result = binaryScr(a, 0, n - 1, m);
    result = (result == -1) ? -2 : result+1;
    return 0;
}