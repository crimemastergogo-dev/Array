#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct
{
    int *A;
    int size;
    int front;
    int rear;
}DEQueue;

/*Initializing DEQueue*/
void DEQueueInit(DEQueue *ptr)
{
    printf("Enter max size of DEQueue:");
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

int isEmpty(DEQueue *ptr)
{
    int ret_val = 1;
    if (ptr->front == ptr->rear)
        ret_val = 0;

    ptr->front = -1;
    ptr->rear  = -1;
    return ret_val;
}

int isFull(DEQueue *ptr)
{
    int ret_val = 1;
    if (ptr->front > ptr->size)
        ret_val = 0;

    ptr->front = -1;
    ptr->rear  = -1;
    return ret_val;
}

void EnDEqueue(DEQueue *ptr, int data)
{
    fflush(stdin);
    char choice = '\0';
    if (0 == isFull(ptr))
    {
        printf("DEQueue is Full\n");
    }
    else
    {
        printf("Insert from front/rear (enter f or r):\n");
        scanf(" %c",&choice);
        if ('r' == choice)
            ptr->A[++ptr->rear] = data;
        if ('f' == choice)
            ptr->A[++ptr->front] = data;
        else
            printf("Wrong Choice\n");
    }
}

int DeDEqueue(DEQueue *ptr)
{
    fflush(stdin);
    int ret_val = 0;
    char choice = '\0';
    if(0 == isEmpty(ptr))
    {
        printf("DEQueue is Empty\n");
    }
    else
    {
        printf("Delete from front/rear (enter f or r):\n");
        scanf(" %c",&choice);
        if ('f' == choice)
            ret_val = ptr->A[++ptr->front];
        else if ('r' == choice)
            ret_val = ptr->A[++ptr->rear];
        else
            printf("Wrong Choice\n");

    }
    return ret_val;
}

int DEQueueFront(DEQueue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("DEQueue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->front+1];
    }

    return ret_val;
}

int DEQueueRear(DEQueue *ptr)
{
    int ret_val = 0;
    if(0 == isEmpty(ptr))
    {
        printf("DEQueue is Empty\n");
    }
    else
    {
        ret_val = ptr->A[ptr->rear];
    }

    return ret_val;
}

void DisplayDEQueue(DEQueue *ptr)
{
    int index = 0;
    if(0 == isEmpty(ptr))
    {
        printf("DEQueue is Empty\n");
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
    DEQueue *dequeue = NULL;
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    dequeue = (DEQueue *)malloc(sizeof(DEQueue));
    memset(dequeue,0,sizeof(DEQueue));

    DEQueueInit(dequeue);
    do
    {
        printf("1.EnDEqueue\n2.DeDEqueue\n3.DEQueue Front\n4.DEQueue Rear\n5.Is Empty DEQueue\n6.Is Full DEQueue\n7.Display \n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("EnDEqueue Element:");
                scanf("%d",&value);
                EnDEqueue(dequeue,value);
                break;
            }
            case 2:
            {
                printf("DEQueue before DeDEqueue\n");
                DisplayDEQueue(dequeue);
                printf("DeDEqueue Element: %d",DeDEqueue(dequeue));
                printf("DEQueue after DeDEqueue\n");
                DisplayDEQueue(dequeue);
                break;
            }
            case 3:
            {
                if (DEQueueFront(dequeue))
                {
                    printf("DEQueue Front = %d",DEQueueFront(dequeue));
                }
                break;
            }
            case 4:
            {
                if (DEQueueRear(dequeue))
                {
                    printf("DEQueue Rear = %d",DEQueueRear(dequeue));
                }

                break;
            }
            case 5:
            {
                if (0 == isEmpty(dequeue))
                    printf ("DEQueue is Empty\n");
                else
                    printf ("DEQueue is not Empty\n");
                break;
            }
            case 6:
            {
                if (0 == isFull(dequeue))
                    printf ("DEQueue is Full\n");
                else
                    printf ("DEQueue is not Full\n");
                break;
            }
            case 7:
            {
                DisplayDEQueue(dequeue);
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    if((NULL != dequeue->A)&&(NULL != dequeue))
    {
        free(dequeue->A);
        dequeue->A = NULL;
        free(dequeue);
        dequeue = NULL;
    }

    return 0;
}
