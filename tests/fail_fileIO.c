
int main()
{
    int i, n=10;
    char str[50];
   
    int *fptr = fopen("sample.txt", "r+");
    int *fptr2 = fopen("sample2.txt", "w+");

   
    for (i = 0; i < n; i++)
    {
        int a, b;
        fscanf(fptr, "%d %d\n", &a, &b);
        fprintf(fptr2,"%d file %d\n", a, b);
    }
    fclose(fptr);
   
    return 0;
}

