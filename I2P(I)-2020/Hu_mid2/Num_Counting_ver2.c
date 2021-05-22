#include <stdlib.h>
#include <stdio.h>

int Solve(int n, int k, int state, char *state_mem){
    if(state_mem[state] != 0) return (state_mem[state] == 1);
    for(int i = 0; i < n; i++){
        if(state & (1 << i)) continue;
        if((i + 1) >= k || !Solve(n, k-(i + 1), state | (1 << i), state_mem)){
            state_mem[state] = 1;
            return 1;
        }
    }
    state_mem[state] = -1;
    return 0;
}

int main()
{
    int q; scanf("%d", &q);
    int N, K;
    while(q--){
        scanf("%d%d", &N, &K);
        char *state_mem = calloc(1<<N, sizeof(char));
        if(Solve(N, K, 0, state_mem)) printf("True\n");
        else printf("False\n");
        free(state_mem);
    }

    return 0;
}
