#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include "slist.h"

typedef struct slist stack;

stack *init_stack();

void push(stack *st, int val);

void pop(stack *st);

bool isEmpty(stack *st);

void print_stack(stack *st);

#endif
