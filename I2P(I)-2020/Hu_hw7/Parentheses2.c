#include <stdio.h>
char arr[105];
int n = 0;
int findEnd(int start){
    int count = 0;
    for(int i = start; i <= n; i++){
        if(arr[i] == '(') 
            count ++;
        else if(arr[i] == ')')
            count --;
        
        if(count == 0)
            return i;
    }
    return n - 1;
}

long long compute(int start){
    long long sum = 0;
    if(arr[start] == '(' && arr[start+1] == ')')
        return 1;
    
    for(int i = start + 1; i < findEnd(start); i++){
        sum += compute(i);
        i = findEnd(i);
    }
    return sum * 2;
}

int main(){
    scanf("%d%s", &n, arr);
    arr[0] = '('; arr[n - 1] = ')';
    printf("%lld\n", compute(0));
    return 0;
}