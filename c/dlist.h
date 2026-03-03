#ifndef _DLIST_H_
#define _DLIST_H_

#include <stdbool.h>

typedef struct dnode {
	int val;
	struct dnode *next;
	struct dnode *prev;
} dnode;

struct dlist {
	int size;
	dnode *start;
	dnode *end;
};

struct dlist *init_dlist();
bool dlist_is_empty(struct dlist *l);
void insert_dlist(struct dlist *l, int i, int val);
void append_dlist(struct dlist *l, int val);
void delete_dlist(struct dlist *l);
int search_dlist(struct dlist *l, int val);
dnode *get_dnode(struct dlist *l, int i);
struct dlist *concat_dlist(struct dlist *l1, struct dlist *l2);
void print_dlist(struct dlist *l);

#endif
