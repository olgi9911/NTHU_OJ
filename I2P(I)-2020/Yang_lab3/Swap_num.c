#include <stdio.h>

int main(){

    int k = 0;
    int a[5];
    for(int i = 0; i < 5; i++){
        a[i] = i;
    }
    scanf("%d", &k);
    for(int j = 0; j < k; j++){
        int x = 0, y = 0, temp = 0;
        scanf("%d %d", &x, &y);
        temp = a[x];
        a[x]  = a[y];
        a[y] = temp;
    }
    printf("%d", a[0]);
    for(int i = 1; i < 5; i++){
        printf(" %d", a[i]);
    }

    return 0;
}