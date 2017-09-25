#include "avl.h"

struct node* search(struct node *root, int data)
{
	if(root==NULL)
		return NULL;
	if(root->data==data)
	{
		calc_height(root);
		return root;
	} 
	if(root->data > data)
	{
		root= search(root->left, data);
	}
	else
	{
		 root=search(root->right, data);
	}
	return root;
}


struct node* find_min(struct node* root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

struct node* find_max(struct node* root)
{
	if(root==NULL)
		return NULL;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}


