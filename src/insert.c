#include"trees.h"

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
	root= balance_tree_avl(root, data);
	return root;
}

struct node* balance_tree_avl(struct node *root, int data)
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
			root->left = balance_tree_avl(root->left, data);
		}
		else if(root->data < data)
		{
			root->right = balance_tree_avl(root->right, data);
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


struct node* insert_rb(struct node *tree, struct node *root, int data)
{
	if(root==NULL)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		if(root!=tree)
		temp->color=RED;
		else 
		temp->color=BLACK;
		temp->left=temp->right=temp->parent=NULL;
		return temp;
	}
	else if(root->data > data)
	{
		root->left=insert_rb(tree, root->left, data);
		root->left->parent=root;
//		balance_tree(tree, root->left);
	}
	else if(root->data < data)
	{
		root->right=insert_rb(tree, root->right, data);
		root->right->parent=root;
//		balance_tree(tree,root->right);
	}
	return root;
}


struct node *insert_node_rb(struct node *tree, struct node *root, int data)
{
	tree=insert_rb(tree, tree, data);
	root=search(tree, data);
	
	struct node *child;
	child=root;
	root=tree;


/*
void balance_tree( struct node *root, struct node *child)
{*/
	
	struct node *p=NULL, *gp=NULL, *u=NULL;
	while(child!=root && child->parent->color==RED)
	{
	
		p=child->parent;
		gp=p->parent;
		if(gp->left==p && gp->right!=NULL)
			u=gp->right;
		else if(gp->right==p && gp->left!=NULL)	
			u=gp->left;
		else 
			u=NULL;
		if(u!=NULL && u->color==RED)
		{
			p->color=u->color=BLACK;
			gp->color=RED;
			child=gp;
		}
		else 
		{
			if(p==gp->left && child==p->left)
			{
				gp->left=p->right;
				p->right=gp;
				
				int color;
				color=p->color;
				p->color=gp->color;
				gp->color=color;
				
				p->parent=gp->parent;
				gp->parent=p;
				
				child=p;
				p=child->parent;
				if(gp==root)
				{
					root=child;
				}
			}
			else if(p==gp->right && child==p->right)
			{
				gp->right=p->left;
				p->left=gp;
			
				int color;
				color=p->color;
				p->color=gp->color;
				gp->color=color;

				p->parent=gp->parent;
				gp->parent=p;
				child=p;
				p=child->parent;

				if(gp==root)
					root=child;
			}
			
			else if(p==gp->right && child==p->left)
			{
				p->left=child->right;		
				child->right=p;
				gp->right=child->left;
				child->left=gp;
				
				int color;
				color=child->color;
				child->color=gp->color;
				gp->color=color;
				
				p->parent=child;
				child->parent=gp->parent;
				gp->parent=child;
				
			//child=child->parent;
				if(gp==root)
					root=child;
	
			}				
				
			else
			{
				p->right=child->left;
				child->left=p;
				gp->left=child->right;
				child->right=gp;
				
				int color;
				color=child->color;
				child->color=gp->color;
				gp->color=color;
				
				p->parent=child;
				child->parent=gp->parent;
				gp->parent=child;
				
			//	child=child->parent;
				if(gp==root)
					root=child;
			}
		}
		
	}
	root->color=BLACK;
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


