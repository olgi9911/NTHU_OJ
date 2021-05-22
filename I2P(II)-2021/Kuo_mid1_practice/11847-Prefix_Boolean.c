#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    char c;
    struct _Node *left, *right;
}Node;

Node *createNode(char c){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node -> c = c;
    return node;
}

char expr[35];
int pos = 0;

Node *build(){ //build the tree from prefix expr
    Node *root = createNode(expr[pos]);
    if(expr[pos] == '&' || expr[pos] == '|'){
        pos++;
        root -> left = build();
        pos++;
        root -> right = build();
    }
    return root; //skipped to here if expr[pos] == A, B, C or D
}

int solve(Node *root, int value){
    if(root -> c == '&')
        return solve(root -> left, value) && solve(root -> right, value);
    else if(root -> c == '|')
        return solve(root -> left, value) || solve(root -> right, value);
    else
        return (value >> (3 - (root -> c - 'A'))) & 1; //a: (b >> 3) to d: (b >> 0)
}

int main(){
    scanf("%s", expr);
    Node *head = build();
    //treated ABCD as a 4-bit binary representation. e.g. 0101 = 5
    for(int i = 0; i < 16; i++){
        for(int j = 3; j >= 0; j--)
            printf("%d ", (i >> j) & 1);
        printf("%d\n", solve(head, i));
    }
}