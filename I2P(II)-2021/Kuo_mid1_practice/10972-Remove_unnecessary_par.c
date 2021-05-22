#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAXEXPR 256

char expr[MAXEXPR];  // string to store the input expression.
int pos; 

typedef struct _Node {
    char data;
    struct _Node *left, *right;
} Node;

Node* EXPR();
Node* FACTOR();
Node* makeNode(char c){
    Node *tmp = (Node*)calloc(1, sizeof(Node));
    tmp -> data = c;
    return tmp;
}

Node* EXPR(){
    Node *root, *right;
    right = FACTOR();
    if(pos >= 0){
        if(expr[pos] == '&' || expr[pos] == '|'){
            root = makeNode(expr[pos]);
            root -> right = right;
            pos--;
            root -> left = EXPR();
        }
        else root = right;
    }
    else root = right;

    return root;
}

Node* FACTOR(){
    Node *root = NULL;
    if(pos >= 0){
        if(expr[pos] == ')'){
            pos--;
            root = EXPR();
        }
        else root = makeNode(expr[pos]);
        pos--;
    }
    return root;
}

void showTree(Node *root){
    int necessary = 0;
    if(root == NULL) return;
    //parenthesis necessary case: (A & B) or (A | B) is a right subtree
    if(root -> right != NULL && (root -> right -> data == '&' || root -> right -> data == '|')) necessary = 1;
    showTree(root -> left);
    printf("%c", root -> data);
    if(necessary) printf("(");
    showTree(root -> right);
    if(necessary) printf(")");
}

void freeTree(Node *root){
    if (root != NULL){
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(){
    scanf("%s", expr);
    pos = strlen(expr) - 1;
    Node *root = EXPR();
    showTree(root);
    freeTree(root);
    return 0;
}