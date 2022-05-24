
#include <stdio.h>
#include <stdlib.h>
  

struct adjnode
{
    int val;
    struct adjnode* next;
};
  
struct adj
{
    struct adjnode *head; 
};
  

struct graph
{
    int v;
    struct adj* list;
};
  

struct adjnode* newnode(int des)
{
    struct adjnode* temp = (struct adjnode*) malloc(sizeof(struct adjnode));
    temp->val = des;
    temp->next = NULL;
    return temp;
}
  

struct graph* create(int n)
{
    struct graph* G = (struct graph*) malloc(sizeof(struct graph));
    G->v = n;
  
    G->list = (struct adj*) malloc(n * sizeof(struct adj));
    int i;
    for (i = 0; i < n; ++i)
        G->list[i].head = NULL;
  
    return G;
}
  

void add(struct graph* G, int src, int des)
{
    
    struct adjnode *p, *temp = newnode(des);
    
    if(G->list[src].head == NULL)
    {
        G->list[src].head = temp;
        temp ->next = NULL;
    }
    else
    {
        p = G->list[src].head;
        while(p->next!=NULL)
        p = p ->next;
        p ->next = temp;
        temp->next = NULL;
        
    }
}



void print(struct graph* G)
{
    
    int v;
    for (v = 0; v < G->v; ++v)
    {
        struct adjnode* cur = G->list[v].head;
        printf("\nAdjacency list of vertex %d\n head ", v);
        while (cur)
        {
            printf("-> %d", cur->val);
            cur = cur->next;
        }
        printf("\n");
    }
}
  
void Sink ( struct graph* G , int v )
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for (i = 0; i < G->v; ++i)
    {
        struct adjnode* cur = G->list[i].head;
        
        while (cur)
        {
            if( i == v )
            count2++;
            if( cur -> val == v )
            count1++;
            cur = cur->next;
            
        }
    }
    if( count2 == 0 && count1 == ( G->v - 1 ) )
    printf("The Given Vertex %d is a Sink \n",v);
    else
    printf("The Given Vertex %d is not a Sink \n",v);
    
}

void Donor ( struct graph* G , int v )
{
    int i;
    int count1 = 0;
    int count2 = 0;
    for (i = 0; i < G->v; ++i)
    {
        struct adjnode* cur = G->list[i].head;
        
        while (cur)
        {
            if( i == v )
            count2++;
            if( cur -> val == v )
            count1++;
            cur = cur->next;
            
        }
    }
    if( count1 == 0 && count2 == ( G->v - 1 ) )
    printf("The Given Vertex %d is a Donor \n",v);
    else
    printf("The Given Vertex %d is not a Donor \n",v);
    
}

int main()
{
    
    int n ,v ;
    printf("Enter Number of Vertices : ");
    scanf("%d",&n);
    struct graph* G = create(n);
    int i , src , des ,edge ;
    printf("Enter Number of Edges : ");
    scanf("%d",&edge);

    for( i = 0 ; i < edge ; i++ )
    {
        printf("Enter Source and Destination : ");
        scanf("%d %d",&src,&des);
        add( G , src , des );
    }
    printf("\nThe formed Adjacency list is : \n");
    print(G);
    printf("\nEnter Node to check if a Sink node : ");
    scanf("%d",&v);
    Sink( G , v );
    printf("\nEnter Node to check if a Donor node : ");
    scanf("%d",&v);
    Donor( G , v );
          
}