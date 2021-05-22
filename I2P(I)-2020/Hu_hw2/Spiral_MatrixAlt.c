#include <stdio.h>

int main()
{
    int n = 0, b = 0, num = 1;
    scanf("%d", &n);
    n *= 2;
    int a[n][n];
    for(int i = 0; i < n; i++)
    {
        for(int j = b; j < (n - b); j++)
        {
            a[j][b] = num;
            num ++;
        }
        for(int i = b + 1; i < (n - b); i++)
        {
            a[n - b - 1][i] = num;
            num ++;
        }
        for(int j = (n - b - 2); j >= b; j--)
        {
            a[j][n - b - 1] = num;
            num ++;
        }
        for(int i = (n - b - 2); i > b; i--)
        {
            a[b][i]= num;
            num ++;
        }
        b++;
    }
    for(int j = 0; j < n; j++)
    {
        for(int i = 0; i < n; i++)
        {
            if(i < n - 1)
                printf("%d ", a[j][i]);
            else if(i == n - 1)
                printf("%d", a[j][i]);
        }
        printf("\n");
    }

    return 0;
}