#include <stdio.h>
#include <stdlib.h>
//#include "function.h"
typedef struct _Tree_Node{
    int number;
    struct _Tree_Node* parent;
    struct _Tree_Node* left;
    struct _Tree_Node* right;
}Tree_Node;

Tree_Node* tree_head;
//Partial Judge
Tree_Node *create_node(int n){
    Tree_Node *temp = (Tree_Node*)calloc(1, sizeof(Tree_Node));
    temp -> number = n;
    return temp;
}

void add_node(int n){
    int leftNULL = 0, rightNULL = 0;
    if(tree_head == NULL){ //Tree is empty
        tree_head = create_node(n);
        return;
    }
    Tree_Node *curr = tree_head, *tmp = create_node(n);
    while(!leftNULL && !rightNULL){
        if(n < curr -> number){ //compare with the leftchild
            if(curr -> left == NULL) //no node to compare
                leftNULL = 1;

            if(!leftNULL) curr = curr -> left;
        }
        else if(n >= curr -> number){ //rightchild
            if(curr -> right == NULL)
                rightNULL = 1;

            if(!rightNULL) curr = curr -> right;
        }
    }
    if(leftNULL)
        curr -> left = tmp, tmp -> parent = curr;
    else if(rightNULL)
        curr -> right = tmp, tmp -> parent = tmp;
}

void show_tree(Tree_Node *treenow){ //inOrder traversal
    if(treenow != NULL){ 
        show_tree(treenow -> left); //left
        printf("%d ", treenow -> number); //root
        show_tree(treenow -> right); //right
    }
}
///Partial Judge end
int main(){
    int n, a;
    scanf("%d", &n);
    while(n--){
        scanf("%d", &a);
        add_node(a);
    } 
    show_tree(tree_head);
}