#ifndef _QUEUE_H_
#define _QUEUE_H_

#include <stdbool.h>

struct task {
	int val;
	struct task *next;
};

struct queue {
	struct task *first;
	struct task *last;
	int size;
};

struct queue *init_queue();
	
void enqueue(struct queue *q, int val);

int dequeue(struct queue *q);

void print_queue(struct queue *q);

bool is_empty(struct queue *q);

#endif
