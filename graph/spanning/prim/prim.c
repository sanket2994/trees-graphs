#include"prim.h"


int links=0; /*total number of links in the grpah*/

/*function to allocate memory for  a graph*/
struct graph* create_graph(int n)
{
	struct graph *graph=(struct graph *)calloc(n, sizeof(struct graph));
	return graph;
}

/*Function to insert elements inside the graph using adjoined list */
void insert_graph(struct graph *graph, int n1, int n2, int weight)
{
	struct graph *temp;
	/*point to neighbours of the base*/
	temp=graph[n1].link;
	
	/*checking for existing links between the nodes*/
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
	/*If no neighbours present attach the node to the base*/
	if(graph[n1].link==NULL)
	{
		graph[n1].link=node;
		
	}
	/*If neighbours present then add the node at the beginning of the list*/
	else 
	{
		node->link=graph[n1].link;
		graph[n1].link=node;
	}
	
	/*Do the same at the node 2 but now add node 1 to the list*/
	struct graph *node2=(struct graph*)calloc(1, sizeof(struct graph));
	node2->node_no=n1;
	node2->link=NULL;
	node2->weight=weight;
	/*If no neighbours*/
	if(graph[n2].link==NULL)
	{
		graph[n2].link=node2;
	}
	/*If neighbours are present*/
	else
	{
		node2->link=graph[n2].link;
		graph[n2].link=node2;
	}
	/*INCREMENT THE LINKS COUNT*/
	links++;
}

/*Prims Algorithm for minimal spanning tree*/
void prim(struct graph *graph, int n)
{
	/*create a binary heap of size equal to number of nodes*/
	struct span *heap_arr=(struct span*)calloc(n, sizeof(struct span));
	/*build the heap such that it is min heap*/
	build_heap(heap_arr, n);
	int  heapsize=n, i, index, heapIndex;
	/*the resulting mst */
	struct span *result=(struct span*)calloc(n, sizeof(struct span));
	struct graph *temp;
	/*Initially the weight of first element of the heap should be zero rest is infinity*/
	heap_arr[0].weight=0;
	heap_arr[0].src=0;
	heap_arr[0].dest=-1;
	/*Initializing the remaining elements to INFINITY*/
	for(i=1;i<n;i++)
	{
		heap_arr[i].src=i;
		heap_arr[i].weight=INFINITY;
		heap_arr[i].dest=-1;
	}
	/*While there are entries in the heap*/
	while(heapsize!=0)
	{
		/*build min heap*/
		build_heap(heap_arr, heapsize);
		/*remove the first element from the heap(i.e. min element)*/
		index= find_min_heap(heap_arr, heapsize);
		heapsize--;/*decrement size of heap*/
				
		temp=graph[index].link;
		/*check for every neighbour of the node*/
		while(temp!=NULL)
		{
			/*find the link whose index is to be updated in heap*/
			heapIndex=find_index(heap_arr, heapsize, temp->node_no);
			/*update value if the entry is present and the weight is more than the newly found weight of the path*/
			if(heapIndex!=-1 && temp->weight < heap_arr[heapIndex].weight )
			{
				/*Update the new weight */
				heap_arr[heapIndex].weight=temp->weight;
				heap_arr[heapIndex].dest=temp->node_no;
				/*update the mst tree*/
				result[temp->node_no].src=index;
				result[temp->node_no].weight=temp->weight;
				result[temp->node_no].dest=temp->node_no;
			}
			temp=temp->link;
		}
	}
	/*Print the mst*/
	print_prim_mst(result, n);
}

/*Build the min heap*/
void build_heap(struct span *heap, int n)
{
	int i;
	for(i=(n-2)/2; i>=0; i--)
	{
		heapify(heap, i, n-1);
	}
}
/*heapify the array to get the minimum value element at the top*/
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

/*Swao function to swap the two nodes of the tree*/
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

/*Find the minimum element and remove that element from the heap*/
int find_min_heap(struct span *heap_arr, int heapsize)
{
	int index=heap_arr[0].src;
	heap_arr[0].src= heap_arr[heapsize-1].src;
	heap_arr[0].dest= heap_arr[heapsize-1].dest;
	heap_arr[0].weight=heap_arr[heapsize-1].weight;
	/*return the source node value */	
	return index;
}

/*Find the index in the heap at which the node is present */
int find_index(struct span *heap_arr, int heapsize, int node)
{
	int i;
	for(i=0; i<heapsize; i++)
	{
		if(heap_arr[i].src==node)
		{
			/*If found return the index value*/
			return i;
		}
	}
	/*If entry not found then return -ve value*/
	return -1;
}

/*Print the Minimum Spanning Tree*/		
void print_prim_mst(struct span *result, int n)
{
	int i;
	printf("The links in the mst are: \n");
	for(i=0; i<n;i++)
	{
		printf("%d->%d(%d)\n", result[i].src, result[i].dest, result[i].weight);
	}
}












