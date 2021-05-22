#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int data;
    struct _Node *left;
    struct _Node *right;
}Node;

int tree_height = 0;
int sum_at_level[10000] = {}, num_of_nodes_at_level[10000] = {};

void add_node(Node **root, int data, int level){
    if((*root) == NULL){
        if(tree_height < level) tree_height = level;
        sum_at_level[level] += data;
        num_of_nodes_at_level[level] ++;
        (*root) = (Node*)calloc(1, sizeof(Node));
        (*root) -> data = data;
        return;
    }
    else{
        if(data > (*root) -> data)
            add_node(&(*root) -> right, data, level + 1);
        else if(data < (*root) -> data)
            add_node(&(*root) -> left, data, level + 1);
        //no (data == (*root) -> data) condition, as same value needs to be ignored
    }
}

void print_inorder(Node *root){
    if(root == NULL) return;
    print_inorder(root -> left);
    printf("%d ", root -> data);
    print_inorder(root -> right);
}

void print_sum_of_level(int level){
    if(level == 0 || level > tree_height) printf("0");
    else printf("%d", sum_at_level[level]);
}

void print_avg_of_level(int level){
    if(level == 0 || level > tree_height) printf("0");
    else printf("%.3f", (float)sum_at_level[level] / num_of_nodes_at_level[level]);
}

int main(){
    int N, M, input;
    char command[10];
    scanf("%d", &N);
    Node *root = NULL;
    while(N--){
        scanf("%d", &input);
        add_node(&root, input, 1);
    }
    scanf("%d", &M);
    while(M--){
        scanf("%s", command);
        if(command[0] == 'P'){ //Print in-order
            if(root) print_inorder(root);
            else printf("NULL");
        }
        else if(command[0] == 'G'){ //GetMax
            printf("%d", tree_height);
        }
        else if(command[0] == 'S'){ //SumLevel
            scanf("%d", &input);
            print_sum_of_level(input);
        }
        else if(command[0] == 'A'){ //AverLevel
            scanf("%d", &input);
            print_avg_of_level(input);
        }
        printf("\n");
    }
    return 0;
}