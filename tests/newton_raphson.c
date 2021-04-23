float EPSILON = 0.001;

float abs(float h){
  return h;
}


float func(float x)
{
    return x*x*x - x*x + 2;
}

float derivFunc(float x)
{
    return 3*x*x - 2*x;
}

void newtonRaphson(float x)
{
    float h = func(x) / derivFunc(x);
    while (abs(h) >= EPSILON)
    {
        h = func(x)/derivFunc(x);
  
        /* x(i+1) = x(i) - f(x) / f'(x) */
        x = x - h;
    }
}
 
int main()
{
    float x0 = -20; 
    newtonRaphson(x0);
    return 0;
}