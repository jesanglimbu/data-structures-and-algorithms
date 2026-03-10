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

void insert_dlist(list *l, int val, int index)
{
	if (index >= l->size || index < 0) {
		printf("Error: tried to insert a node in an out of range index!\n");
		return;
	} else {
		dnode *n = malloc(sizeof(dnode));
		n->val = val;
		
		// if the index is the last index
		if (index == (l->size)-1) {
			append_dlist(l, val);
		}
		if (index == 0) {
			prepend_dlist(l, val);
		} else {
			dnode *next_node = get_dnode(l, index);
			dnode *prev_node = next_node->prev;
			n->prev = prev_node;
			n->next = next_node;
			prev_node->next = n;
			next_node->prev = n;
		}

		(l->size)++;
	}
}

void prepend_dlist(list *l, int val)
{
	dnode *n = malloc(sizeof(dnode));
	n->val = val;
	n->next = l->start;
	l->start->prev = n;
	l->start = n;
	(l->size)++;
}

void append_dlist(list *l, int val)
{
	dnode *n = malloc(sizeof(dnode));
	n->val = val;
	if (l->size == 0) { // if list has no nodes, we make the node the starting node
		l->start = n;
		l->end = n;
	} else {
		n->prev = l->end;
		l->end->next = n;
		l->end = n;
	}
	(l->size)++;
}

void delete_dlist(list *l, int index)
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
			dnode *n = get_dnode(l, index);
			dnode *next_node = n->next;
			dnode *prev_node = n->prev;
			free(n);
			prev_node->next = next_node;
			next_node->prev = prev_node;
		}
		(l->size)--;
	}
	
}

int search_dlist(list *l, int val)
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

dnode *get_dnode(list *l, int index)
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

void clear_dlist(list *l)
{
	free(l);
	l = init_dlist();
}


void print_dlist(list *l)
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
