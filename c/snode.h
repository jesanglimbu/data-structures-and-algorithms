#ifndef _SNODE_H_
#define _SNODE_H_

struct snode {
	int val;
	struct snode *next;
};

struct snode *create_snode(int val);

#endif
