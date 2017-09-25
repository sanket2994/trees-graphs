#include<stdio.h>
#include<stdlib.h>
#define RED 1
#define BLACK 0
struct node {
	int data;
	struct node *left, *right, *parent;
	enum {black, red} color;
	};

int max(int a, int b);
void balance_tree( struct node *root, struct node *child);

struct node* insert_node(struct node *tree, struct node *root, int data);

void inorder(struct node *root);
int calc_height(struct node *root);
struct node* search(struct node *root, int data);
struct node* find_min(struct node* root);
struct node* find_max(struct node* root);












