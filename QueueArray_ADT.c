#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int front;
    int rear;
}Queue;

/*Initializing Queue*/
void QueueInit(Queue *ptr)
{
    printf("Enter max size of Queue:");
    scanf("%d",&ptr->size);
    ptr->front = -1;
    ptr->rear  = -1;
    if((ptr->rear < ptr->size) && (ptr->size > 0) && (ptr->front < ptr->size))
        ptr->A = (int *)malloc(ptr->size*sizeof(int));
    else
    {
        if (NULL == ptr->A)
        {
            printf("ERROR:Memory Allocation Failed\n");
            exit (1);
        }
    }
}

int isEmpty(Queue *ptr)
{
    int ret_val = 1;
    if (ptr->front == ptr->rear)
        ret_val = 0;

    ptr->front = -1;
    ptr->rear  = -1;
    return ret_val;
}

int isFull(Queue *ptr)
{
    int ret_val = 1;
    if (ptr->front > ptr->size)
        ret_val = 0;

    ptr->front = -1;
    ptr->rear  = -1;
    return ret_val;
}

void Enqueue(Queue *ptr, int data)
{
    if (0 == isFull(ptr))
    {
        printf("Queue is Full\n");
    }
    else
    {
        ptr->A[++ptr->rear] = data;
    }
}

int Dequeue(Queue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[++ptr->front];
    }
    return ret_val;
}

int QueueFront(Queue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->front+1];
    }

    return ret_val;
}

int QueueRear(Queue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->rear];
    }

    return ret_val;
}

void DisplayQueue(Queue *ptr)
{
    int index = 0;
    if(0 == isEmpty(ptr))
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (index = ptr->front+1;index <= ptr->rear;index++)
        {
            printf("|  %d |",ptr->A[index]);
        }
    }
}

int main()
{
    Queue *queue = NULL;
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    queue = (Queue *)malloc(sizeof(Queue));
    memset(queue,0,sizeof(Queue));

    QueueInit(queue);
    do
    {
        printf("1.Enqueue\n2.Dequeue\n3.Queue Front\n4.Queue Rear\n5.Is Empty Queue\n6.Is Full Queue\n7.Display \n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enqueue Element:");
                scanf("%d",&value);
                Enqueue(queue,value);
                break;
            }
            case 2:
            {
                printf("Queue before Dequeue\n");
                DisplayQueue(queue);
                printf("Dequeue Element: %d",Dequeue(queue));
                printf("Queue after Dequeue\n");
                DisplayQueue(queue);
                break;
            }
            case 3:
            {
                if (QueueFront(queue))
                {
                    printf("Queue Front = %d",QueueFront(queue));
                }
                break;
            }
            case 4:
            {
                if (QueueRear(queue))
                {
                    printf("Queue Rear = %d",QueueRear(queue));
                }

                break;
            }
            case 5:
            {
                if (0 == isEmpty(queue))
                    printf ("Queue is Empty\n");
                else
                    printf ("Queue is not Empty\n");
                break;
            }
            case 6:
            {
                if (0 == isFull(queue))
                    printf ("Queue is Full\n");
                else
                    printf ("Queue is not Full\n");
                break;
            }
            case 7:
            {
                DisplayQueue(queue);
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if((NULL != queue->A)&&(NULL != queue))
    {
        free(queue->A);
        queue->A = NULL;
        free(queue);
        queue = NULL;
    }

    return 0;
}
