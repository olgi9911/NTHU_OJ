#include<stdio.h>
#define MAX 7
int main()
{
    int i = 0, n = 0, a[MAX], f = 0;
    scanf("%d",&n);
    n = n + 1;
    while (n > 0)
    {
        a[i] = n % 2;
        i = i + 1;
        n = n / 2;
    }
    for(; i > 0; i--)
    {
        printf("%d",a[i-1]);
    }
    while (a[f]==0)
    {
        f++;
    }
    printf(" %d",f);
    
    return 0;
}