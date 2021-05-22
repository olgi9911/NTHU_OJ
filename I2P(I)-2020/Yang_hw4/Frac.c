#include <stdio.h>
#include <math.h>

double fract(double input)
{
    double fractorial = 1;
    for(int i = 1; i <= input; i++)
        fractorial *= i;

    return fractorial;
}

int main()
{
    double ex = 0;
    int x = 0;
    scanf("%d", &x);
    for(int i = 1; i < 200; i++)
    {
        ex += (pow(x, i) / fract(i));
    }
    ex ++;
    printf("e^x = 1+x/1!+x^2/2!+x^3/3!+x^4/4!+... = %.9f...\n", ex);

    return 0;
}