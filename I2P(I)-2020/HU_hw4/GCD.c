#include <stdio.h>

int GCD(int a, int b)
{
    int gcd = 0;
    for (int i = 1; i <= a && i <= b; i++)
    {
        if (a % i == 0 && b % i == 0)
            gcd = i;
    }
    return gcd;
}

int main()
{
    int num1 = 0, num2 = 0;
    scanf("%d %d", &num1, &num2);
    printf("%d\n", GCD(num1, num2));
    return 0;
}