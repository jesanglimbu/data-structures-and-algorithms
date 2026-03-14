#include "queue.h"
#include <stdlib.h>
#include <stddef.h>
#include <stdio.h>

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
		q->first = t;
		q->last = t;
	} else {
		q->last->next = t;
		q->last = t;
	}

	q->size++;
}

int
dequeue(struct queue *q)
{
	struct task *current_task = q->first;
	int val = current_task->val;
	
	q->first = current_task->next;
	free(current_task);

	q->size--;
	
	return val;
}

void
print_queue(struct queue *q)
{
	if (q->size == 0) {
		printf("No tasks in the queue!\n");
	} else {
		struct task *t = q->first;
		for (int i = 0; i < q->size; i++) {
			printf("%d ", t->val);
			t = t->next;
		}
		printf("\n");
	}
}
