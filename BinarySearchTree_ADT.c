#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _BinarySearchTree
{
    int data;
    struct _BinarySearchTree *Left_child;
    struct _BinarySearchTree *Right_child;
}BinarySearchTree_ADT;

void In_orderDisplay(BinarySearchTree_ADT *ptr)
{
    if (NULL != ptr)
    {
        In_orderDisplay(ptr->Left_child);
        printf("%d ",ptr->data);
        In_orderDisplay(ptr->Right_child);
    }
}

void CreatingBST_Itrative(BinarySearchTree_ADT **root,int value)
{
    BinarySearchTree_ADT *temp    = NULL;
    BinarySearchTree_ADT *current = NULL;
    BinarySearchTree_ADT *tailing = NULL;
    temp = (BinarySearchTree_ADT *)malloc(sizeof(BinarySearchTree_ADT));
    if (NULL == temp)
    {
        printf("Memory Allocation Failed\n");
        exit(1);
    }
    temp->data        = value;
    temp->Left_child  = NULL;
    temp->Right_child = NULL;

    if(NULL == *root)
    {
        *root = temp;
    }
    else
    {
        current = *root;
        while(current)
        {
            if (value == current->data)
            {
                printf("Can not Insert value is not unique\n");
                if (NULL != temp)
                {
                    free(temp);
                    temp = NULL;
                }
                return;
            }
            else if (value < current->data)
            {
                tailing = current;
                current = current->Left_child;
            }
            else if(value > current->data)
            {
                tailing = current;
                current = current->Right_child;
            }
        }
        if (value < tailing->data)
            tailing->Left_child  = temp;
        else if (value > tailing->data)
            tailing->Right_child = temp;
    }
}

BinarySearchTree_ADT * CreatingBST_Recursive(BinarySearchTree_ADT *root,int value)
{
    BinarySearchTree_ADT *temp    = NULL;

    if(NULL == root)
    {
        temp = (BinarySearchTree_ADT *)malloc(sizeof(BinarySearchTree_ADT));
        if (NULL == temp)
        {
            printf("Memory Allocation Failed\n");
            exit(1);
        }
        temp->data        = value;
        temp->Left_child  = NULL;
        temp->Right_child = NULL;
        root = temp;
    }
    if (value < root->data)
    {
        root->Left_child = CreatingBST_Recursive(root->Left_child,value);
    }
    else if (value > root->data)
    {
        root->Right_child = CreatingBST_Recursive(root->Right_child,value);
    }
    return root;
}

int  SearchBST_Itravtive(BinarySearchTree_ADT *root,int value)
{
    int ret_val = 0;

    if (NULL != root)
    {
        while(root)
        {
            if (value == root->data)
            {
                ret_val = 1;
                break;
            }
            else if (value < root->data)
            {
                root = root->Left_child;
            }
            else if(value > root->data)
            {
                root = root->Right_child;
            }
        }
    }
    else
    {
        printf("BST is Empty \n");
    }

    return ret_val;
}

int SearchBST_Recursive(BinarySearchTree_ADT *root,int value)
{
    int ret_val = 0;
    if (NULL != root)
    {
        if (value == root->data)
        {
            ret_val = 1;
            return ret_val;
        }
        else if(value < root->data)
            ret_val = SearchBST_Recursive(root->Left_child,value);
        else if (value > root->data)
            ret_val = SearchBST_Recursive(root->Right_child,value);
    
    }
    return ret_val;
}

int HeightBST(BinarySearchTree_ADT *root)
{
    int Left  = 0;
    int Right = 0;

    if (NULL == root)
        return 0;

    Left  = HeightBST(root->Left_child);
    Right = HeightBST(root->Right_child); 

    return Left>Right ?Left+1:Right+1; 
}

BinarySearchTree_ADT *InorderSuccBST(BinarySearchTree_ADT *root)
{
    while (root && (NULL !=root->Left_child))
        root = root->Left_child;

    return root;
}

BinarySearchTree_ADT *InorderPredBST(BinarySearchTree_ADT *root)
{
    while (root && (NULL !=root->Right_child))
        root = root->Right_child;

    return root;
}

BinarySearchTree_ADT *DeleteBST(BinarySearchTree_ADT *root,int data)
{
    BinarySearchTree_ADT        *temp  = NULL;
    static BinarySearchTree_ADT *Rnode = NULL;

    Rnode = root;

    if (NULL == root)
        return NULL;
    if ((NULL==root->Right_child) &&
            (NULL == root->Left_child))
    {
        if (Rnode == root)
            root = NULL;
        free(root);
        root = NULL;
        return NULL;
    }

    if (data > root->data)
        root->Right_child = DeleteBST(root->Right_child,data);
    else if(data < root->data)
        root->Left_child  = DeleteBST(root->Left_child,data);
    else
    {
        if (HeightBST(root->Right_child) < HeightBST(root->Left_child))
        {
            temp = InorderPredBST(root->Left_child);
            root->data = temp->data;
            root->Left_child = DeleteBST(root->Left_child,temp->data);
        }
        else
        {
            temp = InorderSuccBST(root->Right_child);
            root->data = temp->data;
            root->Right_child = DeleteBST(root->Right_child,temp->data);
        }

    }
    return root;
}

int main()
{
    BinarySearchTree_ADT *Iroot = NULL;
    BinarySearchTree_ADT *Rroot = NULL;
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    do
    {
        printf("1.Creation using Itration\n2.Creation using recursion\n");
        printf("3.Searching in BST\n4.Delete Node\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter data:");
                scanf("%d",&value);
                CreatingBST_Itrative(&Iroot,value);
                printf("Inorder Display:");
                In_orderDisplay(Iroot);
                printf("\n");
                break;
            }
            case 2:
            {
                printf("Enter data:");
                scanf("%d",&value);
                Rroot = CreatingBST_Recursive(Rroot,value);
                if(Rroot)
                {
                    printf("Inorder Display:");
                    In_orderDisplay(Rroot);
                    printf("\n");
                }

                break;
            }
            case 3:
            {
                printf("Enter data to be searched:");
                scanf("%d",&value);
                if (SearchBST_Itravtive(Iroot,value))
                    printf("Element found\n");
                else
                    printf("Element not found\n");

                if (SearchBST_Recursive(Rroot,value))
                    printf("Element found\n");
                else
                    printf("Element not found\n");

                break;
            }
            case 4:
            {
                
                printf("Enter Node data to be Deleted:");
                scanf("%d",&value);
                printf("Inorder Display Before Deletion:");
                In_orderDisplay(Rroot);
                printf("\n");
                DeleteBST(Rroot,value);
                printf("Inorder Display after Deletion:");
                In_orderDisplay(Rroot);
                printf("\n");
                break;
            }
            case 5:
            {
                break;
            }

            default:
                printf("Wrong Choice : \n");
        }   
        printf("Do you want to contd. (1/0):");
        scanf("%d",&cont);
    }while(1 == cont);

    if (NULL != Iroot)
    {
        free(Iroot);
        Iroot = NULL;
    }

    if (NULL != Rroot)
    {
        free(Rroot);
        Rroot = NULL;
    }

    return 0;
}
