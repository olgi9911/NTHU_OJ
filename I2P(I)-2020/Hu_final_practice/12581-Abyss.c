#include <stdio.h>
#include <stdlib.h>
int out[100005], from[100005], to[100005], result[100005], count[100005];
int *route[100005];

void sol(int curr){
    result[curr] = 1; //init, but needs to minus 1 as correction
    for(int i = 0; i < out[curr]; i++){
        sol(route[curr][i]); //to next node by the unique path
        result[curr] += result[route[curr][i]];
    }
}

int main(){
    int N; scanf("%d", &N);
    for(int i = 0; i < N - 1; i++){
        scanf("%d %d", &from[i], &to[i]);
        out[from[i]] ++; //num of path from ith node
    }
    for(int i = 1; i <= N; i++)
        route[i] = (int*)malloc(out[i] * sizeof(int)); //malloc route 2d-array
    
    for(int i = 0; i < N - 1; i++){
        route[from[i]][count[from[i]]] = to[i]; //assigning path
        count[from[i]] ++; //num of path from "from[i]" node
    }
    sol(1); //exe the recursive function
    for(int i = 1; i <= N; i++){
        if(i == N) printf("%d\n", result[i] - 1);
        else printf("%d ", result[i] - 1);
    }
}