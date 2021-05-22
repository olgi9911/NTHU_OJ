#include <stdio.h>
#include <stdlib.h>

int main(){
    int *a[2002];
    int people[2002], max[2002], selected[2002];
    long long sum[2002];
    int T; scanf("%d", &T);
    while(T--){
        int N; scanf("%d", &N);
        for(int i = 0; i < N; i++){
            max[i] = selected[i] = sum[i] = 0;
            scanf("%d", &people[i]);
            a[i] = (int*)malloc(people[i] * sizeof(int));
            for(int j = 0; j < people[i]; j++){
                scanf("%d", &a[i][j]);
                sum[i] += a[i][j];
                max[i] = (a[i][j] > max[i] ? a[i][j] : max[i]);
            }
        }
        
        for(int i = 0; i < N; i++){
            int index = -1;
            for(int j = 0; j < N; j++){
                if(selected[j] == 1) continue;
                if(index == -1) index = j;
                else if(sum[j] >sum[index]) index = j;
                else if(sum[j] == sum[index] && max[j] > max[index]) index = j;
                else if(sum[j] == sum[index] && max[j] == max[index] && people[j] > people[index]) index = j;
            }
            selected[index] = 1;
            for(int j = 0; j < people[index]; j++){
                (j == people[index] - 1 ? 
                printf("%d", a[index][j]) : printf("%d ", a[index][j]));
            }
            printf("\n");
        }
        for(int i = 0; i < N; i++) free(a[i]);
    }
    return 0;
}