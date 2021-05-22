#include<stdio.h>
#ifndef NODE
#define NODE
#include<stddef.h>
#include <stdlib.h>

typedef struct node
{
	struct node *next;
	struct node *prev;
	unsigned short val;
} Node;

void do_I(Node **head,size_t pos,unsigned short val){
    Node *insert = (Node*)calloc(1, sizeof(Node)), *curr = *head;
    insert -> val = val;
    if(*head == NULL || pos == 0){ //insert in front of head
        if(*head != NULL){
            insert -> next = *head;
            (*head) -> prev = insert;
        }
        (*head) = insert;
    }else{
        while(--pos){
            if(curr -> next == NULL) break; //at the end of the list
            curr = curr -> next;
        }
        insert -> next = curr -> next;
        curr -> next = insert;
        insert -> prev = curr;
        if(insert -> next) insert -> next -> prev = insert; 
    }
}
void do_E(Node **head,size_t begin_pos,size_t end_pos){
    if(*head == NULL) return;
    Node *curr = *head, *begin = NULL, *toFree, *end;
    if(begin_pos == end_pos) end_pos++; //remove begin_pos only
    for(size_t i = 0; i < end_pos; i++){
        if(i == begin_pos) begin = curr;
        if(curr -> next == NULL){
            if(begin == NULL) return; //no need to erase
            else break; //end_pos is greater than the length of the list
        }
        if(i < (end_pos - 1)) curr = curr -> next;
    }
    if(*head == begin){
        *head = curr -> next;
        if(*head) (*head) -> prev = NULL;
    }else{
        begin -> prev -> next = curr -> next;
        if(curr -> next) curr -> next -> prev = begin -> prev;
    }
    end = curr -> next;
    while(begin != end){
        toFree = begin;
        begin = begin -> next;
        free(toFree);
    }
}
void do_P(Node  *head,size_t pos){
    Node *curr = head;
    if(head != NULL){
        while(pos--){
            if(curr -> next == NULL) break;
            curr = curr -> next;
        }
        printf("%d ", curr -> val);
    }
}
void do_R(Node **head,unsigned short val){
    Node *curr = *head, *toFree;
    while(curr){
        if(curr -> val == val){
            if(curr == (*head)){
                *head = curr -> next;
                if(*head) (*head) -> prev = NULL; 
            }
            else{
                curr -> prev -> next = curr -> next;
                if(curr -> next) curr -> next -> prev = curr -> prev; //If not at the end of list
            }
            toFree = curr;
            curr = curr -> next;
            free(toFree);
        }
        else curr = curr -> next;
    }
}
void do_S(Node  *head){
    if(head){
        while(head){
            printf("%d ", head -> val);
            head = head -> next;
        }
    }
}
#endif

int main(void)
{
	Node *head=NULL;
	size_t N;
	scanf("%zu",&N);
	while(N--)
	{
		char op;
		unsigned short val;
		size_t pos,begin_pos,end_pos;
		scanf(" %c",&op);
		switch(op)
		{
		case 'I':
			scanf("%zu %hu",&pos,&val);
			do_I(&head,pos,val);
			break;
		case 'E':
			scanf("%zu %zu",&begin_pos,&end_pos);
			do_E(&head,begin_pos,end_pos);
			break;
		case 'P':
			scanf("%zu",&pos);
			do_P(head,pos);
			break;
		case 'R':
			scanf("%hu",&val);
			do_R(&head,val);
			break;
		case 'S':
			do_S(head);
			break;
		}
	}
            return 0;
}