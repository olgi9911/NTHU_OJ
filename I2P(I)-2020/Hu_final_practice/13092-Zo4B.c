#include <stdio.h>

void move(int dir, int board[4][4]){
    if(dir == 0){
        for(int j = 0; j < 4; j++){
            for(int i = 3; i >= 0; i--){
                if(board[i][j] == 0){
                    for(int k = i; k < 3; k++)
                        board[k][j] = board[k + 1][j];
                    board[3][j] = 0;
                }
            }
        }
    }
    else if(dir == 1){
        for(int j = 0; j < 4; j++){
            for(int i = 0; i < 4; i++){
                if(board[i][j] == 0){
                    for(int k = i; k > 0; k--)
                        board[k][j] = board[k - 1][j];
                    board[0][j] = 0;
                }
            }
        }
    }
    else if(dir == 2){
        for(int i = 0; i < 4; i++){
            for(int j = 3; j >= 0; j--){
                if(board[i][j] == 0){
                    for(int k = j; k < 3; k++)
                        board[i][k] = board[i][k + 1];
                    board[i][3] = 0;
                }
            }
        }
    }
    else if(dir == 3){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == 0){
                    for(int k = j; k > 0; k--)
                        board[i][k] = board[i][k - 1];
                    board[i][0] = 0;
                }
            }
        }
    }
}

void merge(int dir, int board[4][4]){
    if(dir == 0){
        for(int i = 0; i < 3; i++){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == board[i + 1][j]){
                    board[i][j] *= 2;
                    board[i + 1][j] = 0;
                }
            }
        }
    }
    else if(dir == 1){
        for(int i = 3; i > 0; i--){
            for(int j = 0; j < 4; j++){
                if(board[i][j] == board[i - 1][j]){
                    board[i][j] *= 2;
                    board[i - 1][j] = 0;
                }
            }
        }
    }
    else if(dir == 2){
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 3; j++){
                if(board[i][j] == board[i][j + 1]){
                    board[i][j] *= 2;
                    board[i][j + 1] = 0;
                }
            }
        }
    }
    else if(dir == 3){
        for(int i = 0; i < 4; i++){
            for(int j = 3; j > 0; j--){
                if(board[i][j] == board[i][j - 1]){
                    board[i][j] *= 2;
                    board[i][j - 1] = 0;
                }
            }
        }
    }
}

int check(int A[4][4], int B[4][4]){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 4; j++){
            if(A[i][j] != B[i][j]) return 0;
        }
    }
    return 1;
}

int main(){
    int A[4][4], B[4][4];
    while(scanf("%d", &A[0][0]) != EOF){
        B[0][0] = A[0][0];
        for(int i = 0; i < 4; i++){
            for(int j = 0; j < 4; j++){
                if(i == 0 && j == 0) continue;
                scanf("%d", &A[i][j]);
                B[i][j] = A[i][j];
            }
        }
        for(int k = 0; k < 4; k++){
            move(k, B);
            merge(k, B);
            move(k, B);
            if(check(A, B)) printf("Invalid\n");
            else{
                for(int i = 0; i < 4; i++){
                    for(int j = 0; j < 4; j++){
                        printf("%d%c", B[i][j], (j == 3) ? '\n' : ' ');
                        B[i][j] = A[i][j];
                    }
                }
            }
        }
    }
}