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
	else if(root->data < data)
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
	root= balance_tree(root, data);
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
			
int calc_diff(struct avlnode *root)
{
	if(root==NULL)
		return -1;
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

void inorder(struct avlnode *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}

struct avlnode* search(struct avlnode *root, int data)
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


struct avlnode* find_min(struct avlnode* root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

struct avlnode* find_max(struct avlnode* root)
{
	if(root==NULL)
		return NULL;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}


struct avlnode* delete_node(struct avlnode *root, int data)
{
	if(root==NULL)
		return NULL;
	if(root->data > data)
	{
		root->left= delete_node(root->left, data);

	}
	else if(root->data < data)
	{
		root->right= delete_node(root->right, data);

	}
	else
	{
		if(root->left==NULL)
		{
			struct avlnode *temp = root->right;
			free(root);
			return temp;
		}
		else if(root->right==NULL)
		{
			struct avlnode *temp = root->left;
			free(root);
			return temp;
		}
		else
		{
			struct avlnode *temp = find_min(root->right);
			root->data = temp->data;
			root->right = delete_node(root->right, temp->data);
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


