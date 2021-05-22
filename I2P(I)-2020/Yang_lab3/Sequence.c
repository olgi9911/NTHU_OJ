#include <stdio.h>

int main()
{
    int input = 0, a1 = 0, a2 = 0, a3 = 0, d = 0, dx = 0;
    scanf("%d", &input);
    scanf("%d %d %d", &a1, &a2, &a3);
    int out = a1;
    d = a2 - a1;
    dx = a3 - (2 * a2) + a1;
    printf("%d", out);
    for (int i = 1; i < input; i++)
    {
        out += d;
        printf(" %d", out);
        d += dx;
    }
    printf("\n");

    return 0;
}