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

/* Insert in Sorted Array */
void InsertSorted(ARRAY *ptr,int element)
{
    int i = ptr->length -1;

    while(*(ptr->A+i)>element)
    {
        *(ptr->A+i+1) = *(ptr->A+i);
            i--;
    }
    *(ptr->A+i+1) = element;
    return;
}

/*Checking Sorted or not*/
void CheckSorted(ARRAY *ptr)
{
    int i    = 0;
    int flag = 0;
    for (i = 0;i<ptr->length-1;i++)
    {
        if(*(ptr->A+i)>*(ptr->A+i+1))
        {
            flag = 1;
            break;
        }
    }
    if(flag == 0)
    {
        printf("List is Sorted\n");
    }
    else
    {
        printf("List is Not Sorted\n"); 
    }
    return;
}

/*splitting -ve and +ve elements*/
void splitElement(ARRAY *ptr)
{
    int i    = 0;
    int j    = ptr->length-1;
    int temp = 0;

    while(i<j)
    {
        while(*(ptr->A+i)<0)i++;
        while(*(ptr->A+i)>=0)j--;
        if(i<j)
        {
            temp = *(ptr->A+i);
            *(ptr->A+i) = *(ptr->A+j);
            *(ptr->A+j) = temp;
        }
    }

    printf("Array elements after splitting -ve and +ve elements :\n ");
    Display(ptr);

    return;

}

/*Merge Two Array*/
/*It can be done in sorted list only*/
void Merege(ARRAY *ptr1,ARRAY *ptr2)
{
    ARRAY *p_arrayC = NULL;
    int       sizeC = 0;
    int        lenC = 0;
    int           i = 0;
    int           j = 0;
    int           k = 0;

    p_arrayC = (ARRAY *)malloc(sizeof(ARRAY));
    memset(p_arrayC,0,sizeof(ARRAY));

    
    sizeC = ptr2->size + ptr1->size;
    lenC  = ptr2->length + ptr1->length;
    p_arrayC->size   = sizeC;
    p_arrayC->length = lenC;
    if(lenC < sizeC && sizeC > 0)
        p_arrayC->A = (int *)malloc(sizeC*sizeof(int));
    else
    {
        printf("ERROR:Memory Allocation Failed for ARRAY C\n");
        exit (1);
    }
    
    while(i < ptr1->length && j <ptr2->length)
    {
        if(*(ptr1->A+i)<*(ptr2->A+j))
        {
            *(p_arrayC->A+k) = *(ptr1->A+i);
            k++;
            i++;     
        }
        else
        {
            *(p_arrayC->A+k) = *(ptr2->A+j);
            k++;
            j++;     
        }
    }
    for(;i < ptr1->length;i++)
    {
        *(p_arrayC->A+k) = *(ptr1->A+i);
        k++;
    }
    for(;j < ptr2->length;j++)
    {
        *(p_arrayC->A+k) = *(ptr2->A+j);
        k++;
    }

    printf("Merged Array :\n ");
    Display(p_arrayC);
    free(p_arrayC->A);
    free(p_arrayC);
    return;
}

int main()
{
    ARRAY           *p_array  = NULL ;
    ARRAY           *p_arrayB = NULL;
    int             element   = 0; 
    int             index     = 0;
    int             value     = 0;
    int             choice    = 0;
    char            ch;

    p_array = (ARRAY *)malloc(sizeof(ARRAY));
    memset(p_array,0,sizeof(ARRAY));

    p_arrayB = (ARRAY *)malloc(sizeof(ARRAY));
    memset(p_arrayB,0,sizeof(ARRAY));

    ArrayInit(p_array);

    do
    {
        printf("*************************************\n");
        printf("*************ARRAY ADT***************\n");
        printf("*************************************\n");
        printf("\n1.INSERT\n2.DISPLAY\n3.APPEND\n4.INSERT AT POS");
        printf("\n5.DELETE ELEMENT\n6.LINEAR SEARCH");
        printf("\n7.BINARY SEARCH\n8.ELEMENT AT INDEX");
        printf("\n9.REPLACING ELEMENT\n10.MAX MIN\n11.SUM OF ALL ELEMENT");
        printf("\n12.AVG of ELE\n13.REVERSE\n14.LEFT SHIFT");
        printf("\n15.LEFT ROTATE\n16.RIGHT SHIFT\n17.RIGHT ROTATE");
        printf("\n18.CHECK IF SORTED\n19.INSERT IN SORTED");
        printf("\n20.SPLIT -ve and +ve\n21.MERGE TWO ARRAY\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("INSERT Array Elements:\n");
                Insert(p_array);
                break;
            }
            case 2:
            {
                printf("DISPLAY Array Elements:\n");
                Display(p_array);
                break;
            }
            case 3:
            {
                printf("Enter element to append:\n");
                scanf("%d",&element);
                Append(p_array,element);
                break;
            }
            case 4:
            {
                printf("Enter the Element at any position:\n");
                printf("Enter the index:\n");
                scanf("%d",&index);
                printf("Enter value to be inserted:\n");
                scanf("%d",&value);
                InsertPos(p_array,value,index);
                break;
            }
            case 5:
            {
                printf("Delete the Element from any position:\n");
                printf("Enter the index:\n");
                scanf("%d",&index);
                Delete(p_array,index);
                break;
            }
            case 6:
            {
                printf("Linear Searching in Array\n");
                printf("Enter value to be searched:\n");
                scanf("%d",&value);
                LinearSearch(p_array,value);
                break;
            }
            case 7:
            { 
                printf("Binary Searching in Array\n");
                printf("Enter value to be searched:\n");
                scanf("%d",&value);
                BinarySearch(p_array,value);
                break;
            }
            case 8:
            {  
                printf("Element from given index :\n");
                printf("Enter the index:\n");
                scanf("%d",&index);
                if(GetElement(p_array,index) == -1)
                    printf("INVALID INDEX\n");
                else
                    printf("Element at index %d is %d\n",index,GetElement(p_array,index));
                break;
            }
            case 9:
            {   
                printf("Replacing Element at any position:\n");
                printf("Enter the index:\n");
                scanf("%d",&index);
                printf("Enter value to be inserted:\n");
                scanf("%d",&value);
                SetElement(p_array,index,value);
                break;
            }
            case 10:
            {
                printf("MAX and MIN Element in ARRAY->\n");
                MaxMin(p_array); 
                break;
            }
            case 11:
            {
                printf("Sum of all the Elements :%d\n",sumArray(p_array));
                break;
            }
            case 12:
            {
                printf("Average of the Elements :%f\n",AvgArray(p_array));
                break;
            }
            case 13:
            {
                Reverse(p_array);
                break;
            }
            case 14:
            {
                LeftShift(p_array);
                break;
            }
            case 15:
            {
                LeftRotate(p_array);
                break;
            }
            case 16:
            {
                RightShift(p_array);
                break;
            }
            case 17:
            {
                RightRotate(p_array);
                break;
            }
            case 18:
            {
                CheckSorted(p_array);
                break;
            }
            case 19:
            {
                printf("Enter element in sorted Array\n");
                printf("Enter value to be Entered:\n");
                scanf("%d",&value);
                InsertSorted(p_array,value);
                break;
            }
            case 20:
            {
                splitElement(p_array);
                break;
            }
            case 21:
            {
                ArrayInit(p_arrayB);
                printf("INSERT Array B Elements:\n");
                Insert(p_arrayB);

                printf("DISPLAY Array B Elements:\n");
                Display(p_arrayB);

                Merege(p_array,p_arrayB);
                break;
            }

            default:
            printf("WRONG OPTION\n");
        }
        printf("Do you want to continue (y/n):");
        scanf("%c",&ch);
    }while(ch == 'n');

    free(p_array->A);
    free(p_arrayB->A);
    free(p_array);
    free(p_arrayB);
    return 0;
}
