#include<stdio.h>
#include<stdlib.h>
#include"dijktras.h"

int main()
{
        int ch, n, n1, n2, w;
        struct graph *graph, *nodeList=NULL;
        printf("Enter the max number of nodes taht the graph can have: ");
        scanf("%d",&n);

        graph=create_graph(n);
        nodeList=create_graph(n);
    
        do
        {
                printf("\n\n1. add a node \n2. Add a link between nodes \n3. shortest path using dijktras algorithm \n4. Exit \nEnter your choice: ");
                scanf("%d", &ch);
                switch(ch)
                {
                        case 1: printf("Enter packet details: \n");
                                struct node *node=(struct node*)calloc(1, sizeof(struct node));
                                printf("Enter the node no: ");
                                scanf("%d",&node->src);
                                printf("Enter the data: ");
                                scanf("%d", &node->data);
                                insert_node(nodeList, node);
                                break;
    
                        case 2: printf("Enter the nodes between which the link is to be inserted and the weight of the link: ");
                                scanf("%d%d%d", &n1, &n2, &w);
                                insert_link(nodeList, graph, n1, n2, w);
                                break;
    
                        case 3: printf("Enter the base node from which the distance is to be found: ");
                                scanf("%d", &n1);
                                dijktras(nodeList, graph, nodeList[n1].node, n);
                                break;
                        case 4: printf("quitting....");
                                break;
                 
                        default:printf("Invalid choice");
                  }
        }while(ch!=4);
}
 


