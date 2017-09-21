#include<stdio.h>
#include<stdlib.h>
#define RED 1
#define BLACK 0

struct rbnode{
	int data;
	enum {black, red} color;
	struct rbnode *left;
	struct rbnode *right;
	struct rbnode *parent;
	};
struct rbnode* insert_node_rb(struct rbnode*, struct rbnode *root, int data);
void inorder(struct rbnode *root);
void balance_rbtree(struct rbnode *tree, struct rbnode *node);
struct rbnode* left_rotate(struct rbnode *parent, struct rbnode *node);
struct rbnode* right_rotate(struct rbnode *parent, struct rbnode *node);
int calc_height(struct rbnode *root);
struct rbnode* search(struct rbnode *root, int data);
struct rbnode* find_min(struct rbnode *root);
struct rbnode* find_max(struct rbnode *root);
struct rbnode* insert(struct rbnode*, int);
