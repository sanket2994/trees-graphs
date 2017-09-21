#include"tree.h"

int max(int a, int b)
{
	return (a>b?a:b);
}


struct node* insert(struct node *tree, struct node *root, int data)
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
		root->left=insert(tree, root->left, data);
		root->left->parent=root;
//		balance_tree(tree, root->left);
	}
	else if(root->data < data)
	{
		root->right=insert(tree, root->right, data);
		root->right->parent=root;
//		balance_tree(tree,root->right);
	}
	return root;
}


struct node *insert_node(struct node *tree, struct node *root, int data)
{
	tree=insert(tree, tree, data);
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
				

void inorder(struct node *root)
{
	if(root==NULL)
		return;
	inorder(root->left);		
	printf("%d->", root->data);
	inorder(root->right);
}

int calc_height(struct node *root)
{
	if(root==NULL)
		return -1;
	int lheight=calc_height(root->left);
	int rheight=calc_height(root->right);
	
	return (max(lheight, rheight)+1);
}

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















