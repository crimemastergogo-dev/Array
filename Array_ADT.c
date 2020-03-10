#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int length;
}ARRAY;

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

    for(int i =0 ;i<p_array->length;i++)
        scanf("%d",p_array->A+i);
    return;
}

/*Insert at end of the Array*/
void Append(ARRAY *p_array,int element)
{
    if(p_array->length < p_array->size)
    {
        *(p_array->A + p_array->length++) = element;
    }
    else
    {
        printf("MAX SIZED IS REACHED\n");
        return;
    }
    printf("Array Elements after append:\n");
    Display(p_array);
    return;
}
/*Insert at any position*/
void InsertPos(ARRAY *p_array,int element,int index)
{
    int i = 0;
    if(index >= 0 && index < p_array->length)
    {
        for(i = p_array->length ; i>index; i--)
            *(p_array->A + i) = *(p_array->A + i-1);

        *(p_array->A + index) = element;
        p_array->length++;
    }
    else
    {
        printf("INVALID INDEX\n");
        return;
    }
    printf("\nArray Elements after inserting %d at index %d\n",element,index);
    Display(p_array);
    return;
}

/*Deleting the elemnt in an array*/
void Delete(ARRAY *p_array,int index)
{
    int i    = 0;
    int temp = 0;
    if(index >=0 && index < p_array->length )
    {
        temp = *(p_array->A + index);
        for(i = index ; i< p_array->length-1; i++)
            *(p_array->A + i) = *(p_array->A + i+1);
    
        p_array->length--;
    }
    else
    {
        printf("INVALID INDEX\n");
        return;
    }

    printf("\nArray Elements after Deleting element at index %d\n",index);
    Display(p_array);
    return;
}

/*Linear search in an array*/
void LinearSearch(ARRAY *p_array,int key)
{
    int flag = 0;
    int i    = 0;
    for(i = 0 ; i<p_array->length;i++)
    {
        if(*(p_array->A +i) == key)
        {
            printf("Element %d found at Index %d \n",key,i);
            flag = 1;    
        }
    }
    if(flag == 0)
        printf("No such Element in the Array\n");

    return;
}
int main()
{
    ARRAY           *p_array = NULL ;
    int             element  = 0; 
    int             index    = 0;
    int             value    = 0;

    
    p_array = (ARRAY *)malloc(sizeof(ARRAY));
    memset(p_array,0,sizeof(ARRAY));

    printf("Enter max size of Array:");
    scanf("%d",&p_array->size);
    printf("Enter length  of Array:");
    scanf("%d",&p_array->length);
    p_array->A = (int *)malloc(p_array->size*sizeof(int));

    printf("INSERT Array Elements:\n");
    Insert(p_array);

    printf("DISPLAY Array Elements:\n");
    Display(p_array);

    printf("Enter element to append:\n");
    scanf("%d",&element);
    Append(p_array,element);

    printf("Enter the Elemnt at any position:\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    printf("Enter value to be inserted:\n");
    scanf("%d",&value);
    InsertPos(p_array,value,index);

    printf("Delete the Elemnt from any position:\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    Delete(p_array,index);

    printf("Linear Searching in Array\n");
    printf("Enter value to be searched:\n");
    scanf("%d",&value);
    LinearSearch(p_array,value);

    return 0;
}
