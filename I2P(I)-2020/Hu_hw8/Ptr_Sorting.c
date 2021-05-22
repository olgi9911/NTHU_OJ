#include <stdio.h>
#include <stdlib.h>
#include <math.h>
void bubblesort(int* arr, int len){
    int temp;
    for(int i = 0; i < len - 1; i++){
        for(int j = 0; j < len - 1 - i; j++){
            if(arr[j] > arr[j + 1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int** s(int* ptr, int len){
    bubblesort(ptr, len);
    len = sqrt(len);
    int **arr2d = (int**)malloc(len*sizeof(int*));
    for(int i = 0; i < len; i++){
        arr2d[i] = ptr + i * len;
    }
    return arr2d;
}

int main() {
	int len;
	int **ans;
	
	scanf("%d", &len);
	
	int *a = (int*)malloc(len * sizeof(int));

	for (int i = 0;i < len;i++) {
		scanf("%d", &a[i]);
	}

	ans = s(a,len);

	for (int i = 0;i < (int)sqrt(len);i++) {
		for (int j = 0;j < (int)sqrt(len);j++) {
			printf("%d", ans[i][j]);
		}
		printf("\n");
	}
	
	free(a);
	return 0;
}