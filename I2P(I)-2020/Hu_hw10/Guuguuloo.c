#include <stdio.h>
#include <stdlib.h>
int cmp(const void* a, const void* b){
    int* _a = (int*)a;
    int* _b = (int*)b;
    return *_a - *_b;
}

typedef struct node{
    int data;
    struct node * next;
}node;

node* create_node(int data){
    node* n = (node*)malloc(sizeof(node));
    n -> data = data;
    n -> next = NULL;
    return n;
}

int main(){
    int N, Q, arr[100010] = {0};
    scanf("%d", &N);
    for(int i = 0; i < N; i++) scanf("%d", &arr[i]);
    qsort(arr, N, sizeof(int), cmp);
    node *px, *py, *curr, *end, *temp;
    px = py = curr = create_node(0);
    for(int i = 0; i < N; i++){
        curr -> next = create_node(arr[i]);
        curr = curr -> next;
    }
    end = curr -> next = create_node(0);
    scanf("%d", &Q);
    while(Q--){
        int type, x;
        scanf("%d %d", &type, &x);
        if(type == 1){
            while(px -> next != end && px -> next -> data < x)
                px = px -> next;
            if(px -> next -> data == x){
                temp = px -> next;
                px -> next = px -> next -> next;
                free(temp);
            }
        }
        else{
            while(py -> next != end && py -> next -> data < x)
                py = py -> next;
            if(py -> next -> data == x) printf("Yes\n");
            else printf("No\n");
        }
    }
}