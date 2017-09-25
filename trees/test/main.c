#include<stdio.h>
#include<stdlib.h>
#include "bst.h"

int main()
{
	struct bstnode *root=NULL;
	int data, ch;
	do
	{
		printf("\n\n1. Insert data \n2. Search data \n3. Find smallest \n4. Find largest \n5. Print tree\n6. Exit\nEnter your choice: ");
		scanf(" %d", &ch);
		switch(ch)
		{
			case 1: printf("Enter data to be entered: ");
				scanf("%d", &data);
				root=insert_node(root, data);
				break;
			case 2:	printf("Enter the data to be searched: ");
				scanf("%d", &data);
				struct bstnode *val = search(root, data);
				if(val==NULL)
					printf("Element not found\n");
				else
					printf("Element present at height: %d\n", val->height);
				break;
			case 3:	data = find_min(root);
				printf("The smallest element is: %d\n", data);
				break;
			case 4:	data = find_max(root);
				printf("The largest element is: %d\n", data);
				break;
			case 5: printf("The contents of the tree are: \n");
				inorder(root);
				printf("\n");
				break;
			default:printf("Invalid choice\n"); 
				break;
		}
	}while(ch!=6);
}
