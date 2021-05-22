#include <stdio.h>
#include <string.h>
#include <stdlib.h>
//#include "function.h"
#ifndef FUNCTION_H
#define FUNCTION_H

#define MAXEXPR 256
#define NUMSYM 6

char expr[MAXEXPR];  // string to store the input expression.
int pos;             // current position of parsing, from end to start

typedef enum {ID_A, ID_B, ID_C, ID_D, OP_AND, OP_OR} TokenSet;
char sym[NUMSYM];

typedef struct _Node {
    TokenSet data;
    struct _Node *left, *right;
} BTNode;

BTNode* EXPR();
BTNode* FACTOR();
BTNode* makeNode(char c);

BTNode* EXPR(){
    BTNode *root, *right;
    right = FACTOR(); //parse from the end
    if(pos >= 0){
        if(expr[pos] == '&' || expr[pos] == '|'){ //EXPR OP ID
            root = makeNode(expr[pos]);
            root -> right = right; //right child
            pos--;
            root -> left = EXPR(); //left recursion
        }
        else root = right; //EXPR == ID
    }
    else root = right; //EXPR == ID

    return root;
}
BTNode* FACTOR(){
    BTNode *root = NULL;
    if(pos >= 0){
        if(expr[pos] == ')'){
            pos--;
            root = EXPR(); //treating (EXPR) as a factor
        }
        else root = makeNode(expr[pos]); //factor == ID
        pos--;
    }
    return root;
}
BTNode* makeNode(char c){
    BTNode *newNode = (BTNode*)calloc(1, sizeof(BTNode));
    switch(c){
        case 'A':
            newNode -> data = ID_A;
            break;
        case 'B':
            newNode -> data = ID_B;
            break;
        case 'C':
            newNode -> data = ID_C;
            break;
        case 'D':
            newNode -> data = ID_D;
            break;
        case '&':
            newNode -> data = OP_AND;
            break;
        case '|':
            newNode -> data = OP_OR;
            break;
    }
    return newNode;
}
void freeTree(BTNode *root);
void printPrefix(BTNode *root);

#endif

int main(void){
    sym[0]='A';
    sym[1]='B';
    sym[2]='C';
    sym[3]='D';
    sym[4]='&';
    sym[5]='|';
    while (scanf("%s", expr)!=EOF)
    {
        pos = strlen(expr) - 1;
        BTNode *root = EXPR();
        printPrefix(root);
        printf("\n");
        freeTree(root);
    }

    return 0;
}

/* print a tree by pre-order. */
void printPrefix(BTNode *root){
    if (root != NULL) {
        printf("%c",sym[root->data]);
        printPrefix(root->left);
        printPrefix(root->right);
    }
}

/* clean a tree.*/
void freeTree(BTNode *root){
    if (root!=NULL) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}