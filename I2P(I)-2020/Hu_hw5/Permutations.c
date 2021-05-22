#include<stdio.h>

int num[7];

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void permute(int l, int r){
    if(l == r){
        for(int i = 1; i <= r; i++) printf("%d ", num[i]);
        printf("\n");
        return;
    }

    for(int i = l; i <= r; i++){
        swap(&num[l], &num[i]);
        for(int j = i; j > l + 1; j--) swap(&num[j], &num[j - 1]);
        permute(l + 1, r);
        for(int j = l + 1; j < i; j++) swap(&num[j], &num[j + 1]);
        swap(&num[l], &num[i]);
    }
}

int main(){
    int n = 0;
    scanf("%d", &n);
    for(int i = 0; i <= n; i++) num[i] = i;
    permute(1, n);
}