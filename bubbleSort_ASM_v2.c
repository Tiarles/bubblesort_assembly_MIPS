#include <stdio.h>
#include <stdlib.h>

void* bubbleSort(int* array, int size){
	// # s0 = &array + i * 4
	// # s1 = size - 1
	// -------------
	// # s2 = i
	// # s3 = isChanged

	// la $s0, array

	// la $s1, size
	// lw $s1, 0($s1)
	// addi $s1, $s1, -1
	
	int i, isChanged;
	int tmp;
	
	//do:

	do{
		isChanged = 0;
		// la $s0, array
		// add $s3, $0, $0
		// add $s2, $0, $0
		// for:
		for(i = 0; i < (size - 1); i++){
			// slt $t0, $s2, $s1
			// beq $t0, $0, end_for
			// if:

			if(array[i + 1] < array[i]){
				// lw $t1, 4($s0)
				// lw $t2, 0($s0)

				// slt $t0, $t1, $t2
				// beq $t0, $0, end_if

				tmp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = tmp;
				// sw $t1, 0($s0)
				// sw $t2, 4($s0)
				isChanged = 1;
				// addi $s3, $0, 1
			}
			// end_if:
			// addi $s0, $s0, 4
			// addi $s2, $s2, 1
			// j for
		// end_for:
		}
	} while(isChanged);

	// beq $s3, $0, end_do
	// j do

	//end_do:

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