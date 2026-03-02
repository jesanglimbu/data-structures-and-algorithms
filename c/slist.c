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

int get_node(list *l, int val)
{
	int len = get_size(l);
	node *n = l->start;
	for (int i = 0; i < len; i++) {
		if (n->val == val) {
			return i;
		}
	}

	return -1;
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
		l->end = n; // make new node the end node
	}
	
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

