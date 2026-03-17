#include "stack.h"
#include "slist.h"
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

struct stack_node {
	int val;
	struct stack_node *next;
};

struct stack {
	int size;
	struct stack_node *top;
};

struct stack
*stack_init()
{
	struct stack *my_stack = malloc(sizeof(struct stack));
	my_stack->size = 0;
	my_stack->top = NULL;

	return my_stack;
}

void
stack_push(struct stack *s, int val)
{
	/* Allocate and initialize an item on the stack */
	struct stack_node *my_node = malloc(sizeof(struct stack_node));
	my_node->val = val;
	my_node->next = NULL;

	/* Update the stack's top item */
	if (s->size > 0) {
		my_node->next = s->top;
	}
	
	s->top = my_node;

	(s->size)++;
}

int
stack_pop(struct stack *s)
{
	if (s->size == 0) {
		printf("Stack is empty!\n");
		return -1;
	} else {
		/* Get the item and its value that we want to delete */
		struct stack_node *my_node = s->top;
		int val = my_node->val;

		/* Update the stack's top item and delete our old item */
		s->top = my_node->next;
		free(my_node);

		s->size--;
		
		return val;
	}
}

void
stack_print(struct stack *s)
{
	if (s->size == 0) {
		printf("Stack is empty!\n");
	} else {
		struct stack_node *my_node = s->top;
		for (int i = 0; i < s->size; i++) {
			printf("%d ", my_node->val);
			my_node = my_node->next;
		}
		printf("\n");
	}
}

