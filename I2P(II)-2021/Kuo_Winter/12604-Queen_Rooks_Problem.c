#include <stdio.h>
char board[10][10];
int n, m, size;

int queen(int row, int col){
    for(int i = 1; i <= row; i++){
        if(col - i >= 0 && (board[row - i][col - i] == 'Q' || board[row - i][col - i] == 'R'))
            return 0; //upper-left check
        if(col + i < size && (board[row - i][col + i] == 'Q' || board[row - i][col + i] == 'R'))
            return 0; //upper-right check
        if(board[row - i][col] == 'Q' || board[row - i][col] == 'R')
            return 0; //up check
    }
    return 1;
}

int rooks(int row, int col){
    for(int i = 1; i <= row; i++){
        if(col - i >= 0 && board[row - i][col - i] == 'Q')
            return 0; //upper-left check
        if(col + i < size && board[row - i][col + i] == 'Q')
            return 0; //upper-right check
        if(board[row - i][col] == 'Q' || board[row - i][col] == 'R')
            return 0; //up check
    }
    return 1;
}

int solve(int q, int r, int row){
    if(row == size) return 1; //condition satisfied, q = n and r = m
    int num = 0;
    for(int col = 0; col < size; col++){
        if(q < n && queen(row, col)){
            board[row][col] = 'Q';
            num += solve(q + 1, r, row + 1);
            board[row][col] = '0';
        }
        if(r < m && rooks(row, col)){
            board[row][col] = 'R';
            num += solve(q, r + 1, row + 1);
            board[row][col] = '0';
        }
    }
    return num;
}

int main(){
    while(scanf("%d %d", &n, &m) != EOF){
        size = n + m;
        printf("%d\n", solve(0, 0, 0));
    }
}