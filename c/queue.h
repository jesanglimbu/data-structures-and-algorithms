#ifndef _QUEUE_H_
#define _QUEUE_H_

#include "dlist.h"
#include <stdbool.h>

typedef struct dlist dlist;

struct queue {
	int *items;
	int MAXSIZE;
	int size;
	int front;
};

struct queue *init_queue();
	
void enqueue(struct queue *q, int val);

int dequeue(struct queue *q);

bool is_empty(struct queue *q);

#endif
