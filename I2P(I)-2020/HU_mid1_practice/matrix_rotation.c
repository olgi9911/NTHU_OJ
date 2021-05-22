#include <stdio.h>

int main()
{
    long long int row = 0, col = 0, time = 0;
    scanf("%lld %lld", &row, &col);
    long long matrix[100][100];
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%lld", &matrix[i][j]);
        }
    }
    scanf("%lld", &time);
    switch (time % 4)
    {
    case (0):
    {
        for (int i = 0; i < row; i++)
        {
            for (int j = 0; j < col; j++)
            {
                if (j < (col - 1))
                    printf("%lld ", matrix[i][j]);
                else
                {
                    printf("%lld", matrix[i][j]);
                }
            }
            printf("\n");
        }
        break;
    }
    case (1):
    {
        for (int i = 0; i < col; i++)
        {
            for (int j = (row - 1); j >= 0; j--)
            {
                if (j > 0)
                    printf("%lld ", matrix[j][i]);
                else
                {
                    printf("%lld", matrix[j][i]);
                }
            }
            printf("\n");
        }
        break;
    }
    case (2):
    {
        for (int i = (row - 1); i >= 0; i--)
        {
            for (int j = (col - 1); j >= 0; j--)
            {
                if (j > 0)
                    printf("%lld ", matrix[i][j]);
                else
                {
                    printf("%lld", matrix[i][j]);
                }
            }
            printf("\n");
        }
        break;
    }
    case (3):
    {
        for (int i = (col - 1); i >= 0; i--)
        {
            for (int j = 0; j < row; j++)
            {
                if (j < (row - 1))
                    printf("%lld ", matrix[j][i]);
                else
                {
                    printf("%lld", matrix[j][i]);
                }
            }
            printf("\n");
        }
        break;
    }
    }
}