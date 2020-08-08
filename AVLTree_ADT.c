#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct _AVLTree
{
    int data;
    int height;
    struct _AVLTree *Left_child;
    struct _AVLTree *Right_child;
}AVLTree_ADT;

AVLTree_ADT *Rroot = NULL;

AVLTree_ADT *InorderSuccAVLTree(AVLTree_ADT *root)
{
    while (root && (NULL !=root->Left_child))
        root = root->Left_child;

    return root;
}

AVLTree_ADT *InorderPredAVLTree(AVLTree_ADT *root)
{
    while (root && (NULL !=root->Right_child))
        root = root->Right_child;

    return root;
}


int HeightAVLTree(AVLTree_ADT *root)
{
    int Left  = 0;
    int Right = 0;

    if (NULL == root)
        return 0;

    Left  = HeightAVLTree(root->Left_child);
    Right = HeightAVLTree(root->Right_child); 

    return Left>Right ?Left+1:Right+1; 
}

void In_orderDisplay(AVLTree_ADT *ptr)
{
    if (NULL != ptr)
    {
        In_orderDisplay(ptr->Left_child);
        printf("%d ",ptr->data);
        In_orderDisplay(ptr->Right_child);
    }
}
void post_orderDisplay(AVLTree_ADT *ptr)
{
    if (NULL != ptr)
    {
        post_orderDisplay(ptr->Left_child);
        post_orderDisplay(ptr->Right_child);
        printf("%d ",ptr->data);
    }
}

int NodeHeight(AVLTree_ADT *root)
{
    int Rheight = 0;
    int Lheight = 0;

    Lheight =  root && root->Left_child ? root->Left_child->height : 0;
    Rheight =  root && root->Right_child ? root->Right_child->height : 0;

    return Lheight > Rheight ?Lheight+1:Rheight+1;
}

int BalanceFactorAVLTree(AVLTree_ADT* root)
{
    int Rheight = 0;
    int Lheight = 0;

    Lheight =  root && root->Left_child ? root->Left_child->height : 0;
    Rheight =  root && root->Right_child ? root->Right_child->height : 0;

    return Lheight - Rheight;;
}

AVLTree_ADT* LLRotation(AVLTree_ADT* root)
{
    AVLTree_ADT *LRoot = root->Left_child;
    AVLTree_ADT *LRoot_Rchild = LRoot->Right_child;

    LRoot->Right_child = root;
    root->Left_child = LRoot_Rchild;

    root->height  = NodeHeight(root);
    LRoot->height = NodeHeight(root);

    if (Rroot == root)
        Rroot = LRoot;

    return LRoot;
}

AVLTree_ADT* RRRotation(AVLTree_ADT* root)
{
    AVLTree_ADT *RRoot = root->Right_child;
    AVLTree_ADT *RRoot_Lchild = RRoot->Left_child;

    RRoot->Left_child = root;
    root->Right_child = RRoot_Lchild;

    root->height  = NodeHeight(root);
    RRoot->height = NodeHeight(root);

    if (Rroot == root)
        Rroot = RRoot;

    return RRoot;
}

AVLTree_ADT* LRRotation(AVLTree_ADT* root)
{
    AVLTree_ADT *LRoot = root->Left_child;
    AVLTree_ADT *LRoot_Rchild = LRoot->Right_child;

    LRoot->Right_child = LRoot_Rchild->Left_child;
    root->Left_child = LRoot_Rchild->Right_child;

    LRoot_Rchild->Left_child  = LRoot;
    LRoot_Rchild->Right_child = root;

    LRoot->height  = NodeHeight(root);
    root->height = NodeHeight(root);
    LRoot_Rchild->height = NodeHeight(root);

    if (Rroot == root)
        Rroot = LRoot_Rchild;

    return LRoot_Rchild;
}

AVLTree_ADT* RLRotation(AVLTree_ADT* root)
{
    AVLTree_ADT *RRoot = root->Right_child;
    AVLTree_ADT *RRoot_Lchild = RRoot->Left_child;

    RRoot->Left_child = RRoot_Lchild->Right_child;
    root->Left_child = RRoot_Lchild->Left_child;

    RRoot_Lchild->Left_child  = root;
    RRoot_Lchild->Right_child = RRoot;

    root->height  = NodeHeight(root);
    RRoot->height = NodeHeight(root);
    RRoot_Lchild->height = NodeHeight(root);

    if (Rroot == root)
        Rroot = RRoot_Lchild;

    return RRoot_Lchild;
}

AVLTree_ADT* CreatingAVLTree(AVLTree_ADT *root,int value)
{
    AVLTree_ADT *temp    = NULL;

    if(NULL == root)
    {
        temp = (AVLTree_ADT *)malloc(sizeof(AVLTree_ADT));
        if (NULL == temp)
        {
            printf("Memory Allocation Failed\n");
            exit(1);
        }
        temp->data        = value;
        temp->height      = 1;
        temp->Left_child  = NULL;
        temp->Right_child = NULL;
        root = temp;
    }
    if (value < root->data)
    {
        root->Left_child = CreatingAVLTree(root->Left_child,value);
    }
    else if (value > root->data)
    {
        root->Right_child = CreatingAVLTree(root->Right_child,value);
    }

    root->height = NodeHeight(root);

    /*For LL Rotation*/
    if ((2 == BalanceFactorAVLTree(root) &&
                (1 == BalanceFactorAVLTree(root->Left_child))))
    {
        return LLRotation(root);
    }

    /*For RR Rotation*/
    if ((-2 == BalanceFactorAVLTree(root) &&
                (-1 == BalanceFactorAVLTree(root->Right_child))))
    {
        return RRRotation(root);
    }

    /*For LR Rotation*/
    if ((2 == BalanceFactorAVLTree(root) &&
                (-1 == BalanceFactorAVLTree(root->Left_child))))
    {
        return LRRotation(root);
    }

    /*For RL Rotation*/
    if ((-2 == BalanceFactorAVLTree(root) &&
                (1 == BalanceFactorAVLTree(root->Right_child))))
    {
        return RLRotation(root);
    }

    return root;
}

int  SearchBST_Itravtive(AVLTree_ADT *root,int value)
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

int SearchBST_Recursive(AVLTree_ADT *root,int value)
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



AVLTree_ADT *DeleteAVLTree(AVLTree_ADT *root,int data)
{
    AVLTree_ADT        *temp  = NULL;

    if (NULL == root)
        return NULL;
    if ((NULL==root->Right_child) &&
            (NULL == root->Left_child))
    {
        if (Rroot == root)
            root = NULL;
        free(root);
        root = NULL;
        return NULL;
    }

    if (data > root->data)
        root->Right_child = DeleteAVLTree(root->Right_child,data);
    else if(data < root->data)
        root->Left_child  = DeleteAVLTree(root->Left_child,data);
    else
    {
        if (HeightAVLTree(root->Right_child) < HeightAVLTree(root->Left_child))
        {
            temp = InorderPredAVLTree(root);
            root->data = temp->data;
            root->Left_child = DeleteAVLTree(root->Left_child,temp->data);
        }
        else
        {
            temp = InorderSuccAVLTree(root);
            root->data = temp->data;
            root->Right_child = DeleteAVLTree(root->Right_child,temp->data);
        }

        /*For L1 Rotation*/
        if ((2 == BalanceFactorAVLTree(root) &&
                    (1 == BalanceFactorAVLTree(root->Left_child))))
        {
            return LLRotation(root);
        }

        /*For L-1 Rotation*/
        if ((2 == BalanceFactorAVLTree(root) &&
                    (-1 == BalanceFactorAVLTree(root->Right_child))))
        {
            return LRRotation(root);
        }

        /*For L0 Rotation*/
        if ((2 == BalanceFactorAVLTree(root) &&
                    (0 == BalanceFactorAVLTree(root->Left_child))))
        {
            return LLRotation(root);
        }

        /*For R1 Rotation*/
        if ((-2 == BalanceFactorAVLTree(root) &&
                    (-1 == BalanceFactorAVLTree(root->Right_child))))
        {
            return RRRotation(root);
        }

        /*For R-1 Rotation*/
        if ((-2 == BalanceFactorAVLTree(root) &&
                    (1 == BalanceFactorAVLTree(root->Left_child))))
        {
            return RLRotation(root);
        }

        /*For R0 Rotation*/
        if ((-2 == BalanceFactorAVLTree(root) &&
                    (0 == BalanceFactorAVLTree(root->Right_child))))
        {
            return RRRotation(root);
        }

    }

    return root;
}

int main()
{
    int   choice = 0;
    int   value  = 0;
    int   cont   = 0;

    do
    {
        printf("1.Insert In AVL Tree\n");
        printf("3.Searching in AVL\n4.Delete Node\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1:
            {
                printf("Enter data:");
                scanf("%d",&value);
                Rroot = CreatingAVLTree(Rroot,value);
                if(Rroot)
                {
                    printf("Postorder Display:");
                    post_orderDisplay(Rroot);
                    printf("\n");
                }
                break;
            }
            case 2:
            {

                break;
            }
            case 3:
            {
                printf("Enter data to be searched:");
                scanf("%d",&value);

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
                printf("Postorder Display Before Deletion:");
                post_orderDisplay(Rroot);
                printf("\n");
                DeleteAVLTree(Rroot,value);
                printf("Postorder Display after Deletion:");
                post_orderDisplay(Rroot);
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


    if (NULL != Rroot)
    {
        free(Rroot);
        Rroot = NULL;
    }

    return 0;
}
