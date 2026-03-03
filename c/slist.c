#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#define null (void*)0

typedef struct slist list;

bool slist_is_empty(list *l)
{
	return l->size == 0;
}

list *init_slist()
{
	list *list = malloc(sizeof(list));
	list->size = 0;
	list->start = null;
	list->end = null;

	return list;
}

node *get_snode(list *l, int i)
{
	if (slist_is_empty(l)) {
		return null;
	}
	
	node *n = l->start;
	for (int j = 0; j < i; j++) {
		if (n->next == null) {
			return null;
		} else {
			n = n->next;
		}
	}

	return n;
}

int search_slist(list *l, int val)
{
	if (slist_is_empty(l)) {
		return -1;
	} else {
		node *n = l->start;
		int i = 0;
		while (i < l->size) { // upper bound complexity: O(n)
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

void insert_slist(list *l, int i, int val)
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
		node *n = malloc(sizeof(node));
		n->val = val;

		if (i == 0) {
			n->next = l->start;
			l->start = n;
		} else {
			node *n1 = get_snode(l, i-1); // node to be "replaced" by new node			                              // upper bound complexity: O(n)
			node *n2 = n1->next; // new node's "next"
			n1->next = n;
			n->next = n2;
		}

		(l->size)++;
	}
}

void delete_slist(list *l)
{
	free(l);
	l = init_slist();
}

void append_slist(list *l, int val)
{
	// create new node
	node *n = malloc(sizeof(node));
	n->val = val;

	// check if list is empty
	if (slist_is_empty(l)) {
		l->start = n;
	} else {
		l->end->next = n; // make end node point to new node
	}

	l->end = n; // make new node the end node
	            // upper bound complexity O(1)
	(l->size)++;
}

list *concat_slist(list *l1, list *l2)
{
	list *l = malloc(sizeof(list));
	l->start = l1->start;
	l1->end->next = l2->start;
	l->end = l2->end;
	l->size = l1->size + l2->size;

	return l;
}

void delete_snode(list *l, int i)
{
	if (i < 0 || i > (l->size)-1) {
		printf("Please enter a valid index to delete a node from the list!\n");
	} else {
		if (i == 0) {
			node *n = l->start;
			l->start = n->next;
			free(n);
		} else {
			node *pn = get_snode(l, i-1);
			node *n = pn->next;
			node *nn = n->next;
			free(n);
			pn->next = nn;
		}
		
		(l->size)--;
	}
}

void print_slist(list *l)
{
	int len = l->size;
	node *n = l->start;
	for (int i = 0; i < len; i++) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

