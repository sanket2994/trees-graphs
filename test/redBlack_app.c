#include<stdio.h>
#include"trees.h"


int main()
{
	int ch, data;
	struct node *tree=NULL, *temp;
	do
	{
		printf("\n\n1. insert\n2. calc height\n3. print\n4. EXIT \nEnter your choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter data to insert: ");
				scanf("%d", &data);
				tree=insert_node_rb(tree, tree, data);
				break;
			
			case 2:	printf("Enter node whose height to be found: ");
				scanf("%d", &data);
				temp=search(tree, data);
				printf("Thr height is: %d\n", calc_height(temp));
				break;
			
			case 3: printf("The inorder traversal is: ");
				inorder(tree);
				printf("\n");
				break;
			
			case 4:	exit(0);
				break;
			default:printf("Invalid choice");
				break;
		}
	}while(ch!=4);
}
