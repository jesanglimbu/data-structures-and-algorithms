#include "bst.h"
#include <stddef.h>
#include <stdlib.h>
#include <stdbool.h>

struct node {
	int val;
	struct node *parent;
	struct node *rchild;
	struct node *lchild;
};

struct bst {
	struct node *root;
	int size;
	int height;
};

int
get_val(struct node *n)
{
	return n->val;
}

struct bst
*init_bst()
{
	struct bst *my_bst = malloc(sizeof(struct bst));
	my_bst->root = NULL;
	my_bst->size = 0;
	my_bst->height = -1;

	return my_bst;
}

struct node
*get_root(struct bst *t)
{
	return t->root;
}

void
insert_bst(struct bst *t, int val)
{
	struct node *n = malloc(sizeof(struct node));
	n->val = val;
	n->rchild = NULL;
	n->lchild = NULL;
	n->parent = NULL;
	if (t->size == 0) {
		t->root = n;
	} else {
		struct node *m = t->root;
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
dfs (struct bst *t, struct node *n, int val)
{
	if (n == NULL) {
		return false;
	} else if (n->val == val) {
		return true;
	} else if (dfs(t, n->lchild, val)) {
		return true;
	} else {
		return dfs(t, n->rchild, val);
	}
}

void
clear_bst(struct bst *t)
{
	free(t);
	t = init_bst();
}
