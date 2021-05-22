#include <stdio.h>
#include <stdlib.h>
///
#define SWAP(a,b) {a^=b^=a^=b;}
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;
Node* createList(int *a, int size){
    Node *start, *curr;
    start = curr = (Node*)calloc(1, sizeof(Node));
    curr -> data = a[0];
    for(int i = 1; i < size; i++){
        curr -> next = (Node*)calloc(1, sizeof(Node));
        curr = curr -> next;
        curr -> data = a[i];
    }
    return start;
}
void push_front(Node** head, int val){
    Node *curr = (Node*)calloc(1, sizeof(Node));
    curr -> data = val;
    curr -> next = *head;
    *head = curr;
}
Node* copyList(Node* head){
    Node *start = NULL, *curr = NULL;
    while(head != NULL){
        if(curr == NULL) start = curr = (Node*)calloc(1, sizeof(Node));
        else curr = curr -> next = (Node*)calloc(1, sizeof(Node));
        curr -> data = head -> data;
        head = head -> next;
    }
    return start;
}
void deleteElementByIdx(Node** head, int idx){
    Node *curr = *head, *temp;
    if(idx == 0){
        temp = *head;
        *head = (*head) -> next;
    } 
    else {
        while(idx-- > 1 && curr->next != NULL) curr = curr->next;
        if(curr->next == NULL) return;
        temp = curr->next;
        curr->next = curr->next->next;
    }
    free(temp);
}
void SwapElementByIdx(Node** head, int idx1, int idx2){
    Node *curr = *head, *t1, *t2;
    int max = (idx1 > idx2) ? idx1 : idx2;
    for(int i = 0; i <= max && curr != NULL; i++, curr = curr -> next){
        if(i == idx1) t1 = curr;
        else if(i == idx2) t2 = curr;
    }
    SWAP(t1 -> data, t2 -> data);
}
///
void traversal(Node* head);
int main(){

    int T,M,inst,i;
    int val,idx1,idx2;
    scanf("%d%d", &T,&M);
    Node* head = NULL;
    int *array = (int*)malloc(sizeof(int)*M);
    for(i=0; i<M; ++i){
        scanf("%d",&array[i]);
    }
    if(M > 0){
        head = createList(array, M);
        traversal(head);
    }
    while(T--){
        scanf("%d",&inst);
        if(inst == 0){ // insert
            scanf("%d",&val);
            push_front(&head, val);
        }else if(inst == 1){ // copy link list
            Node* otherHead = copyList(head);
            /* free original list*/
            while(head != NULL){
                Node* temp = head;
                head = head->next;
                free(temp);
            }
            head = otherHead;
        }else if(inst == 2){ // delete element
            scanf("%d",&val);
            deleteElementByIdx(&head, val);
        }else if(inst == 3){ // swap link element
            scanf("%d%d",&idx1, &idx2);
            SwapElementByIdx(&head,idx1,idx2);
        }
        traversal(head);
    }

    /* free linked list*/
    while(head != NULL){
        Node* temp = head;
        head = head->next;
        free(temp);
    }
    return 0;
}
void traversal(Node* head){
    if(head == NULL)
        return;
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }printf("\n");
}