int main(){
    int *fp;
    fp = fopen("file.txt","w+");
    fclose(fp);
    return 0;
}