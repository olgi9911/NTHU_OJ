#include <stdio.h>
#include <string.h>

int placeNum(char *ans, int curr, int val){
    static char temp[10];
    int digit = 0;
    while(val > 0){
        temp[digit++] = (char)(val % 10 + '0');
        val /= 10;
    }
    for(int i = digit - 1; i >= 0; i--) 
        ans[curr++] = temp[i];
    return curr;
}

int main(){
    char s[1005], ans[1005*4];
    scanf("%s", s);
    char previous = s[0];
    int len = strlen(s), curr = 0, count = 0;

    for(int i = 0; i <= len; i++){
        char c = s[i];
        if(c == previous) count++;
        else{
            if('0' <= previous && previous <= '9'){
                if(count > 1)
                    curr = placeNum(ans, curr, count);
                
                ans[curr++] = '\'';
                ans[curr++] = previous;
                ans[curr++] = '\'';
            }
            else{
                if(count < 3){
                    while(count--) ans[curr++] = previous;
                }
                else{
                    curr = placeNum(ans, curr, count);
                    ans[curr++] = previous;
                }
            }
            previous = c, count = 1;
        }
    }

    ans[curr] = '\0';
    printf("%s\n", ans);

    float rate = (double) curr / len;
    if(rate < 1.0) printf("Compress rate: %.3f\n", rate);
    else printf("The string can't zip\n");

    return 0;
}