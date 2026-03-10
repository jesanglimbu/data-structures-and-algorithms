#include "stack.h"
#include "slist.h"
#include <stdio.h>

stack *init_stack()
{
	return init_slist();
}

void push(stack *st, int val)
{
	prepend_slist(st, val);
}

void pop(stack *st)
{
	if (st->size == 0) {
		printf("Stack is empty!\n");
	} else {
		delete_snode(st, 0);
	}
}

void print_stack(stack *st)
{
	if (st->size == 0) {
		printf("Stack is empty!\n");
	} else {
		print_slist(st);
	}
}

