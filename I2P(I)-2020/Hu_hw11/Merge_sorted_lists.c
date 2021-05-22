#include<stdio.h>
#include<stdlib.h>
//
typedef struct _Node {
    int data;
    struct _Node *next;
} Node;

Node* Merge_lists(Node* a, Node* b){
    Node *start = NULL, *curr = NULL;
    int operation = 0;
    while(a != NULL || b != NULL){
        if(curr == NULL) start = curr = (Node*)calloc(1, sizeof(Node));
        else{
            while(a != NULL && a -> data == curr -> data) a = a -> next;
            while(b != NULL && b -> data == curr -> data) b = b -> next;
            if(a == NULL && b == NULL) break;
            curr = curr -> next = (Node*)calloc(1, sizeof(Node));
        }
        if(a != NULL && b != NULL){ 
            if(a -> data < b -> data) operation = 1;
            else operation = 2;
        }
        else if(a != NULL) operation = 1;
        else if(b != NULL) operation = 2;

        if(operation == 1){
            curr -> data = a -> data;
            a = a -> next;
        }
        else{
            curr -> data = b -> data;
            b = b -> next;
        }
    }
    return start;
}
//
Node* Create_Node(int val);

void Print_list(Node* head);

int main() {
    int N,M,val;
    scanf("%d %d",&N,&M);

    Node* head1 = NULL;
    Node* cur_node = NULL;
    for(int i=0; i<N; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head1==NULL){
            head1 = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    Node* head2 = NULL;
    cur_node = NULL;
    for(int i=0; i<M; i++){
        scanf("%d",&val);
        Node* new_node = Create_Node(val);
        if(head2==NULL){
            head2 = new_node;
            cur_node = new_node;
        }
        else{
            cur_node->next = new_node;
            cur_node = new_node;
        }
    }

    Node* merge_head = Merge_lists(head1, head2);
    Print_list(merge_head);

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
