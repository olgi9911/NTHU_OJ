#include <stdio.h>
#include <stdlib.h>
typedef struct{
    int i;
}small;

typedef struct {
    int i;
    struct small *direct[4];
}cell;

cell* create_cell(cell* a, int dir, int val){
    cell* new = (cell*)malloc(sizeof(cell));
    new->i = val;
    new->direct[dir] = a;
    return new;
}

int main(){
    cell* current, *portal;
    current = portal = create_cell(NULL, 0, 0);
    int q = 0; scanf("%d", &q);
    int t = 0, dir = 0, val = 0;
    while(q--){
        scanf("%d", &t);
        switch(t){
            case 1:
            scanf("%d %d", &dir, &val);
            current->direct[dir] = create_cell(current, dir, val);
            break;
            case 2:
            scanf("%d", &dir);
            current = current->direct[dir];
            break;
            case 3:
            scanf("%d", &val);
            current -> i = val;
            break;
            case 4:
            printf("%d\n", current->i);
            break;
            case 5:
            portal = current;
            break;
            case 6:
            current = portal;
            break;
        }
    }
}