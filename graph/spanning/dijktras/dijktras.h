#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define INFINITE 65535

struct node{
	int data;
	int src;
	int dest;
	int weight;
	struct node *link;
	};

struct graph{
	struct node *node;
	};

static inline struct graph* create_graph(int n)
{
	struct graph *graph=(struct graph*)calloc(n, sizeof(struct graph));
	return graph;
}

static inline void insert_node(struct graph *nodeList , struct node *node)
{
	nodeList[node->src].node=node;
}


void insert_link(struct graph *nodelist , struct graph *graph, int n1, int n2, int weight);
void dijktras(struct graph *nodeList, struct graph *graph, struct node *baseNode, int n);
void build_heap(struct node *heap, int n);
void heapify(struct node *heap, int i, int heapsize);
void swap(struct node *h1, struct node *h2);
int find_min_heap(struct node *heap_arr, int heapsize);
int find_index(struct node *heap_arr, int heapsize, int node);
void print_shortest_path(struct node *result, int n);

