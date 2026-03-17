#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

#include "heap.h"
#include "queue.h"

struct heap_node {
	int val;
	struct heap_node *parent;
	struct heap_node *lchild;
	struct heap_node *rchild;
};

struct heap {
	struct heap_node *root;
	int size;
	int height;
};

struct heap
*heap_init()
{
	struct heap *my_heap = malloc(sizeof(struct heap));
	my_heap->root = NULL;
	my_heap->size = 0;
	my_heap->height = -1;

	return my_heap;
}

int
heap_height(struct heap *h)
{
	return h->height;
}

int
heap_size(struct heap *h)
{
	return h->size;
}

void
heap_insert(struct heap *h, int val)
{
	struct heap_node *n = malloc(sizeof(struct heap_node));
	n->val = val;
	n->parent = NULL;
	n->lchild = NULL;
	n->rchild = NULL;
	
	
	struct heap_node *m = h->root;

	if (h->height == -1) { 	
		h->root = n;
		h->height++;
	} else { /* Find the next position for the leaf. */
		int height = 0;
		while (m->lchild != NULL) {
			m = m->rchild;
			height++;
		}
		
		height++;
		m->lchild = n;
		n->parent = m;
		
		if (height > h->height)
			h->height++;
	}

	h->size++;
}
