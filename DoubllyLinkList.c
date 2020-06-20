#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

typedef enum {False,True} MyBool;
struct node 
{
    int data;
    struct node *next;
    struct node *prev;
};

void InsertDoubllyLinkList(struct node **ptr,int value)
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
    temp->prev = NULL;
    if (NULL == *ptr)
    {
        *ptr = temp;
    }
    else
    {
        while (NULL != p->next)
        {
            p = p->next;
        }
        p->next    = temp;
        temp->prev = p;
    }

}

void DisplayDoubllyLinkList(struct node *ptr)
{

    if (NULL != ptr)
    {
        printf("NULL<-->");
        while(NULL != ptr)
        {
            printf("%d<-->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DeleteDoubllyLinkList(struct node **ptr)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    
    current = *ptr;
    if(NULL!= *ptr)
    {
        while(current->next !=NULL)
        {
            temp       = current;
            current    = current->next;
        }
        temp->next = current->next;
        free(current);
        current = NULL;
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void reversingDoubllyLinkList(struct node **ptr)
{
    struct node *current = NULL;
    struct node *temp    = NULL;

    current = *ptr;
    if (NULL != *ptr)
    {
        while(NULL != current)
        {
            temp = current->prev;
            current->prev = current->next;
            current->next = temp;
            current = current->prev;
        }
        if (NULL != temp)
        {
            *ptr = temp->prev;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
        exit(1);
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
        printf("1.Insert\n2.Display\n3.Delete\n4.Reverse\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertDoubllyLinkList(&head,value);
                break;
            }
            case 2:
            {
                printf("******************************** \n");
                printf("*******DOUBLLY LINK LIST******** \n");
                printf("******************************** \n");
                DisplayDoubllyLinkList(head);
                break;
            }
            case 3:
            {
                printf("Doublly Link List before Deletion \n");
                DisplayDoubllyLinkList(head);
                DeleteDoubllyLinkList(&head);
                printf("Doublly Link List after Deletion \n");
                DisplayDoubllyLinkList(head);
                break;
            }
            case 4:
            {
                printf("Doublly Link List before Reverse \n");
                DisplayDoubllyLinkList(head);
                reversingDoubllyLinkList(&head);
                printf("Doublly Link List after Reverse \n");
                DisplayDoubllyLinkList(head);
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
        printf("Freeing Doublly Link List\n");
        free(head);
        head = NULL;
    }

    return 0;
}
