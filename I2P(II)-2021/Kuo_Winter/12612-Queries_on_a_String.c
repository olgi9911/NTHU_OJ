#include <stdio.h>
#include <string.h>

int main(){
    char s[10005];
    char newS[10005];
    int m, l, r, k, length;
    scanf("%s", s);
    scanf("%d", &m);
    while(m--){
        scanf("%d %d %d", &l, &r, &k);
        l--, r--; //number to index
        length = r - l + 1;
        strncpy(newS, s + l, length);
        for(int i = 0; i < length; i++){
            s[l + (i + k) % length] = newS[i];
        }
    }
    
    printf("%s\n", s);
    return 0;
}