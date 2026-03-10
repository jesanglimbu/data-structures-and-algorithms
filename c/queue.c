#include "queue.h"

struct queue *init_queue(int max)
{
	struct queue *q = malloc(sizeof(q));
	q->MAXSIZE = max;
	q->items = int[max];
	q->size = 0;
	q->front = 0;
}
