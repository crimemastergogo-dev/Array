#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef enum {False,True} MyBool;
struct node 
{
    int data;

    struct node *next;
};

void InsertAtEnd(struct node **ptr,int value)
{
    struct node *temp = NULL;
    struct node *p = NULL;
    p = *ptr;
    temp = (struct node *)malloc(sizeof(struct node));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        free(temp);
        temp =NULL;
        exit(1);
    }
    memset(temp,0,sizeof(struct node));

    temp->data = value;
    temp->next = NULL;
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
        p->next = temp;
    }

}
void DisplayLinkList(struct node *ptr)
{

    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            printf("%d-->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void DisplayLinkListRecursion(struct node *ptr)
{
    static int flag = 0;
    if (NULL != ptr)
    {
        flag =1;
        printf("%d--->",ptr->data);
        DisplayLinkListRecursion(ptr->next);
    }
    else if ((NULL == ptr)&&
            (0 == flag))
    {
        printf("EMPTY LINK LIST\n");
    }
    else if ((NULL == ptr)&&
            (1 == flag))
    {
        printf("NULL\n");
    }

}

int NodeCount(struct node *ptr)
{
    int count =0;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            count ++;
            printf("%d--->",ptr->data);
            ptr = ptr->next;
        }
        printf("NULL\n");
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return count;

}

void SearchElement(struct node *ptr, int value)
{
    int count           = 0;
    MyBool isValueFound = False;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            count++;
            if (value == ptr->data)
            {
                printf("Element %d found at node %d\n",value,count);
                isValueFound = True;
            }
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    if (True != isValueFound)
    {
        printf("Element %d not found \n",value);
    }
}

int SumLinkList (struct node *ptr)
{
    int sum = 0;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            sum += ptr->data;
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return sum;

}


void MaxMinLinkList (struct node *ptr)
{
    int max = ptr->data;
    int min = ptr->data;
    if (NULL != ptr)
    {
        while(NULL != ptr)
        {
            if (min > ptr->data)
            {
                min = ptr->data;
            }
            if (max < ptr->data)
            {
                max = ptr->data;
            }

            ptr = ptr->next;
        }

        printf("Max Element = %d\nMin Element = %d\n",max,min);
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

void InsertAtBeg(struct node **ptr,int value)
{
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node ));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        free(temp);
        temp =NULL;
        exit(1);
    }
    memset(temp,0,sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    if (NULL == *ptr)
    {
        printf ("Empty link List Adding first element \n");
        *ptr = temp;
    }
    else 
    {
        printf ("Link List exist Adding Element at the beg \n");
        temp->next = *ptr;
        *ptr = temp;
    }

}

void InsertAtPos(struct node **ptr,int value,int pos)
{
    struct node *temp    = NULL;
    struct node *current = NULL;
    int currentNode      = 0;
    temp = (struct node *)malloc(sizeof(struct node ));

    if (NULL == temp)
    {
        printf("Memory Allocation failed ");
        free(temp);
        temp =NULL;
        exit(1);
    }
    memset(temp,0,sizeof(struct node));
    temp->data = value;
    temp->next = NULL;

    current = *ptr;
    while(NULL !=current)
    {
        if (1 == pos)
        {
            if (NULL == *ptr)
            {
                printf ("Empty link List Adding first element \n");
                *ptr = temp;
            }
            else 
            {
                printf ("Link List exist Adding Element at the beg \n");
                temp->next = *ptr;
                *ptr = temp;
            }
        }
        if ((pos == currentNode-1) && ((currentNode-1) >=1))
        {
            temp->next    = current->next;
            current->next = temp;
        }
        currentNode++;
        current = current->next;
    }
}

int main()
{
    struct node *head = NULL;
    int choice = 0; 
    int value  = 0; 
    int cont   = 0; 
    int ele    = 0;
    int pos    = 0;

    do
    {
        printf("1.InsertAtEnd\n2.Display\n3.Display using Recursion\n");
        printf("4.No. of nodes\n5.Searching\n6.Sum of LL\n7.Max and Min\n");
        printf("8.Insert at beg\n9.Insert at pos\n10.Delete at pos\n11.Delete at beg\n");
        printf("12.Delete at end\n13.Insert in sorted list\n14.check if link list is sorted\n");
        printf("15.Delete by data\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertAtEnd(&head,value);
                break;
            }
            case 2:
            {
                printf("******************************** \n");
                printf("********SINGLE LINK LIST******** \n");
                printf("******************************** \n");
                DisplayLinkList(head);
                break;
            }
            case 3:
            {
                printf("******************************** \n");
                printf("********SINGLE LINK LIST******** \n");
                printf("******************************** \n");
                DisplayLinkListRecursion(head);
                break;
            }
            case 4:
            {
                printf("No. of nodes in the LINK LIST = %d\n",NodeCount(head));
                break;
            }
            case 5:
            {
            
                printf("Enter element for searching : ");
                scanf("%d",&ele);
                SearchElement(head,ele);
                break;
            }
            case 6:
            {
            
                printf("Sum of LL = %d\n", SumLinkList(head));
                break;
            }
            case 7:
            {
                MaxMinLinkList(head);
                break;
            }
            case 8:
            {
                printf("Enter Data to be inserted \n");
                scanf("%d",&value);
                InsertAtBeg(&head,value);
                break;
            }
            case 9:
            {
                printf("Enter Data to be inserted :");
                scanf("%d",&value);
                printf("Enter Pos : ");
                scanf("%d",&pos);
                InsertAtPos(&head,value,pos);
                break;
            }
            case 10:
            {
                MaxMinLinkList(head);
                break;
            }
            case 11:
            {
                MaxMinLinkList(head);
                break;
            }
            case 12:
            {
                MaxMinLinkList(head);
                break;
            }
            case 13:
            {
                MaxMinLinkList(head);
                break;
            }
            case 14:
            {
                MaxMinLinkList(head);
                break;
            }
            case 15:
            {
                MaxMinLinkList(head);
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
        printf("Freeing Link List\n");
        free(head);
        head = NULL;
    }

    return 0;
}
