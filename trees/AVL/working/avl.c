#include"avl.h"
//#include"bst.h"
 int max(int a, int b)
 {
         return (a>b?a:b);
 }
	

struct avlnode* insert_node(struct avlnode* root, int data)
{
	if(root==NULL)
	{
		struct avlnode *tempnode=(struct avlnode*)malloc(sizeof(struct avlnode));
		tempnode->data=data;
		tempnode->left=NULL;
		tempnode->right=NULL;
		
		return tempnode;
	}
	else if(root->data > data)
	{
		root->left=insert_node(root->left, data);
	}
	else
	{	
		root->right=insert_node(root->right, data);
	}
	return root;
	
}

struct avlnode* insert_node_avl(struct avlnode* root, int data)
{
	root=insert_node(root, data);
	if(root==NULL)
	{
		return NULL;
	}
/*	if(root->data > data)
	{
		root->left=balance_tree(root->left, data);
	}
	else if(root->data < data)
	{*/
		root= balance_tree(root, data);
//	}	
	return root;
}

struct avlnode* balance_tree(struct avlnode *root, int data)
{
	
	if(root==NULL)
	{
		return NULL;
	}
	struct avlnode *child, *gchild; 
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
			root=right_left_rotate(root, child, gchild);
		}
		else
		{
			root=left_right_rotate(root, child, gchild);
		}
	}
	return root;
}
			
int calc_diff(struct avlnode *root)
{
	int hleft=calc_height(root->left);
	int hright=calc_height(root->right);
	return abs(hleft - hright);
}

int calc_height(struct avlnode *root)
{
	if(root==NULL)
		return -1;
	int lheight=calc_height(root->left);
	int rheight=calc_height(root->right);
	
	return (max(lheight, rheight)+1);
}

struct avlnode* left_rotate(struct avlnode *root, struct avlnode *child/*, struct avlnode *gchild*/)
{
	root->right=child->left;
	child->left=root;
	return child;
}

struct avlnode* right_rotate(struct avlnode *root, struct avlnode *child/*, struct avlnode *gchild*/)
{
	root->left=child->right;
	child->right=root;
	return child;
}

struct avlnode* right_left_rotate(struct avlnode *root, struct avlnode *child, struct avlnode *gchild)
{
//	root->right=right_rotate(child, gchild);
	child->left=gchild->right;
	gchild->right=child;
	//gchild->
	root->right=gchild->left;
	gchild->left=root;
}

struct avlnode* left_right_rotate(struct avlnode *root, struct avlnode *child, struct avlnode *gchild)
{
	child->right=gchild->left;
	gchild->left=child;
	root->left=gchild->right;
	gchild->right=root;
}

void inorder(struct avlnode *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}

int search(struct avlnode *root, int data)
{
	if(root==NULL)
		return -1;
	if(root->data==data)
	{
		data=calc_height(root);
		return data;
	} 
	if(root->data > data)
	{
		 search(root->left, data);
	}
	else
	{
		 search(root->right, data);
	}
}

