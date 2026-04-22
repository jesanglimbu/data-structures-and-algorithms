#include "bst.h"
#include <stdlib.h>


struct bst_node {
	int val;
	struct bst_node *rchild;
	struct bst_node *lchild;
	struct bst_node *parent;
};

struct bst {
	struct bst_node *root;
	int size;
};

struct bst
*bst_init()
{
	/* Initialise bst */
	struct bst *my_bst = malloc(sizeof(struct bst));

	my_bst->root = NULL;
	my_bst->size = 0;

	return my_bst;
}

void
bst_insert(struct bst *bst, int val)
{
	struct bst_node *n = malloc(sizeof(struct bst_node));
	n->val = val;
	n->rchild = NULL;
	n->lchild = NULL;
	n->parent = NULL;
	
	if (bst->size == 0) {
		bst->root = n;
	} else {
		struct bst_node *m = bst->root;
		while (n->parent == NULL) {
			if (val < m->val) {
				if (m->lchild == NULL) {
					n->parent = m;
					m->lchild = n;
				} else {
					m = m->lchild;
				}
			} else {
				if (m->rchild == NULL) {
					n->parent = m;
					m->rchild = n;
				} else {
					m = m->rchild;
				}
			}
		}
	}

	bst->size++;
}

int
bst_search(struct bst *bst, int val)
{
	struct bst_node *n = bst->root;
	while (n != NULL) {
		if (val == n->val) {
			return n->val;
		} else if (val < n->val) {
			n = n->lchild;
		} else {
			n = n->rchild;
		}
	}

	return -1;
}
