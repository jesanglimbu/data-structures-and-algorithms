#include "stack.h"
#include "dlist.h"

stack *init_stack()
{
	return init_dlist();
}

void push(stack *st, int val)
{
	prepend_dlist(st, val);
}

void pop(stack *st)
{
	delete_dlist(st, (st->size)-1);
}


