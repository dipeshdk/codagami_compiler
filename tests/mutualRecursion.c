char* str = "%d\n";

int hofstaderFemale(int);
int hofstaderMale(int);
  
int hofstaderFemale(int n)
{
    if (n < 0){
        printf(str, 0);
        return 0;
    }
    else
        if (n == 0){
            printf(str, 1);
            return 1;
        }
        else{
            printf(str, 2);
            return (n - hofstaderFemale(n - 1));
        }
}
  
int hofstaderMale(int n)
{
    if (n < 0){
        printf(str, 3);
        return 0;
    }
    else
        if (n == 0){
            printf(str, 4);
            return 1;
        }
        else{
            printf(str, 5);
            return (n - hofstaderMale(n - 1));
        }
}
  
int main()
{
    int i, k;
    for (i = 0; i < 20; ++i){
        k = hofstaderFemale(i);
        printf(str, k);
    }
      
    for (i = 0; i < 20; ++i){ 
        k = hofstaderMale(i);
        printf(str, k);
    }
  
    return 0;
}