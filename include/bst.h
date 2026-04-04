#ifndef _BST_H_
#define _BST_H_

typedef struct bst bst_t;

bst_t *bst_init();

void bst_insert(bst_t *t, int val);

int bst_destroy(bst_t *t);

int bst_dfs(bst_t *t, int val);

int bst_bfs(bst_t *t, int val);

#endif
