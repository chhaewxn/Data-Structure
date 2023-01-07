#include <stdio.h>
#define MAX_ELEMENT 200

typedef struct {
	int key;
} element;
typedef struct {
	element heap[MAX_ELEMENT];
	int heap_size;
} HeapType;

// Initialisation
void init(HeapType* A)
{
	int value[11] = { 0, 1, 4, 2, 7, 5, 3, 3, 7, 8, 9 };
	A->heap_size = 10;
	for (int i = 1; i <= A->heap_size; i++)
		A->heap[i].key = value[i];
}

// Print the heap
void print_heap(HeapType* A)
{
	for (int i = 1; i <= A->heap_size; i++)
		printf("%d ", A->heap[i].key);
	printf("\n");
}

// decrease the element i's value to 'key'
void Decrease_key_min_heap(HeapType* A, int i, int key)
{
	element temp;

	if (key >= A->heap[i].key) {
		printf("new key is not smaller than current key\n");
		return;
	}

	A->heap[i].key = key;
	while (i > 0 && A->heap[i / 2].key > A->heap[i].key)
	{
		temp = A->heap[i / 2];
		A->heap[i / 2] = A->heap[i];
		A->heap[i] = temp;
		i = i / 2;
	}
}

// Increase the element i's value
void Increase_key_min_heap(HeapType* A, int i, int key)
{
	element temp;

	if (key <= A->heap[i].key) {
		printf("new key is not larger than current key\n");
		return;
	}

	A->heap[i].key = key;
	while ((i * 2) <= A->heap_size && A->heap[i * 2].key < A->heap[i].key)
	{
		temp = A->heap[i * 2];
		A->heap[i * 2] = A->heap[i];
		A->heap[i] = temp;
		i = i * 2;
	}
}

int main(void)
{
	HeapType min_heap;
	init(&min_heap);

	printf("Before : ");
	print_heap(&min_heap);

	Decrease_key_min_heap(&min_heap, 4, 3);
	Increase_key_min_heap(&min_heap, 3, 10);

	printf("After : ");
	print_heap(&min_heap);
}