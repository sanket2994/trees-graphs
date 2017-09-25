#include "trees.h"
/*Function to delete a node from BST*/
struct node* delete_node_bst(struct node *root, int data)
{
	if(root==NULL)
		return NULL;
	/*If node data is grater than data then go left*/
	if(root->data > data)
	{
		root->left= delete_node_bst(root->left, data);

	}
	/*If node data is less than data then go right*/
	else if(root->data < data)
	{
		root->right= delete_node_bst(root->right, data);

	}
	/*if the node to be deleted is found*/
	else
	{
		/*If the left side of the node is empty*/
		if(root->left==NULL)
		{
			struct node *temp = root->right;
			free(root);
			return temp;
		}
		/*IF the right side of the node is empty*/
		else if(root->right==NULL)
		{
			struct node *temp = root->left;
			free(root);
			return temp;
		}
		/*If both the nodes are present*/
		else
		{
			struct node *temp = find_min(root->right);
			root->data = temp->data;
			root->right = delete_node_bst(root->right, temp->data);
		}
	}
	return root;
}
	
/*Delete a node from an AVL tree*/
struct node* delete_node_avl(struct node *root, int data)
{
	/*this part is same as BST delete*/
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
	/*If after deleteion the tree becomes unbalanced*/
	if(root==NULL)
		return root;	
	if(calc_diff(root)>1)
	{
		/*left-left case*/
		if (calc_diff(root->left)>=0)
		{
			root=right_rotate(root, root->left);
			return root;
		}
		/*right - right case*/
		else if(calc_diff(root->right)<=0)
		{
			root=left_rotate(root, root->right);
			return root;
		}
		/*left-right case*/
		else if(calc_diff(root->left)<0)
		{
			root->left=left_rotate(root->left, root->left->right);
			root=right_rotate(root, root->left);
			return root;
		}
		/*right-left case*/
		else if(calc_diff(root->right)>0)
		{
			root->right=right_rotate(root->right, root->right->left);
			root=left_rotate(root, root->right);
			return root;
		}
	}
	return root;
}


