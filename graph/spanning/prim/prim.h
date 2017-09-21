#ifndef __PRIM_H
#define __PRIM_H

#include<stdio.h>
#include<stdlib.h>
#include"prim.h"
#define INFINITY 65535 /*Infinity value */

/*Graph structure which reprents each node in a graph  */
struct graph{
	int data; 		/*Any data which node stores*/
	int node_no;		/*The node number unique for each node*/
	struct graph *link;	/*Points to the neighbour of the node*/
	int weight;		/*the cost o fthe node*/
	};

/*structure for minimal spanning tree representing a link*/
struct span{
	int src; 		/*Source node*/
	int dest;		/*Destination node*/
	int weight;		/*Weight of each node*/
	};

/*Function to create a Graph*/
struct graph* create_graph(int n);
/*
*Takes the number of maximum nodes a graph can have as an argument
*Returns a pointer to the graph
*/
void insert_node_graph(struct graph *graph, );
/*Function to insert a node inside a graph*/
void insert_link_graph(struct graph *graph, int n1, int n2, int weight);
/**Inserts a link between the two nodes .
*takes the two nodes numbers where the link is to be inserted as an argument and the weight of the node.
*/
void prim(struct graph *graph, int n);
	
void build_heap(struct span *heap_arr, int n);

int find_min_heap(struct span *heap_arr, int heap);

int find_index(struct span *heap_arr, int heapsize, int node);

void swap(struct span *heap1, struct span *heap2);

void heapify(struct span *heap, int i, int heapsize);

void print_prim_mst(struct span *result, int n);



#endif
