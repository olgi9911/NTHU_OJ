#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct treeNode {
    char data;
    struct treeNode *left;
    struct treeNode *right;
} Node;

char s1[100] , s2[100];
int idx;

void constructTree(Node** head){ //root -> right -> left
    if((*head)==NULL)
    {
        (*head) = (Node *)calloc(1, sizeof(Node));
		(*head)->data = s2[idx];
        idx++;
        if((*head)->data=='&' || (*head)->data=='|')
            constructTree( &(*head)->right);
        if((*head)->data=='&' || (*head)->data=='|')
            constructTree( &(*head)->left);
        
    }
}

void printInfix(Node *root);
void freeTree(Node *root);

void printInfix(Node *root){
    if (root != NULL) {
        printInfix(root->left);

        printf("%c", root->data);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf("(");

        printInfix(root->right);

        if((root->data == '|' || root->data == '&') && (root->right->left != NULL && root->right->right != NULL))
            printf(")");
    }
}


void freeTree(Node *root)
{
    if (root!=NULL)
    {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}

int main(void)
{
    int n;
    int i , j ;
    scanf("%d", &n);// the number of test cases

    while(n>0)
    {
        scanf("%s" ,s1) ;
        idx = 0 ;
        for(i = 0 ; i < strlen(s1) ; i++){
            s2[i] = s1[strlen(s1)-1-i] ;
        }
        Node *root=NULL;
        constructTree(&root);// you have to implement this function
        printInfix(root);//output function
        printf("\n");
        freeTree(root);
        n--;


    }

    return 0;
}