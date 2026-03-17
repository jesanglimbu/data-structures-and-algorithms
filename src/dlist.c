#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

struct dlist_node {
	int val;
	struct dlist_node *next;
	struct dlist_node *prev;
};

struct dlist {
	int size;
	struct dlist_node *start;
	struct dlist_node *end;
};

struct dlist
*dlist_init()
{
	struct dlist *l = malloc(sizeof(struct dlist));
	l->size = 0;
	l->start = NULL;
	l->end = NULL;

	return l;
}

void
dlist_append(struct dlist *l, int val)
{
	struct dlist_node *n = malloc(sizeof(struct dlist_node));
	n->val = val;
	if (l->size == 0) { /* If list has no nodes,
			       we make it the start node */
		l->start = n;
		l->end = n;
	} else {
		n->prev = l->end;
		l->end->next = n;
		l->end = n;
	}
	(l->size)++;
}

void
dlist_prepend(struct dlist *l, int val)
{
	struct dlist_node *n = malloc(sizeof(struct dlist_node));
	n->val = val;
	if (l->size == 0) { /* If there are no nodes, we make
			       the starting node */
		l->start = n;
	} else {
		n->next = l->start;
		l->start->prev = n;
		l->start = n;
	}
	(l->size)++;
}

struct dlist_node
*dlist_dnode(struct dlist *l, int index)
{
	if (index >= 0 && index < l->size) {
		struct dlist_node *n = l->start;
		for (int i = 0; i < index; i++) {
			n = n->next;
		}

		return n;
	}

	return NULL;
}

void
dlist_insert(struct dlist *l, int val, int index)
{
	if (index >= l->size || index < 0) {
		printf("Error: tried to insert a node in an out of range index!\n");
		return;
	} else {
		/* Create our new node */
		struct dlist_node *n = malloc(sizeof(struct dlist_node));
		n->val = val;
		
		if (index == (l->size)-1) {
			dlist_append(l, val);
		}
		if (index == 0) {
			dlist_prepend(l, val);
		} else {
			/* Get the nodes at the index and the index before */
			struct dlist_node *next_node = dlist_dnode(l, index);
			struct dlist_node *prev_node = next_node->prev;

			/* Assign pointers of the new node to point to the nodes */
			n->prev = prev_node;
			n->next = next_node;

			/* Assign pointers of the nodes to point to our new node */
			prev_node->next = n;
			next_node->prev = n;
		}

		(l->size)++;
	}
}

void
dlist_delete(struct dlist *l, int index)
{
	if (index < 0 || index >= l->size) {
		printf("Error: tried to delete a node in an index out of range!\n");
	} else {
		if (index == 0) {
			l->start = l->start->next;
			free(l->start->prev);
		} else if (index == (l->size)-1) {
			l->end = l->end->prev;
			free(l->end->next);
		} else {
			/* Get the node we want to delete and its neighbours. */
			struct dlist_node *n = dlist_dnode(l, index);
			struct dlist_node *next_node = n->next;
			struct dlist_node *prev_node = n->prev;

			/* Delete the node. */
			free(n);

			/* Update the pointers of the neighbour nodes
			   to maintain the structure of the list. */
			prev_node->next = next_node;
			next_node->prev = prev_node;
		}
		(l->size)--;
	}
	
}

int
dlist_search(struct dlist *l, int val)
{
	int len = l->size;
	struct dlist_node *n = l->start;

	for (int i = 0; i < len; i++) {
		if (n->val == val) {
			return i;
		} else {
			n = n->next;
		}
	}

	return -1;
}

void
dlist_clear(struct dlist *l)
{
	free(l);
	l = dlist_init();
}


void
dlist_print(struct dlist *l)
{
	if (l->size == 0) {
		printf("No elements in the list!\n");
	} else {
		struct dlist_node *n = l->start;
		for (int i = 0; i < l->size; i++) {
			printf("%d ", n->val);
			n = n->next;
		}
		printf("\n");
	}
}
