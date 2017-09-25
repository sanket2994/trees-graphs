#include"graph.h"
#include"spanning.h"
#include"heap.h"

void dijktras(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n)
{
        int i, heapsize, heapIndex, graphIndex, parentWeight;
        struct node *heap_arr=(struct node*)calloc(n, sizeof(struct node));
        heap_arr[baseNode->src].weight=0;
        heap_arr[baseNode->src].dest=-1;
        heap_arr[baseNode->src].src=baseNode->src;
        heap_arr[baseNode->src].data=baseNode->data;
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

        //build_heap(heap_arr, n);
        heapsize=n;
        struct node *result=(struct node*)calloc(n, sizeof(struct node));
        struct node *temp;
        while(heapsize!=0)
        {
                build_heap(heap_arr, heapsize);
                graphIndex=find_min_heap(heap_arr, heapsize);
		parentWeight=heap_arr[heapsize-1].weight;
                heapsize--;
                temp=graph[graphIndex].node;
                while(temp!=NULL)
                {
			
                        heapIndex=find_index(heap_arr, heapsize, temp->dest);
                        if(heapIndex!=-1 && heap_arr[heapIndex].weight > (parentWeight + temp->weight)) //doubtfull about condition
                        {
                                heap_arr[heapIndex].weight = parentWeight + temp->weight;
                                heap_arr[heapIndex].dest = graphIndex;
                                result[temp->dest].src = graphIndex;
                                result[temp->dest].dest= temp->dest;
                                result[temp->dest].weight = parentWeight + temp->weight;
                        }
                temp = temp->link;
                }
        }
        print_shortest_path(result, n);
}



void print_shortest_path(struct node *result, int n)
{
        int i;
        printf("The shortest path from the node are: \n");
        for(i=0;i<n;i++)
        {
                printf("%d->%d(parent) cost=%d\n", result[i].dest, result[i].src, result[i].weight);
        }

}
                                  
