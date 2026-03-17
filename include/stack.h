#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include "slist.h"

/*
struct item {
	int val;
	struct item *next;
};

struct stack {
	int size;
	struct item *top;
};
*/

typedef struct stack stack_t;

stack_t *stack_init();

void stack_push(stack_t *s, int val);

int stack_pop(stack_t *s);

void stack_print(stack_t *s);

#endif
