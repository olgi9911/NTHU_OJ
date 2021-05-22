#include <stdio.h>

int N, R, C;
char maze[101][101];
int used[101][101];
int start[2];
int pathCount = 0, leastStep = 1000000000;
void Maze(int row, int col, int step){
    if(maze[row][col] == 'F'){
        pathCount ++;
        leastStep = (leastStep < step ? leastStep : step);
        return;
    }
    for(int i = -1; i <= 1; i += 2){
        if((maze[row + i][col] == '$' || maze[row + i][col] == 'F') && !used[row + i][col]){
            used[row + i][col] = 1;
            Maze(row + i, col, step + 1);
            used[row + i][col] = 0;
        }
    }
    for(int i = -1; i <= 1; i += 2){
        if((maze[row][col + i] == '$' || maze[row][col + i] == 'F') && !used[row][col + i]){
            used[row][col + i] = 1;
            Maze(row, col + i, step + 1);
            used[row][col + i] = 0;
        }
    }
}
int main(){
    scanf("%d", &N);
    while(N--){
        pathCount = 0;
        leastStep = 10000000;
        scanf("%d %d", &R, &C);
        for(int i = 1; i <= R; i++){
            scanf("%s", maze[i] + 1);
            for(int c = 1; c <= C; c++) if(maze[i][c] ==  'S') start[0] = i, start[1] = c;
        }
        Maze(start[0], start[1], 0);
        if(pathCount) printf("%d %d\n", pathCount, leastStep);
        else printf("0 -1\n");
    }
}