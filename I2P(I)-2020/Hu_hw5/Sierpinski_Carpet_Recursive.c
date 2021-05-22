#include <stdio.h>
#include <math.h>
char arr[2188][2188];

void Sirepinski(int length, int row_left, int col_left){
    if (length == 1)
        return;
    for (int i = row_left + length / 3; i < (row_left + (length / 3) * 2); i++){
            for (int j = col_left + length / 3; j < (col_left + (length / 3) * 2); j++)
                arr[i][j] = '#';
    }
    Sirepinski(length / 3, row_left, col_left);
    Sirepinski(length / 3, row_left, col_left + (length / 3));
    Sirepinski(length / 3, row_left, col_left + (length / 3) * 2);
    Sirepinski(length / 3, row_left + (length / 3), col_left);
    Sirepinski(length / 3, row_left + (length / 3), col_left + (length / 3) * 2);
    Sirepinski(length / 3, row_left + (length / 3) * 2, col_left);
    Sirepinski(length / 3, row_left + (length / 3) * 2, col_left + (length / 3));
    Sirepinski(length / 3, row_left + (length / 3) * 2, col_left + (length / 3) * 2);
}

int main(){
    int n; scanf("%d", &n);
    int power = pow(3, n);
    for (int i = 1; i <= power; i++){
        for (int j = 1; j <= power; j++)
            arr[i][j] = '.';
    }
    Sirepinski(power, 1, 1);
    for (int i = 1; i <= power; i++){
        for (int j = 1; j <= power; j++)
            printf("%c", arr[i][j]);
        printf("\n");
    }
    return 0;
}
