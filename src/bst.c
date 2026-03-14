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
		t->height++;
	} else {
		struct node *parent = t->root;
		/* Traversing the tree. */
		if (val < parent->val) {
			/* We go to the left if val < parent */
			if (parent->lchild == NULL) {
				/* If the left child is empty, we insert the node here */
				parent->lchild = n;
				n->parent = parent;
			} else {
				/* Otherwise, keep traversing the tree. */
				parent = parent->lchild;
			}
		} else {
			/* We go right if the val >= parent */
			if (parent->rchild == NULL) {
				/* If right child is empty, we insert the node here. */
				parent->rchild = n;
				n->parent = parent;
			} else {
				/* Otherwise, keep traversing. */
				parent = parent->rchild;
			}
		}
		
	}
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
