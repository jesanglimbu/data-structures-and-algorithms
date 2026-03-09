#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

#define null (void*)0

typedef struct dlist list;

list *init_dlist()
{
	list *l = malloc(sizeof(list));
	l->size = 0;
	l->start = null;
	l->end = null;

	return l;
}

void insert(list *l int val, int index)
{
	if (index >= l->size || index < 0) {
		printf("Error: tried to insert a node in an out of range index!\n");
		return;
	} else {
		node *n = malloc(sizeof(node));
		n->val = val;
		
		// if the index is the last index
		if (index == (l->size)-1) {
			n->prev = l->end;
			l->end->next = n;
			l->end = n;
		}
		if (index == 0) {
			n->next = l->start;
			l->start->prev = n;
			l->start = n;
		} else {
			node *prev_node = get_node(l, index);
			node *next_node = next_node->next;
			n->prev = prev_node;
			n->next = next_node;
			prev_node->next = n;
			next_node->prev = n;
		}

		(l->size)++;
	}
}
