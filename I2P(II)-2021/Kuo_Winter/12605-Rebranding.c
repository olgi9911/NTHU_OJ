#include<stdio.h>
#include<string.h>
int N, M;
int newChar[26];
char name[200005], X, Y;

int main(){
    for(int i = 0; i < 26; i++) newChar[i] = i;
    scanf("%d %d %s", &N, &M, name);
    while(M--){
        scanf("%s %s", &X, &Y);
        for(int i = 0; i < 26; i++){
            if(newChar[i] == X-'a') newChar[i] = Y-'a';
            else if(newChar[i] == Y-'a') newChar[i] = X-'a';
        }
    }
    for(int i = 0; i < N; i++) name[i] = newChar[name[i]-'a']+'a';
    printf("%s\n", name);
}