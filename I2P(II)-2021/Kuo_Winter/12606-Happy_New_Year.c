#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a, const void *b){
    int A = *(int*)a, B = *(int*)b;
    if(A > B) return 1;
    else if(A < B) return -1;
    return 0;
}

int main(){
    int N, x[200005], result;
    scanf("%d", &N);
    for(int i = 0; i <= N; i++)
        scanf("%d", x + i);
    qsort(x + 1, N, sizeof(int), cmp); //x_0 is the starting position
    if(x[0] <= x[1]) //x_0 at the left of the street
        result = 2 * (x[N] - x[0]);
    else if(x[0] >= x[N]) //x_0 at the right
        result = 2 * (x[0] - x[1]);
    else //x_0 in the middle
        result = 2 * (x[N] - x[1]);

    printf("%d\n", result);
}