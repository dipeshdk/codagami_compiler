void printf(char* str, int x);
char* str = "%d\n";

int main(){
    int x = -89, y = 65, z = 57;
    z = -x/y;
    printf(str,z);
    z = x/y;
    printf(str,z);
    z = 80/x;
    printf(str, z);
    z = x/34;  
    printf(str, z);
    z = -34/y;
    printf(str,z);
    z = x/(-34);
    printf(str,z);
    return 0;
}