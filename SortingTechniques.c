#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int length;
}ARRAY;

/*Initializing Array*/
void ArrayInit(ARRAY *ptr)
{
    printf("Enter max size of Array:");
    scanf("%d",&ptr->size);
    printf("Enter length  of Array:");
    scanf("%d",&ptr->length);
    if(ptr->length < ptr->size && ptr->size > 0)
        ptr->A = (int *)malloc(ptr->size*sizeof(int));
    else
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }

    return;
}

/*Display the array*/
void Display(ARRAY *p_array)
{
    int i;

    for( i =0 ;i<p_array->length;i++)
        printf("%d ",*(p_array->A+i));
    
    printf("\n");
    return;
}

/*Insert the elements in the array*/
void Insert(ARRAY *p_array)
{
    int i;

    for(i =0 ;i<p_array->length;i++)
        scanf("%d",p_array->A+i);
    return;
}

/* Bubble sort */
void BubbleSort(ARRAY *p_array)
{
    int index1 = 0;
    int index2 = 0;
    int temp   = 0;
    int flag   = 0;

    for (index1 = 0 ; index1 < p_array->length ; index1++)
    {
        flag = 0;
        for (index2 = 0 ; index2 < p_array->length-1-index1 ; index2++)
        {
            if (p_array->A[index2] > p_array->A[index2+1])
            {
                temp               = p_array->A[index2+1];
                p_array->A[index2+1] = p_array->A[index2];
                p_array->A[index2] = temp;
                flag = 1;
            }
            if (!flag)
                break;
        }
    }
}

/* Insertion Sort */
void InsertionSort(ARRAY *p_array)
{
    int index1 = 0;
    int index2 = 0;
    int temp   = 0;

    for (index1 = 1 ; index1 <p_array->length; index1++)
    {
        temp   = p_array->A[index1];
        index2 = index1 - 1;
        while ((index2 >= 0)&&
                (p_array->A[index2] > temp))
        {
            p_array->A[index2+1] = p_array->A[index2];
            index2--;
        }
        p_array->A[index2+1] = temp;
    }
}

/* Selection Sort */
void SelectionSort(ARRAY *p_array)
{
    int index1 = 0;
    int index2 = 0;
    int index3 = 0;
    int temp   = 0;

    for (index1 = 0 ; index1 < p_array->length-1 ; index1++)
    {
        for (index2 = index3 = index1 ; index2 < p_array->length ; index2++)
        {
            if (p_array->A[index2] < p_array->A[index3])
                index3 = index2;
        }
        temp               = p_array->A[index1];
        p_array->A[index1] = p_array->A[index3];
        p_array->A[index3] = temp;
    }

}

void QuickSort(ARRAY *p_array)
{

}

int main()
{
    ARRAY *p_array = NULL;

    p_array = (ARRAY *)malloc(sizeof(ARRAY));
    if (NULL == p_array)
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(p_array,0,sizeof(ARRAY));

    ArrayInit(p_array);
    printf("Insert...\n");
    Insert(p_array);

    Display(p_array);
    //printf("Array After Bubble Sort:");
    //BubbleSort(p_array);
    //printf("Array After Insertion Sort:");
    //InsertionSort(p_array);
    //printf("Array After Selection Sort:");
    //SelectionSort(p_array);
    printf("Array After Quick Sort:");
    QuickSort(p_array);
    Display(p_array);
    if (NULL != p_array)
    {
        free(p_array);
        p_array = NULL;
    }
}
