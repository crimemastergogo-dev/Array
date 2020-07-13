#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_PRIORITY 3

struct  QueueLinkList
{
    char data;
    struct QueueLinkList *next;
};

struct QueueLinkList  *Pfront[MAX_PRIORITY]  = {NULL};
struct QueueLinkList  *Prear[MAX_PRIORITY]   = {NULL};

int isEmpty(struct QueueLinkList *ptr)
{
    int ret_val = 1;
    if (NULL == ptr)
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

int Priority(char value)
{
    int ret_val = 0;
    switch(value)
    {
        case 'A':
        case 'a':
        case 'G':
        case 'g':
        {
            ret_val = 1;
            break;
        }
        case 'B':
        case 'b':
        case 'C':
        case 'c':
        {
            ret_val = 2;
            break;
        }
        case 'D':
        case 'd':
        case 'E':
        case 'e':
        case 'F':
        case 'f':
        {
            ret_val = 3;
            break;
        }
        default :
        {
            printf("Wrong Input\n");
        }
    }

    return ret_val-1;
}

void EnPqueueLL(struct QueueLinkList  **ptr,char value)
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
        if(NULL == *ptr)
        {
            *ptr  = temp;
            Pfront[Priority(value)] = temp;
            Prear[Priority(value)]  = temp;
        }
        else
        {
            Prear[Priority(value)]->next = temp;
            Prear[Priority(value)] = temp;
        }
    }
}

void DisplayPQueueLL()
{
    int index = 0;
    int count = 0;
    for (index = 0 ; index < MAX_PRIORITY; index++)
    {
        if (0 == isEmpty(Prear[index]))
        {
            count++;
        }
    }
    if (MAX_PRIORITY == count) 
    {
        printf("Queue is Empty\n");
    }
    else
    {
        for (index = 0 ; index < MAX_PRIORITY; index++)
        {
            struct QueueLinkList  *current = NULL;
            if (0 == isEmpty(Prear[index]))
            {
                printf("PQueue %d is empty",index);
            }
            else
            {
                for (current = Pfront[index]; current ; current = current->next)
                {
                    printf("|  %c  |",current->data);
                }
            }
            printf("\n");
        }
    }
}


int DePqueueLL()
{
    char ret_val = '\0';
    int  index   = 0;
    int  count   = 0;

    for (index = 0 ; index < MAX_PRIORITY; index++)
    {
        if (0 == isEmpty(Prear[index]))
        {
            count++;
        }
    }
    if (MAX_PRIORITY == count) 
    {
        printf("Queue is Empty\n");
    }
    else
    {
        struct QueueLinkList  *temp = NULL;

        for (index = 0 ; index < MAX_PRIORITY; index++)
        {
            if (0 == isEmpty(Pfront[index]))
            {
                printf("PQueue %d is empty",index);
            }
            else
            {
                temp            = Pfront[index];
                ret_val         = Pfront[index]->data; 
                Pfront[index]   = Pfront[index]->next;
                if (NULL != temp)
                {
                    free(temp);
                    temp = NULL;
                }
                break;
            }
        }
    }

    return ret_val;
}

int main()
{
    struct QueueLinkList  *queue[MAX_PRIORITY]  = {NULL};
    int            choice  = 0;
    char           value   = 0;
    int            cont    = 0;
    int            index    = 0;

    do
    {
        printf("1.EnPqueue\n2.DePqueue\n3.Display\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter  Element:");
                scanf(" %c",&value);
                EnPqueueLL(&queue[Priority(value)],value);
                break;
            }
            case 2:
            {
                printf("Element before Dequeue\n");
                DisplayPQueueLL();
                printf("Dequeue Element : %c\n",DePqueueLL());
                printf("Element after Dequeue\n");
                DisplayPQueueLL();
                break;
            }
            case 3:
            {
                DisplayPQueueLL();
                break;
            }

            default:
                printf("Wrong Choice : \n");
        
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);
   
    for (index = 0 ; index < MAX_PRIORITY; index++)
    if(NULL != queue[index])
    {
        free(queue[index]);
        queue[index] = NULL;
    }

    return 0;
}
