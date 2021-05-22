#include <stdio.h>
#include <stdlib.h>
long long min(long long a, long long b){
    return a < b ? a : b;
}
void bubblesort(int length, int x, int y, long long arr[][500]){
    for(int i = 0; i < length - 1; i++){
        for(int j = 0; j < length - 1 - i; j++){
            if(arr[x + j][y + j] > arr[x + j + 1][y + j + 1]){
                long long temp = arr[x + j][y + j];
                arr[x + j][y + j] = arr[x + j + 1][y + j + 1];
                arr[x + j + 1][y + j + 1] = temp;
            }
        }
    }
}
void array2d_sort(int row, int col, long long arr[][500]){
    bubblesort(min(row, col), 0, 0, arr);
    for(int i = 1; i < row; i++)
        bubblesort(min(row - i, col), i, 0, arr);
    
    for(int j = 1; j < col; j++)
        bubblesort(min(row, col - j), 0, j, arr);
}
//
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