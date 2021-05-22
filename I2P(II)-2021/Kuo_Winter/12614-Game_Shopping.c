#include <stdio.h>

int main(){
    int n, m, idxWallet, idxGame, result;
    int a[1002], c[1002];
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++)
        scanf("%d", c + i);
    for(int j = 0; j < m; j++)
        scanf("%d", a + j);
    idxGame = idxWallet = result = 0;
    while(idxWallet < m && idxGame < n){
        if(a[idxWallet] >= c[idxGame]){
            result ++;
            idxWallet++;
        }
        idxGame++;
    }
    printf("%d\n", result);
}
