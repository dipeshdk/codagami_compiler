void printf(char* p, int d);
char* str = "%d\n";

int main(){
    int i, j;
    int arr[10][12];
    int arr2[10][12];
    for(i = 0 ;i < 10; ++i){
        for( j = 0; j < 12; ++j){
            arr[i][j] = (i *2 + j *3) % (i+j+1);
            arr[i][j] = 90;
            arr2[i][j] = (int)arr[i][j]/2;
        }
    }
    for(i = 0 ;i < 10; ++i){
        for( j = 0; j < 12; ++j){
            printf(str, arr[i][j]);
            printf(str, arr2[i][j]);
        }
    }
    for(i = 0 ;i < 10; ++i){
        for( j = 0; j < 12; ++j){
            arr[i][j] = i+j;
            arr2[i][j] = arr[i][j];
        }
    }

    for(i = 0 ;i < 10; ++i){
        for( j = 0; j < 12; ++j){
            printf(str, arr[i][j]);
            printf(str, arr2[i][j]);
        }
    }
    return 0;
}