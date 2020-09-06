#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

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

int partition(int A[],int low,int high)
{
    int index1 = 0;
    int index2 = 0;
    int pivot  = 0;
    int temp   = 0;

    index1 = low;
    index2 = high;
    pivot  = A[0];
    
    do 
    {
        do
        {
            index1++;
        }while(A[index1] <= pivot);
        do
        {
            index2++;
        }while(A[index2] > pivot);

        if (index1 < index2)
        {
            temp      = A[index1];
            A[index1] = A[index2];
            A[index2] = temp;
        }

    }while(index1 < index2);
    temp      = A[low];
    A[low]    = A[index2]; 
    A[index2] = temp; 

    return index2;
}

void RQuickSort(int A[],int low,int high)
{
    int index = 0;
    if (low < high)
    {
        index = partition(A,low,high);
        RQuickSort(A,low,index);
        RQuickSort(A,index+1,high);
    }
}

void QuickSort(ARRAY *p_array)
{
    p_array->A[++p_array->length] = INT_MAX;

    RQuickSort(p_array->A,0,p_array->length);
}

int Max(ARRAY *ptr)
{
    int max = *ptr->A;
    int i   = 0;

    for (i = 0;i<ptr->length;i++)
        if(*(ptr->A+i)>max)
            max = *(ptr->A+i);

    return max;
}

void CountSort(ARRAY *p_array)
{
    int max_ele = 0;
    int index1  = 0;
    int index2  = 0;

    max_ele = Max(p_array) + 1;

    int Array[max_ele] ;
    memset(Array,0,max_ele * sizeof(int));

    for (index1 = 0 ; index1 < p_array->length ; index1++)
    {
        Array[p_array->A[index1]]++;
    }

    index1  = 0;
    while((index1 < max_ele) &&
            (index2 < p_array->length))
    {
        if (0 != Array[index1])
        {
            p_array->A[index2] = index1;
            Array[index1]--;
            index2++;
        }
        else
            index1++;
    }

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
    //printf("Array After Quick Sort:");
    //QuickSort(p_array);
    //printf("Array After Quick Sort:");
    //QuickSort(p_array);
    printf("Array After Count Sort:");
    CountSort(p_array);
    Display(p_array);
    if (NULL != p_array)
    {
        free(p_array);
        p_array = NULL;
    }
}
