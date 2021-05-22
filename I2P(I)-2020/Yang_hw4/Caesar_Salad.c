#include <stdio.h>

int main()
{
    char a, b, c;
    int n = 0;
    scanf("%c%c%c %d", &a, &b, &c, &n);
    a = (a - 'A' + n%26 + 26)%26 + 'A';
    b = (b - 'A' + n%26 + 26)%26 + 'A';
    c = (c - 'A' + n%26 + 26)%26 + 'A';

    printf("%c%c%c\n", a, b, c);
    return 0;
}
