#include "stack.h"
#include "slist.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct stack
*init_stack()
{
	struct stack *my_stack = malloc(sizeof(struct stack));
	my_stack->size = 0;
	my_stack->top = NULL;

	return my_stack;
}

void
push(struct stack *s, int val)
{
	/* Allocate and initialize an item on the stack */
	struct item *my_item = malloc(sizeof(struct item));
	my_item->val = val;
	my_item->next = NULL;

	/* Update the stack's top item */
	if (s->size > 0) {
		my_item->next = s->top;
	}
	
	s->top = my_item;

	(s->size)++;
}

int
pop(struct stack *s)
{
	if (s->size == 0) {
		printf("Stack is empty!\n");
		return -1;
	} else {
		/* Get the item and its value that we want to delete */
		struct item *my_item = s->top;
		int val = my_item->val;

		/* Update the stack's top item and delete our old item */
		s->top = my_item->next;
		free(my_item);

		s->size--;
		
		return val;
	}
}

void
print_stack(struct stack *s)
{
	if (s->size == 0) {
		printf("Stack is empty!\n");
	} else {
		struct item *my_item = s->top;
		for (int i = 0; i < s->size; i++) {
			printf("%d ", my_item->val);
			my_item = my_item->next;
		}
		printf("\n");
	}
}

