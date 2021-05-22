#include <stdio.h>

int main()
{
    unsigned long long int arr[117]={1, 1, 1};
    int input = 0;
    scanf("%d", &input);
    for(int i = 3; i <= input; i++)
    {
        arr[i] = arr[i - 1] + arr[i - 3];
    }
    printf("%llu\n", arr[input]);

    return 0;
}