#include <stdio.h>
#include <stdlib.h>

int global = 42;
int uninitialized;

int main() {
	int local_stack_var = 10;
	int *heap_var = (int *)malloc(sizeof(int));
	if (heap_var == NULL) {
        	printf("Memory allocation failed!\n");
        	return 1;
	}
	printf("Data Segment (Global Initialized)   : %p\n", (void*)&global);
	printf("BSS Segment  (Global Uninitialized) : %p\n", (void*)&uninitialized);
	printf("Heap Segment (Dynamic Allocation)   : %p\n", (void*)heap_var);
	printf("Stack Segment (Local Variable)      : %p\n", (void*)&local_stack_var);
	long long difference = (char*)&local_stack_var - (char*)heap_var;
	printf("Address difference (Stack - Heap)   : %lld bytes\n", difference);
	
	free(heap_var);
	return 0;
}

