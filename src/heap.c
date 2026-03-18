/*
  In this implementation, I use a static array for the heap.
  This is the way that was taught in my lectures so I will
  implement it that way in here.
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "heap.h"

#define MAXSIZE 10

static void bubble_up(struct heap *h, int index);
static void bubble_down(struct heap *h);

struct heap {
	int heap_arr[MAXSIZE];
	size_t size;
};

struct heap
*heap_init()
{
	struct heap *my_heap = malloc(sizeof(struct heap));
	my_heap->size = 0;

	return my_heap;
}

int
heap_size(struct heap *h)
{
	return h->size;
}

enum HeapStatus
heap_max(struct heap *h, int *out)
{
	if (h->size == 0) {
		return HEAP_EMPTY;
	}
		
	*out = h->heap_arr[0];
	return HEAP_OK;
}

enum HeapStatus
heap_insert(struct heap *h, int val)
{
	size_t size = h->size;
	
	if (size >= MAXSIZE) {
		return HEAP_FULL;
	} else {
		if (h->size == 0) {
			h->heap_arr[size] = val;
		} else {
			h->heap_arr[size] = val;
			bubble_up(h, size);
		}
		
		h->size++;
	}

	return HEAP_OK;
}

static void
bubble_up(struct heap *h, int i)
{
	while (i > 0 && h->heap_arr[i] > h->heap_arr[(i-1)/2]) {
		int tmp = h->heap_arr[i];
		h->heap_arr[i] = h->heap_arr[(i-1)/2];
		h->heap_arr[(i-1)/2] = tmp;
		i = (i-1)/2;
	}
}

static void
bubble_down(struct heap *h)
{
	/* TO DO */
}
