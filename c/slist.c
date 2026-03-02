#include "slist.h"
#include <stdlib.h>
#include <stdio.h>
#define null (void*)0

typedef struct slist list;

bool is_empty(list *l)
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

int get_size(list *l)
{
	return l->size;
}

node *get_node(list *l, int i)
{
	if (is_empty(l)) {
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

void insert(list *l, int i, int val)
{
	if (i > l->size) {
		printf("Index must be smaller than %d!\n", l->size);
		return;
	} else if (i < 0) {
		printf("Index must be greater than 0!\n");
		return;
	} else if (i == l->size) {
		append(l, val);
		return;
	} else {
		// create new node
		node *n = malloc(sizeof(node));
		n->val = val;

		if (i == 0) {
			n->next = l->start;
			l->start = n;
		} else {
			node *n1 = get_node(l, i-1); // node to be "replaced" by new node
			node *n2 = n1->next; // new node's "next"
			n1->next = n;
			n->next = n2;
		}

		(l->size)++;
	}
}

void append(list *l, int val)
{
	// create new node
	node *n = malloc(sizeof(node));
	n->val = val;

	// check if list is empty
	if (is_empty(l)) {
		l->start = n;
	} else {
		l->end->next = n; // make end node point to new node
	}

	l->end = n; // make new node the end node
	(l->size)++;
}

void print_list(list *l)
{
	int len = l->size;
	node *n = l->start;
	for (int i = 0; i < len; i++) {
		printf("%d ", n->val);
		n = n->next;
	}
	printf("\n");
}

