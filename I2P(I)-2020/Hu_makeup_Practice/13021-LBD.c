#include <stdio.h>
#include <stdlib.h>
unsigned long long N;
int solve(unsigned long long N){
    int first = 1, current = 0, previous = 0, ans = -1, d;
    while(N){
        if(N & 1){
            d = current - previous - 1;
            if(first){
                d = -1;
                first = 0;
            }
            ans = ans > d ? ans : d;
            previous = current;
        }
        current ++;
        N >>= 1;
    }
    return ans;
}

int main(){
    int q; scanf("%d", &q);
    while(q--){
        scanf("%lld", &N);
        printf("%d\n", solve(N));
    }
}