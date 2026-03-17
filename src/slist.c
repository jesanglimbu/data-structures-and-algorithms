#include "slist.h"
#include <stdlib.h>
#include <stdio.h>

struct slist_node {
	int val;
	struct slist_node *next;
};

struct slist {
	struct slist_node *start;
	struct slist_node *end;
	int size;
};


bool
slist_empty(struct slist *l)
{
	return l->size == 0;
}

struct slist
*slist_init()
{
	struct slist *list = malloc(sizeof(struct slist));
	list->size = 0;
	list->start = NULL;
	list->end = NULL;

	return list;
}

struct slist_node
*slist_node(struct slist *l, int i)
{
	if (slist_empty(l)) {
		return NULL;
	}
	
	struct slist_node *n = l->start;
	for (int j = 0; j < i; j++) {
		if (n->next == NULL) {
			return NULL;
		} else {
			n = n->next;
		}
	}

	return n;
}

int
slist_search(struct slist *l, int val)
{
	if (slist_empty(l)) {
		return -1;
	} else {
		struct slist_node *n = l->start;
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
slist_append(struct slist *l, int val)
{
	/* Create new node with value given by parameter */
	struct slist_node *n = malloc(sizeof(struct slist_node));
	n->val = val;

	if (slist_empty(l)) {
		l->start = n;
	} else {
		l->end->next = n; /* Current last node will point to our new last node */
	}

	l->end = n; /* New node is now currently labeled as the end node of our list */
	(l->size)++;
}

void
slist_insert(struct slist *l, int i, int val)
{
	if (i > l->size) {
		printf("Index must be smaller than %d!\n", l->size);
		return;
	} else if (i < 0) {
		printf("Index must be greater than 0!\n");
		return;
	} else if (i == l->size) {
		slist_append(l, val);
		return;
	} else {
		// create new node
		struct slist_node *n = malloc(sizeof(struct slist_node));
		n->val = val;

		if (i == 0) {
			n->next = l->start;
			l->start = n;
		} else {
			struct slist_node *n1 = slist_node(l, i-1); // node to be "replaced" by new node
			struct slist_node *n2 = n1->next; // new node's "next"
			n1->next = n;
			n->next = n2;
		}

		(l->size)++;
	}
}

void
slist_prepend(struct slist *l, int val)
{
	/* Create a new node with value given by parameter */
	struct slist_node *n = malloc(sizeof(struct slist_node));
	n->val = val;
	n->next = NULL;
	
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

struct slist
*slist_concat(struct slist *l1, struct slist *l2)
{
	/* Create a new list */
	struct slist *l = malloc(sizeof(struct slist));
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
slist_delete(struct slist *l, int i)
{
	if (i < 0 || i > (l->size)-1) {
		printf("Please enter a valid index to delete a node from the list!\n");
	} else {
		if (i == 0) {
			struct slist_node *n = l->start;
			l->start = n->next;
			free(n);
		} else {
			/*
			  Get the nodes that are before and after the node we
			  want to delete
			*/
			struct slist_node *pn = slist_node(l, i-1);
			struct slist_node *nn = pn->next->next;
			
			/* Delete our node */
			struct slist_node *n = pn->next; 
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
slist_print(struct slist *l)
{
	if (l->size == 0) {
		printf("List is empty!\n");
	} else {
		int len = l->size;
		struct slist_node *n = l->start;
		for (int i = 0; i < len; i++) {
			printf("%d ", n->val);
			n = n->next;
		}
		printf("\n");
	}
}

