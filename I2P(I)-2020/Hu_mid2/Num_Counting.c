#include <stdio.h>
#include <stdlib.h>
int N, K;
char save[1050000];
int solve(int sum, int state){
    if(sum >= K){
        save[state] = 0;
        return 0;
    }
    if(save[state] != -1) return save[state];
    int next;
    for(int i = 0; i < N; i++){
        if(!(state & (1 << i))){
            next = solve(sum + i + 1, state | (1 << i));
            if(next == 0) return save[state] = 1;
        }
    }
    save[state] = 0;
    return 0;
}

int main(){
    int q = 0; scanf("%d", &q);
    while(q--){
        scanf("%d %d", &N, &K);
        for(int i = 0; i < (1 << N); i++) save[i] = -1;
        printf("%s\n", solve(0, 0) ? "True" : "False");
    }
    return 0;
}