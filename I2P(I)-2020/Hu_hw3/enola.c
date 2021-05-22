#include <stdio.h>

int main()
{
    int n, m;
    while (scanf("%d %d", &n, &m) != EOF)
    {
        char a[n], b[m];
        int am[26] = {0}, bm[26] = {0};
        int correct = 1;
        scanf("%s %s", a, b);
        if (n != m)
            correct = 0;
        else
        {
            for (int i = 0; a[i] != '\0'; i++)
            {
                am[a[i] - 97]++;
            }
            for (int j = 0; b[j] != '\0'; j++)
            {
                bm[b[j] - 97]++;
            }
            for (int i = 0; i < 26; i++)
            {
                if (am[i] != bm[i])
                {
                    correct = 0;
                    break;
                }
            }
        }

        if (correct)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}