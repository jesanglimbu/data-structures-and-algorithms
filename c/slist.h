#ifndef _SLIST_H_
#define _SLIST_H_

#include "snode.h"
#include <stdbool.h>

typedef struct snode node;

struct slist {
	node *start;
	node *end;
	int size;
};

struct slist *init_slist();
bool slist_is_empty(struct slist *l);
void append_slist(struct slist *l, int val);
void insert_slist(struct slist *l, int i, int val);
int search_slist(struct slist *l, int val);
void delete_snode(struct slist *l, int i);
node *get_snode(struct slist *l, int i);
void delete_slist(struct slist *l);
void print_slist(struct slist *l);

#endif
