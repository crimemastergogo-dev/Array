#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct BinaryTree
{
    int data;
    struct BinaryTree *Left_child;
    struct BinaryTree *Right_child;
};

struct  QueueLinkList
{
    void *data;
    struct QueueLinkList *next;
};

struct QueueLinkList  *front  = NULL;
struct QueueLinkList  *rear   = NULL;

int isEmpty(void)
{
    int ret_val = 1;
    if (NULL == front) 
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

void EnqueueLL(struct QueueLinkList  **ptr,void *value)
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
        if(NULL == rear)
        {
            *ptr  = temp;
            front = temp;
            rear  = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
        }
    }
}

void *DequeueLL()
{
    void *ret_val = NULL;

    if (0 == isEmpty())
    {
        printf("Queue Is Empty\n");
    }
    else
    {
        struct QueueLinkList  *temp = NULL;
        temp    = front;
        ret_val = front->data; 
        front   = front->next;
        if (NULL == front)
        {
            rear = NULL;
        }
        if (NULL != temp)
        {
            free(temp);
            temp = NULL;
        }
    }
    return ret_val;
}

void pre_orderDisplay(struct BinaryTree *ptr)
{
    if (NULL != ptr)
    {
        printf("%d ",ptr->data);
        pre_orderDisplay(ptr->Left_child);
        pre_orderDisplay(ptr->Right_child);
    }
}
void post_orderDisplay(struct BinaryTree *ptr)
{
    if (NULL != ptr)
    {
        post_orderDisplay(ptr->Left_child);
        post_orderDisplay(ptr->Right_child);
        printf("%d ",ptr->data);
    }
}
void In_orderDisplay(struct BinaryTree *ptr)
{
    if (NULL != ptr)
    {
        In_orderDisplay(ptr->Left_child);
        printf("%d ",ptr->data);
        In_orderDisplay(ptr->Right_child);
    }
}

void CreateBinaryTree(struct BinaryTree **Node)
{
    struct BinaryTree    *root  = NULL;
    struct BinaryTree    *temp  = NULL;
    struct QueueLinkList *queue = NULL;
    int value                   = 0;

    printf("Enter Root value:");
    scanf("%d",&value);

    root = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
    if(NULL == root)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }

    memset(root,0,sizeof(struct BinaryTree));
    root->data = value;
    root->Left_child  = NULL;
    root->Right_child = NULL;
    *Node = root;

    EnqueueLL(&queue,root);

    while(isEmpty())
    {
        root = (struct BinaryTree *)DequeueLL();
        printf("Current  Node %d\n",root->data);
        printf("Enter Left Child (enter -1 for No Left Child):");
        scanf("%d",&value);
        if (-1 != value)
        {
            temp = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
            if(NULL == temp)
            {
                printf("Memory Allocation Failed\n");
                exit(1);
            }
            memset(temp,0,sizeof(struct BinaryTree));
            temp->data = value;
            temp->Left_child  = NULL;
            temp->Right_child = NULL;
            root->Left_child  = temp;
            EnqueueLL(&queue,temp);
        }
        printf("Enter Right Child (enter -1 for No Right Child):");
        scanf("%d",&value);
        if (-1 != value)
        {
            temp = (struct BinaryTree *)malloc(sizeof(struct BinaryTree));
            if(NULL == temp)
            {
                printf("Memory Allocation Failed\n");
                exit(1);
            }
            memset(temp,0,sizeof(struct BinaryTree));
            temp->data = value;
            temp->Left_child  = NULL;
            temp->Right_child = NULL;
            root->Right_child  = temp;
            EnqueueLL(&queue,temp);
        }
    }

    if(NULL != queue)
    {
        free(queue);
        queue = NULL;
    }


}

int main()
{
    struct BinaryTree *root = NULL;

    printf("Creating Binary Tree \n");
    CreateBinaryTree(&root);

    printf("Pre Order Traversal using Recursion \n");
    pre_orderDisplay(root);

    printf("\nPost Order Traversal using Recursion \n");
    post_orderDisplay(root);

    printf("\nIn Order Traversal using Recursion \n");
    In_orderDisplay(root);

    if (NULL != root)
    {
        free(root);
        root = NULL;
    }

    return 0;
}
