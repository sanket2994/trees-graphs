#include<stdio.h>
#include<stdlib.h>
#include"prim.h"

int main()
{
	int ch, n,n1,n2,w;
	printf("Enter the size of the graph: ");
	scanf("%d",&n);
	struct graph *graph=NULL;
	graph=create_graph(n);

	do
	{
		printf("\n\n1. insert in graph\n2. make mst \n3.exit\nEnter your choice: ");
		scanf("%d",&ch);
		
		switch(ch)
		{
			case 1: printf("Enter the two nodes to be linked and the weight of link: ");
				scanf("%d%d%d",&n1,&n2,&w);
				insert_graph(graph, n1, n2, w);
				break;
	
			case 2:	prim(graph, n);
				break;
				
			case 3: exit(0);
				break;
			default:printf("Invalid choice");
				break;
		}
	}while(ch!=3);
}
