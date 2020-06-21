#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct
{
    int *A;
    int size;
    int top;
}Stack;

/*Initializing Stack*/
void StackInit(Stack *ptr)
{
    printf("Enter max size of Array:");
    scanf("%d",&ptr->size);
    ptr->top = -1;
    if(ptr->top < ptr->size && ptr->size > 0)
        ptr->A = (int *)malloc(ptr->size*sizeof(int));
    else
    {
        printf("ERROR:Memory Allocation Failed\n");
        exit (1);
    }
}

int isEmpty(Stack *ptr)
{
    if (-1 == ptr->top)
        return 0;
    else
        return 1;
}

int isFull(Stack *ptr)
{
    if ((ptr->size-1) == ptr->top)
        return 0;
    else
        return 1;

}

void push(Stack *ptr, int data)
{
    if (0 == isFull(ptr))
    {
        printf("Stack is Full\nNo Element can be push further\n");
    }
    else
    {
        ptr->top++;
        ptr->A[ptr->top] = data;
    }
}

void pop(Stack *ptr)
{
    if (0 == isEmpty(ptr))
    {
        printf("Stack is Empty\nNo Element can be poped further\n");
    }
    else
    {
        ptr->A[ptr->top] = 0;
        ptr->top--;
    }
}

int peek(Stack *ptr,int index)
{
    int ret_val = 0;

    if (0 == isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        if (index > ptr->top)
        {
            printf("Index is greater than Top\nNo element present\n");
        }
        else
        {
            return ptr->A[index];
        }
    }

    return ret_val;
}

int StackTop(Stack *ptr)
{
    return ptr->top;
}

void DisplayStack(Stack *ptr)
{
    int index = 0;
    if (0 == isEmpty(ptr))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        for (index = ptr->top;index >=0 ;index--)
        {
            printf("| %d |\n",ptr->A[index]);
            printf("|____|\n");
        }
    }


}

int main()
{
    Stack *stack = NULL;
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    stack = (Stack *)malloc(sizeof(Stack));
    memset(stack,0,sizeof(Stack));

    StackInit(stack);
    do
    {
        printf("1.Push\n2.Pop\n3.Peek\n4.Stack top\n5.Is Empty Stack\n6.Is Full Stack\n7.Display\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Push Element:");
                scanf("%d",&value);
                push(stack,value);
                break;
            }
            case 2:
            {
                printf("Pop Element:");
                pop(stack);
                break;
            }
            case 3:
            {
                break;
            }
            case 4:
            {
                printf("Enter Index to Peek:");
                scanf("%d",&value);
                if (peek(stack,value))
                {
                    printf("Value at index %d = %d",value,peek(stack,value));
                }
                break;
            }
            case 5:
            {
                if (0 == isEmpty(stack))
                    printf ("Stack is Empty\n");
                else
                    printf ("Stack is not Empty\n");
                break;
            }
            case 6:
            {
                if (0 == isFull(stack))
                    printf ("Stack is Full\n");
                else
                    printf ("Stack is not Full\n");
                break;
            }
            case 7:
            {
                DisplayStack(stack);
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if(NULL != stack->A)
    {
        free(stack->A);
        stack->A = NULL;
    }

    return 0;
}
