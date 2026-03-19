/*
  In this implementation, I use a static array for the heap.
  This is the way that was taught in my lectures so I will
  implement it that way in here.
*/

#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>
#include <math.h>

#include "heap.h"

#define MAXSIZE 50

static void bubble_up(struct heap *h, int index);
static void bubble_down(struct heap *h, int index);

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

enum HeapStatus
heap_delete_max(struct heap *h)
{
	if (h->size == 0) {
		return HEAP_EMPTY;
	}

	/* Replace root with the last node. */
	int tmp = h->heap_arr[h->size];
	h->heap_arr[h->size] = -1;
	h->size--;
	h->heap_arr[0] = tmp;

	/* Bubble down to maintain heap structure */
	bubble_down(h, 0);

	return HEAP_OK;
}

static void
bubble_up(struct heap *h, int i)
{
	while (i >= 0 && h->heap_arr[i] > h->heap_arr[(i-1)/2]) {
		/* Keep swapping node and parent until
		   node is smaller or equal to parent
		*/
		int tmp = h->heap_arr[i];
		h->heap_arr[i] = h->heap_arr[(i-1)/2];
		h->heap_arr[(i-1)/2] = tmp;
		i = (i-1)/2;
	}
}


/* Please note: for this function to work,
   MAXSIZE must be defined as a value that is
   greater than or equal to (n * 2) + 2 where
   n is the maximum number of nodes you want
*/
static void
bubble_down(struct heap *h, int i)
{
	int lc = (i*2) + 1; /* Left child */
	int rc = (i*2) + 2; /* Right child */

	/* We keep looping if parent is smaller than one or both children */
	while (h->heap_arr[i] < h->heap_arr[lc] || h->heap_arr[i] < h->heap_arr[rc]) {
		/* First check that left child is bigger/equal than right child */
		if (h->heap_arr[lc] >= h->heap_arr[rc]) {
			/* Then swap parent and left child */
			int tmp = h->heap_arr[i];
			h->heap_arr[i] = h->heap_arr[lc];
			h->heap_arr[lc] = tmp;

			/* Update index */
			i = lc;
		} else {
			/* Otherwise, we swap parent and right child */
			int tmp = h->heap_arr[i];
			h->heap_arr[i] = h->heap_arr[rc];
			h->heap_arr[rc] = tmp;

			/* Update index */
			i = rc;
		}

		/* Update children index */
		lc = (i*2) + 1;
		rc = (i*2) + 2;
	}
}

