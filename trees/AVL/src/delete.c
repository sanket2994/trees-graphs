#include "avl.h"

struct node* delete_node_bst(struct node *root, int data)
{
	if(root==NULL)
		return NULL;
	if(root->data > data)
	{
		root->left= delete_node_bst(root->left, data);

	}
	else if(root->data < data)
	{
		root->right= delete_node_bst(root->right, data);

	}
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node *temp = find_min(root->right);
			root->data = temp->data;
			root->right = delete_node_bst(root->right, temp->data);
		}
	}
	return root;
}
	
struct node* delete_node_avl(struct node *root, int data)
{
	if(root==NULL)
		return NULL;
	if(root->data > data)
	{
		root->left= delete_node_avl(root->left, data);

	}
	else if(root->data < data)
	{
		root->right= delete_node_avl(root->right, data);

	}
	else
	{
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct node *temp = find_min(root->right);
			root->data = temp->data;
			root->right = delete_node_avl(root->right, temp->data);
		}
	}
	
	if(root==NULL)
		return root;	
	if(calc_diff(root)>1)
	{
		if (calc_diff(root->left)>=0)
		{
			root=right_rotate(root, root->left);
			return root;
		}
		else if(calc_diff(root->right)<=0)
		{
			root=left_rotate(root, root->right);
			return root;
		}
		else if(calc_diff(root->left)<0)
		{
			root->left=left_rotate(root->left, root->left->right);
			root=right_rotate(root, root->left);
			return root;
		}
		else if(calc_diff(root->right)>0)
		{
			root->right=right_rotate(root->right, root->right->left);
			root=left_rotate(root, root->right);
			return root;
		}
	}
	return root;
}


