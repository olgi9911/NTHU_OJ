#include<stdio.h>
#include<stdlib.h>

typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Partial_sort(Node* head, int x){
    Node *curr, *realCurr, *realHead, *previous, *temp;
    realCurr = realHead = previous = (Node*)calloc(1, sizeof(Node));
    curr = realCurr -> next = head;
    while(curr != NULL){
        if(curr -> data < x){
            temp = curr;
            curr = curr -> next;
            previous -> next = curr;
            temp -> next = realCurr -> next;

            if(realCurr -> next == curr) //If the first element 
                previous = temp;

            realCurr -> next = temp;
            realCurr = realCurr -> next;
        }
        else{
            previous = curr;
            curr = curr -> next;
        }
    }
    realCurr = realHead -> next;
    return realCurr;
}

Node* Split_and_Swap(Node* head, int a, int b){
    Node *curr, *left, *right, *end, *realHead;
    curr = end = head;
    for(int i = 0; curr -> next != NULL; i++){
        if(i == a && i == (b - 1)){
            realHead = curr -> next;
            curr -> next = NULL;
            curr = realHead;
        }
        else if(i == a){
            left = curr -> next;
            curr -> next = NULL; //becomes the ending node, so ->next =NULL
            curr = left;
        }
        else if(i == (b - 1)){
            realHead = curr -> next;
            right = curr;
            curr = curr -> next;
        }
        else
            curr = curr -> next;

        end = curr;
    }

    if(a + 1 == b)
        end -> next = head;
    else{
        end -> next = left;
        right -> next = head;
    }

    return realHead;
}
///
Node* Create_Node(int val);

void Print_list(Node* head);

int main() {
    int N,target,split_start,split_end,val;
    scanf("%d %d %d %d",&N,&target,&split_start,&split_end);

    Node* head = NULL;
    Node* cur_node = NULL;
    for(int i=0; i<N; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head==NULL){
            head = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    head = Partial_sort(head, target);
    head = Split_and_Swap(head, split_start, split_end);
    Print_list(head);

	return 0;
}

Node* Create_Node(int val)
{
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = val;
    node->next = NULL;
    return node;
}

void Print_list(Node* head)
{
    Node *temp = head;
	while(temp!=NULL){
        if(temp->next==NULL) printf("%d\n", temp->data);
		else printf("%d ", temp->data);
		temp = temp->next;
	}
}
