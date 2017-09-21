#include<stdio.h>
#include<stdlib.h>

struct bstnode{
	void* data;
	struct bstnode *left;
	struct bstnode *right;

	};


struct bstnode* insert_node(struct bstnode*, void*);
struct bstnode* search(struct bstnode*, void*);
int find_min(struct bstnode*);
int find_max(struct bstnode*);
void inorder(struct bstnode*);
void* key(void* data);
