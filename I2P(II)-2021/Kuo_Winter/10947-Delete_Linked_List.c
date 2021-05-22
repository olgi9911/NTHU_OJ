#include <stdio.h>
#include <stdlib.h>
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

void deleteNode(Node** nd, int data){
    Node *curr = (*nd), *toFree;
    if(data == 1){
        if((*nd) == NULL) return;

        toFree = (*nd);
        (*nd) = (*nd) -> next;
    }
    else{
        while(--data > 1 && curr -> next)
            curr = curr -> next;
        
        if(curr -> next == NULL) return;
        
        toFree = curr -> next;
        curr -> next = curr -> next -> next;
    }
    free(toFree);
}

Node* createList(){
    Node *head, *curr = NULL;
    int input = 0;
    while(input != -1){
        scanf("%d", &input);
        if(input == -1) 
            break;
        if(curr == NULL)
            head = curr = (Node*)calloc(1, sizeof(Node));
        else
            curr = curr -> next = (Node*)calloc(1, sizeof(Node));
        curr -> data = input;
    }
    return head;
}

///
void printList(Node *head){
    Node *temp;
    for(temp = head; temp!=NULL; temp=temp->next) {
        printf("%d ", temp->data);
    }
}

void freeList(Node *head){
    Node *temp;
    for(temp=head; temp!=NULL; temp=head){
        head = head->next;
        free(temp);
    }
}

int main()
{
    Node *head;
    int data;

    head = createList();

    while(1){
        scanf("%d", &data);
        if(data>-1){
            deleteNode(&head,data);
        }else break;

    }

    printList(head);
    freeList(head);
    return 0;
}