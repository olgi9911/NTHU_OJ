#include <stdio.h>

int main()
{
    int lenA = 0, lenB = 0, lenOut = 0, neg = 0;
    int arrA[100] = {-1}, arrB[100] = {0}, arrAB[100] = {0};
    char bigger = 'A';
    scanf("%d", &lenA);
    for (int i = lenA; i > 0; i--)
    {
        int input = 0;
        scanf("%1d", &input);
        arrA[i] = input;
    }
    scanf("%d", &lenB);
    for (int i = lenB; i > 0; i--)
    {
        int input = 0;
        scanf("%1d", &input);
        arrB[i] = input;
    }

    if (lenA > lenB)
        bigger = 'A';
    else if (lenA < lenB)
        bigger = 'B';
    else if (lenA == lenB)
    {
        for (int i = lenA; i > 0; i--)
        {
            if (arrA[i] > arrB[i])
            {
                bigger = 'A';
                break;
            }
            else if (arrA[i] < arrB[i])
            {
                bigger = 'B';
                break;
            }
        }
    }

    if (bigger == 'A')
    {
        lenOut = lenA;
        for (int i = 1; i <= lenA; i++)
        {
            if (arrA[i] < arrB[i])
            {
                for (int j = i + 1; j <= lenA; j++)
                {
                    if (arrA[j] > 0)
                    {
                        arrA[j]--;
                        arrA[i] += 10;
                        break;
                    }
                    else if (arrA[j] == 0)
                    {
                        arrA[j] = 9;
                    }
                }
            }
            arrAB[i] = arrA[i] - arrB[i];
        }
    }
    else if (bigger == 'B')
    {
        neg = 1;
        lenOut = lenB;
        for (int i = 1; i <= lenB; i++)
        {
            if (arrB[i] < arrA[i])
            {
                for (int j = i + 1; j <= lenB; j++)
                {
                    if (arrB[j] > 0)
                    {
                        arrB[j]--;
                        arrB[i] += 10;
                        break;
                    }
                    else if (arrB[j] == 0)
                    {
                        arrB[j] = 9;
                    }
                }
            }
            arrAB[i] = arrB[i] - arrA[i];
        }
    }

    for (int i = lenOut; i > 0; i--)
    {
        if (arrAB[i] > 0)
            break;
        else if (arrAB[i] == 0)
            lenOut--;
    }
    if (lenOut == 0)
        lenOut++;
    if (neg == 1)
        printf("-");

    for (int i = lenOut; i > 0; i--)
    {
        printf("%d", arrAB[i]);
    }
    return 0;
}