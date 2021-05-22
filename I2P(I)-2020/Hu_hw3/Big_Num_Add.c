#include <stdio.h>

int main()
{
    int lenA = 0, lenB = 0, lenOut = 0;
    int A[100] = {-1}, B[100] = {0}, AB[100] = {0};
    scanf("%d", &lenA);
    for (int i = lenA; i > 0; i--)
    {
        int input = 0;
        scanf("%1d", &input);
        A[i] = input;
    }
    scanf("%d", &lenB);
    for (int i = lenB; i > 0; i--)
    {
        int input = 0;
        scanf("%1d", &input);
        B[i] = input;
    }

    if (lenA >= lenB)
        lenOut = lenA;
    else if (lenA < lenB)
        lenOut = lenB;
    
    for(int i = 1; i <= lenOut; i++)
    {
        if((A[i] + B[i]) >= 10)
        {
            AB[i + 1] ++;
            AB[i] = (A[i] + B[i]) - 10;
        }
        else
        {
            AB[i] = A[i] + B[i];
        }
    }

    for (int i = lenOut + 1; i > 0; i--)
    {
        if (AB[i] > 0)
        {
            lenOut = i;
            break;
        }
    }
    
    for (int i = lenOut; i > 0; i--)
    {
        printf("%d", AB[i]);
    }
    return 0;
}