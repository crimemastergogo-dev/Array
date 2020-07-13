#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STACK 2
struct  StackLinkList
{
    int data;
    struct StackLinkList *next;
};


int isEmpty(struct StackLinkList *top)
{
    if (NULL == top)
        return 0;
    else
        return 1;
}

int isFull()
{
    int ret_val = 1;
    struct StackLinkList *ptr = NULL;
    ptr = (struct StackLinkList *)malloc(sizeof(struct StackLinkList));
    if (NULL == ptr )
    {
        ret_val = 0;
    }
    if (NULL != ptr)
    {
        free(ptr);
        ptr = NULL;
    }
    return ret_val;
}

void push(struct StackLinkList **ptr,struct StackLinkList **top,int data)
{
    if (0 == isFull())
    {
        printf("Stack is Full\nNo Element can be push further\n");
    }
    else
    {
        struct StackLinkList *temp    = NULL;
        temp = (struct StackLinkList *)malloc(sizeof(struct StackLinkList));
        memset(temp,0,sizeof(struct StackLinkList));
        temp->data = data;
        temp->next = NULL;
        if (NULL == *ptr)
        {
            *ptr = temp;
            *top = temp;
        }
        else
        {
            temp->next = *ptr;
            *ptr = temp;
            *top = temp;
        }
    }
}


int pop(struct StackLinkList **ptr,struct StackLinkList **top)
{
    int ret_val = 0;
    if (0 == isEmpty(*top))
    {
        printf("Stack is Empty\nNo Element can be poped further\n");
    }
    else
    {
        struct StackLinkList *temp = NULL;
        if (NULL != *ptr)
        {
            temp    = *ptr;
            ret_val = temp->data;
            *ptr    = temp->next;
            *top    = temp->next;
            if (NULL != temp)
            {
                free(temp);
                temp = NULL;
            }
        }
        else
        {
            printf("Stack is Empty\n");
        }
    }

    return ret_val;
}

int  NodeCountStack(struct StackLinkList *ptr,struct StackLinkList *top)
{
    int count = 0;
    if (0 == isEmpty(top))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        if (NULL != ptr)
        {
            while (ptr)
            {
                count++;
                ptr = ptr->next;
            }
        }
        else
        {
            printf("Stack is Empty\n");
        }
    }
    return count;
}

int DequeueStack(struct StackLinkList *stack[MAX_STACK],struct StackLinkList *top[MAX_STACK])
{
    int ret_val = 0;
    int index   = 0;
    if (0 == isEmpty(top[0]))
    {
        printf("Stack is Empty\nNo Element can be poped further\n");
    }
    else
    {
        if (0 == isEmpty(top[1]))
        {
            for (index = 0 ;index <= NodeCountStack(stack[0],top[0]);index++)
            {
                push(&stack[1],&top[1],pop(&stack[0],&top[0]));
            }
        }

        ret_val = pop(&stack[1],&top[1]);
    }

    return ret_val;
}

int main()
{
    struct StackLinkList  *stack[MAX_STACK]  = {NULL};
    struct StackLinkList  *top[MAX_STACK]    = {NULL};
    int            choice  = 0;
    int            value   = 0;
    int            cont    = 0;
    int            index    = 0;

    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Display\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Push Element:");
                scanf("%d",&value);
                push(&stack[0],&top[0],value);
                break;
            }
            case 2:
            {
                printf("Dequeue Element %d\n",DequeueStack(stack,top));
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    for (index = 0 ; index < MAX_STACK; index++)
    {
        if(NULL != stack[index])
        {
            free(stack[index]);
            stack[index] = NULL;
        }
        if(NULL != top[index])
        {
            free(top[index]);
            top[index] = NULL;
        }
    }
    return 0;
}
