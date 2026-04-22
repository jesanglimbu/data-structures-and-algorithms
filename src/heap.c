#include "heap.h"
#include <stdlib.h>
#include <stdio.h>

struct heap {
	int *arr;
	int size;
	int capacity;
};

static void sift_up(struct heap *h, int i);
static void sift_down(struct heap *h, int i);

struct heap
*heap_init(int cap)
{
	struct heap *my_heap = malloc(sizeof(struct heap));

	my_heap->size = 0;
	
	/* Initial capacity of array will be cap */
	my_heap->capacity = cap; 
	my_heap->arr = malloc(cap * sizeof(int));

	return my_heap;
}

void
heap_insert(struct heap *h, int val)
{
	int size = h->size;
	const int capacity = h->capacity;
	int *heap_arr = h->arr;
	
	/* Check if adding a child indexes out of bounds */
	if (size >= capacity) {
		heap_arr = realloc(heap_arr, 2 * capacity * sizeof(int));
	}
	
	/* Add node at the next free space then sift up */
	heap_arr[size] = val;
	sift_up(h, size);
	
	h->size++;
}

int
heap_pop(struct heap *h)
{
	if (h->size == 0) {
		fprintf(stderr, "heap: can't pop at size 0");
	}

	h->size--;
	int *heap_arr = h->arr;

	int ret = heap_arr[0];
	int n = heap_arr[h->size];
	
	heap_arr[0] = n;
	sift_down(h, 0);

	return ret;
}

void
heap_print(struct heap *h)
{
	const int size = h->size;
	const int *heap_arr = h->arr;
	for (int i = 0; i < size; i++) {
		printf("%d ", heap_arr[i]);
	}
	printf("\n");
}

void
sift_up(struct heap *h, int i)
{
	int *heap_arr = h->arr;
	int n = heap_arr[i];

	while (n < heap_arr[(i-1)/2]) {
		int tmp = heap_arr[(i-1)/2];
		heap_arr[(i-1)/2] = n;
		heap_arr[i] = tmp;
		i = (i-1)/2;
		if (i < 0) break;
	}
}

void
sift_down(struct heap *h, int i)
{
	int *arr = h->arr;
	int left = (i*2)+1;
	int right = (i*2)+2;
	int j;
	

	while (arr[i] > arr[left] || arr[i] > arr[right]) {
		j = (arr[left] < arr[right] ? left : right);
		
			int tmp = arr[j];
			arr[j] = arr[i];
			arr[i] = tmp;
			i = j;
		left = (i*2)+1;
		right = (i*2)+2;

		if (left >= h->size || right >= h->size) break;
	}
}
