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
bool is_empty(struct slist *l);
int get_size(struct slist *l);
node *get_node(struct slist *l, int i);
int search(struct slist *l, int val);
void append(struct slist *l, int val);
void delete(struct slist *l, int i);
void insert(struct slist *l, int i, int val);
void print_list(struct slist *l);

#endif
