#include"graph.h"
#include"spanning.h"
#include"heap.h"

/*Function to perform dijiktras algorithm*/
void dijktras(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n)
{
        int i, heapsize, heapIndex, graphIndex, parentWeight;
        struct node *heap_arr=(struct node*)calloc(n, sizeof(struct node));
	/*initialize the base node weight as zero*/
        heap_arr[baseNode->src].weight=0;
        heap_arr[baseNode->src].dest=-1;
        heap_arr[baseNode->src].src=baseNode->src;
        heap_arr[baseNode->src].data=baseNode->data;
	/*Initialize all the other nodes weight as infinity*/
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
        struct node *result=(struct node*)calloc(n, sizeof(struct node));
        struct node *temp;
	/*Run untill heap is not empty*/
        while(heapsize!=0)
        {
                build_heap(heap_arr, heapsize);
                graphIndex=find_min_heap(heap_arr, heapsize);
		parentWeight=heap_arr[heapsize-1].weight;
                heapsize--;
                temp=graph[graphIndex].node;
		/*Check for all the neighbours of that node*/
                while(temp!=NULL)
                {
			
                        heapIndex=find_index(heap_arr, heapsize, temp->dest);
			/*If node in HEAP and the weight o fthe corresponding node is grater than the new weight*/
                        if(heapIndex!=-1 && heap_arr[heapIndex].weight > (parentWeight + temp->weight)) 
                        {
				/*Update the new distance in heap*/
                                heap_arr[heapIndex].weight = parentWeight + temp->weight;
                                heap_arr[heapIndex].dest = graphIndex;
				/*Update the new distance in the final result data structure*/
                                result[temp->dest].src = graphIndex;
                                result[temp->dest].dest= temp->dest;
                                result[temp->dest].weight = parentWeight + temp->weight;
                        }
                temp = temp->link;
                }
        }
	/*Print the shortest paths from the bas enode*/
        print_shortest_path(result, n);
}


/*Print the shortest paths from all the nodes*/
void print_shortest_path(struct node *result, int n)
{
        int i;
        printf("The shortest path from the node are: \n");
        for(i=0;i<n;i++)
        {
		/*Print format as the node whose distance to be calculated -> the immediate parent in the path from the base node and cost from the base Node*/
                printf("%d->%d(parent) cost=%d\n", result[i].dest, result[i].src, result[i].weight);
        }

}
                                  
