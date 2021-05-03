void scanf(char c, int d);
void printf(char *c, int d); 
char *p = "%ld\n\0";

int main() {
    int arr[2][3];
    arr[1][2] = 34;
    
    /* scanf(p,&gVar); */
    printf(p,arr[1][2]);
    printf(p,arr[1][2]);

    return 0;
}