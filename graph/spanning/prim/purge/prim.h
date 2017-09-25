#ifndef __PRIM_H
#define __PRIM_H

#include<stdio.h>
#include<stdlib.h>
#include"prim.h"
#define INFINITY 65535
struct graph{
	int node_no;
	struct graph *link;
	int weight;
	};

struct span{
	int src;
	int dest;
	int weight;
	};

struct mst{
	int src;
	int weight;
	};

struct graph* create_graph(int n);

void insert_graph(struct graph *graph, int n1, int n2, int weight);

void prim(struct graph *graph, int n);
	
void build_heap(struct span *heap_arr, int n);

int find_min_heap(struct span *heap_arr, int heap);

int find_index(struct span *heap_arr, int heapsize, int node);

void swap(struct span *heap1, struct span *heap2);

void heapify(struct span *heap, int i, int heapsize);

void print_prim_mst(struct mst *result, int n);



#endif
