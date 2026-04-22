#ifndef _AVL_H_
#define _AVL_H_

typedef struct avl avl_t;

avl_t *avl_init();

void avl_insert(avl_t *t, int val);

void avl_delete(aval_t *t, int val);

#endif
