#ifndef __SPANNING_H_
#define __SPANNING_H_

#include "graph.h"

/*Find the shortest path from a node to all nodes in graph using dijktras Algorithm*/
void dijktras(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n);
/*
*Takes the graph and nodelist as the argument
*Also takes the baseNode structure i.e. structure of the node from which the cost is t be calculates and thetotal number of nodes asarguments
*internally calls print_shortest_path and prints the shortest paths
*/

/*prints the shortest path of each node from the bas e node*/
void print_shortest_path(struct node *result, int n);
/*
*Called internally by dijktras
*It prints in following format
* NODE -> PARENT NODE (COST OF THE NODE FROM BASE NODE)	
*/

/*Makes a minimal spanning tree using prims algorithm*/
void prim(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n);
/*
*takes the graph structure and the nodelist structure as arguments
*Also takes the baseNode structure for which MST is to be printed
*internally calls print_prim_mst which printsthe minimal spanning tree
*/

/*Prints the minimal spanning tree*/
void print_prim_mst(struct node *result, int n);
/*
*it is internally called by prim
*it prints the MST in given format
*"NODE -> PARENT NODE (WEIGHT/ COST OF NODE FROM PARENT)
*/

#endif
