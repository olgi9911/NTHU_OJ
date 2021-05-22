#include<stdio.h>

void filldomino(int (*board)[20], int n, int row, int col, int dominos, int* pwc);
void showtheboard(int (*board)[20], int n);

int main()
{
    int n;
    int possible_way_count = 0;
    scanf("%d", &n);
    int board[3][20];
    //initialize the board
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 20; j++){
            board[i][j] = 0;
        }
    }
    filldomino(board, n, 0, 0, 0, &possible_way_count);
    printf("%d\n", possible_way_count);
    return 0;
}

void filldomino(int (*board)[20], int n, int row, int col, int dominos, int* pwc)
{
    if(n%2 != 0){
        printf("No possible way\n");
        return;
    }
    if(dominos == 3*n/2){
        (*pwc)++;
        printf("\n-------------------------------------------------\n");
        printf("Successful tiled the full board with %d dominals!\n", dominos);
        printf("One of %d possible-way \n", *pwc);
        printf("-------------------------------------------------\n");
        return;
    }
    if(row < 3 && col == n){
        printf("\nChangeline\n");
        filldomino(board, n, row+1, 0, dominos, pwc);
        return;
    }
    if(board[row][col] != 0){
        printf("\n(%d, %d) is used, so move to the next position\n", row+1, col+1);
        filldomino(board, n, row, col+1, dominos, pwc);
        return;
    }
    dominos++;
    printf("\nCurrent at (%d, %d)\n", row+1, col+1);    
    if(col < n-1  && board[row][col+1] == 0){
        board[row][col] = board[row][col+1] = dominos;
        printf("\nTile a horizental dominal\n\n");
        showtheboard(board, n);
        filldomino(board, n, row, col+1, dominos, pwc);
        board[row][col] = board[row][col+1] = 0;
    }
    if(row < 2 && board[row+1][col] == 0){
        board[row][col] = board[row+1][col] = dominos;
        printf("\nTile a vertical domino\n\n");
        showtheboard(board, n);
        filldomino(board, n, row, col+1, dominos, pwc);
        board[row][col] = board[row+1][col] = 0;
    }
    dominos--;
    return;
}

void showtheboard(int (*board)[20], int n)
{
    for(int i = 0; i < 3; i++){
        printf("|");
        for(int j = 0; j < n; j++){
            printf("%3d", board[i][j]);
        }
        printf("  |");
        printf("\n");
    }
}