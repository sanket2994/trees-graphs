#include"graph.h"
#include"spanning.h"
#include"heap.h"
/*Apply prims algorithm for minimal spanning tree*/
void prim(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n)
{
		int i, heapsize, graphIndex, heapIndex;
		struct node *heap_arr=(struct node*)calloc(n, sizeof(struct node));
		struct node *result=(struct node*)calloc(n, sizeof(struct node));
		struct node *temp;
		heap_arr[0].weight=0;
		heap_arr[0].src=baseNode->src;
		heap_arr[0].dest=-1;
		heap_arr[0].data=baseNode->data;
		for(i=0;i<n;i++)
		{
			if(i!=baseNode->src)
			{
				heap_arr[i].src=i;
				heap_arr[i].dest=-1;
				heap_arr[i].weight=INFINITE;
				heap_arr[i].data=nodeList[i].node->data;
			}
		}
		heapsize=n;
		while(heapsize!=0)
		{
			build_heap(heap_arr, heapsize);
			graphIndex=find_min_heap(heap_arr, heapsize);
			heapsize--;
		
			temp=graph[graphIndex].node;
			while(temp!=NULL)
			{
				heapIndex=find_index(heap_arr, heapsize, temp->dest);
				if(heapIndex!=-1 && temp->weight < heap_arr[heapIndex].weight)
				{
					heap_arr[heapIndex].weight=temp->weight;
					heap_arr[heapIndex].dest=graphIndex;
					result[temp->dest].src=graphIndex;
					result[temp->dest].weight=temp->weight;
					result[temp->dest].dest=temp->dest;
					result[temp->dest].data=nodeList[temp->dest].node->data;
								
				}
				temp=temp->link;
			}	
		}
		print_prim_mst(result, n);
}




void print_prim_mst(struct node *result, int n)
{
        int i;
        printf("The mst for node is: \n");
        for(i=0;i<n;i++)
        {
                printf("%d->%d(parent) cost=%d\n", result[i].dest, result[i].src, result[i].weight);
        }

}
 































