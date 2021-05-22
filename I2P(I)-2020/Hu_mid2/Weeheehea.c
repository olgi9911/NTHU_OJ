#include <stdio.h>
#include <math.h>

int main(){
    char str[11];
    int sum[4096][10] = {};
    int ans = 0, xPos = 0;
    int N = 0; scanf("%d", &N);
    while(N--){
        int num = 0;
        scanf("%s", str);
        for(int i = 0; i < 10; i++){
            if(str[i] == 'x') xPos = i;
            if(str[i] == '1')
                num += pow(2, i);
        }
        sum[num][xPos] ++;
    }
    for(int i = 0; i < 4096; i++){
        for(int j = 0; j < 10; j++)
            if(sum[i][j]) ans ++;
    }
        
    printf("%d\n", ans);
}