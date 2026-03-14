#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#define null (void*)0

typedef struct slist list;

bool
slist_is_empty(list *l)
{
	return l->size == 0;
}

list
*init_slist()
{
	list *list = malloc(sizeof(list));
	list->size = 0;
	list->start = null;
	list->end = null;

	return list;
}

snode
*get_snode(list *l, int i)
{
	if (slist_is_empty(l)) {
		return null;
	}
	
	snode *n = l->start;
	for (int j = 0; j < i; j++) {
		if (n->next == null) {
			return null;
		} else {
			n = n->next;
		}
	}

	return n;
}

int
search_slist(list *l, int val)
{
	if (slist_is_empty(l)) {
		return -1;
	} else {
		snode *n = l->start;
		int i = 0;
		while (i < l->size) {
			if (n->val == val) {
				return i;
			} else {
				n = n->next;
				i++;
			}
		}
	}

	return -1;
}

void
insert_slist(list *l, int i, int val)
{
	if (i > l->size) {
		printf("Index must be smaller than %d!\n", l->size);
		return;
	} else if (i < 0) {
		printf("Index must be greater than 0!\n");
		return;
	} else if (i == l->size) {
		append_slist(l, val);
		return;
	} else {
		// create new node
		snode *n = malloc(sizeof(snode));
		n->val = val;

		if (i == 0) {
			n->next = l->start;
			l->start = n;
		} else {
			snode *n1 = get_snode(l, i-1); // node to be "replaced" by new node			                              // upper bound complexity: O(n)
			snode *n2 = n1->next; // new node's "next"
			n1->next = n;
			n->next = n2;
		}

		(l->size)++;
	}
}

void
delete_slist(list *l)
{
	free(l);
	l = init_slist();
}

void
append_slist(list *l, int val)
{
	/* Create new node with value given by parameter */
	snode *n = malloc(sizeof(snode));
	n->val = val;

	if (slist_is_empty(l)) {
		l->start = n;
	} else {
		l->end->next = n; /* Current last node will point to our new last node */
	}

	l->end = n; /* New node is now currently labeled as the end node of our list */
	(l->size)++;
}

void
prepend_slist(list *l, int val)
{
	/* Create a new node with value given by parameter */
	snode *n = malloc(sizeof(snode));
	n->val = val;
	n->next = null;
	
	if (l->size == 0) {
		l->start = n;
	} else {
		/* New node points to the current starting node of our list */
		n->next = l->start;

		/* New node is now currently labeled as the start node of our list */
		l->start = n;
	}

	(l->size)++;
}

list
*concat_slist(list *l1, list *l2)
{
	/* Create a new list */
	list *l = malloc(sizeof(list));
	l->size = l1->size + l2->size;

	/* Label the starting node of our new list as the start node of the first list */
	l->start = l1->start;

	/* End node of the first list now points to the start node of the second list */
	l1->end->next = l2->start;

	/* Label the end node of our new list as the end node of the second list */
	l->end = l2->end;
	

	return l;
}

void
delete_snode(list *l, int i)
{
	if (i < 0 || i > (l->size)-1) {
		printf("Please enter a valid index to delete a node from the list!\n");
	} else {
		if (i == 0) {
			snode *n = l->start;
			l->start = n->next;
			free(n);
		} else {
			/*
			  Get the nodes that are before and after the node we
			  want to delete
			*/
			snode *pn = get_snode(l, i-1);
			snode *nn = pn->next->next;
			
			/* Delete our node */
			snode *n = pn->next; 
			free(n);

			/*
			  The node that was previous to the deleted node points to
			  the node that was next the deleted node, maintaining the
			  structure of the list
			*/
			pn->next = nn;
		}
		
		(l->size)--;
	}
}

void
print_slist(list *l)
{
	if (l->size == 0) {
		printf("List is empty!\n");
	} else {
		int len = l->size;
		snode *n = l->start;
		for (int i = 0; i < len; i++) {
			printf("%d ", n->val);
			n = n->next;
		}
		printf("\n");
	}
}

