#include<stdio.h>
#include<stdlib.h>
#include<string.h>

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

void DisplayStack(struct StackLinkList *ptr,struct StackLinkList *top)
{
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
                printf("| %d |\n",ptr->data);
                printf("|____|\n");
                ptr = ptr->next;
            }
        }
        else
        {
            printf("Stack is Empty\n");
        }
    }
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


void pop(struct StackLinkList **ptr,struct StackLinkList **top)
{
    if (0 == isEmpty(*top))
    {
        printf("Stack is Empty\nNo Element can be poped further\n");
    }
    else
    {
        struct StackLinkList *temp = NULL;
        if (NULL != *ptr)
        {
            temp = *ptr;
            *ptr = temp->next;
            *top = temp->next;
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
}

int StackTop(struct StackLinkList *top)
{
    int ret_val = 0;

    if (0 == isEmpty(top))
    {
        printf("Stack is Empty\n");
    }
    else
    {
            return top->data;
    }
    return ret_val;
}


int peek(struct StackLinkList *ptr,struct StackLinkList *top,int pos)
{
    int ret_val = 0;
    int index   = NodeCountStack(ptr,top);

    if (0 == isEmpty(top))
    {
        printf("Stack is Empty\n");
    }
    else
    {
        if (NULL != ptr)
        {
            if (index < pos)
            {
                printf("Peek Pos is greater than Top\nNo element present\n");
            }
            else
            {
                while ((ptr) && (index != pos))
                {
                    ptr = ptr->next;
                    index--;
                }
                return ptr->data;
            }
        }
        else
        {
            printf("Stack is Empty\n");
        }

    }

    return ret_val;
}

int main()
{
    struct StackLinkList  *stack  = NULL;
    struct StackLinkList  *top    = NULL;
    int            choice  = 0;
    int            value   = 0;
    int            cont    = 0;

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
                push(&stack,&top,value);
                break;
            }
            case 2:
            {
                printf("Element before POP\n");
                DisplayStack(stack,top);
                printf("Poping Element\n");
                pop(&stack,&top);
                printf("Element after POP\n");
                DisplayStack(stack,top);
                break;
            }
            case 3:
            {
                printf("Enter Index to Peek:");
                scanf("%d",&value);
                if (peek(stack,top,value))
                {
                    printf("Value at index %d = %d\n",value,peek(stack,top,value));
                }

                break;
            }
            case 4:
            {
                if (StackTop(top))
                {
                   printf("Stack Top = %d\n",StackTop(top));
                }

                break;
            }
            case 5:
            {
                if (0 == isEmpty(top))
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
                DisplayStack(stack,top);
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if(NULL != stack)
    {
        free(stack);
        stack = NULL;
    }

    return 0;
}
