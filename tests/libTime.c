int main(){
    int sec;
    int start_time, end_time, total_t;
    int i;
    char* charTime;
    int j = 0;
    start_time = clock();
    printf("Starting of the program, start_time = %d\n", start_time);

    printf("Going to scan a big loop, start_time = %d\n", start_time);
    for (i = 0; i < 100; i++)
    {j = 0;}
    end_time = clock();
    printf("End of the big loop, end_time = %d\n", end_time);
    printf("Difference is  %d seconds\n", difftime(end_time, start_time));
    charTime = ctime(&end_time);
    printf("Time in characters = %s\n", charTime);
    return 0;
}