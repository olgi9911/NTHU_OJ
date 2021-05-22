#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int index;
    struct _Node *next;
}Node;

Node *createNode(int index){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node -> index = index;
    return node;
}

void push(Node *node, int index){
    Node *tmp = createNode(index);
    tmp -> next = node -> next;
    node -> next = tmp;
}

void pop(Node *node, int index){
    while(node -> next -> index != index)
        node = node -> next;
    Node *toFree = node -> next;
    node -> next = node -> next -> next;
    free(toFree);
}

int main(){
    int N, v, u, deg[5005] = {};
    Node *label[5005];
    scanf("%d", &N);
    for(int i = 1; i <= N; i++){
        label[i] = createNode(i);
        label[i] -> next = label[i]; //points to itself at first
    }
    for(int i = 0; i < (N - 1); i++){
        scanf("%d %d", &v, &u);
        deg[v] ++, deg[u] ++;
        push(label[v], u);
        push(label[u], v);
    }
    for(int i = 0; i < (N - 2); i++){
        int targetIndex = 1, pruferCode;
        while(deg[targetIndex] != 1) targetIndex ++;
        pruferCode = label[targetIndex] -> next -> index; //its neighbor
        deg[targetIndex] --, deg[pruferCode] --;
        printf("%d ", pruferCode);
        pop(label[targetIndex], pruferCode);
        pop(label[pruferCode], targetIndex);
    }
    printf("\n");
}