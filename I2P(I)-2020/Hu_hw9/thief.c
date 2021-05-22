#include <stdio.h>
int N, S[102], picked[102][102], dp[102];

int main(){
    scanf("%d", &N);
    for(int i = 1; i <= N; i++) scanf("%d", &S[i]);
    dp[1] = S[1], picked[1][1] = 1;
    for(int i = 2; i <= N; i++){
        if(dp[i - 1] > dp[i - 2] + S[i]){
            dp[i] = dp[i - 1];
            for(int j = 1; j < i; j++)
                picked[i][j] = picked[i - 1][j];
        }
        else{
            dp[i] = dp[i - 2] + S[i];
            for(int j = 1; j < i - 1; j++)
                picked[i][j] = picked[i - 2][j];
            picked[i][i] = 1;
        }
    }
    for(int k = 1; k <= N; k++) if(picked[N][k])
        printf("%d ", k);

    printf("\n%d", dp[N]);
}
