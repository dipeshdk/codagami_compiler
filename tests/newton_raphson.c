double EPSILON = 0.001;

double myAbs(double h){
  return h;
}

double func(double x)
{
    return x*x*x - x*x + 2.0;
}

double derivFunc(double x)
{
    return 3.0*x*x - 2.0*x;
}

void newtonRaphson(double x)
{
    double f = func(x), df = derivFunc(x);
    double h = f/df;
    while (myAbs(h) >= EPSILON)
    {
        double f = func(x), df = derivFunc(x);
        h = f/df;
        x = x - h;
    }
}
 
int main()
{
    double x0 = -20.0; 
    newtonRaphson(x0);
    return 0;
}