#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int length;
}Heap_ADT;

/*Display the Heap*/
void DisplayHeap(Heap_ADT *p_heap)
{
    int i;

    for( i = 1 ;i<p_heap->length;i++)
        printf("%d ",*(p_heap->A+i));
    
    printf("\n");
    return;
}

/*Initializing Heap*/
void HeapInit(Heap_ADT *ptr)
{
    printf("Enter max size of Heap:");
    scanf("%d",&ptr->size);
    ptr->length = 1;
    if(ptr->length < ptr->size && ptr->size > 0)
        ptr->A = (int *)malloc(ptr->size*sizeof(int));
    else
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }

    return;
}

/*Insert MAX Heap*/
void InsertMaxHeap(Heap_ADT *p_max, int key)
{
    int index = p_max->length;

    p_max->A[p_max->length++] = key;

    while (1 < index && p_max->A[index/2] < key)
    {
        p_max->A[index] = p_max->A[index/2];
        index = index/2;
    }
    p_max->A[index] = key;

}

/*Insert MIN heap*/
void InsertMinHeap(Heap_ADT *p_min, int key)
{
    int index = p_min->length;

    p_min->A[p_min->length++] = key;

    while (1 < index && p_min->A[index/2] > key)
    {
        p_min->A[index] = p_min->A[index/2];
        index = index/2;
    }
    p_min->A[index] = key;
}

/*Delete From MAX heap*/
void DeleteMaxHeap(Heap_ADT *p_max)
{
    int index = 1;
    int temp  = 0;

    p_max->A[1] = p_max-A[p_max->length--];
    temp = p_max->A[1];

    while (index < p_max->length)
    {
        if (p_max->A[2*index] > p_max->A[(2*index)+1])
    }
}

int main()
{
    Heap_ADT    *p_MAX_Heap  = NULL ;
    Heap_ADT    *p_MIN_Heap  = NULL ;

    p_MAX_Heap = (Heap_ADT*)malloc(sizeof(Heap_ADT));
    if (NULL == p_MAX_Heap)
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(p_MAX_Heap,0,sizeof(Heap_ADT));

    p_MIN_Heap = (Heap_ADT*)malloc(sizeof(Heap_ADT));
    if (NULL == p_MIN_Heap)
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(p_MIN_Heap,-1,sizeof(Heap_ADT));

    HeapInit(p_MAX_Heap);
    HeapInit(p_MIN_Heap);

    InsertMaxHeap(p_MAX_Heap,10);
    InsertMaxHeap(p_MAX_Heap,20);
    InsertMaxHeap(p_MAX_Heap,30);
    InsertMaxHeap(p_MAX_Heap,25);
    InsertMaxHeap(p_MAX_Heap,5);
    InsertMaxHeap(p_MAX_Heap,40);
    InsertMaxHeap(p_MAX_Heap,35);

    DisplayHeap(p_MAX_Heap);




    if ((NULL != p_MAX_Heap) &&
            (NULL != p_MAX_Heap->A))
    {
        printf("GARBAGE COLLECTION:Freeing MAX Heap\n");
        free(p_MAX_Heap->A);
        p_MAX_Heap->A = NULL;
        free(p_MAX_Heap);
        p_MAX_Heap = NULL;
    
    }

    if ((NULL != p_MIN_Heap) &&
            (NULL != p_MIN_Heap->A))
    {
        printf("GARBAGE COLLECTION:Freeing MIN Heap\n");
        free(p_MIN_Heap->A);
        p_MIN_Heap->A = NULL;
        free(p_MIN_Heap);
        p_MIN_Heap = NULL;
    }

}
