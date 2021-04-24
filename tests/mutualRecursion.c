int hofstaderFemale(int);
int hofstaderMale(int);
  
int hofstaderFemale(int n)
{
    if (n < 0)
        return 0;
    else
        if (n == 0)
            return 1;
        else
            return (n - hofstaderFemale(n - 1));
}
  
int hofstaderMale(int n)
{
    if (n < 0)
        return 0;
    else
        if (n == 0)
            return 0;
        else
            return (n - hofstaderMale(n - 1));
}
  
int main()
{
    int i, k;
    for (i = 0; i < 20; ++i) 
        k = hofstaderFemale(i);
      
    for (i = 0; i < 20; ++i) 
        k = hofstaderMale(i);
  
    return 0;
}