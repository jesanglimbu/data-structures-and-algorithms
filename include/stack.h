#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include "slist.h"

struct item {
	int val;
	struct item *next;
};

struct stack {
	int size;
	struct item *top;
};

struct stack *init_stack();

void push(struct stack *s, int val);

int pop(struct stack *s);

void print_stack(struct stack *s);

#endif
