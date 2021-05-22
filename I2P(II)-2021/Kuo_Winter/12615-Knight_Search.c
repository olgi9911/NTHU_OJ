#include <stdio.h>
#include <string.h>
const int dx[] = {-2, -2, -1, 1, 2, 2, 1, -1}, dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};
char board[105][105], ans[11] = "ICPCASIASG";
int N;

int check(int x, int y, int time){
    if(time == 10)  return 1;

    for(int i = 0; i < 8; i++){
        int X = x + dx[i], Y = y + dy[i];
        if(0 <= X && X < N && 0 <= Y && Y < N && board[X][Y] == ans[time]){
            if(check(X, Y, time + 1))
                return 1;
        }
    }
    return 0;
}

int main(){
    scanf("%d\n", &N); //mind "\n"
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++) scanf("%c", &board[i][j]);
    }
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++)
            if(board[i][j] == 'I'){
                if(check(i, j ,1)){
                    printf("YES\n");
                    return 0;
                }
            }
    }
    printf("NO\n");
}