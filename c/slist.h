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
int get_size(struct slist *l);
node *get_snode(struct slist *l, int i);
int search_slist(struct slist *l, int val);
void append_slist(struct slist *l, int val);
void delete_snode(struct slist *l, int i);
void insert_slist(struct slist *l, int i, int val);
void print_slist(struct slist *l);

#endif
