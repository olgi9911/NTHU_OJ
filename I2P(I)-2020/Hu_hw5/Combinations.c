#include <stdio.h>
int output[22];
int arr[22];
void Combine(int start, int end, int index, int m){
    if(index == m){
        for(int i = 0; i < m; i++) 
            i == (m - 1) ? printf("%d\n", output[i]) : 
            printf("%d ", output[i]);
        return;
    }
    for(int j = start; j <= end; j++){
        output[index] = arr[j];
        Combine(j + 1, end, index + 1, m);
    }
}

int main(){
    int n = 0, m = 0; scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &arr[i]);
    Combine(0, n - 1, 0, m);
    return 0;
}