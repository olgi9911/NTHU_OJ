#include <stdio.h>
#include <stdlib.h>

int main(){
    int n, index, v[5005], u[5005], deg[5005] = {};
    scanf("%d", &n);
    for(int i = 0; i < n - 1; i++){ //read n-1 lines
        scanf("%d %d", v + i, u + i);
        deg[v[i]] ++, deg[u[i]] ++;
    }
    for(int i = 0; i < n - 2; i++){
        index = 1;
        while(index <= n){
            if(deg[index] == 1) break; //find the min. index of a leaf
            index++;
        }
        for(int j = 0, found = 0; j < n - 1 && !found; j++){
            if(v[j] == index){
                printf("%d ", u[j]); //print its neighboring vertex
                found = 1;
            }
            else if(u[j] == index){
                printf("%d ", v[j]); //print its neighboring vertex
                found = 1;
            }
            if(found){
                deg[v[j]] --, deg[u[j]] --; //degree-1 for both the removed one and its neighbor
                v[j] = u[j] = -1; //remove edge between them
            }
        }
    }
    printf("\n");
}