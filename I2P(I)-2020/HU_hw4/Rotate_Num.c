#include <stdio.h>
#include <string.h>

int main()
{
    char num[100];
    int j = 0, meaningless = 0, flag = 0;
    scanf("%s", num);
    char num_180[strlen(num)];
    for (int i = strlen(num) - 1; i >= 0; i--)
    {
        if (num[i] == '2' || num[i] == '3' || num[i] == '4' || num[i] == '5' || num[i] == '7')
        {
            meaningless = 1;
            break;
        }
        else
        {
            switch (num[i])
            {
            case ('1'):
                num_180[j] = '1';
                j++;
                break;
            case ('6'):
                num_180[j] = '9';
                j++;
                break;
            case ('8'):
                num_180[j] = '8';
                j++;
                break;
            case ('9'):
                num_180[j] = '6';
                j++;
                break;
            case ('0'):
                num_180[j] = '0';
                j++;
                break;
            }
        }
    }

    if (meaningless == 1)
        printf("No\n");
    else
    {
        for (int i = 0; i < j; i++)
        {
            if (num_180[i] != '0')
                flag = 1;
            if (flag == 1)
                printf("%c", num_180[i]);
        }
        printf("\n");
    }
}