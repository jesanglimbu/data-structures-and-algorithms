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

