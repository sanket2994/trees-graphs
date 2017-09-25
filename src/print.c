#include"trees.h"
/*Print tree using inorder traversal*/
/*Left ->parent ->right*/
void inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}

/*Print tree using pre order traversal*/
/*parent->left->right*/
void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d->", root->data);
	preorder(root->left);
	preorder(root->right);
}

/*Print tree using post order traversal*/
/*Left ->right->parent*/
void postorder(struct node *root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	preorder(root->right);
	printf("%d->", root->data);
}
