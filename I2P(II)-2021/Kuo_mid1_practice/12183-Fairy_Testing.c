#include <stdio.h>
#include <stdlib.h>
typedef struct _Node{
    int value;
    int tokentype; //0: var, 1: '&', 2: '|'
    struct _Node *left;
    struct _Node *right;
    struct _Node *parent;
}Node;
Node *variable[100001]; //pointer to var(leaf in syntax tree)

Node *createNode(int type){
    Node *node = (Node*)calloc(1, sizeof(Node));
    node -> tokentype = type;
    return node;
}

Node *buildTree(){
    Node *root;
    char input[2];
    int id;
    scanf("%1s", input); //prevent the '\n' case
    if(input[0] == '['){ //variable case
        scanf("%d", &id);
        root = variable[id];
        getchar(); //read in ']'
    }else{
        if(input[0] == '|') root = createNode(2); // '|'
        else root = createNode(1); // '&'
        root -> left = buildTree();
        root -> left -> parent = root;
        root -> right = buildTree();
        root -> right -> parent = root;
    }
    return root;
}

void update(Node *root){
    if(root){
        if(root -> tokentype == 1)
            root -> value = root -> left -> value && root -> right -> value;
        else if(root -> tokentype == 2)
            root -> value  = root -> left -> value || root -> right -> value;
        update(root -> parent);
    }
}

void freeTree(Node *root){
    if(root){
        freeTree(root -> left);
        freeTree(root ->right);
        free(root);
    }
}

int main(){
    int T; scanf("%d", &T);
    while(T--){
        int var_num, flip_count; scanf("%d%d", &var_num, &flip_count);
        for(int i = 1; i <= var_num; i++)
            variable[i] = createNode(0);
        Node *root = buildTree();
        while(flip_count--){
            int id; scanf("%d", &id);
            variable[id] -> value = !(variable[id] -> value);
            update(variable[id] -> parent);
            printf("%d\n", root -> value);
        }
        freeTree(root);
    }
    return 0;
}