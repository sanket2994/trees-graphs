#include"kruskal.h"
int links=0;
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

void insert_graph(struct graph *graph, int n1, int n2, int weight)
{
	struct graph *temp;
	
	temp=graph[n1].link;
	while(temp!=NULL)
	{
		if(temp->node_no==n2 && temp->weight==weight)
		{
			return;
		}
		temp=temp->link;

	}
	
	struct graph *node=(struct graph*)malloc(sizeof(struct graph));
	node->node_no=n2;
	node->link=NULL;
	node->weight=weight;
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
	node2->weight=weight;
	if(graph[n2].link==NULL)
	{
		graph[n2].link=node2;
	}
	else
	{
		node2->link=graph[n2].link;
		graph[n2].link=node2;
	}
	links++;
}


void kruskal(struct graph *graph, int n)
{
	int i, j=0;
	struct span *arr = (struct span *)malloc(sizeof(struct span)*links);
	struct graph *node;
	for(i=0; i<n; i++)
	{
		node=graph[i].link;
		while(node!=NULL)
		{
			if(node->node_no >=graph[i].node_no)
			{
				arr[j].src=graph[i].node_no;
				arr[j].dst=node->node_no;
				arr[j].weight=node->weight;
				j++;
			}
		node=node->link;
		}
	}

	sort_array(arr, links);
	make_tree(arr, n);
}

void make_tree(struct span *arr, int n)
{
	int i;
	struct graph *graph = (struct graph*)malloc(sizeof(struct graph)*n);
	for(i=0;i<n;i++)
	{
		graph[i].node_no=i;
		graph[i].link=NULL;
	}
	for(i=0;i<links;i++)
	{
		struct graph *node=(struct graph*)malloc(sizeof(struct graph));
		struct graph *node2=(struct graph*)malloc(sizeof(struct graph));
		node->node_no=arr[i].dst;
		node2->node_no=arr[i].src;
		node->weight=node2->weight=arr[i].weight;
	/*	if(graph[src].link==NULL)
		{
			graph[arr[i].src].link=node;
	//		graph[dst].link=node2;
		}*/
	/*	else
		{*/
			int ret=check_loop(graph, arr[i]);
			if(ret==0)
			{
				node->link=graph[arr[i].src].link;
				graph[arr[i].src].link=node;
				node2->link=graph[arr[i].dst].link;
				graph[arr[i].dst].link=node2;
			}
	/*	}
		
		if(graph[src].link==NULL)
		{
			graph[dst].link=node2;
		}
	*/	
	}
	print_tree(graph, n);
}

int check_loop(struct graph *graph, struct span arr)
{
	struct graph *next, *check;
	next=graph[arr.src].link;
	int dest=arr.dst;
	int temp;//=next->node_no;
	int src=arr.src;
	int flag=0;
	while(next!=NULL)
	{
		temp=next->node_no;

		if(next->node_no==dest)
			return 1;
			
		check=graph[temp].link;
		while(check!=NULL)
		{
			if(check->node_no==dest)
				return 1;
			
			check=check->link;
		}
		next=next->link;
		}
	return 0;
}
		
		
		
	
	

void sort_array(struct span *arr, int n)
{
	int i, j;
	for(i=0;i<n;i++)
	{
		for(j=i+1;j<n;j++)
		{
			if(arr[i].weight > arr[j].weight)
			{
				struct span temp;
				temp.src = arr[i].src;
				temp.dst = arr[i].dst;
				temp.weight=arr[i].weight;

				arr[i].weight=arr[j].weight;
				arr[i].src=arr[j].src;
				arr[i].dst=arr[j].dst;
			
				arr[j].src=temp.src;
				arr[j].dst=temp.dst;
				arr[j].weight=temp.weight;
			}
		}
	}
}

void print_tree(struct graph *graph, int n)
{
	int i;
	struct graph *print;
	for(i=0;i<n;i++)
	{
		printf("The links at %d node are: ", graph[i].node_no);
		print=graph[i].link;
		while(print!=NULL)
		{
			printf("%d(%d)->", print->node_no, print->weight);
			print=print->link;
		}
		printf("\n");	
	}
}





	
		












		
