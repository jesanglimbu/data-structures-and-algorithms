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

int pop(stack *st)
{
	if (st->size == 0) {
		printf("Stack is empty!\n");
		return -1;
	} else {
		int ret = get_snode(st, 0)->val;
		delete_snode(st, 0);
		return ret;
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

bool is_empty(stack *st)
{
	return st->size == 0;
}
