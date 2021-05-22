#include <stdio.h>

int main()
{
    int a = 0, b = 0, c = 0, A = 0, B = 0, C = 0, input1 = 0, input2 = 0;
    scanf("%d,%d,%d", &a, &b, &c);
    scanf("%d,%d,%d", &A, &B, &C);
    input1 = a * 1000000 + b * 1000 + c;
    input2 = A*1000000 + B * 1000 + C;
    printf("%d\n", input1 + input2);


    return 0;
}