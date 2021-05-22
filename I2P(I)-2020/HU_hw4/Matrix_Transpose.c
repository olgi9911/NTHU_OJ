#include <stdio.h>

int main()
{
    int matrixA[1000][1000];
    int row = 0, col = 0;
    scanf("%d %d ", &row, &col);
    for (int i = 0; i < row; i++)
    {
        for (int j = 0; j < col; j++)
        {
            scanf("%d", &matrixA[i][j]);
        }
    }

    for (int i = 0; i < col; i++)
    {
        for (int j = 0; j < row; j++)
        {
            if (j < (row - 1))
                printf("%d ", matrixA[j][i]);
            else
                printf("%d", matrixA[j][i]);
        }
        printf("\n");
    }
}