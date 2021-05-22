#include <stdio.h>

int main()
{
    int n = 0, m = 0, t = 0, input = 0, flag = 1, result = 0;
    char arr[501][501];
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            scanf(" %c", &arr[i][j]);
    }
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &input);
        for (int j = 1; j <= n; j++)
        {
            if (arr[j][input] == '\\')
            {
                if (input > (m - 1))
                {
                    result = 2;
                    break;
                }
                else
                {
                    if (arr[j][input + 1] == '\\')
                        result = 0;
                    else if (arr[j][input + 1] == '/')
                    {
                        result = 3;
                        break;
                    }
                }
                input++;
            }
            else if (arr[j][input] == '/')
            {
                if (input < 2)
                {
                    result = 1;
                    break;
                }
                else
                {
                    if (arr[j][input - 1] == '/')
                        result = 0;
                    else if (arr[j][input - 1] == '\\')
                    {
                        result = 3;
                        break;
                    }
                }
                input--;
            }
        }
        if (result == 3)
            printf("Stuck QQ\n");
        else if (result == 1)
            printf("Left!\n");
        else if (result == 2)
            printf("Right!\n");
        else
            printf("Position: %d\n", input);
    }

    return 0;
}