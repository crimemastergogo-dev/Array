#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef enum {False,True} MyBool;
struct node 
{
    int data;

    struct node *next;
};

void InsertCircularLL(struct node **ptr,int value)
{
    struct node *temp = NULL;
    struct node *p = NULL;
    p = *ptr;
    temp = (struct node *)malloc(sizeof(struct node));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        exit(1);
    }
    memset(temp,0,sizeof(struct node));

    temp->data = value;
    temp->next = NULL;
    if (NULL == *ptr)
    {
        *ptr = temp;
        temp->next = *ptr;
    }
    else
    {
        while (*ptr != p->next)
        {
            p = p->next;
        }
        p->next = temp;
        temp->next = *ptr;
    }
}

void DisplayCircularLinkList(struct node *ptr)
{
    struct node *first = NULL;

    first = ptr;

    if (NULL != ptr)
    {
        while(first != ptr->next)
        {
            printf("%d-->",ptr->data);
            ptr = ptr->next;
        }
        printf("%d-->%d\n",ptr->data,first->data);
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DeleteCircularLL(struct node **ptr)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    
    current = *ptr;
    if(NULL!= *ptr)
    {
        while(current->next != *ptr)
        {
            temp       = current;
            current    = current->next;
        }
        temp->next = *ptr;
        free(current);
        current = NULL;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

int main()
{
    struct node *head = NULL;
    int choice = 0; 
    int value  = 0; 
    int cont   = 0; 

    do
    {
        printf("1.Insert\n2.Display\n3.Delete\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertCircularLL(&head,value);
                break;
            }
            case 2:
            {
                printf("******************************** \n");
                printf("******CIRCULAR LINK LIST******** \n");
                printf("******************************** \n");
                DisplayCircularLinkList(head);
                break;
            }
            case 3:
            {
                printf("Circular link list befor Deletetion\n");
                DisplayCircularLinkList(head);
                DeleteCircularLL(&head);
                printf("Circular link list after Deletetion\n");
                DisplayCircularLinkList(head);
                break;
            }
            default:
                printf("Wrong Choice : \n");
        
        }
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);

    if (NULL != head)
    {
        printf("Freeing Circular Link List\n");
        free(head);
        head = NULL;
    }

    return 0;
}
