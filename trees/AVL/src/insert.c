#include"avl.h"

 int max(int a, int b)
 {
         return (a>b?a:b);
 }
	

struct node* insert_node(struct node* root, int data)
{
	if(root==NULL)
	{
		struct node *tempnode=(struct node*)malloc(sizeof(struct node));
		tempnode->data=data;
		tempnode->left=NULL;
		tempnode->right=NULL;
		
		return tempnode;
	}
	else if(root->data > data)
	{
		root->left=insert_node(root->left, data);
	}
	else if(root->data < data)
	{	
		root->right=insert_node(root->right, data);
	}
	return root;
	
}

struct node* insert_node_avl(struct node* root, int data)
{
	root=insert_node(root, data);
	if(root==NULL)
	{
		return NULL;
	}
	root= balance_tree(root, data);
	return root;
}

struct node* balance_tree(struct node *root, int data)
{
	
	if(root==NULL)
	{
		return NULL;
	}
	struct node *child, *gchild; 
	if(calc_diff(root) <= 1)
	{
		if(root->data > data)
		{
			root->left = balance_tree(root->left, data);
		}
		else if(root->data < data)
		{
			root->right = balance_tree(root->right, data);
		}
	}
	else
	{
		if(root->data > data)
		{
			child=root->left;
			if(child->data > data)
			gchild = child->left;
			else
			gchild = child->right;
		}
		else if(root->data < data)
		{
			child=root->right;
			if(child->data > data)
			gchild = child->left;
			else
			gchild = child->right;
		}
		
		if(gchild == child->left && child == root->left)
		{	
			root=right_rotate(root, child);
		}
		else if(gchild == child->right && child == root->right)
		{
			root=left_rotate(root, child);
		}
		else if(gchild == child->left && child == root->right)
		{
			root->right=right_rotate(child, gchild);
			root=left_rotate(root, root->right);

		}
		else
		{
			root->left=left_rotate(child, gchild);
			root=right_rotate(root, root->left);

		}
	}
	return root;
}
			
int calc_diff(struct node *root)
{
	if(root==NULL)
		return -1;
	int hleft=calc_height(root->left);
	int hright=calc_height(root->right);
	return abs(hleft - hright);
}

int calc_height(struct node *root)
{
	if(root==NULL)
		return -1;
	int lheight=calc_height(root->left);
	int rheight=calc_height(root->right);
	
	return (max(lheight, rheight)+1);
}

struct node* left_rotate(struct node *root, struct node *child)
{
	root->right=child->left;
	child->left=root;
	return child;
}

struct node* right_rotate(struct node *root, struct node *child)
{
	root->left=child->right;
	child->right=root;
	return child;
}


