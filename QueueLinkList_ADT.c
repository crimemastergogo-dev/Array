#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct  QueueLinkList
{
    int data;
    struct QueueLinkList *next;
};

struct QueueLinkList  *front  = NULL;
struct QueueLinkList  *rear   = NULL;

int isEmpty(void)
{
    int ret_val = 1;
    if (NULL == front)
        ret_val = 0;

    return ret_val;
}

int isFull()
{
    int ret_val = 1;
    struct QueueLinkList  *temp = NULL;
    temp = (struct QueueLinkList *)malloc(sizeof(struct QueueLinkList));
    if (NULL == temp)
    {
        ret_val = 0;
    }

    if (NULL != temp)
    {
        free(temp);
        temp = NULL;
    }

    return ret_val;
}

void EnqueueLL(struct QueueLinkList  **ptr,int value)
{
    if (0 == isFull())
    {
        printf("Queue Is Full\n");
    }
    else
    {
        struct QueueLinkList  *temp = NULL;
        temp = (struct QueueLinkList*)malloc(sizeof(struct QueueLinkList));
        if (NULL == temp)
        {
            printf("Memory Allocation Failed \n");
            exit(0);
        }
        temp->data = value;
        temp->next = NULL;
        if(NULL == rear)
        {
            *ptr  = temp;
            front = temp;
            rear  = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

void DisplayQueueLL()
{
    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        struct QueueLinkList  *current = NULL;
        for (current = front; current ; current = current->next)
        {
            printf("|  %d  |",current->data);
        }
        printf("\n");
    }
}

int  NodeCountQueueLL()
{
    int count = 0;
    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        struct QueueLinkList  *current = NULL;
        for (current = front; current ; current = current->next)
        {
            printf("|  %d  |",current->data);
        }
        printf("\n");
    }
    return count;
}


int DequeueLL()
{
    int ret_val = 0;
    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        struct QueueLinkList  *temp = NULL;
        temp    = front;
        ret_val = front->data; 
        front   = front->next;
        if (NULL == front)
        {
            rear = NULL;
        }
        if (NULL != temp)
        {
            free(temp);
            temp = NULL;
        }
    }
    return ret_val;
}

int QueueFrontLL()
{
    int ret_val = 0;

    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        ret_val = front->data;
    }
    return ret_val;
}

int QueueRearLL()
{
    int ret_val = 0;

    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        ret_val = rear->data;
    }
    return ret_val;
}

int main()
{
    struct QueueLinkList  *queue  = NULL;
    int            choice  = 0;
    int            value   = 0;
    int            cont    = 0;

    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Queue Front\n4.Queue Rear\n5.Is Empty Queue\n6.Is Full Queue\n7.Display\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter  Element:");
                scanf("%d",&value);
                EnqueueLL(&queue,value);
                break;
            }
            case 2:
            {
                printf("Element before Dequeue\n");
                DisplayQueueLL();
                printf("Dequeue Element : %d\n",DequeueLL());
                printf("Element after Dequeue\n");
                DisplayQueueLL();
                break;
            }
            case 3:
            {
                if (QueueFrontLL())
                {
                   printf("Queue Front = %d\n",QueueFrontLL());
                }
                break;
            }
            case 4:
            {
                if (QueueRearLL())
                {
                   printf("Queue Rear = %d\n",QueueRearLL());
                }

                break;
            }
            case 5:
            {
                if (0 == isEmpty())
                    printf ("Queue is Empty\n");
                else
                    printf ("Queue is not Empty\n");
                break;
            }
            case 6:
            {
                if (0 == isFull())
                    printf ("Queue is Full\n");
                else
                    printf ("Queue is not Full\n");
                break;
            }
            case 7:
            {
                DisplayQueueLL();
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if(NULL != queue)
    {
        free(queue);
        queue = NULL;
    }

    return 0;
}
