#include <stdio.h>
#include <stdlib.h>

int main()
{
    char shifted = 00, original = 00;
    int d = 0;
    scanf("%c %d", &shifted, &d);
    if (shifted >= 65 && shifted <= 90 && d != 0)
    {
        original = (shifted - 65 - d + 26) % 26 + 65 + 32;
    }
    else if (shifted >= 97 && shifted <= 122 && d != 0)
    {
        original = (shifted - 97 - d + 26) % 26 + 97 - 32;
    }
    else if (shifted >= 65 && shifted <= 90 && d == 0)
    {
        original = shifted + 32;
    }
    else if (shifted >= 97 && shifted <= 122 && d == 0)
    {
        original = shifted - 32;
    }
    printf("%c\n", original);

    return 0;
}