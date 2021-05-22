#include <stdio.h>
#include <stdlib.h>
int min(int a, int b){
    if(a >= b) return b;
    else return a;
}

void bubblesort(long long arr[][500], int len, int y, int x){
    long long temp;
    for(int i = 0; i < len-1; i++){
        for(int j = 0; j < len-1-i; j++){
            if(arr[y+j][x+j] > arr[y+j+1][x+j+1]){
                temp = arr[y+j][x+j];
                arr[y+j][x+j] = arr[y+j+1][x+j+1];
                arr[y+j+1][x+j+1] = temp;
            }
        }
    }
}

void array2d_sort(int row, int col, long long arr[][500]){
    bubblesort(arr, min(row, col), 0, 0);
    for(int i = 1; i < row; i++)
        bubblesort(arr, min(row-i, col), i, 0);
    for(int i = 1; i < col; i++)
        bubblesort(arr, min(row, col-i), 0, i);
}
///Partial Judge
long long arr[500][500] = {};

int main(void){
    int row, col;
    scanf("%d%d", &row, &col);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            scanf("%lld", &arr[i][j]);

    array2d_sort(row, col, arr);

    for(int i = 0; i < row; ++i)
        for(int j = 0; j < col; ++j)
            printf("%lld%c", arr[i][j], (j==col-1) ? '\n' : ' ');

    return 0;
}