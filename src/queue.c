#include "queue.h"
#include <stdlib.h>
#include <stddef.h>

struct queue
*init_queue()
{
	/* Allocate and initialize a queue */
	struct queue *my_queue = malloc(sizeof(struct queue));
	my_queue->size = 0;
	
	return my_queue;
}

void
enqueue(struct queue *q, int val)
{
	/* Allocate and initialize the task */
	struct task *t = malloc(sizeof(struct task));
	t->val = val;
	t->next = NULL;

	if (q->size == 0) {
		q->start = t;
	} else {
		q->end->next = t;
		q->end = t;
	}

	q->size++;
}
