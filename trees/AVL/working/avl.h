#include<stdio.h>
#include<stdlib.h>
#include<math.h>
struct avlnode{
	int data;
	struct avlnode *left;
	struct avlnode *right;
	};
struct bstnode{
	int data;
	struct avlnode *left;
	struct avlnode *right;
	};
struct avlnode* insert_node(struct avlnode*, int);
struct avlnode* insert_node_avl(struct avlnode* ,int);
int search(struct avlnode*, int);
struct avlnode* right_shift(struct avlnode*, struct avlnode*);
struct avlnode* left_shift(struct avlnode*, struct avlnode*);
struct avlnode* double_shift(struct avlnode*, struct avlnode*);
int find_min(struct avlnode *);
int find_max(struct avlnode*);
void inorder(struct avlnode*);
struct avlnode* balance_tree(struct avlnode*, int);
int calc_diff(struct avlnode*);
int calc_height(struct avlnode*);
struct avlnode* left_rotate(struct avlnode*, struct avlnode*);
struct avlnode* right_rotate(struct avlnode*, struct avlnode*);
struct avlnode* left_right_rotate(struct avlnode*, struct avlnode*, struct avlnode*);
struct avlnode* right_left_rotate(struct avlnode*, struct avlnode*, struct avlnode*);

