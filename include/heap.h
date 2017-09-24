#ifndef __HEAP_H_
#define __HEAP_H_

#include "graph.h"

/*Build the minimum heap*/
void build_heap(struct node *heap, int n);
/*
*Takes the array as an argument and makes it a min heap
*athe elemant with the smallest key is brought to the first index
*/

/*heapify the array*/
void heapify(struct node *heap, int i, int heapsize);
/*
*Makes the array as min heap. 
*traverses from last to top and makes the array a min heap.
*/

/*Swaps the two elements of the array*/
void swap(struct node *h1, struct node *h2);

/*Gives the minimum elemnt in the array*/
int find_min_heap(struct node *heap_arr, int heapsize);
/*
*Takes the array as an argument and the heapsize
*returns the node number with the lowest weight/cost present in the array 
*/

/*finds the index location in the heap*/
int find_index(struct node *heap_arr, int heapsize, int node);
/*
*takes the heap array as an argument along with the node number
*returns the index location of heap matching the node number 
*/
#endif
