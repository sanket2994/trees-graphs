#include"trees.h"

void inorder(struct node *root)
{
	if(root==NULL)
		return ;
	inorder(root->left);
	printf("%d->", root->data);
	inorder(root->right);
}


void preorder(struct node *root)
{
	if(root==NULL)
		return;
	printf("%d->", root->data);
	preorder(root->left);
	preorder(root->right);
}

void postorder(struct node *root)
{
	if(root==NULL)
		return;
	preorder(root->left);
	preorder(root->right);
	printf("%d->", root->data);
}
