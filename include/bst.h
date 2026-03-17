#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct bst bst_t;
typedef struct bst_node bst_node_t;

bst_t *bst_init();

void bst_insert(bst_t *t, int val);

void bst_destroy(bst_t *t);

bst_node_t *bst_root(bst_t *t);

bool bst_dfs(bst_t *t, bst_node_t *n, int val);

bool bst_bfs(bst_t *t, bst_node_t *n, int val);

#endif
