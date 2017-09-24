#include"graph.h"
#include"heap.h"

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
	temp.data=h1->data;
	
        h1->weight = h2->weight;
        h1->src = h2->src;
        h1->dest = h2->dest;
	h1->data= h2->data;

        h2->src=temp.src;
        h2->dest=temp.dest;
        h2->weight=temp.weight;
	h2->data = temp.data;
}


int find_min_heap(struct node *heap_arr, int heapsize)
{
        int index=heap_arr[0].src;
        swap(&heap_arr[0],&heap_arr[heapsize-1]);
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


