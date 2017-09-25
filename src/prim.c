#include"graph.h"
#include"spanning.h"
#include"heap.h"
/*Apply prims algorithm for minimal spanning tree*/
void prim(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n)
{
		int i, heapsize, graphIndex, heapIndex;
		/*Create a heap data structure*/
		struct node *heap_arr=(struct node*)calloc(n, sizeof(struct node));
		/*create the result data structure contatining the MST*/
		struct node *result=(struct node*)calloc(n, sizeof(struct node));
		struct node *temp;
		/*Initialize the weight of base node with weight zero in the heap*/
		heap_arr[0].weight=0;
		heap_arr[0].src=baseNode->src;
		heap_arr[0].dest=-1;
		heap_arr[0].data=baseNode->data;
		/*Initialize the weight of all the other nodes as INFINITE*/
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
		/*While there are elements present in the heap*/
		while(heapsize!=0)
		{
			/*Build min heap of the heap array*/
			build_heap(heap_arr, heapsize);
			/*Remove the node with the smallest weight from the heap*/
			graphIndex=find_min_heap(heap_arr, heapsize);
			heapsize--;
		
			temp=graph[graphIndex].node;
			/*check for all neighbours of this node removed from heap*/
			while(temp!=NULL)
			{
				/*Find the index of the neighbour in the heap*/
				heapIndex=find_index(heap_arr, heapsize, temp->dest);
				/*If the neighbour present in heap and the weight of the neighbour is less than that in the heap */
				if(heapIndex!=-1 && temp->weight < heap_arr[heapIndex].weight)
				{
					/*Update the new weight in the heap*/
					heap_arr[heapIndex].weight=temp->weight;
					heap_arr[heapIndex].dest=graphIndex;
					/*update the link in the result data structure*/
					result[temp->dest].src=graphIndex;
					result[temp->dest].weight=temp->weight;
					result[temp->dest].dest=temp->dest;
					result[temp->dest].data=nodeList[temp->dest].node->data;
								
				}
				temp=temp->link;
			}	
		}
		/*Print the MST */
		print_prim_mst(result, n);
}



/*Print the MST formed by using prims Algorithm*/
void print_prim_mst(struct node *result, int n)
{
        int i;
        printf("The mst for node is: \n");
        for(i=0;i<n;i++)
        {
		/*Printing format as node -> its neighbour (parent) and the cost between the two nodes*/
                printf("%d->%d(parent) cost=%d\n", result[i].dest, result[i].src, result[i].weight);
        }

}
 
