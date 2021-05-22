#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    long long data;
    struct _Node *right, *left;
}Node;

Node *createNode(long long data){
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode -> data = data;
    newnode -> left = newnode -> right = NULL;
    return newnode;
}

int cmp(const void *a, const void *b){
    long long _a = *(long long *)a;
    long long _b = *(long long *)b;
    if(_a < _b) return -1;
    if(_a > _b) return 1;
    return 0;
}

int main(){
    long long arr[100005];
    int Q, type2cnt = 0, type;
    int N; scanf("%d", &N);
    for(int i = 1; i <= N; i++)
        scanf("%lld", &arr[i]);
    qsort(arr+1, N, sizeof(long long), cmp);

    Node *head = createNode(-1), *temp, *mid;
    temp = head;

    for(int i = 1; i <= N; i++){
        temp -> right = createNode(arr[i]);
        temp -> right -> left = temp;
        temp = temp -> right;
        if(i == (N + 1) / 2)
            mid = temp;
    }

    scanf("%d", &Q);
    while(Q--){
        scanf("%d", &type);
        if(type == 1){
            mid = mid -> left;
            mid -> right = mid -> right -> right;
            mid -> right -> left = mid;
            N--;
            if(N % 2 == 1)
                mid = mid -> right;
        }
        else{
            int k; scanf("%d", &k);
            long long output = 0;

            if(type2cnt < 60){
                temp = head -> right;
                for(int j = 1; j <= N; j++){
                    if(j == k)
                        output = temp -> data;
                    temp -> data /= 2ll;
                    temp = temp -> right;
                }
            }
            printf("%lld\n", output);
            type2cnt ++;
        }
    }
    return 0;
}