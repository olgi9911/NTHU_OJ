#include<stdio.h>
#include<string.h>

int main(){
    int i = 1, False = 0, targetTrue = 1;
    char target[1000003] = {}, temp[1000003] = {}, input[4];
    fgets(target+1, 500003, stdin);
    while(fgets(input, 4, stdin) != NULL){
        if(input[0] == '\\'){
            if(target[i-1] != temp[i-1]){
                False --;
                temp[i-1] = 0;
            }
            if(i == 1) i = 1;
            else i--;
        }
        else{
            temp[i] = input[0];
            if(target[i] != temp[i]) False ++;
            i++;
        }
        if(False) printf("0\n");
        else printf("1\n");
    }
    for(int t = 1; target[t] != '\n'; t++){
        if(target[t] != temp[t]){
            targetTrue = 0;
        }
    }
    if(targetTrue && (!False)) puts("Correct");
    else puts("Incorrect");
}