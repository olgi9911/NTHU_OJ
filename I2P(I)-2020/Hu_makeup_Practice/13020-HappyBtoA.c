#include <stdio.h>
int count[50000] = {0};
static int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}
int encode(char board [3][5]){
    int num = 0;
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++)
            num = (num * 3) + (board[i][j] == 'x' ? 2 : board[i][j] - '0');
    }
    return num;
}
int solve(int depth, int x, int y, int K, char board[][5]){
    int ans = 0, code = encode(board);
    ans += count[code], count[code] = 0;
    if(depth == K)
        return ans;
    for(int dir = 0; dir < 4; dir++){
        int nX = x + dx[dir], nY = y + dy[dir];
        if(nX < 0 || nX > 2 || nY < 0 || nY > 2) continue;
        swap(&board[x][y], &board[nX][nY]);
        ans += solve(depth + 1, nX, nY, K, board);
        swap(&board[x][y], &board[nX][nY]);
    }
    return ans;
}

int main(){
    int N, K, x, y;
    char board[3][5];
    scanf("%d%d", &N, &K);
    for(int i = 0; i <= N; i++){
        for(int j = 0; j < 3; j++)
            scanf("%s", board[j]);
        
        if(i == N) break;
        count[encode(board)] ++;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(board[i][j] == 'x')
                x = i, y = j;
        }
    }
    printf("%d\n", solve(0, x, y, K, board));
}