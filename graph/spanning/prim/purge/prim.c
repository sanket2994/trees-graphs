#include"prim.h"


int links=0;
struct graph* create_graph(int n)
{
	struct graph *graph=(struct graph *)calloc(n, sizeof(struct graph));
	return graph;
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
	
	struct graph *node=(struct graph*)calloc(1, sizeof(struct graph));
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
	
	struct graph *node2=(struct graph*)calloc(1, sizeof(struct graph));
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

/*
void prim(struct graph *graph, int n)
{
	unsigned int *map_arr=(int*)calloc(n, sizeof(int)); //input graph with elements infinity;
	int i, index, dest, small;
	map_arr[0]=0;
	for(i=1;i<n;i++)
	{
		map_arr[i]=INFINITY;
	}
	
	struct span *mst_arr=(struct span*)calloc(n-1, sizeof(struct span));
	for(i=0;i<n-1;i++)
	{
			index=find_min(map_arr);
			temp=graph[index].link;
			small=temp->weight;
			while(temp!=NULL)
			{
				if(small > temp->weight)
				{
					small=temp->weight;
					dest=temp->node_no;
				}
				if(temp->node_no > graph[index].node_no && map_arr[index] > temp->weight)
				{
					map_arr[index]=temp->weight;
					//dest=temp->node_no;
				}
				temp=temp->node;
			}
			mst_arr[i].weight=small;
			mst_arr[i].src=index;
			mst_arr[i].dest=dest;
	}
	
*/

void prim(struct graph *graph, int n)
{

	struct span *heap_arr=(struct span*)calloc(n, sizeof(struct span));
	build_heap(heap_arr, n);
	int  heapsize=n, i, index, heapIndex;
	struct mst *result=(struct mst*)calloc(n, sizeof(struct mst));
	struct graph *temp;
	heap_arr[0].weight=0;
	heap_arr[0].src=0;
	heap_arr[0].dest=-1;
	for(i=1;i<n;i++)
	{
		heap_arr[i].src=i;
		heap_arr[i].weight=INFINITY;
		heap_arr[i].dest=-1;
	}
	while(heapsize!=0)
	{
		build_heap(heap_arr, heapsize);
		index= find_min_heap(heap_arr, heapsize);
		heapsize--;
				//heapify(heap_arr, heapsize);
		temp=graph[index].link;
		while(temp!=NULL)
		{
			heapIndex=find_index(heap_arr, heapsize, temp->node_no);
			if(heapIndex!=-1 && temp->weight < heap_arr[heapIndex].weight )
			{
				heap_arr[heapIndex].weight=temp->weight;
				result[temp->node_no].src=index;
				result[temp->node_no].weight=temp->weight;
			}
			temp=temp->link;
		}
	}
	print_prim_mst(result, n);
}


void build_heap(struct span *heap, int n)
{
	int i;
	for(i=(n-2)/2; i>=0; i--)
	{
		heapify(heap, i, n-1);
	}
}

void heapify(struct span *heap, int i, int heapsize)
{
	int left=2*i+1;
	int right=2*i+2;
	int smallest;
	if(heap[left].weight < heap[i].weight && left <=heapsize)
		smallest = left;
	else 
		smallest = i;
	
	if(heap[right].weight < heap[smallest].weight && right <=heapsize)
		smallest = right;

	if(i!=smallest)
	{
		swap(&heap[i], &heap[smallest]);
		heapify(heap, smallest, heapsize);
	}
}

void swap(struct span *h1, struct span *h2)
{
	struct span temp;
	temp.src = h1->src;
	temp.dest = h1->dest;
	temp.weight=h1->weight;
	
	h1->weight = h2->weight;
	h1->src = h2->src;
	h1->dest = h2->dest;
	
	h2->src=temp.src;
	h2->dest=temp.dest;
	h2->weight=temp.weight;
}


int find_min_heap(struct span *heap_arr, int heapsize)
{
	int index=heap_arr[0].src;
	heap_arr[0].src= heap_arr[heapsize-1].src;
//	heap_arr[0].dest= heap_arr[heapsize].dest;
	heap_arr[0].weight=heap_arr[heapsize-1].weight;
	
	return index;
}

int find_index(struct span *heap_arr, int heapsize, int node)
{
	int i;
	for(i=0; i<heapsize; i++)
	{
		if(heap_arr[i].src==node)
		{
			return i;
		}
	}
	return -1;
}
		
void print_prim_mst(struct mst *result, int n)
{
	int i;
	printf("The links in the mst are: \n");
	for(i=0; i<n;i++)
	{
		printf("%d->%d(%d)\n", result[i].src, i, result[i].weight);
	}
}












