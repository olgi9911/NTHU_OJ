#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, prev, curr, temp;
    char symbol[200005];
    int time = 0x7FFFFFFF; //int_max, 2147483647
    scanf("%d", &n);
    scanf("%s", symbol);
    for(int i = 0; i < n; i++){
        prev = curr;
        scanf("%d", &curr);
        if(i == 0) continue;
        temp = (curr - prev) / 2;
        if(temp < time && symbol[i - 1] == 'R' && symbol[i] == 'L')
            time = temp;
    }

    if(time < 0x7FFFFFFF)
        printf("%d\n", time);
    else
        printf("-1\n");
    
    return 0;
}