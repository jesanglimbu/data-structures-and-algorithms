#include "snode.h"
#include <stdlib.h>

struct snode *create_snode(int val)
{
	struct snode *n = malloc(sizeof(struct snode));
	n->val = val;
	return n;
}
