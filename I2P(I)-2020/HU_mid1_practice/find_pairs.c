#include <stdio.h>

int main()
{
    int length = 0, arr[100001] = {0};
    long long int num[10001] = {0}, counter = 0;
    scanf("%d", &length);
    for(int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
        num[arr[i]] += 1;
    }

    for(int i = 0; i < 10001; i++)
    {
        if(num[i] == 1)
            counter += 0;
        else if(num[i] > 1)
        {
            counter += (num[i] * (num[i] - 1))/2;
        }
    }
    
    printf("%lld\n", counter);
    return 0;
}