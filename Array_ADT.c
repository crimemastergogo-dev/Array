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
        *(p_array->A + p_array->length) = element;
        p_array->length++;
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
    if(index >= 0 && index <= p_array->length)
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

/*Deleting the element in an array*/
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
/*Transpostion and  move to front can be used to improve Linear Searching*/
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

/*Binary Search in array*/
/*Pre-requiste for binary search is that the Array should be sorted*/
void BinarySearch(ARRAY *p_array,int key)
{
    int mid  = 0;
    int low  = 0;
    int high = p_array->length-1;
    int flag = 0;

    while(low<=high)
    {
        mid = (low + high)/2;

        if(key == *(p_array->A+mid))
        {
            flag = 1;
            printf("Element %d found at index %d\n",key,mid);
            break;
        }
        else if(key < *(p_array->A+mid))
        {
            high = mid-1;
        }
        else 
            low = mid + 1;
    }

    if(flag == 0)
        printf("No such Element in the Array\n");

    return;
}

/*Fetching element from index*/
int GetElement(ARRAY *p_array,int index)
{
    if(index >= 0 && index < p_array->length)
        return *(p_array->A+index);
    else
        return -1;
}

/*Replacing any element at given index*/
void SetElement(ARRAY *p_array,int index,int value)
{
    if(index >= 0 && index < p_array->length)
         *(p_array->A+index) = value;
    else
    {
        printf("INVALID INDEX\n");
        return;
    }
    printf("Array Elements after Replacing element %d at index %d\n",value,index);
    Display(p_array);
    return;
}

/*MAX & MIN Element in an Array*/
void MaxMin(ARRAY *ptr)
{
    int max = *ptr->A;
    int min = *ptr->A;
    int i   = 0;

    for (i = 0;i<ptr->length;i++)
        if(*(ptr->A+i)>max)
            max = *(ptr->A+i);

    for (i = 0;i<ptr->length;i++)
        if(*(ptr->A+i)<min)
            min = *(ptr->A+i);
    printf("Max Element in the Array is %d \n",max);
    printf("Min Element in the Array is %d \n",min);

    return;
}

/*sum of all the element*/
int sumArray(ARRAY *ptr)
{
    int i   = 0;
    int sum = 0;
    for (i = 0; i < ptr->length;i++)
        sum+=*(ptr->A + i);
    return sum;
}

/*Avg of all the element*/
double AvgArray(ARRAY *ptr)
{
    int i   = 0;
    int sum = 0;
    for (i = 0; i < ptr->length;i++)
        sum+=*(ptr->A + i);
    return sum/ptr->length;
}

/*Reversal of Array*/
void Reverse(ARRAY *ptr)
{
    int mid  = 0;
    int i    = 0;
    int temp = 0;

    printf("Original Array\n");
    Display(ptr);

    mid = ptr->length/2;

    for(i = 0 ;i< mid ;i++)
    {
        temp = *(ptr->A + (ptr->length-1-i));
        *(ptr->A + (ptr->length-1-i)) = *(ptr->A+i);
        *(ptr->A+i) = temp;
    } 

    printf("Array elements after Reversal :\n ");
    Display(ptr);

    return;
}

/*Left Shift*/
void LeftShift(ARRAY *ptr)
{
    int i = 0;

    printf("Original Array\n");
    Display(ptr);

    for (i =0;i < ptr->length;i++)
        *(ptr->A+i) = *(ptr->A+i+1);

    *(ptr->A + ptr->length-1) = 0;

    printf("Array elements after Left Shift :\n ");
    Display(ptr);

    return;
}

/*Left Rotate*/
void LeftRotate(ARRAY *ptr)
{
    int i    = 0;
    int temp = *(ptr->A);

    printf("Original Array\n");
    Display(ptr);

    for (i =0;i < ptr->length;i++)
        *(ptr->A+i) = *(ptr->A+i+1);

    *(ptr->A + ptr->length-1) = temp;

    printf("Array elements after Left Rotate :\n ");
    Display(ptr);

    return;
}

/*Right Shift*/
void RightShift(ARRAY *ptr)
{
    int i = 0;

    printf("Original Array:\n");
    Display(ptr);

    for (i = ptr->length-1;i>=0;i--)
        *(ptr->A+i) = *(ptr->A+i-1);

    *(ptr->A) = 0;

    printf("Array elements after Right Shift :\n ");
    Display(ptr);

    return;
}

/*Right Rotate*/
void RightRotate(ARRAY *ptr)
{
    int i    = 0;
    int temp = *(ptr->A+ptr->length-1);

    printf("Original Array:\n");
    Display(ptr);

    for (i = ptr->length-1;i>=0;i--)
        *(ptr->A+i) = *(ptr->A+i-1);

    *(ptr->A) = temp;

    printf("Array elements after Right Rotate :\n ");
    Display(ptr);

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
    if(p_array->length < p_array->size && p_array->size > 0)
        p_array->A = (int *)malloc(p_array->size*sizeof(int));
    else
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    printf("INSERT Array Elements:\n");
    Insert(p_array);

    printf("DISPLAY Array Elements:\n");
    Display(p_array);

    printf("Enter element to append:\n");
    scanf("%d",&element);
    Append(p_array,element);

    printf("Enter the Element at any position:\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    printf("Enter value to be inserted:\n");
    scanf("%d",&value);
    InsertPos(p_array,value,index);

    printf("Delete the Element from any position:\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    Delete(p_array,index);

    printf("Linear Searching in Array\n");
    printf("Enter value to be searched:\n");
    scanf("%d",&value);
    LinearSearch(p_array,value);

    printf("Binary Searching in Array\n");
    printf("Enter value to be searched:\n");
    scanf("%d",&value);
    BinarySearch(p_array,value);

    printf("Element from given index :\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    if(GetElement(p_array,index) == -1)
        printf("INVALID INDEX\n");
    else
        printf("Element at index %d is %d\n",index,GetElement(p_array,index));

    printf("Replacing Element at any position:\n");
    printf("Enter the index:\n");
    scanf("%d",&index);
    printf("Enter value to be inserted:\n");
    scanf("%d",&value);
    SetElement(p_array,index,value);

    printf("MAX and MIN Element in ARRAY->\n");
    MaxMin(p_array); 

    printf("Sum of all the Elements :%d\n",sumArray(p_array));
    printf("Average of the Elements :%f\n",AvgArray(p_array));

    Reverse(p_array);
    LeftShift(p_array);
    LeftRotate(p_array);
    RightShift(p_array);
    RightRotate(p_array);
   
    free(p_array->A);
    free(p_array);
    return 0;
}
