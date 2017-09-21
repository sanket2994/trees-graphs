#include<stdio.h>
#include<stdlib.h>
#include"kruskal.h"

int main()
{
	int n,n1, n2, ch, w;
	struct graph *graph=NULL;
	printf("Enter the maximum nodes in the graph: ");
	scanf("%d", &n);
	graph=create_graph(graph, n);
	do
	{
		printf("\n\n1. insert\n2. display path\n3. make tree\n4. exit \nEnter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the nodes in which link to be inserted and weight between them : ");
				scanf("%d%d%d", &n1, &n2, &w);
				insert_graph(graph, n1, n2, w);
				break;
			case 2: printf("Enter the nodes to find if conected: ");
				scanf("%d%d", &n1, &n1);
				break;
			case 3: kruskal(graph, n);
				break;
			case 4: exit(0);
			
			default:printf("Invalid choice");
				break;
		}
	}while(ch!=4);
}

