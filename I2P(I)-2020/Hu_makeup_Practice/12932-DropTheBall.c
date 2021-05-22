#include <stdio.h>

int main(){
    char board[505][505];
    int n, m; scanf("%d%d", &n, &m);
    for(int i = 1; i <= n; i++){
        scanf("%s", board[i] + 1);
    }

    int Q; scanf("%d", &Q);
    while(Q--){
        int result = -1, col;
        scanf("%d", &col);
        for(int row = 1; row <= n; row++){
            if(board[row][col] == '\\'){
                if(col == m){
                    result = 2;
                    break;
                }
                else if(board[row][col + 1] == '\\') col++;
                else{
                    result = 0;
                    break;
                }
            } else if(board[row][col] == '/'){
                if(col == 1){
                    result = 1;
                    break;
                }
                else if(board[row][col - 1] == '/') col--;
                else{
                    result = 0;
                    break;
                }
            }
        }

        if(result == 0) printf("Stuck QQ\n");
        else if(result == 1) printf("Left!\n");
        else if(result == 2) printf("Right!\n");
        else printf("Position: %d\n", col);
    }
}