#include <stdio.h>
#include <stdlib.h>
#ifndef FUNCTION_H
#define FUNCTION_H
typedef struct _Node{
    struct _Node *prev;
    struct _Node *next;
    int val;
    int tag;
}Node;

int n, k, q;
Node *head, *end = NULL, *mid = NULL;

int nodeCount, tanoshiCount, median;

Node *createNode(int val){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node -> val = val;
    node -> tag = tanoshiCount; //counter for the operation before node been created
    return node;
}

void push(int x){
    Node *node = createNode(x);
    if(nodeCount == 0){ //the first node
        end = NULL;
        head = end = node;
    }
    else{
        node -> prev = end;
        end -> next = node;
        end = end -> next;
    }
    nodeCount ++;
}

void pop(){
    if(nodeCount == 0) return;
    int newMedian = (nodeCount + 1) / 2; //according to the description
    if(mid == NULL){ //first time doing pop
        mid = head;
        for(int i = 1; i < newMedian; i++)
            mid = mid -> next;
    }else{
        for(int i = median; i < newMedian; i++)
            mid = mid -> next;
    }
    median = newMedian;
    Node *curr  = mid;
    if(nodeCount % 2){ //nodeCount becomes even after pop, so median--
        mid = mid -> prev; //the mid item that the pointer points to after pop
        median --;
    }else{ //nodeCount becomes odd, median remains the same
        mid = mid -> next;
    }
    if(curr -> prev != NULL) curr -> prev -> next = curr -> next; //condition not met if nodeCount < 3
    if(curr -> next != NULL) curr -> next -> prev = curr -> prev; //not met if nodeCount < 2
    free(curr);
    nodeCount --;
}

void programming_tanoshi(){
    tanoshiCount ++; //counter for new nodes after this operation are greater than nodes that exist before the operation
}

void KuoYangTeTe(){
    Node *tmp = head;
    while(tmp){
        if(tmp -> tag < tanoshiCount) //only assign if the node exists before the last tanoshi operation
            (tmp -> val) %= k; //only need to perform once despite multiple op calls
        tmp = tmp -> next;
    }
}
#endif

void PrintList();

int main() {
	scanf("%d %d %d", &n, &k, &q);
	for (int i = 1; i <= n; ++ i) {
		int x;
		scanf("%d", &x);
		push(x);
	}
	while (q--) {
		char op[20];
		scanf("%s", op);
		if (op[1] == 'u') {
			int x;
			scanf("%d", &x);
			push(x);
		}
		else if (op[1] == 'o') {
			pop();
		}
		else {
			scanf(" %s", op);
			programming_tanoshi();
		}
	}
	KuoYangTeTe();
	PrintList();
}

void PrintList() {
	Node* res = head;
	while (res) {
		printf("%d ", res->val);
		res = res->next;
	}
	puts("");
}