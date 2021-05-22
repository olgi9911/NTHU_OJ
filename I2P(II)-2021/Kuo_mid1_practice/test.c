#include <stdio.h>
#include <string.h>

int main() {
    char in_string[100], sub_string[100] = {}, check_string[100] = {};
    scanf("%s", in_string);
    int length = strlen(in_string);
    for(int i = 1; i <= length; i++){
        int flag = 1;
        strncpy(sub_string, in_string, i);
        //printf("%s\n", sub_string); //for debug purpose
        int sub_str_len = strlen(sub_string);
        for(int j = 0; j <= length - sub_str_len; j += sub_str_len){
            strncpy(check_string, in_string + j, sub_str_len); //e.g. catdog, sub_str_len = 2, check_string = 'ca', 'td', 'og'
            if(length % sub_str_len != 0)
                flag = 0;
            else if(strcmp(check_string, sub_string) != 0) //strcmp returns 0 if two strings are the same
                flag = 0;
        }
        if(flag == 1){
            printf("%s\n%d\n", sub_string, sub_str_len);
            break; //find the sub_string with shortest length
        }
    }
    return 0;
}