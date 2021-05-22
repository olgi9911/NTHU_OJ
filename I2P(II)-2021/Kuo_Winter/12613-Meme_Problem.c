#include <stdio.h>
#include <math.h>

int main(){
    int times;
    long long A, B;
    scanf("%d", &times);
    while(times--){
        scanf("%lld%lld", &A, &B);
        printf("%lld\n", (long long)log10(B + 1) * A);
    }
}