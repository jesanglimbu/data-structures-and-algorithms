#include "bst.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

struct bst_node {
	int val;
	struct bst_node *parent;
	struct bst_node *rchild;
	struct bst_node *lchild;
};

struct bst {
	struct bst_node *root;
	int size;
	int height;
};

int
get_val(struct bst_node *n)
{
	return n->val;
}

struct bst
*bst_init()
{
	struct bst *my_bst = malloc(sizeof(struct bst));
	my_bst->root = NULL;
	my_bst->size = 0;
	my_bst->height = -1;

	return my_bst;
}

struct bst_node
*bst_root(struct bst *t)
{
	return t->root;
}

void
bst_insert(struct bst *t, int val)
{
	struct bst_node *n = malloc(sizeof(struct bst_node));
	n->val = val;
	n->rchild = NULL;
	n->lchild = NULL;
	n->parent = NULL;
	if (t->size == 0) {
		t->root = n;
	} else {
		struct bst_node *m = t->root;
		/* Traversing the tree. */
		while (n->parent == NULL) { /* Invariant: n guaranteed to have a parent by the end */
			if (val > m->val) {
				if (m->rchild == NULL) {
					/* We place the node to the right */
					m->rchild = n;
					n->parent = m;
				} else {
					m = m->rchild; /* Keep traversing */
				}
			} else {
				if (m->lchild == NULL) {
					/* Place the node to the left */
					m->lchild = n;
					n->parent = m;
				} else {
					/* Keep traversing */
					m = m->lchild;
				}
			}
		}
	}
	
	/* Increase the size after all that! */
	t->size++;
}

bool
bst_dfs (struct bst *t, struct bst_node *n, int val)
{
	if (n == NULL) { /* Base case 1 */
		return false;
	} else if (n->val == val) { /* Base case 2 */
		return true;
	} else if (bst_dfs(t, n->lchild, val)) {
		return true;
	} else {
		return bst_dfs(t, n->rchild, val);
	}
}

// TO DO: bfs_destroy(struct bst *t)
