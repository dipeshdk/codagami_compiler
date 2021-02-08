void countChars(char* str){
    int len = strlen(str);
    int count[26];
    for(int i = 0;i<26;i++){
        count[i] = 0;
    }
    for(int i = 0;i<len;i++){
        int x = str[i] - 'a';
        count[x]++;
    }
    for(int i = 0;i<26;i++){
        printf("Number of %c in str = %d\n",'a' + i, count[i]);
    }
    return;
}
int main(){
    float x = 12.6;
    int y = 34;
    float z = pow(x,y);
    int a = ceil(sqrt(x)), b = floor(x);
    float c = log(fabs(-x));

    char str1[50] = "This is a test case\0";
    char str2[50] = " for compiler project.\0";
    strcat(str1, str2);
    strcpy(str2, str1);
    int len = strlen(str2);

    char st[] = "our team name is codagami"; 
    char ch = 'm'; 
    char* p = strrchr(st, ch); 
    printf("String after last %c is : %s \n", ch, p); 
    countChars(st);
    return 0;
}