#include <stdio.h>
char A[3][5], B[3][5];
int K;
void swap(char *a, char *b){
    char temp = *a;
    *a = *b;
    *b = temp;
}

int check(){
    for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
        if(A[i][j] != B[i][j]) return 0;
    return 1;
}

int solve(int curr, int x, int y){
    int dx[4] = {-1, 0, 0, 1}, dy[4] = {0, -1, 1, 0};
    if(check()) return 1;
    if(curr == K) return 0;
    for(int i = 0; i < 4; i++){
        if(0 <= (x+dx[i]) && (x+dx[i]) < 3 && 0 <= (y+dy[i]) && (y+dy[i] < 3)){
            swap(&A[x][y], &A[x + dx[i]][y + dy[i]]);
            if(solve(curr + 1, x + dx[i], y + dy[i])) return 1;
            swap(&A[x][y], &A[x + dx[i]][y + dy[i]]);
        }
    }
    return 0;
}

int main(){
    int T = 0; scanf("%d", &T);
    while(T--){
        int x, y;
        scanf("%d", &K);
        for(int i = 0; i < 3; i++) scanf("%s", A[i]);
        for(int i = 0; i < 3; i++) scanf("%s", B[i]);
        for(int i = 0; i < 3; i++) for(int j = 0; j < 3; j++)
            if(A[i][j] == 'x') x = i, y = j;
        if(solve(0, x, y)) puts("Yes");
        else puts("No");
    }
    return 0;
}