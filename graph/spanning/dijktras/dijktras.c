#include"dijktras.h"

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
        node1->weight=weight;
             
        /*Insert node in adjoincy list of n2*/
        node2->link=graph[n2].node;
        graph[n2].node=node2;
              
        links++;
}

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
                heapsize--;
                temp=graph[graphIndex].node;
                while(temp!=NULL)
                {
                        heapIndex=find_index(heap_arr, heapsize, temp->dest);
                        parentWeight=heap_arr[heapsize].weight;
                        if(heapIndex!=-1 && heap_arr[heapIndex].weight > (parentWeight + temp->weight)) //doubtfull about condition
                        {
                                heap_arr[heapIndex].weight = parentWeight + temp->weight;
                                heap_arr[heapIndex].dest = temp->dest;
                                result[graphIndex].src = temp->dest;
                                result[graphIndex].dest= graphIndex;
                                result[graphIndex].weight = parentWeight + temp->weight;
                        }
                temp = temp->link;
                }
        }
        print_shortest_path(result, n);
}


/*Build the min heap*/
void build_heap(struct node *heap, int n)
{
        int i;
        for(i=(n-2)/2; i>=0; i--)
        {
                heapify(heap, i, n-1);
        }
}
/*heapify the array to get the minimum value element at the top*/
void heapify(struct node *heap, int i, int heapsize)
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

/*Swap function to swap the two nodes of the tree*/
void swap(struct node *h1, struct node *h2)
{
        struct node temp;
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


int find_min_heap(struct node *heap_arr, int heapsize)
{
        int index=heap_arr[0].src;
        swap(&heap_arr[0],&heap_arr[heapsize-1]);/*
        heap_arr[0].src=heap_arr[heapsize-1].src;
        heap_arr[0].dest=heap_arr[heapsize-1].dest;
        heap_arr[0].weight=heap_arr[heapsize-1].weight;*/
        return index;
}

int find_index(struct node *heap_arr, int heapsize, int node)
{
        int i;
        for(i=0;i<heapsize;i++)
        {
                if(node==heap_arr[i].src)
                        return i;
        }
        return -1;
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
                                  
