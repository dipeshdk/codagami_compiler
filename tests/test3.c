/* Test case for input/output, control structures*/
int main(){
    int x = 0;
    scanf("Give a number between 1-9: %d",&x);
    if(x == 0){
        printf("The input was not supplied\n");
    }else{
        printf("The input supplied was %d.", x);
    }
    int b[2];
    for(int i =0 ;i < 2; i++){
        b[i] = i * i + 6;
    }
    char a = 'a';
    while((int)a <(int)'e'){
        printf("%c\n",a);
        a = (char)((int)a + 1);
    }

    return 0;
}