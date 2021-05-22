#include <stdio.h>

int main()
{
    int input = 0, first = 0, second = 0, last = 0;
    scanf("%d", &input);
    first = (input / 100);
    second = (input - first * 100) / 10;
    last = (input - first * 100 - second * 10);
    printf("%c%c%c", first + 64, second + 64, last + 64);

    return 0;
}