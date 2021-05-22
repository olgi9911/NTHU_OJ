#include <stdio.h>
#include <stdlib.h>

int main()
{
    double a = 0, b = 0, result = 0;
    char o;
    scanf("%lf%c%lf", &a, &o, &b);
    if(o == '+')
        result = a + b;
    else if(o == '-')
        result = a - b;
    else if(o == '*')
        result = a * b;
    else if(o == '/' && b != 0)
        result = a / b;
    if(b == 0 && o == '/')
        printf("Error\n");
    else
        printf("%.3lf\n", result);
    
    return 0;
}