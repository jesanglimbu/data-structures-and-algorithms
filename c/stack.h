#ifndef _STACK_H_
#define _STACK_H_

#include <stdbool.h>
#include "dlist.h"

typedef struct dlist stack;

stack *init_stack();
void push(stack *st, int val);
void pop(stack *st);
bool isEmpty(stack *st);

#endif
