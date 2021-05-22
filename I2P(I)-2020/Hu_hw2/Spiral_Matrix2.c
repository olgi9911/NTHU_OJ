#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    n *= 2;
    int a[n][n];
    int b = 0, c = 0, num = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = c; j < (n - c); j++)
        {
            a[b][j] = num;
            num++;
        }
        for (int i = b + 1; i < (n - b) - 1; i++)
        {
            a[i][n - c - 1] = num;
            num++;
        }
        for (int j = n - c - 1; j >= c; j--)
        {
            a[n - b - 1][j] = num;
            num++;
        }
        for (int i = n - b - 2; i > b; i--)
        {
            a[i][c] = num;
            num++;
        }
        b++;
        c++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (j < n - 1)
                printf("%d ", a[i][j]);
            else if (j == (n - 1))
                printf("%d", a[i][j]);
        }
        printf("\n");
    }

    return 0;
}