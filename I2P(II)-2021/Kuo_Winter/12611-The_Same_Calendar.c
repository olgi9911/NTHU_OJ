#include <stdio.h>
int isLeap(int num){
    if(num % 400 == 0 || (num % 4 == 0 && num % 100)) return 1;
    return 0;
}

int main(){
    int T, year, nextYear, days;
    scanf("%d", &T);
    while(T--){
        scanf("%d", &year);
        nextYear = year;
        days = 0;
        do{
            days += (isLeap(nextYear) + 1);
            nextYear ++;
        }while(days % 7 || isLeap(nextYear) != isLeap(year));

        printf("%d\n", nextYear);
    }
}