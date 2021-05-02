void printf(char *c, int a);
char *arr = "y = %d\n";

int main(){
    int x=5,y=100,z;
    z = x < y;
    printf(arr,z);

    z = x > y;
    printf(arr,z);

    z = x >= y;
    printf(arr,z);

    z = x <= y;
    printf(arr,z);

    z = x == y;
    printf(arr,z);

    z = x != y;
    printf(arr,z);
    return 0;
}