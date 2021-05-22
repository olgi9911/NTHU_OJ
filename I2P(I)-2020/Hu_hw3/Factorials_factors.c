#include <stdio.h>

int main()
{
    int input = 0;
    int n = 0;
    int PrimeArr[25] = {2, 3, 5, 7, 11, 13, 17, 
    19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
    int AnsArr[100]={0};
    unsigned long long int ans = 1;
    scanf("%d", &input);
    for(int j = input; j > 1; j--)
    {   
        for(int i = 24; i >= 0 && input > 1; i--)
        {
            n = j;
            while(n >= 2)
            {
                if(n >= PrimeArr[i] && (n % PrimeArr[i]) == 0)
                {
                    AnsArr[PrimeArr[i]] ++;
                    n /= PrimeArr[i];
                }
                else
                    n = 0;
            }
        }
    }

    for(int j = 2; j <= 97; j++)
    {
        if(AnsArr[j] > 0)
            ans *= (AnsArr[j] + 1);
    }

    printf("%llu", ans);
    return 0;
}