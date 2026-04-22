#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct bst bst_t;

bst_t *bst_init();

void bst_insert(bst_t *t, int val);

void bst_destroy(bst_t *t);

int bst_search(bst_t *t, int val);

#endif
