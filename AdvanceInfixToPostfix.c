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
    char data;
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

void push(struct StackLinkList **ptr,struct StackLinkList **top,char data)
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
                printf("| %c |\n",ptr->data);
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


char pop(struct StackLinkList **ptr,struct StackLinkList **top)
{
    char ret_val = '\0';
    if (0 == isEmpty(*top))
    {
        printf("Stack Underflow...!!!\n");
        exit(1);
    }
    else
    {
        struct StackLinkList *temp = NULL;
        if (NULL != *ptr)
        {
            temp = *ptr;
            ret_val = temp->data;
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
    return ret_val;
}

char StackTop(struct StackLinkList *top)
{
    char ret_val = '\0';

    if (0 == isEmpty(top))
    {
        ret_val = '\0';
    }
    else
    {
            ret_val = top->data;
    }
    return ret_val;
}

int isOperend(char chr)
{
    int ret_val = 1;
    if ((chr == '+') || (chr == '-') || (chr == '/') || (chr == '*') || 
            (chr == '(') || (chr == ')') || (chr == '^'))
    {
        ret_val = 0;
    }

    return ret_val;
}

int PrecedenceOutsideStack(char chr)
{
    int ret_val = 0;

    if ((chr == '+') || (chr == '-'))
        ret_val = 1;
    else if ((chr == '*') || (chr == '/'))
        ret_val = 3;
    else if (chr == '^')
        ret_val = 6;
    else if (chr == '(')
        ret_val = 7;
    else if (chr == ')')
        ret_val = 0;

    return ret_val;
}

int PrecedenceInsideStack(char chr)
{
    int ret_val = 0;

    if ((chr == '+') || (chr == '-'))
        ret_val = 2;
    else if ((chr == '*') || (chr == '/'))
        ret_val = 4;
    else if (chr == '^')
        ret_val = 5;
    else if (chr == '(')
        ret_val = 0;

    return ret_val;
}

void convert(String *Infix ,String *postfix)
{
    struct StackLinkList *stack = NULL;
    struct StackLinkList *top   = NULL;
    int Index_Infix             = 0;
    int Index_postfix           = 0;

    while (Infix->chr[Index_Infix]!= '\0')
    {
        if(isOperend(Infix->chr[Index_Infix]))
        {
            postfix->chr[Index_postfix++] = Infix->chr[Index_Infix++];
        }
        else
        {
            if(PrecedenceOutsideStack(Infix->chr[Index_Infix]) > 
                    PrecedenceInsideStack(StackTop(top)))
            {
                push(&stack,&top,Infix->chr[Index_Infix++]);
                continue;
            }
            if(PrecedenceOutsideStack(Infix->chr[Index_Infix]) == 
                    PrecedenceInsideStack(StackTop(top)))
            {
                pop(&stack,&top);
                Index_Infix++;
                continue;
            }
            else
            {
                postfix->chr[Index_postfix++] =  pop(&stack,&top);
            }
        }
    }

    while (isEmpty(top))
    {
        postfix->chr[Index_postfix++] =  pop(&stack,&top);
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
    String *Infix               = NULL; 
    String *postfix             = NULL; 

    Infix = (String *)malloc(sizeof(String));
    if (NULL == Infix)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(Infix,0,sizeof(String));

    postfix = (String *)malloc(sizeof(String));
    if (NULL == postfix)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(postfix,0,sizeof(String));


    fprintf(stdout,"Enter the Infix String :");

    getString(Infix);
    

    mallocString(postfix,Infix->length+1);

    convert(Infix ,postfix);

    fprintf(stdout,"Infix     String : %s\n",DisplayString(Infix));
    fprintf(stdout,"Postfix   String : %s\n",DisplayString(postfix));
    
    if ((NULL != Infix->chr) &&
            (NULL != Infix))
    {
        free(Infix->chr);
        Infix->chr = NULL;
        free(Infix);
        Infix = NULL;
    }
    if ((NULL != postfix->chr) &&
            (NULL != postfix))
    {
        free(postfix->chr);
        postfix->chr = NULL;
        free(postfix);
        postfix = NULL;
    }

    return 0;
}
