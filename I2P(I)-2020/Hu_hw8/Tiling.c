#include <stdio.h>

int tile(int max){
    if(max == 0) return 1;
    int sum = 0;
    sum += tile(max - 1) * 3;
    for(int i = 2; i <= max; i++){
        sum += tile(max - i) * 2;
    }
    return sum;
}

int main(){
    int n = 0; scanf("%d", &n);
    printf("%d\n", tile(n / 2));
}