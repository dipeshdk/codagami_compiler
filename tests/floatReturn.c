double dist(double x, double y){
    double diff = x - y;
    return diff;
}



int main() {
    double f = 10.234;
    double g = dist(f, 32.432);
    printf("%lf %lf\n", f, g);
    return 0;
}