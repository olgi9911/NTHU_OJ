#include <stdio.h>
#include <stdlib.h>
int n = 0;
int partition(int k, int target, int current, int num[], int used[], int start)
{
    if (k == 1)
        return 1;
    if (current > target)
        return 0;
    if (current == target)
        return partition(k - 1, target, 0, num, used, 0);
    for (int i = start; i < n; i++)
    {
        if (!used[i])
        {
            used[i] = 1;
            if (partition(k, target, current + num[i], num, used, i + 1))
                return 1;
            used[i] = 0;
        }
    }
    return 0;
}

int main()
{
    int q = 0;
    scanf("%d", &q);
    while (q--)
    {
        int k = 0, sum = 0, target = 0;
        scanf("%d %d", &n, &k);
        int arr[10], used[10] = {0};
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &arr[i]);
            sum += arr[i];
        }
        if (n < k)
            printf("False\n");
        else if (sum % k != 0)
            printf("False\n");
        else
        {
            target = sum / k;
            partition(k, target, 0, arr, used, 0) == 1 ? printf("True\n")
            : printf("False\n");
        }
    }
}