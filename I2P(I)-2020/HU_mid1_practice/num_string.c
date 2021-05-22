#include <stdio.h>
#include <math.h>

int main()
{
    int length = 0, times = 0;
    char str[1001] = {'0'}, newstr[1001];
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
    {
        scanf(" %c", &str[i]);
    }
    scanf("%d", &times);
    for(int i = 0; i < times; i++)
    {
        int a = 0, b = 0, sz = 0;
        long int outa = 0, outb = 0;
        scanf("%d %d %d", &a, &b, &sz);
        int outn = sz;
        for(int j = a; j < (a + sz); j++)
        {
            outa += ((str[j] - '0') * pow(10, outn - 1));
            str[j] = '0';
            outn --;
        }
        outn = sz;
        for(int j = b; j < (b + sz); j++)
        {
            outb += ((str[j] - '0') * pow(10, outn - 1));
            str[j] = '0';
            outn --;
        }
        int n = 0;
        for(int m = 0; m < length; m++)
        {
            if(str[m] != '0')
            {
                newstr[n] = str[m];
                n++;
                str[m] = '0';
            }
        }
        for(int k = 0; k <= n; k++)
        {
            str[k] = newstr[k];
        }
        for(int l = n + 1; l < length; l++)
        {
            str[l] = '0';
        }
        printf("%ld\n", outa * outb);
    }
    return 0;
}