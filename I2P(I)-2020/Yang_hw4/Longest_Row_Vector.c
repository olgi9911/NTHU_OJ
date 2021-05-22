#include <stdio.h>
#include <math.h>

int main()
{
    int m = 0, n = 0, k = 0;
    scanf("%d %d %d", &m, &n, &k);
    int a[m][n];
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    }

    for (int q = 0; q < k; q++)
    {
        int op = 2, i = 0, j = 0;
        scanf("%d %d %d", &op, &i, &j);
        if (op == 0)
        {
            for (int m = 0, temp = 0; m < n; m++)
            {
                temp = a[i][m];
                a[i][m] = a[j][m];
                a[j][m] = temp;
            }
        }
        else if (op == 1)
        {
            for (int m = 0; m < n; m++)
                a[i][m] += a[j][m];
        }
    }

    double v = 1;
    int I = 0;
    for (int i = m - 1; i >= 0; i--)
    {
        double tem = 0;
        for (int j = 0; j < n; j++)
            tem += pow((a[i][j]), 2);

        if (sqrt(tem) >= v)
        {
            v = sqrt(tem);
            I = i;
        }
    }

    for (int j = 0; j < n; j++)
    {
        if (j < n - 1)
            printf("%d ", a[I][j]);
        else if (j == n - 1)
            printf("%d\n", a[I][j]);
    }
    return 0;
}