#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
typedef struct _Node{ 
    int number;
    struct _Node* next;
    struct _Node* prev;
}Node;

Node* head;
//partial judge
Node *createNode(int input){
    Node *temp = (Node*)calloc(1, sizeof(Node));
    temp -> number = input;
    return temp;
}

Node* createList(int n){
    Node *start, *curr, *temp;
    start = curr = createNode(1);
    for(int i = 2; i <= n; i++){
        temp = createNode(i);
        curr -> next = temp;
        temp -> prev = curr; //doubly
        curr = temp;
    }
    curr -> next = start; //circular
    start -> prev = curr; //
    return start;
}

void solveJosephus(int n, int m){
    int lucky, isOdd;
    Node *curr = head, *temp;
    for(int i = 0; i < m; i++){
        scanf("%d", &lucky);
        isOdd = lucky % 2 ? 1 : 0;
        lucky = lucky % (n - i) ? lucky % (n - i) : n - i; //prevent TLE
        
        if(i != 0){ //After someone leaves the circle
            if(isOdd) curr = curr -> next; //count from the next person
            else curr = curr -> prev; //count from the previous person
        }
        if(isOdd){ //odd
            while(--lucky)
                curr = curr -> next;
        }else{ //even
            while(--lucky)
                curr = curr -> prev;
        }
        temp = curr;
        printf("%d\n", temp -> number);
        temp -> prev -> next = temp -> next;
        temp -> next -> prev = temp -> prev;
        free(temp);
    }
}
//13129.c
int main(){
    int n, k;

    while(scanf("%d%d", &n, &k)!=EOF){
        head = createList(n);
        solveJosephus(n, k);
    }

    return 0;
}