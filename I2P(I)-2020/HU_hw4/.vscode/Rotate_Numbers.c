#include <stdio.h>
#include <string.h>
int main()
{
    char num[100];
    scanf("%s", num);
    int j = 0, meaningless = 0;
    int length = strlen(num);
    char num_180[length];
    for (int i = length - 1; i >= 0; i--)
    {
        if (num[i] == '2' || num[i] == '3' || 
        num[i] == '4' || num[i] == '5' || num[i] == '7')
        {
            meaningless = 1;
            break;
        }
        switch (num[i])
        {
        case '0':
            num_180[j] = '0';
            j++;
            break;
        case '1':
            num_180[j] = '1';
            j++;
            break;
        case '6':
            num_180[j] = '9';
            j++;
            break;
        case '8':
            num_180[j] = '8';
            j++;
            break;
        case '9':
            num_180[j] = '6';
            j++;
            break;
        }
    }
    if (meaningless == 1)
    {
        printf("No");
    }
    else if(meaningless == 0)
    {
        int flag = 0;
        for (int i = 0; i < j; i++)
        {
            if (num_180[i] != '0')
                flag = 1;

            if (flag == 1)
                printf("%c", num_180[i]);
        }
    }
    printf("\n");
}