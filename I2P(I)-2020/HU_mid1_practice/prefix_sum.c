#include <stdio.h>

int main()
{
    int size = 0, query = 0;
    long long arr[1000000];
    scanf("%d", &size);
    arr[0] = 0;
    for (int i = 1; i <= size; i++)
    {
        int temp = 0;
        scanf("%d", &temp);
        arr[i] = arr[i - 1] + temp;
    }
        
    scanf("%d", &query);
    for (int i = 0; i < query; i++)
    {
        int L = 0, R = 0;
        scanf("%d %d", &L, &R);
        printf("%lld\n", arr[R] - arr[L - 1]);
    }

    return 0;
}