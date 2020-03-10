#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int length;
}ARRAY;

void Display(ARRAY *p_array)
{
    int i;

    for( i =0 ;i<p_array->length;i++)
        printf("%d ",*(p_array->A+i));
}

void Insert(ARRAY *p_array)
{
    int i;

    for(int i =0 ;i<p_array->length;i++)
        scanf("%d",p_array->A+i);
}

int main()
{
    ARRAY           *p_array = NULL ;

    p_array = (ARRAY *)malloc(sizeof(ARRAY));
    memset(p_array,0,sizeof(ARRAY));

    printf("Enter max size of Array:");
    scanf("%d",&p_array->size);
    printf("Enter length  of Array:");
    scanf("%d",&p_array->length);
    p_array->A = (int *)malloc(p_array->size*sizeof(int));

    printf("INSERT Array Elements :\n");
    Insert(p_array);

    printf("DISPLAY Array Elements :\n");
    Display(p_array);

    return 0;
}
