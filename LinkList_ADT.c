#include<stdio.h>
#include<stdlib.h>

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
        free(temp);
        temp =NULL;
    }

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
        while(NULL != ptr->next)
        {
            printf("%d--->",ptr->data);
            ptr = ptr->next;
        }
        printf("%d-->NULL\n",ptr->data);
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
        count = 1;
        while(NULL != ptr->next)
        {
            printf("%d--->",ptr->data);
            ptr = ptr->next;
            count ++;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return count;

}

void SearchElement(struct node *ptr, int value)
{
    int count =0;
    if (NULL != ptr)
    {
        count = 1;
        while(NULL != ptr->next)
        {
            count ++;
            if (value == ptr->data)
            {
                printf("Element %d found at node %d\n",value,count);
            }
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
}

int SumLinkList (struct node *ptr)
{
    int sum = 0;
    if (NULL != ptr)
    {
        while(NULL != ptr->next)
        {
            sum += ptr->data;
            ptr = ptr->next;
        }
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }
    return sum + ptr->data;

}


void MaxMinLinkList (struct node *ptr)
{
    int max = ptr->data;
    int min = ptr->data;
    if (NULL != ptr)
    {
        do
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
        }while(NULL != ptr->next);
        printf("Max Element = %d\nMin Element = %d\n",max,min);
    }
    else
    {
        printf("EMPTY LINK LIST\n");
    }


}
int main()
{
    struct node *head = NULL;
    int choice,value,cont,ele;

    do
    {
        printf("1.InsertAtEnd\n2.Display\n3.Display using Recursion\n");
        printf("4.No. of nodes\n5.Searching\n6.Sum of LL\n7.Max and Min\n");
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
            default:
                printf("Wrong Choice : \n");
        
        }
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);

    return 0;
}
