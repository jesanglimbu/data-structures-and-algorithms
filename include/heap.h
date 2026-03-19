#ifndef _HEAP_H_
#define _HEAP_H_

typedef struct heap heap_t;

enum HeapStatus {
	HEAP_OK,
	HEAP_EMPTY,
	HEAP_FULL,
};

heap_t *heap_init();

enum HeapStatus heap_insert(heap_t *h, int val);

enum HeapStatus heap_max(heap_t *h, int *out);

enum HeapStatus heap_delete_max(heap_t *h);

enum HeapStatus heap_delete(heap_t *h, int i);

int heap_size(heap_t *h);

void heap_print(heap_t *h);

#endif
