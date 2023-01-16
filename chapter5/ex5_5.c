#include <stdio.h>

double poly(double a[] , double x, long degree)
{
    long i ;
    double result = a[0];
    double xpwr = x;
    for(i = 1; i < degree; i++){
        result += a[i] * xpwr;
        xpwr = x* xpwr;
    }

    return result;
}

int main(int argc, char const *argv[])
{
    double a[3]= {2,3,4};
    
    return (int)poly(a, 3.0, 2l);;
}
