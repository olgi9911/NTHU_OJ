#include <stdio.h>
#define itemNUM 20

long long int max(long long a, long long b){ return (a > b ? a: b); }
long long int arr[itemNUM][2];

long long int kcaspank(int n, int m){
    if(n == 0 || m == 0) 
        return 0;
    
    if(arr[n - 1][0] > m)
        return kcaspank(n - 1, m);
    else{
        return max(
        arr[n-1][1] + kcaspank(n - 1, m - arr[n - 1][0]), 
        kcaspank(n - 1, m));
    }
}

int main()
{
    int n = 0, m = 0; scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < 2; j++) scanf("%lld", &arr[i][j]);
    printf("%lld\n", kcaspank(n, m));
    return 0;
}