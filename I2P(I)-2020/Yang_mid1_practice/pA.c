#include <stdio.h>

int main()
{
    int arr[100001] = {}, printed[200001] = {0}, n = 0, m = 0, location = 0;
    scanf("%d %d", &n, &m);
    while(m--)
    {
        scanf("%d", &arr[location]);
        location ++;
    }
    for(int i = (location - 1); i >= 0; i--)
    {
        if(printed[arr[i]] == 0)
            printf("%d\n", arr[i]);
        printed[arr[i]] = 1;
    }
    for(int i = 1; i <= n ; i++)
    {
        if(printed[i] == 0)
            printf("%d\n", i);
    }
    return 0;
}