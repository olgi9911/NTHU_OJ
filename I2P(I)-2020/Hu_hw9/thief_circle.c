#include <stdio.h>
#define max(a, b) (a > b ? a : b)
int N, ans = 0;

void solve(int l, int r){
    int S[102], dp[102], picked[102][102];
    dp[1] = S[l], picked[1][1] = 1;
    for(int i = 2; i <= N; i++){
        if(dp[i - 1] > dp[i - 2] + S[l + i]){
            dp[i] = dp[i - 1];
            for(int j = 1; j < i; j++)
                picked[i][j] = picked[i - 1][j];
        }
        else{
            dp[i] = dp[i - 2] + S[l + i];
            for(int j = 1; j < i - 1; j++)
                picked[i][j] = picked[i - 2][j];
            picked[i][i] = 1;
        }
    }
}
int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &S[i]);
}