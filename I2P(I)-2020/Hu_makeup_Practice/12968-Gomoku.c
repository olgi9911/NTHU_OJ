#include <stdio.h>

int main(){
    char board[20][20];
    int q; scanf("%d", &q);
    while(q--){
        for(int i = 0; i < 15; i++)
            scanf("%s", board[i]);
        char winner = 'n';

        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                if(board[i][j] != '.'){
                    if(i + 4 < 15 && board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j])
                        winner = board[i][j];
                    if(j + 4 < 15 && board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4])
                        winner = board[i][j];
                    if(i + 4 < 15 && j + 4 < 15 && board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4])
                        winner = board[i][j];
                    if(i + 4 < 15 && j - 4 >=0 && board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4])
                        winner = board[i][j];
                }
            }
        }

        if(winner == 'w') printf("white\n");
        else if(winner == 'b') printf("black\n");
        else printf("none\n");
    }
}