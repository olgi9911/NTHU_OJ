#include <stdio.h>
#include <math.h>
char arr[2188][2188]; int n;
void makeHash(int n, int row_left, int col_left)
{
    for (int i = row_left; i < (row_left + n); i++){
        for(int j = col_left; j < (col_left + n); j++)
            arr[i][j] = '#';
    }
}
void Sirepinski(int m)
{
    if(m == (n + 1))
        return;
    int length = pow(3, m - 1);
    for (int i = (length + 1); i <= (pow(3, n) - 1); i += (length * 3)){
        for(int j = (length + 1); j <= (pow(3, n) - 1); j += (length * 3))
            makeHash(length, i, j);
    }
    Sirepinski(m + 1);
}

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= pow(3, n); i++){
        for (int j = 1; j <= pow(3, n); j++)
            arr[i][j] = '.';
    }
    Sirepinski(1);
    for (int i = 1; i <= pow(3, n); i++){
        for (int j = 1; j <= pow(3, n); j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
    return 0;
}
