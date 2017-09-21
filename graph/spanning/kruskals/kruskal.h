#ifndef __KRUSKAL_H_
#define __KRUSKAL_H_

#include<stdio.h>
#include<stdlib.h>


struct graph{
	int node_no;
	int weight;
	struct graph *link;
	};
	
struct span{
	int node_no;
	int weight;
	int src, dst;
	};


struct graph* create_graph(struct graph *graph, int n);

void insert_graph(struct graph *graph, int n1, int n2, int weight);


void kruskal(struct graph *graph, int n);

void sort_array(struct span *arr, int n);

void make_tree(struct span *arr, int n);

int check_loop(struct graph *graph, struct span arr);

void print_tree(struct graph *graph, int n);

#endif
