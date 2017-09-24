/*#ifndef __KRUSKAL_H_
#define __KRUSKAL_H_
*/
#include<stdio.h>
#include<stdlib.h>

/*graph structure*/
struct graph{
	int node_no;		/*Node number of vertex*/
	int weight;		/*Weight between two nodes*/
	struct graph *link;	/*Points to next node in adjoincy list*/
	};

/*Spanning tree structure*/
struct span{
	int node_no;		/*Node number*/
	int weight;		/*weights between two nodes*/
	int src, dst;		/*Source and destinations of the link*/
	};

/*Creates a graph*/
struct graph* create_graph(struct graph *graph, int n);

/*inserts a node between two nodes of a graph*/
void insert_graph(struct graph *graph, int n1, int n2, int weight);
/*
*Takes the graph and thetwo node numbers between which a link is to be established and the weight between them
*as arguments
*/

/*Applies kruskals algorithm to make MST*/
void kruskal(struct graph *graph, int n);
/*
*Makes the graps into Minimal spanning tree
*internally calls the following functions
*/

/*Sort the array in ascending order of weights og the links*/
void sort_array(struct span *arr, int n);

/*convert int spanning tree*/
void make_tree(struct span *arr, int n);

/*Check if any loop while converting into MST*/
int check_loop(struct graph *graph, struct span arr);
/*
*If any loops found ignore that link 
*Else include it into the spanning tree
*/

/*Print the spanning tree*/
void print_tree(struct graph *graph, int n);

//#endif
