#include"redBlack.h"
int max(int a, int b)
{
	return (a>b ? a : b);
}


struct rbnode* insert_node_rb(struct rbnode *tree, struct rbnode *root, int data)
{
	if(root==NULL)
	{
		struct rbnode *temp=(struct rbnode*)malloc(sizeof(struct rbnode));
		temp->data=data;
		temp->right=temp->left=temp->parent=NULL;
		if(root!=tree)
		temp->color=RED;
		else
		temp->color=BLACK;
		return temp;
	}
	struct rbnode *rbnode;	
	if(root->data > data)
	{
		root->left=insert_node_rb(tree, root->left, data);
		root->left->parent=root;
		//rbnode=root->left;
		//rbnode= balance_rbtree(tree, rbnode);
	}
	else if(root->data < data)
	{
		root->right=insert_node_rb(tree, root->right, data);
		root->right->parent=root;
		//rbnode=root->right;
		//rbnode = balance_rbtree(tree, rbnode);
	}
	return root;
}

struct rbnode* insert(struct rbnode *tree, int data)
{
	tree=insert_node_rb(tree, tree, data);
	struct rbnode *parent, *gparent, *uncle;

	struct rbnode *root=search(tree, data);
/*	balance_rbtree(tree, root);
	return tree;
}
void  balance_rbtree(struct rbnode *tree, struct rbnode *root)
{*/
	if(root!=tree&&root->parent->parent!=NULL){
	parent= root->parent;
	gparent=parent->parent;

	if(gparent->left==parent && gparent->right!=NULL)
		uncle=gparent->right;
	else if(gparent->right==parent && gparent->right!=NULL)
		uncle=gparent->left;
	else
		uncle==NULL;
	
	while(parent->color==RED)
	{
		if(uncle!=NULL && uncle->color==RED)
		{
			uncle->color=parent->color=BLACK;
			gparent->color=RED;
			root=gparent;
			
		}
		else
		{
			if(parent==gparent->left && root==parent->left)
			{
				gparent->left=parent->right;
				parent->right=gparent;
				int color;
				color=parent->color;
				parent->color=gparent->color;
				gparent->color=color;
				parent->parent=parent->right->parent;
				parent->right->parent=parent;
				
			}
			else if(parent==gparent->right && root==parent->right)
			{
				gparent->right=parent->left;
				parent->left=gparent;
				int color;
				color=parent->color;
				parent->color=gparent->color;
				gparent->color=color;
				parent->parent=parent->left->parent;
				parent->left->parent=parent;
				
			}
			else if(parent==gparent->left && root==parent->right)
			{
				parent->right=root->left;
				root->left=parent;
				gparent->left=root;
				
				root->parent=gparent;
				parent->parent=root;
				
				gparent->left=root->right;
				root->right=gparent;
				int color;
				color=root->color;
				root->color=gparent->color;
				gparent->color=color;
				
			}
			else
			{
				parent->left=root->right;
				root->right=parent;
				gparent->right=root;
				
				root->parent=gparent;
				parent->parent=root;
			
				gparent->right=root->left;
				root->left=gparent;
				int color;
				color=root->color;
				root->color=gparent->color;
				gparent->color=color;
				
			}
			
			
		}
	
			
	}
	}

	tree->color=BLACK;

}

/*struct rbnode* balance_rbtree(struct rbnode *tree, struct rbnode *rbnode)
{
	if(tree==rbnode )
	{
		rbnode->color=BLACK;
		return rbnode;
	}
	if(rbnode->parent->parent==NULL)
		return rbnode;

	struct rbnode *parent, *gparent, *uncle;
	parent=rbnode->parent;
	gparent=rbnode->parent->parent;

	if(gparent->left==parent && gparent->right!=NULL)
		uncle=gparent->right;
	else if(gparent->right==parent && gparent->left!=NULL)
		uncle=gparent->left;
	else
		uncle=NULL;
	if(parent->color==RED && tree!=rbnode)
	{
		if(uncle!=NULL && uncle->color==RED )
		{
			parent->color=uncle->color=BLACK;
			gparent->color=RED;
			gparent= balance_rbtree(tree, gparent);
			return rbnode;
		}
		else
		{
			if(parent->left==rbnode && gparent->left==parent )
			{
				parent= right_rotate(gparent, parent);
				int color;
				gparent=parent;
				parent= rbnode;
				
				color= gparent->color;
				gparent->color=gparent->left->color;
				gparent->left->color=color;
				return parent;
			}
			else if(parent->right==rbnode && gparent->right==parent)
			{
				parent= left_rotate(gparent, parent);
				//parent= balance_rbtree(tree, parent);
				int color;
				gparent=parent;
				parent= rbnode;
	
				color= gparent->color;		
				gparent->color=gparent->right->color;
				gparent->right->color=color;
				return parent;
			}
			else if(rbnode ==parent->left && parent == gparent->right)
			{
				parent=right_rotate(parent, rbnode);
				parent=left_rotate(gparent, parent);
			//	gparent=balance_rbtree(tree, gparent);
				int color;
				gparent=parent;
				parent=parent->right;		
				gparent->color=gparent->right->color;
				gparent->right->color=color;

				return parent;
			}
			else if(rbnode == parent->right && parent == gparent->left)
			{
				parent = left_rotate(parent, rbnode);
				parent = right_rotate(gparent, parent);
		//		gparent=balance_rbtree(tree, gparent);
				gparent=parent;
				parent=parent->left;
				int color;
				parent->color=parent->right->color;
				parent->right->color=color;

				return gparent;	
			}
		}
	}
}*/

void inorder(struct rbnode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);		
	printf("%d->", root->data);
	inorder(root->right);
}

int calc_height(struct rbnode *root)
{
	if(root==NULL)
		return -1;
	int lheight=calc_height(root->left);
	int rheight=calc_height(root->right);
	
	return (max(lheight, rheight)+1);
}

struct rbnode* left_rotate(struct rbnode *root, struct rbnode *child)
{
	root->right=child->left;
	child->left=root;
	return child;
}

struct rbnode* right_rotate(struct rbnode *root, struct rbnode *child)
{
	root->left=child->right;
	child->right=root;
	return child;
}

struct rbnode* search(struct rbnode *root, int data)
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


struct rbnode* find_min(struct rbnode* root)
{
	if(root==NULL)
		return NULL;
	while(root->left!=NULL)
	{
		root=root->left;
	}
	return root;
}

struct rbnode* find_max(struct rbnode* root)
{
	if(root==NULL)
		return NULL;
	while(root->right!=NULL)
	{
		root=root->right;
	}
	return root;
}


