#include<stdio.h>
#include<stdlib.h>

struct graph{
	int node_no;
	int ndata;
	struct graph *link;
	};
/*
struct node {
	int data;
	struct node *link;
	};*/
struct graph* create_graph(struct graph *graph, int n);
void insert_graph(struct graph *graph, int n, int n1);
void display_path(struct graph *graph, int n, int n1);


int main()
{
	int n, ch, n1, n2;
	printf("Enter the number of nodes : ");
	scanf("%d", &n);
	struct graph *graph=create_graph(graph, n);
	do
	{
		printf("\n\n1. Enter a link\n2. display path \n3. Exit\n Enter choice: ");
		scanf("%d", &ch);
		switch(ch)
		{
			case 1: printf("Enter the two nodes: ");
				scanf("%d%d", &n1, &n2);
				insert_graph(graph, n1, n2);
				break;

			case 2: printf("Enter nodes: ");
				scanf("%d%d", &n1, &n2);
				display_path(graph, n1, n2);
				break;

			case 3: exit(0);
				break;
			
			default: printf("Invalid choice");
				break;
		}

	}while(ch!=3);
}



struct graph* create_graph(struct graph *graph, int n)
{
	int i;
	struct graph *temp=(struct graph*)malloc(sizeof(struct graph)*n);
	for(i=0; i<n; i++)
	{
		temp[i].node_no=i;
		temp[i].link=NULL;
	}
	return temp;
}

void insert_graph(struct graph *graph, int n1, int n2)
{
	struct graph *temp;
	struct graph *node=(struct graph*)malloc(sizeof(struct graph));
	node->node_no=n2;
	node->link=NULL;
	if(graph[n1].link==NULL)
	{
		graph[n1].link=node;
	}
	else 
	{
		node->link=graph[n1].link;
		graph[n1].link=node;
	}
	
	struct graph *node2=(struct graph*)malloc(sizeof(struct graph));
	node2->node_no=n1;
	node2->link=NULL;
	if(graph[n2].link==NULL)
	{
		graph[n2].link=node2;
	}
	else
	{
		node2->link=graph[n2].link;
		graph[n2].link=node2;
	}
}


		
void display_path(struct graph *graph, int n1, int n2)
{
	if(graph[n1].link==NULL)
	{
		printf("No link");
		return;
	}
	struct graph *node=&graph[n1];

	while(node->link!=NULL && node->node_no!=n2)
	{
		node=node->link;
	}
	if(node->node_no==n2)
	{
		printf("Link present\n");
		return;
	}
	printf("Link not present\n");
	return;
} 
	
	











