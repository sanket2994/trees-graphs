#include "trees.h"
/*Search in a tree*/
struct node* search(struct node *root, int data)
{
	if(root==NULL)
		return NULL;
	/*If data found than return the node*/
	if(root->data==data)
	{
		calc_height(root);
		return root;
	} 
	/*If data less than the node data search in left sub tree*/
	if(root->data > data)
	{
		root= search(root->left, data);
	}
	/*If data greater than the node data search in right sub tree*/
	else
	{
		 root=search(root->right, data);
	}
	return root;
}

/*Find the minimum element in tree i.e. the leftmost element in tree */
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

/*Find the maximum element in the tree i.e. the right most elemant in  tree*/
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


