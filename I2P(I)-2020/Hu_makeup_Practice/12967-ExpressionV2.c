#include <stdio.h>
#include <string.h>

int main(){
    char s[1005];
    scanf("%s", s);

    int len = strlen(s), reverse = 0, numIdx = 0;
    long long ans = 0, coef = 1;
    for(int i = 0; i < len; i++){
        if(s[i] == '('){
            if(i > 0 && s[i - 1] == '-') reverse = 1;
            else reverse = 0;
        }
        else if(s[i] == ')') reverse = 0;
        else if(s[i] == '+' && reverse == 1) s[i] = '-';
        else if(s[i] == '-' && reverse == 1) s[i] = '+';
    }

    for(int i = 0; i < len; i++){
        if(s[i] != '(' && s[i] != ')')
            s[numIdx++] = s[i];
    }
    len = numIdx;

    for(int i = 0; i < len; i++){
        if(s[i] == '+') coef = 1;
        else if(s[i] == '-') coef = -1;
        else{
            int num = 0;
            for(; i< len && '0' <= s[i] && s[i] <= '9'; i++)
                num = num * 10 + s[i] - '0';
            
            ans = ans + coef * num;
            i--;
        }
    }

    printf("%lld\n", ans);
}