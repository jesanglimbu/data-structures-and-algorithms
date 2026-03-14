#ifndef _SLIST_H_
#define _SLIST_H_

#include <stdbool.h>

typedef struct snode {
	int val;
	struct snode *next;
} snode;
struct slist {
	snode *start;
	snode *end;
	int size;
};

struct slist *init_slist();

bool slist_is_empty(struct slist *l);

void append_slist(struct slist *l, int val);

void prepend_slist(struct slist *l, int val);

void insert_slist(struct slist *l, int i, int val);

int search_slist(struct slist *l, int val);

void delete_snode(struct slist *l, int i);

snode *get_snode(struct slist *l, int i);

struct slist *concat_slist(struct slist *l1, struct slist *l2);

void delete_slist(struct slist *l);

void print_slist(struct slist *l);

#endif
