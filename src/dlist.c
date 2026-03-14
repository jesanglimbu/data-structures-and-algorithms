#include "dlist.h"
#include <stdlib.h>
#include <stdio.h>

#define null (void*)0

typedef struct dlist list;

list
*init_dlist()
{
	list *l = malloc(sizeof(list));
	l->size = 0;
	l->start = null;
	l->end = null;

	return l;
}

void
insert_dlist(list *l, int val, int index)
{
	if (index >= l->size || index < 0) {
		printf("Error: tried to insert a node in an out of range index!\n");
		return;
	} else {
		/* Create our new node */
		dnode *n = malloc(sizeof(dnode));
		n->val = val;
		
		if (index == (l->size)-1) {
			append_dlist(l, val);
		}
		if (index == 0) {
			prepend_dlist(l, val);
		} else {
			/* Get the nodes at the index and the index before */
			dnode *next_node = get_dnode(l, index);
			dnode *prev_node = next_node->prev;

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
prepend_dlist(list *l, int val)
{
	dnode *n = malloc(sizeof(dnode));
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

void
append_dlist(list *l, int val)
{
	dnode *n = malloc(sizeof(dnode));
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
delete_dlist(list *l, int index)
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
			dnode *n = get_dnode(l, index);
			dnode *next_node = n->next;
			dnode *prev_node = n->prev;

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
search_dlist(list *l, int val)
{
	int len = l->size;
	dnode *n = l->start;

	for (int i = 0; i < len; i++) {
		if (n->val == val) {
			return i;
		} else {
			n = n->next;
		}
	}

	return -1;
}

dnode
*get_dnode(list *l, int index)
{
	if (index >= 0 && index < l->size) {
		dnode *n = l->start;
		for (int i = 0; i < index; i++) {
			n = n->next;
		}

		return n;
	}

	return null;
}

void
clear_dlist(list *l)
{
	free(l);
	l = init_dlist();
}


void
print_dlist(list *l)
{
	if (l->size == 0) {
		printf("No elements in the list!\n");
	} else {
		dnode *n = l->start;
		for (int i = 0; i < l->size; i++) {
			printf("%d ", n->val);
			n = n->next;
		}
		printf("\n");
	}
}
