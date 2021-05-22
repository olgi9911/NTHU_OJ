#include <stdio.h>
#include <stdlib.h>
#pragma warning( disable : 4996 )

int** malloc_ptr(int array_size){
    return (int**)malloc(array_size*sizeof(int*));
}

void malloc_array(int **array, int array_size){
    *array = (int*)malloc(array_size*sizeof(int));
}

void pointer_ptr_to_array(int *array, int **ptr,int N){
    for(int i = 0; i < N; i++){
        *(ptr + i) = array + ((1 + i)*i)/2;
    }
}

int main() {
	int *array;
	int **ptr;
	int N;
	int offset;
	scanf("%d %d",&N, &offset);

	malloc_array(&array, (1+N)*N/2);
	ptr = malloc_ptr(N);

	int i;
	for(i = 0; i < (1+N)*N/2; i++){
		array[i] = i;
	}
	pointer_ptr_to_array(array,ptr,N);
	for(i = 0; i < N; i++){
		printf("%d\n",*(ptr[i])+offset);
	}
	free(ptr);
	free(array);
	return 0;
}