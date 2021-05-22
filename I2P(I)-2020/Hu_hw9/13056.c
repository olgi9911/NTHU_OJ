#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define min(a, b) (a < b ? a : b)

typedef struct {
	int num;
	char* name;
} Monkey;

Monkey* CreateMonkeyArray(int length){
	Monkey* arr = (Monkey*)calloc(length, sizeof(Monkey));
	for(int i = 0; i < length; i++) arr[i].name = (char*)calloc(51, sizeof(char));
	return arr;
}

void FreeMonkeyArray(Monkey* arr, int length){
	for(int i = 0; i < length; i++)
		free(arr[i].name);
	free(arr);
}

void SetVal(Monkey* arr, int i, int num, char *name){
	arr[i].num = num;
	strcpy(arr[i].name, name);
}

int Compare(Monkey* arr, int i, int j){
	if(arr[i].num < arr[j].num) return 1;
	else if(arr[i].num > arr[j].num) return 0;
	int length = min(strlen(arr[i].name), strlen(arr[j].name));
	for(int k = 0; k < length; k++){
		if(arr[i].name[k] < arr[j].name[k]) return 1;
		else if(arr[i].name[k] > arr[j].name[k]) return 0;
	}
	return (strlen(arr[i].name) < strlen(arr[j].name));
}

void Swap(Monkey* arr, int a, int b){
	int temp = arr[a].num;
	char *name = arr[a].name;
	arr[a].num = arr[b].num, arr[a].name = arr[b].name;
	arr[b].num = temp, arr[b].name = name;
}

//Partial Judge
int main() {
	int n; scanf("%d\n", &n);
	Monkey* arr = CreateMonkeyArray(n);
	for(int i = 0; i < n; i++) {
		int num;
		char c[51];
		scanf("%d %s", &num, c);
		SetVal(arr, i, num, c);
	}
	for(int i = 0; i < n; i++) {
		for(int j = i + 1; j < n; j++) {
			if(Compare(arr, i, j) > 0) {
				Swap(arr, i, j);
			} 
		}
	}
	for(int i = 0; i < n; i++) {
		printf("%d %s\n", arr[i].num, arr[i].name);
	}
	FreeMonkeyArray(arr, n);
}