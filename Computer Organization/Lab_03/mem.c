
#include <stdio.h>
#include <stdlib.h>
//#include <malloc.h> program doesn't run with this included, stdlb.h covers malloc

 int main() {
	int num;
	int *ptr;
	int **handle;

	num = 14;
	ptr = (int *)malloc(2 * sizeof(int));
	*ptr = num;
	handle = (int **)malloc(1 * sizeof(int *));
	*handle = ptr;

	// Insert code here
	printf("Adress of num: %p\n", &num);
	printf("Value of num: %d\n", num);
	printf("Adress of ptr: %p\n", ptr);
	printf("Value of ptr: %d\n", *ptr);
	printf("Adress of handle: %p\n", handle);
	printf("Value of handle: %p\n", *handle);



	return 0;
} 

