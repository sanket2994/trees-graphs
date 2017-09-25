
#include"bst.h"


struct bstnode* insert_node(struct bstnode* root, void* data)
{
	int *k_node, *k_data;
	k_node=(int*)key(root->data);
	k_data=(int*)key(data);
	if(root==NULL)
	{
		struct bstnode *tempnode=(struct bstnode*)malloc(sizeof(struct bstnode));
		tempnode->data=data;
		tempnode->left=NULL;
		tempnode->right=NULL;
	
		return tempnode;
	}
	else if(*k_node > *k_data)
	{
		root->left=insert_node(root->left, data);
	}
	else
	{	
		root->right=insert_node(root->right, data);
	}
	return root;
	
}

/*struct bstnode* search(struct bstnode *root, int data)
{
	if(root==NULL)
	{
		return NULL;
	}
	if(root->data ==data)
	{
		return root;
	}
	else if(data > root->data)
	{
		search(root->right, data);
	}
	else
	{
		search(root->left, data);
	}
}
*/
int find_min(struct bstnode *root)
{
	if(root==NULL)
	{
		return 0;
	}
	while(root->left!=NULL)
	{
		root=root->left;
	}
	int *data= root->data;
	return *data;
}


int find_max(struct bstnode *root)
{
	if(root==NULL)
	{
		return 0;
	}
	while(root->right!=NULL)
	{
		root=root->right;
	}
	int *data=root->data;
	return *data;
}


void inorder(struct bstnode *root)
{
	if(root==NULL)
		return;
	inorder(root->left);
	int *data=(int*)root->data;
	printf("%d->", *data);
	inorder(root->right);
}



