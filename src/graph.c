#include"graph.h"


int links=0;

void insert_link(struct graph *nodelist , struct graph *graph, int n1, int n2, int weight)
{
        struct node *node1=(struct node*)calloc(1, sizeof(struct node));
        node1->data=nodelist[n1].node->data;
        node1->src=n1;
        node1->dest=n2;
        node1->weight=weight;
                                                                           
        struct node *temp=graph[n1].node;
            
        /*Check if path already exist*/
        if(temp!=NULL)
        {   
                if(temp->data==node1->data && temp->weight == node1->data && temp->dest == node1->dest)
                {   
                        memset(node1, 0, sizeof(struct node));
                        free(node1);
                        return;
                }   
                temp=temp->link;
        }   
     
        /*Insert in adjoincy list of n1*/
        node1->link=graph[n1].node;
        graph[n1].node=node1;

        struct node *node2=(struct node*)calloc(1, sizeof(struct node));
        node2->data=nodelist[n2].node->data;
        node2->src=n2;
        node2->dest=n1;
        node2->weight=weight;
             
        /*Insert node in adjoincy list of n2*/
        node2->link=graph[n2].node;
        graph[n2].node=node2;
              
        links++;
}


