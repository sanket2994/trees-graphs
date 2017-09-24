#ifndef __GRAPH_H_
#define __GRAPH_H_

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITE 65535

/*Node structure which reprents each node in a graph*/
struct node{
	int data;		/*represents data stored at that node*/
	int src;		/*stores the source node*/
	int dest;		/*destination node*/
	int weight;		/*weight or cost of the link*/
	struct node *link;	/*points to the next node in adjoincy list*/
	};

/*represents the graph*/
struct graph{
	struct node *node;	/*points to the neighbours of that node*/
	};

/*Creates a graph */
static inline struct graph* create_graph(int n)
{
	struct graph *graph=(struct graph*)calloc(n, sizeof(struct graph));
	return graph;
}
/*
* The graph can have maximum of n edges 
* returns a pointer to the graph
*/

/*inserts a node into the graph*/
static inline void insert_node(struct graph *nodeList , struct node *node)
{
	nodeList[node->src].node=node;
}
/*
*takes a list of nodes present in graph and a structure to the node to be ineted as argument .
*associates the node to the corresponding location in the graph.
*/


/*Insert a link between two nodes*/
void insert_link(struct graph *nodelist , struct graph *graph, int n1, int n2, int weight);
/*
*Inserts a link or edge between the two nodes.
*Takes the nodeList structure, graphStructure,
* the node number  between which the link is to be inserted 
*And the weight or cost of the node as argument .
*/
#endif
