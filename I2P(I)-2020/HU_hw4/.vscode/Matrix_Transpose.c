#include <stdio.h>

int main()
{
    int row = 0, col = 0;
    scanf("%d %d", &row, &col);
    int arr[1000][1000], arr_new[1000][1000];
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            scanf("%d", &arr[i][j]);
        }
    }

    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            arr_new[j][i] = arr[i][j];
        }
    }

    for(int i = 0; i < col; i++)
    {
        for(int j = 0; j < row; j++)
        {
            if(j < (row - 1))
                printf("%d ", arr_new[i][j]);
            else
                printf("%d", arr_new[i][j]);
        }
        printf("\n");
    }

    return 0;
}