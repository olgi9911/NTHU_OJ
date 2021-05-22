#include <stdio.h>

int main(void)
{
    int n =1;
    scanf("%d", &n);
    int a[2 * n][2 * n];
    int k = 1, r = 0, m = 0;
    for(int i = 0; i <= n; i++)
    {
       
       for(int j = m; j < (2 * n) - m; j++)
        {
            a[r][j] = k;
            k++;
        }
        for(int i = r + 1; i < (2 * n)-r - 1; i++)
        {
            a[i][(2 * n)-m - 1] = k;
            k++;
        }
        for(int j = (2 * n) - m - 1; j >= m; j--)
        {
            a[(2 * n) - r - 1][j] = k;
            k++;
        }
        for(int i = (2 * n) - r - 2; i > r; i--)
        {
            a[i][m] = k;
            k++;
        }
        r++;
        m++;
    }

    for(int i = 0; i < (2 * n); i++)
    {
        for(int j = 0; j < (2 * n); j++)
            if(j != (2 * n) -1)
                printf("%d ", a[i][j]);
            else if(j == (2 * n - 1))
                printf("%d", a[i][j]);
        printf("\n");
    }
    return 0;
}