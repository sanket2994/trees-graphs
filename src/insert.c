#include"trees.h"

 int max(int a, int b)
 {
         return (a>b?a:b);
 }
	
/*Insert a node in BST tree*/
struct node* insert_node(struct node* root, int data)
{
	/*If the node is empty*/
	if(root==NULL)
	{
		struct node *tempnode=(struct node*)malloc(sizeof(struct node));
		tempnode->data=data;
		tempnode->left=NULL;
		tempnode->right=NULL;
		
		return tempnode;
	}
	/*If root data is greater than data go left*/
	else if(root->data > data)
	{
		root->left=insert_node(root->left, data);
	}
	/*IF root data is less than data go right*/
	else if(root->data < data)
	{	
		root->right=insert_node(root->right, data);
	}
	return root;
	
}
/*Avl insertion*/
struct node* insert_node_avl(struct node* root, int data)
{
	if(root==NULL)
	{
		struct node *tempnode = (struct node*)malloc(sizeof(struct node));
		tempnode->data=data;
		tempnode->left=NULL;
		tempnode->right=NULL;
		return tempnode;
	}	
	
	else if(root->data < data)
	{
		root->right=insert_node_avl(root->right, data);
		root=balance_tree_avl(root,data);
	}
	else if(root->data > data)
	{
		root->left=insert_node_avl(root->left, data);
		root=balance_tree_avl(root, data);
	}
	return root;
}

/*Balnce tree function*/
struct node* balance_tree_avl(struct node *root, int data)
{
	
	if(root==NULL)
	{
		return NULL;
	}
	struct node *child, *gchild; 
	/*Check is diffrence in height of left sub tree and righ tsub tree is less than or equql to 1*/
	if(calc_diff(root) > 1)
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
		/*left-left case*/
		if(gchild == child->left && child == root->left)
		{	
			root=right_rotate(root, child);
		}
		/*right-right case*/
		else if(gchild == child->right && child == root->right)
		{
			root=left_rotate(root, child);
		}
		/*right - left case*/
		else if(gchild == child->left && child == root->right)
		{
			root->right=right_rotate(child, gchild);
			root=left_rotate(root, root->right);
		}
		/*left-right case*/
		else
		{
			root->left=left_rotate(child, gchild);
			root=right_rotate(root, root->left);

		}
	}
	return root;
}




/*Insert a node in red Black tree*/
struct node* insert_rb(struct node *tree, struct node *root, int data)
{
	if(root==NULL)
	{
		struct node *temp=(struct node*)malloc(sizeof(struct node));
		temp->data=data;
		/*If the node inserted is not root than color is red*/
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

	}
	else if(root->data < data)
	{
		root->right=insert_rb(tree, root->right, data);
		root->right->parent=root;

	}
	return root;
}


struct node *insert_node_rb(struct node *tree, struct node *root, int data)
{
	/*Normal BST insertiom*/
	tree=insert_rb(tree, tree, data);
	root=search(tree, data);
	
	struct node *child;
	child=root;
	root=tree;


	/*Balancing the tree if any violations*/	
	struct node *p=NULL, *gp=NULL, *u=NULL; 	/*p = parent node gp=grandparent u=uncle*/
	while(child!=root && child->parent->color==RED)
	{
	
		p=child->parent;
		gp=p->parent;
		/*Assign uncle node*/
		if(gp->left==p && gp->right!=NULL)
			u=gp->right;
		else if(gp->right==p && gp->left!=NULL)	
			u=gp->left;
		else 
			u=NULL;
		/*If uncle is red assign uncle and parent as Black and grandparent as red and keep going up the tree to balance the tree*/
		if(u!=NULL && u->color==RED)
		{
			p->color=u->color=BLACK;
			gp->color=RED;
			child=gp;
		}
		/*If uncle is black and parent is red than balance the tree*/
		else 
		{
			/*left - left case*/
			if(p==gp->left && child==p->left)
			{
				gp->left=p->right;
				p->right=gp;
				/*interchange color*/
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
			/*right - right case*/
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
			/*right-left case*/
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
				
				if(gp==root)
					root=child;
	
			}				
			/*left-right case*/	
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
				
				if(gp==root)
					root=child;
			}
		}
		
	}
	root->color=BLACK;
	return root;
}			


/*Calculate the diffrence between left sub tree and right sub tree*/
int calc_diff(struct node *root)
{
	if(root==NULL)
		return -1;
	int hleft=calc_height(root->left);
	int hright=calc_height(root->right);
	return abs(hleft - hright);
}

/*Calculate the height of the node*/
int calc_height(struct node *root)
{
	if(root==NULL)
		return -1;
	int lheight=calc_height(root->left);
	int rheight=calc_height(root->right);
	
	return (max(lheight, rheight)+1);
}

/*Function for left rotation*/
struct node* left_rotate(struct node *root, struct node *child)
{
	root->right=child->left;
	child->left=root;
	return child;
}

/*function for right rotation*/
struct node* right_rotate(struct node *root, struct node *child)
{
	root->left=child->right;
	child->right=root;
	return child;
}


