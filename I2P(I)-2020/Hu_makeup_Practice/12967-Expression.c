#include <stdio.h>
#include <string.h>

char s[10000];

long long str2int(int left, int right){
    int length = right - left + 1;
    long long ret = 0;
    for(int i  = 0; i < length; i++){
        ret *= 10;
        ret += s[left + i] - '0';
    }
    return ret;
}

int main(){
    scanf("%s", s + 1);
    int cofNum = 1, cofBracket = 1;
    long long answer = 0;
    int length = strlen(s+1);
    for(int i = 1; i <= length; i++){
        if(s[i] == ')')
            cofBracket = 1, i++;
        
        if(s[i] == '-' && s[i + 1] == '(')
            cofBracket = -1, i++;
        else if(s[i] == '+' && s[i + 1] == '(')
            cofBracket = 1, i++;
        else if(s[i] == '(')
            cofBracket = 1;
        else if(s[i] == '+')
            cofNum = 1;
        else if(s[i] == '-')
            cofNum = -1;
        else if( '0' <= s[i] && s[i] <= '9'){
            int j = i;
            while('0' <= s[j + 1] && s[j + 1] <= '9') j++;

            answer += cofNum * cofBracket * str2int(i, j);
            i = j;
        }
    }
    printf("%lld\n", answer);
}