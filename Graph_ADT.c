#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct _Node
{
    int    data;
    int    weight;
    struct _Node *next;
}Data_node_t;

typedef struct _Graph
{
    int         num_node;
    Data_node_t **p_p_node;
    int *VisitedNodes;
}GraphAdjencyList_ADT;

typedef struct
{
    int *A;
    int size;
    int front;
    int rear;
}Queue;

/*Initializing Queue*/
void QueueInit(Queue *ptr,GraphAdjencyList_ADT *p_graph)
{
    ptr->size = p_graph->num_node;
    ptr->front = -1;
    ptr->rear  = -1;
    if((ptr->rear < ptr->size) && (ptr->size > 0) && (ptr->front < ptr->size))
        ptr->A = (int *)malloc(ptr->size*sizeof(int));
    else
    {
        if (NULL == ptr->A)
        {
            printf("ERROR:Memory Allocation Failed\n");
            exit (1);
        }
    }
}

int isEmpty(Queue *ptr)
{
    int ret_val = 1;
    if (ptr->front == ptr->rear)
        ret_val = 0;

    return ret_val;
}

int isFull(Queue *ptr)
{
    int ret_val = 1;
    if (ptr->front > ptr->size)
        ret_val = 0;

    return ret_val;
}

void Enqueue(Queue *ptr, int data)
{
    if (0 == isFull(ptr))
    {
        printf("Queue is Full\n");
    }
    else
    {
        ptr->A[++ptr->rear] = data;
    }
}

int Dequeue(Queue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[++ptr->front];
    }
    return ret_val;
}

/* Initializing Graph using Adjance List */
void GraphAdjancyListInit(GraphAdjencyList_ADT *ptr)
{
    int  index   = 0;
    int  num     = 0;
 
    fprintf(stdout,"Enter No of Nodes:\n");
    scanf("%d",&num);

    ptr->num_node = num+1;

    ptr->p_p_node = (Data_node_t **)malloc(ptr->num_node*sizeof(Data_node_t));
    if (NULL == ptr->p_p_node)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }

    ptr->VisitedNodes = (int *) malloc(ptr->num_node*sizeof(int));
    memset(ptr->VisitedNodes,0,ptr->num_node*sizeof(int));

    for (index = 0 ; index < ptr->num_node; index++)
    {
        ptr->p_p_node[index] = NULL;
    }
    return;
}


void InsertGraphAdjancyList(GraphAdjencyList_ADT *p_graph,int vertex,int edge, int weight)
{
    Data_node_t *temp    = NULL;
    Data_node_t *current = NULL;

    temp = (Data_node_t *) malloc(sizeof(Data_node_t));
    if (NULL == temp)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(temp,0,sizeof(Data_node_t));
    temp->data   = edge;
    temp->weight = weight;
    temp->next   = NULL;

    /* Creating First Node for a vertex*/
    if (NULL == p_graph->p_p_node[vertex])
    {
        p_graph->p_p_node[vertex] = temp;
        return;
    }
    /* Appending in Adjancy List for a vertex*/
    else
    {
        current = p_graph->p_p_node[vertex];
        while(NULL != current->next)
        {
            current = current->next;
        }
        current->next = temp;
    }

}

void BreadthFirstSearchAdjancyList(GraphAdjencyList_ADT *p_graph,int vertex)
{
    Queue *queue         = NULL;
    Data_node_t *current = NULL;
    int Dequeue_vertex   = 0;

    queue = (Queue *)malloc(sizeof(Queue));
    memset(queue,0,sizeof(Queue));

    QueueInit(queue,p_graph);

    fprintf(stdout,"%d,",vertex);
    p_graph->VisitedNodes[vertex] = 1;
    Enqueue(queue, vertex);
    while(isEmpty(queue))
    {
        Dequeue_vertex = Dequeue(queue);
        current = p_graph->p_p_node[Dequeue_vertex];
        while(current)
        {
            if (p_graph->VisitedNodes[current->data] == 0)
            {
                fprintf(stdout,"%d,",current->data);
                p_graph->VisitedNodes[current->data] = 1;
                Enqueue(queue, current->data);
            }
            current = current->next;
        }
    
    }
    fprintf(stdout,"\n");
}

void DeapthFirstSearchAdjancyList(GraphAdjencyList_ADT *p_graph,int vertex)
{
    Data_node_t *current = NULL;


    if (0 == p_graph->VisitedNodes[vertex])
    {
        fprintf(stdout,"%d,",vertex);
        p_graph->VisitedNodes[vertex] = 1;
        current = p_graph->p_p_node[vertex];
        while(current)
        {
            DeapthFirstSearchAdjancyList(p_graph,current->data);
            current = current->next;
        }

    }
}

int main()
{
    GraphAdjencyList_ADT   *p_graph        = NULL;
    int       index    = 0;

    p_graph = (GraphAdjencyList_ADT *)malloc(sizeof(GraphAdjencyList_ADT));
    if (NULL == p_graph)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(p_graph,0,sizeof(GraphAdjencyList_ADT));

    GraphAdjancyListInit(p_graph);

    InsertGraphAdjancyList(p_graph,1,2,0);
    InsertGraphAdjancyList(p_graph,1,3,0);
    InsertGraphAdjancyList(p_graph,1,4,0);
    InsertGraphAdjancyList(p_graph,2,1,0);
    InsertGraphAdjancyList(p_graph,2,3,0);
    InsertGraphAdjancyList(p_graph,3,1,0);
    InsertGraphAdjancyList(p_graph,3,2,0);
    InsertGraphAdjancyList(p_graph,3,4,0);
    InsertGraphAdjancyList(p_graph,3,5,0);
    InsertGraphAdjancyList(p_graph,4,3,0);
    InsertGraphAdjancyList(p_graph,4,5,0);
    InsertGraphAdjancyList(p_graph,5,6,0);
    InsertGraphAdjancyList(p_graph,5,7,0);

    //BreadthFirstSearchAdjancyList(p_graph,2);
    DeapthFirstSearchAdjancyList(p_graph,1);


    if (NULL != p_graph)
    {
        for (index = 0 ; index < p_graph->num_node; index++)
        {
            if (NULL != p_graph->p_p_node[index])
            {
                free(p_graph->p_p_node[index]);
                p_graph->p_p_node[index] = NULL;
            }
        }
        free(p_graph);
        p_graph = NULL;
    }
}
