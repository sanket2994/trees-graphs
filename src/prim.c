#include"graph.h"
#include"spanning.h"
#include"heap.h"
int links=0;

void insert_link(struct graph *nodelist , struct graph *graph, int n1, int n2, int weight)
{
        struct node *node1=(struct node*)calloc(1, sizeof(struct node));
        node1->data=nodelist[n1].node->data;
        node1->src=n1;
        node1->dest=n2;
        node1->weight=weight;
                                                                           
        struct node *temp=graph[n1].node;
            
        /*Check if path already exist*/
        if(temp!=NULL)
        {   
                if(temp->data==node1->data && temp->weight == node1->data && temp->dest == node1->dest)
                {   
                        memset(node1, 0, sizeof(struct node));
                        free(node1);
                        return;
                }   
                temp=temp->link;
        }   
     
        /*Insert in adjoincy list of n1*/
        node1->link=graph[n1].node;
        graph[n1].node=node1;

        struct node *node2=(struct node*)calloc(1, sizeof(struct node));
        node2->data=nodelist[n2].node->data;
        node2->src=n2;
        node2->dest=n1;
        node2->weight=weight;
             
        /*Insert node in adjoincy list of n2*/
        node2->link=graph[n2].node;
        graph[n2].node=node2;
              
        links++;
}

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
 































