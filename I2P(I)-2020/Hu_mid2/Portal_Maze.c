#include <stdio.h>
#define MAX 305
char maze[MAX][MAX];
int portX[26], portY[26], visited[MAX][MAX];
int N, M;

int solve(int x, int y, int endX, int endY){
    int dx[] = {-1, 0, 0, 1}, dy[] = {0, -1, 1, 0};
    visited[x][y] = 1;
    if(x == endX && y == endY) return 1;
    for(int i = 0; i < 4; i++){
        int nextX = x + dx[i], nextY = y + dy[i];
        if(nextX < 0 || nextX >= N || nextY < 0 || nextY >= M) continue;
        char nextElement = maze[nextX][nextY];
        if('a' <= nextElement && nextElement <= 'z')
            nextX = portX[nextElement - 'a'], nextY = portY[nextElement - 'a'];
        if(!visited[nextX][nextY] && maze[nextX][nextY] != '#')
            if(solve(nextX, nextY, endX, endY) == 1) return 1;
    }
    return 0;
}

int main(){
    int T; scanf("%d", &T);
    int startX, startY, endX, endY;
    while(T--){
        scanf("%d %d", &N, &M);
        for(int i = 0; i < N; i++) scanf("%s", maze[i]);
        for(int i = 0; i < N; i++){
            for(int j = 0; j < M; j++){
                visited[i][j] = 0;

                if(maze[i][j] == '$')
                    startX = i, startY = j;
                else if(maze[i][j] == '&')
                    endX = i, endY = j;
                else if('A' <= maze[i][j] && maze[i][j] <= 'Z')
                    portX[maze[i][j] - 'A'] = i, portY[maze[i][j] - 'A'] = j;
            }
        }
        printf("%s\n", (solve(startX, startY, endX, endY) == 1 ? "Yes" : "No"));
    }
}