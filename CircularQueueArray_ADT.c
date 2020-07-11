#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int front;
    int rear;
}CircularQueue;

/*Initializing CircularQueue*/
void CircularQueueInit(CircularQueue *ptr)
{
    printf("Enter max size of Circular CircularQueue:");
    scanf("%d",&ptr->size);
    ptr->front = 0;
    ptr->rear  = 0;
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

int isEmpty(CircularQueue *ptr)
{
    int ret_val = 1;
    if (ptr->front == ptr->rear)
        ret_val = 0;

    return ret_val;
}

int isFull(CircularQueue *ptr)
{
    int ret_val = 1;
    if (((ptr->rear +1)% ptr->size) == ptr->front)
        ret_val = 0;

    return ret_val;
}

void EnCircularcqueue(CircularQueue *ptr, int data)
{
    if (0 == isFull(ptr))
    {
        printf("CircularQueue is Full\n");
    }
    else
    {
        ptr->rear = (ptr->rear +1)% ptr->size;
        ptr->A[ptr->rear] = data;
    }
}

int DeCricularcqueue(CircularQueue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("CircularQueue is Empty\n");
    }
    else
    {
        ptr->front = (ptr->front +1)% ptr->size;
        ret_val = ptr->A[ptr->front];
    }
    return ret_val;
}

int CircularQueueFront(CircularQueue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("CircularQueue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->front+1];
    }

    return ret_val;
}

int CircularQueueRear(CircularQueue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("CircularQueue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->rear];
    }

    return ret_val;
}

void DisplayCircularQueue(CircularQueue *ptr)
{
    int index = ptr->front+1;
    if(0 == isEmpty(ptr))
    {
        printf("CircularQueue is Empty\n");
    }
    else
    {
        do
        {
            printf("|  %d |",ptr->A[index++]);
        }while(index != (ptr->rear+1)%ptr->size);
    }
}

int main()
{
    CircularQueue *cqueue = NULL;
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    cqueue = (CircularQueue *)malloc(sizeof(CircularQueue));
    memset(cqueue,0,sizeof(CircularQueue));

    CircularQueueInit(cqueue);
    do
    {
        printf("1.Encqueue\n2.Dequeue\n3.CircularQueue Front\n4.Queue Rear\n5.Is Empty Queue\n6.Is Full Queue\n7.Display \n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Encqueue Element:");
                scanf("%d",&value);
                EnCircularcqueue(cqueue,value);
                break;
            }
            case 2:
            {
                printf("CircularQueue before Decqueue\n");
                DisplayCircularQueue(cqueue);
                printf("Decqueue Element: %d",DeCricularcqueue(cqueue));
                printf("CircularQueue after Decqueue\n");
                DisplayCircularQueue(cqueue);
                break;
            }
            case 3:
            {
                if (CircularQueueFront(cqueue))
                {
                    printf("CircularQueue Front = %d",CircularQueueFront(cqueue));
                }
                break;
            }
            case 4:
            {
                if (CircularQueueRear(cqueue))
                {
                    printf("CircularQueue Rear = %d",CircularQueueRear(cqueue));
                }

                break;
            }
            case 5:
            {
                if (0 == isEmpty(cqueue))
                    printf ("CircularQueue is Empty\n");
                else
                    printf ("CircularQueue is not Empty\n");
                break;
            }
            case 6:
            {
                if (0 == isFull(cqueue))
                    printf ("CircularQueue is Full\n");
                else
                    printf ("CircularQueue is not Full\n");
                break;
            }
            case 7:
            {
                DisplayCircularQueue(cqueue);
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if((NULL != cqueue->A)&&(NULL != cqueue))
    {
        free(cqueue->A);
        cqueue->A = NULL;
        free(cqueue);
        cqueue = NULL;
    }

    return 0;
}
