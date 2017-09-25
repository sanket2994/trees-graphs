#include<stdio.h>
#include<stdlib.h>
#include"trees.h"

int main()
{
	int ch, data;
	struct node *temp, *root=NULL;
	
	do
	{
		printf("\n\n1. Insert node\n2. Print Height\n3. print tree\n4. Find Maximum \n5. Find Minimum\n6. Delete Node\n7. Exit\n\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1:	printf("Enter the data: ");
				scanf("%d", &data);
				root=insert_node_avl(root, data);
				break;

			case 2:	printf("Enter the data to find height: ");
				scanf("%d", &data);
				temp=search(root, data);
				printf("The root is at: %d\n", calc_height(temp));
				break;

			case 3: printf("\nThe avl tree is: \n");
				inorder(root);
				break;
			
			case 4: temp= find_max(root);
				printf("The maximum element is: %d\n", temp->data);
				break;
			
			case 5: temp=find_min(root);
				printf("The minimum element is: %d\n", temp->data);
				break;

			case 6:	printf("Enter the number you want to delete: ");	
				scanf("%d", &data);
				root = delete_node_avl(root, data);
				//root=balance_tree(root, data);
				break;		

			case 7:	exit(0);
				break;

			default:printf("invalid choice\n");
				break;
		}
	}while(ch!=7);
}
