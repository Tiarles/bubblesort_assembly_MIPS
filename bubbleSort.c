#include <stdio.h>
#include <stdlib.h>

void* bubbleSort(int* array, int size){
	int i, isChanged;
	int tmp;
	
	do{
		isChanged = 0;
		for(i = 0; i < (size - 1); i++){
			if(array[i + 1] < array[i]){
				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				isChanged = 1;
			}
		}
	} while(isChanged);

	return;
}

int main(){

	int i, array[] = {3, 4, 1, 2, 5, 7, 0, 9, 8, 6}, size = 10;

	bubbleSort(array, size);
	
	for(i = 0; i < size; i++){
		printf("array[%d] = %d\n", i, array[i]);
	}

	return 0;
}