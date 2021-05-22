#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
#define MAX_N 1000006
typedef struct Node
{
    int key;
    struct Node *ltree;
    struct Node *rtree;
} Node ;

// build a binary search tree with given pre-order traversal
// return pointer to root
Node *buildBST(int n, int *preOrder){
    Node *head = (Node*)calloc(1, sizeof(Node)), *curr;
    head -> key = preOrder[0];
    for(int i = 1; i < n; i++){
        int lNULL = 0, rNULL = 0;
        curr = head;
        Node *tmp = (Node*)calloc(1, sizeof(Node));
        tmp -> key = preOrder[i];
        while(!lNULL && !rNULL){
            if(preOrder[i] < curr -> key){
                if(curr -> ltree == NULL) lNULL = 1;
                if(!lNULL) curr = curr -> ltree;
            }
            else if(preOrder[i] >= curr -> key){
                if(curr -> rtree == NULL) rNULL = 1;
                if(!rNULL) curr = curr -> rtree;
            }
        }
        if(lNULL)
            curr -> ltree = tmp;
        else if(rNULL)
            curr -> rtree = tmp;
    }
    return head;
}

// print the in-order traversal of a given tree
// it is suggested to implement using recursion
void printInOrder(Node *ptr){
    if(ptr){
        printInOrder(ptr -> ltree);
        printf("%d ", ptr -> key);
        printInOrder(ptr -> rtree);
    }
}

// print the post-order traversal of a given tree
// it is suggested to implement using recursion
void printPostOrder(Node *ptr){
    if(ptr){
        printPostOrder(ptr ->ltree);
        printPostOrder(ptr -> rtree);
        printf("%d ", ptr -> key);
    }
}

// delete the binary search tree in case of memory leak
// it is suggested to implement using recursion
void freeTree(Node *ptr){
    if(ptr){
        freeTree(ptr -> ltree);
        freeTree(ptr -> rtree);
        free(ptr);
    }
}

int n;
int preOrder[MAX_N];

int main() 
{
    int T; scanf("%d", &T);
    for(int t = 0; t < T; t++)
    {
        printf("test %d : \n", t);
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d", &preOrder[i]);
        Node *root = buildBST(n, preOrder);
        printInOrder(root);
        printf("\n");
        printPostOrder(root);
        printf("\n");
        freeTree(root);
    }
}