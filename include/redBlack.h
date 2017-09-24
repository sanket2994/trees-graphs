#ifndef __REDBLACK_H_
#define __REDBLACK_H_

#include<stdio.h>
#include<stdlib.h>

#define RED 1
#define BLACK 0

/*node for red Black tree*/
struct rbnode{
	int data;			/*data feild ofnode*/
	enum {black, red} color;	/*color of the node*/
	struct rbnode *left;		/*pointer to left child*/
	struct rbnode *right;		/*pointer to right child*/
	struct rbnode *parent;		/*pointer to parent node*/
	};

/*Inserts a node into red black tree*/
struct rbnode* insert_node_rb(struct rbnode*, struct rbnode *root, int data);
/*
*takes the pointer to the base node (tree), rootand the data to be inserted as an argument.
*returns the base address to the tree
*/

/*Performs inorder traversal of the redback tree*/

void inorder(struct rbnode *root);

/*Balances the redblack tree after insertion of a node*/
void balance_rbtree(struct rbnode *tree, struct rbnode *node);

/*Performs the left roatation*/
struct rbnode* left_rotate(struct rbnode *parent, struct rbnode *node);

/*Performs the right rotation*/
struct rbnode* right_rotate(struct rbnode *parent, struct rbnode *node);

/*Calculates the height of the red blacktree*/
int calc_height(struct rbnode *root);

/*Searches an elemntfrom the redblack tree*/
struct rbnode* search(struct rbnode *root, int data);

/*finds the minimum elemsnt in the red black tree*/
struct rbnode* find_min(struct rbnode *root);

/*finds the maximum element in the redblack tree*/
struct rbnode* find_max(struct rbnode *root);

/*inserts into rb*/
struct rbnode* insert(struct rbnode*, int);


#endif
