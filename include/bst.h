#ifndef _BST_H_
#define _BST_H_

#include <stdbool.h>

typedef struct node node;
typedef struct bst bst;

bst *init_bst();

void insert_bst(bst *t, int val);

void destroy_bst(bst *t);

node *get_root(bst *t);

bool dfs(bst *t, node *n, int val);

bool bfs(bst *t, node *n, int val);

#endif
