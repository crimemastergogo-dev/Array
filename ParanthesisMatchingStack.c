#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING_LIMIT 1024

typedef enum {False,True} MyBool;

typedef struct
{
    char *chr;
    int length;
}String;

void mallocString(String *ptr,int len)
{
    if (0 < len )
    {
        ptr->chr = (char *)malloc(len);
    }
    else if ((0 >len) || (NULL == ptr->chr))
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }

}
void getString(String *ptr)
{
    char temp[MAX_STRING_LIMIT];
    int index =0;

    fgets(temp,MAX_STRING_LIMIT,stdin);
    int len = strlen(temp);

    mallocString(ptr,len);

    for (index =0;index<len;index++)
    {
        ptr->chr[index] = temp[index];
    }
    *(ptr->chr +len -1) = '\0';
    ptr->length = strlen(ptr->chr);
}

char *DisplayString(String *ptr)
{
    if (0 > ptr->length)
    {
        fprintf(stderr,"ERROR:string length is 0 no string found ");
        exit (1);
    }
    else
        return ptr->chr;
}

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
        printf("Paranthesis Mis-Matched...!!!\n");
        exit(1);
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

void CheckParanthesis(String *string)
{
    struct StackLinkList  *stack  = NULL;
    struct StackLinkList  *top    = NULL;
    int Index                     = 0;

    for (Index = 0 ; Index < string->length;Index++)
    {
        if ('(' == string->chr[Index])
        {
            push(&stack,&top,1);
        }
        if (')' == string->chr[Index])
        {
            pop(&stack,&top);
        }
        if ('{' == string->chr[Index])
        {
            push(&stack,&top,1);
        }
        if ('}' == string->chr[Index])
        {
            pop(&stack,&top);
        }
        if ('[' == string->chr[Index])
        {
            push(&stack,&top,1);
        }
        if (']' == string->chr[Index])
        {
            pop(&stack,&top);
        }
    }

    if (isEmpty(top))
    {
        printf("Paranthesis Mis-Matched...!!!\n");
    }
    else
    {
        printf("Paranthesis Matched...!!!\n");
    }

    if (NULL != stack)
    {
        free(stack);
        stack = NULL;
    }
    if (NULL != top)
    {
        free(top);
        top = NULL;
    }
}

int main()
{
    String *string                = NULL; 

    string = (String *)malloc(sizeof(String));
    if (NULL == string)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(string,0,sizeof(String));

    fprintf(stdout,"Enter the String :");

    getString(string);

    fprintf(stdout,"Entered  String : %s\n",DisplayString(string));

    CheckParanthesis(string);
    
    if ((NULL != string->chr) &&
            (NULL != string))
    {
        free(string->chr);
        string->chr = NULL;
        free(string);
        string = NULL;
    }

    return 0;
}
