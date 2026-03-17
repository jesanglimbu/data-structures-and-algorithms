#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdbool.h>

/*
typedef struct snode {
	int val;
	struct snode *next;
} snode;
struct slist {
	snode *start;
	snode *end;
	int size;
};
*/

typedef struct slist slist_t;

slist_t *init_slist();

bool slist_empty(slist_t *l);

void append_slist(slist_t *l, int val);

void prepend_slist(slist_t *l, int val);

void insert_slist(slist_t *l, int i, int val);

int search_slist(slist_t *l, int val);

void delete_snode(slist_t *l, int i);

/*snode *get_snode(slist_t *l, int i);*/

slist_t *concat_slist(slist_t *l1, slist_t *l2);

void delete_slist(slist_t *l);

void print_slist(slist_t *l);

#endif
