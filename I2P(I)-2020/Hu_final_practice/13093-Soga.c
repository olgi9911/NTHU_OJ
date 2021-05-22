#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int data;
    struct _Node *left, *right;
}Node;

Node *createNode(int data){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = data;
    return newNode;
}

int main(){
    int N, Q, type, dir, midIdx; 
    scanf("%d", &N);
    Node *start, *curr, *middle;
    start = curr = createNode(-1); //starting block(because 0 <= Ai <= 10^9)
    for(int i = 0; i < N; i++){
        int input; scanf("%d", &input);
        curr -> right = createNode(input);
        curr -> right -> left = curr;
        curr = curr -> right;
    }
    curr -> right = createNode(10e9 + 1); //ending block
    curr = middle = start -> right;
    
    midIdx = (N % 2) ? (N / 2) + 1 : N / 2;
    while(midIdx > 1){
        middle = middle -> right;
        midIdx--;
    }

    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &type);
        if(type == 1){
            scanf("%d", &dir);
            if(dir == -1)
                curr = curr -> left;
            else if(dir == 1)
                curr = curr -> right;
        }
        else if(type == 2){
            printf("%d\n", curr -> data);
        }
        else if(type == 3){
            if(curr == middle)
                curr = curr -> right;

            middle -> left -> right = middle -> right;
            middle -> right -> left = middle -> left;

            if(N % 2)
                middle = middle -> left;
            else
                middle = middle -> right;

            N--;
        }
    }
    return 0;
}