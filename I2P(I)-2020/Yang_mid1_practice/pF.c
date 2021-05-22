#include <stdio.h>

int main()
{
    int t = 0, num_is_two = 0, num_is_three = 0, ch['Q' + 1] = {0};
    char c;
    scanf("%d\n", &t);
    while (t--)
    {
        num_is_two = 0, num_is_three = 0;
        for(int i = '1'; i <= 'Q'; i++) ch[i] = 0;
        for (int i = 0; i < 5; i++)
        {
            scanf(" %c", &c);
            ch[(int)c]++; 
            if (c == '1') scanf("%c", &c);
        }
        for (int i = '1'; i <= 'Q'; i++)
        {
            if (ch[i] == 3)
                num_is_three = 1;
            else if (ch[i] == 2)
                num_is_two = 1;
        }
        printf("%s\n", (num_is_three&&num_is_two) ? "YES" : "NO");
    }
    return 0;
}