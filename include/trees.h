#ifndef __TREE_H
#define __TREE_H

#include<stdio.h>
#include<stdlib.h>
#include<math.h>

#define RED 1
#define BLACK 0


/*Node of a tree works for both avl and bst*/
struct node{
	int data;			/*data feild of node*/
	struct node *left;		/*pointer to left child*/
	struct node *right;		/*pointer to right child*/
	struct node *parent;		/*pointer to the parent */
	enum {black, red} color;
	};

/*Function to insert a node in BST*/
struct node* insert_node(struct node*, int);
/*
*This functions inserts an entry into a BST. 
*Takes the data and a pointer to the root node as an argument.
*It returns a pointer to a structure which points to the root node of the BST.
*/

/*Function to insert a node into AVL tree*/
struct node* insert_node_avl(struct node* ,int);
/*
*This function internally calls the above function i.e. insert_node
*After calling this function it balances the tree so that it follows the AVL property.
*It takes data to be inserted as an argument and a pointer to a root node as an argument.
*/

/*Function to insert node into redblack tree*/
struct node* insert_node_rb(struct node *tree, struct node *root, int data);
/*
*Takes the pointer to the root of the tree, pointer to the parent and data as an argument
*Returns the pointer to the tree i.e. pointer to the root of the tree
*also balances the tree after a new node hash been inserted
*/

/*Inserts the node into an rb*/
struct node* insert_rb(struct node *tree, struct node *root, int data);
/*
*internally called by the above function to insert a new node into the tree
*returns a pointer to the base(root) node of the tree
*/

/*Function to search for an entry into the tree*/
struct node* search(struct node*, int);
/*
*It takes data to be searched as an argument and a pointer to the root node as an argument.
*It returns the address pointer od the node where the data is found.
*/

/*Right shift the nodes to balance the tree*/
struct node* right_shift(struct node*, struct node*);
/*
*this function takes the pointer of two nodes between which the shift takes pplace as an argument.
*/

/*Left shift the nodes to bal;ance the tree*/
struct node* left_shift(struct node*, struct node*);

/*Find the minimum element in the tree*/
struct node* find_min(struct node*);

/*Find the maximum element in the tree*/
struct node* find_max(struct node*);

/*Print the inorder traversal of the tree*/
void inorder(struct node*);

/*Used to abalance the tree*/
struct node* balance_tree_avl(struct node*, int);
/*
*Called internally by insert_node_avl.
*takes the address of the root node as the argument and then balances the tree if necessary,
*by performing the single shift or double shift operations as required.
*/

/**/
void balance_tree_rb(struct node *root, struct node *child);
/*Calculates the diffrences in the heights of the left sub tree ans right subtree*/
int calc_diff(struct node*);

/*Calculates the height of the node*/
int calc_height(struct node*);

/*Performs left side rotation of the nodes*/
struct node* left_rotate(struct node*, struct node*);

/*Performs the right side rotation of the nodes*/
struct node* right_rotate(struct node*, struct node*);


/*deletes a node from a BST*/
struct node* delete_node_bst(struct node*, int);

/*deletes a node from the AVL tree*/
struct node* delete_node_avl(struct node*, int);


#endif
