#include "bst.h"
#include <stddef.h>
#include <stdlib.h>

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

static struct bst_node *node_init();
static int dfs(struct bst *t, struct bst_node *n, int val);

static struct bst_node
*node_init(int val)
{
	struct bst_node *n = malloc(sizeof(struct bst_node));
	n->val = val;
	n->parent = NULL;
	n->lchild = NULL;
	n->rchild = NULL;

	return n;
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

void
bst_insert(struct bst *t, int val)
{
	struct bst_node *n = node_init(val);

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

int
bst_dfs (struct bst *t, int val)
{
	struct bst_node *n = t->root;
	
	if (n == NULL) { /* Empty tree */
		return -1;
	} else if (n->val == val) { 
		return 0;
	} else if (dfs(t, n->lchild, val) != -1) {
		return 0;
	} else {
		return dfs(t, n->rchild, val);
	}
}

int
dfs(struct bst *t, struct bst_node *n, int val)
{
	if (n == NULL) { /* First base case */
		return -1;
	} else if (n->val == val) { /* Second base case */
		return 0;
	} else if (dfs(t, n->lchild, val) != -1) {
		return 0;
	} else {
		return dfs(t, n->rchild, val);
	}	
}
