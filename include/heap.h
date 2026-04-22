#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct heap heap_t;

heap_t *heap_init();

void heap_insert(heap_t *h, int val);

int heap_pop(heap_t *h);

void heap_print(heap_t *h);

#endif
