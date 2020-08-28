#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING_LIMIT 1024

typedef struct
{
    char *chr;
    int length;
}String;


typedef struct _Node
{
    int data;
    struct _Node *next;
}Data_node_t;

typedef struct
{
    int         size;
    Data_node_t **p_p_node;
    String *Hash_function; 
}Hash_Chaining_t;

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

/*Initializing Hash - Map*/
void HashChainigInit(Hash_Chaining_t *ptr)
{
    int index             = 0;
    char *p_size          = NULL;
 
    ptr->Hash_function = (String *)malloc(sizeof(String));
    if (NULL == ptr->Hash_function)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(ptr->Hash_function,0,sizeof(String));

    fprintf(stdout,"Enter the Hash Function:");
    getString(ptr->Hash_function);

    while('\0' != ptr->Hash_function->chr[index])
    {
        if ('%' == ptr->Hash_function->chr[index])
        {
            p_size = &ptr->Hash_function->chr[index +1];
            break;
        }
        index++;
    }
    ptr->size = atoi(p_size); 

    ptr->p_p_node = (Data_node_t **)malloc(ptr->size *sizeof(Data_node_t));
    if (NULL == ptr->p_p_node)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }


    for (index = 0 ; index < ptr->size; index++)
    {
        ptr->p_p_node[index] = NULL;
    }
    return;
}

void InsertHashChaining(Hash_Chaining_t *p_Hash_map,int key)
{
    Data_node_t *temp    = NULL;
    Data_node_t *current = NULL;
    Data_node_t *prev    = NULL;
    int idx              = 0;
    int flag             = 0;

    /* Finding Index of the map using size mentioned in HashFunction */
    idx = key % p_Hash_map->size;

    temp = (Data_node_t *)malloc(sizeof(Data_node_t));
    if (NULL == temp)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    memset(temp,0,sizeof(Data_node_t));

    temp->data = key;
    temp->next = NULL;

    /* Creating First Node */
    if (NULL == p_Hash_map->p_p_node[idx])
    {
        p_Hash_map->p_p_node[idx] = temp;
        return;
    }
    else
    {
        current = p_Hash_map->p_p_node[idx];
        prev    = current;
        while (current)
        {
            /* Key shoud be inserted in incerasing order */
            if ((prev->data < key ) && 
                    (current->data > key))
            {
                flag = 1;
                break;
            }

            /* No duplicate Key should be inserted */
            if (key == current->data)
            {
                printf ("Key already present at pos = %d...!!!\n",idx);
                if (NULL != temp)
                {
                    free(temp);
                    temp = NULL;
                }
                return;
            }

            prev    = current;
            current = current->next;
        }
        if (0 == flag)
        {
            prev->next = temp;
        }
        else
        {
            temp->next = current;
            prev->next = temp;
        }
    }
}

void DisplayHashChain(Hash_Chaining_t *p_Hash_map)
{
    Data_node_t *temp = NULL;
    int pos_idx       = 0;

    for (pos_idx = 0 ; pos_idx < p_Hash_map->size; pos_idx++)
    {
        printf("At pos = %d\n",pos_idx);
        if (NULL == p_Hash_map->p_p_node[pos_idx])
        {
            printf("No keys are added in this position...!!!\n");
            continue;
        }
        else
        {
            temp = p_Hash_map->p_p_node[pos_idx];
            while(temp)
            {
                printf("%d--->",temp->data);
                temp = temp->next;
            }
            printf("NULL\n");
        }
    }
}

int SearchHashChaining(Hash_Chaining_t *p_Hash_map,int key)
{
    int pos_idx       = 0;
    int ret_val       = 0;
    Data_node_t *temp = NULL;
    Data_node_t *prev = NULL;

    pos_idx = key % p_Hash_map->size;
    temp = p_Hash_map->p_p_node[pos_idx];
    if (temp)
    {
        prev = temp;
        while(temp)
        {
            /* key found */
            if (key == temp->data)
            {
                ret_val = 1;
                break;
            }
            /* All keys are inserted in sorted order */
            if ((prev->data < key ) && 
                    (temp->data > key))
            {
                ret_val = 0;
                break;
            }

            prev = temp;
            temp = temp->next;
        }
    }
    else
    {
        fprintf(stderr,"ERROR:Memory Corrupted\n");
        exit (1);
    }

    return ret_val;
}

void DeleteHashChaini(Hash_Chaining_t *p_Hash_map,int key)
{
    Data_node_t *temp    = NULL;
    Data_node_t *prev    = NULL;
    Data_node_t *current = NULL;
    int pos_idx          = 0;

    pos_idx = key % p_Hash_map->size;

    /* Checking if key is present or not */
    if (SearchHashChaining(p_Hash_map,key))
    {
        current = p_Hash_map->p_p_node[pos_idx];
        if (current)
        {
            while((NULL != current) && key != current->data)
            {
                prev     = current;
                current  = current->next;
            }
            prev->next = current->next;
            temp       = current;
            
            if (NULL != temp)
            {
                free(temp);
                temp = NULL;
            }
        }
        else
        {
            fprintf(stderr,"ERROR:Memory Corrupted\n");
            exit (1);
        }
    }
    else
    {
        printf("Key = %d NOT Found ...!!!\n",key);
    }
}

int main()
{
    Hash_Chaining_t *p_Hash_map = NULL;

    p_Hash_map = (Hash_Chaining_t *)malloc(sizeof(Hash_Chaining_t));
    if (NULL == p_Hash_map)
    {
        printf("Memory Allocation Failed ");
        exit(1);

    }
    memset(p_Hash_map,0,sizeof(Hash_Chaining_t));

    HashChainigInit(p_Hash_map);

    InsertHashChaining(p_Hash_map,5);
    InsertHashChaining(p_Hash_map,35);
    InsertHashChaining(p_Hash_map,15);
    InsertHashChaining(p_Hash_map,142);
    InsertHashChaining(p_Hash_map,12);
    InsertHashChaining(p_Hash_map,76);
    InsertHashChaining(p_Hash_map,76);
    InsertHashChaining(p_Hash_map,99);
    InsertHashChaining(p_Hash_map,69);
    InsertHashChaining(p_Hash_map,100);
    InsertHashChaining(p_Hash_map,500);
    InsertHashChaining(p_Hash_map,300);

    DisplayHashChain(p_Hash_map);

    if (SearchHashChaining(p_Hash_map,5))
    {
        printf("Found ...!!!\n");
    }
    else
    {
        printf("NOT Found ...!!!\n");
    }
    if (SearchHashChaining(p_Hash_map,6))
    {
        printf("Found ...!!!\n");
    }
    else
    {
        printf("NOT Found ...!!!\n");
    }
    if (SearchHashChaining(p_Hash_map,25))
    {
        printf("Found ...!!!\n");
    }
    else
    {
        printf("NOT Found ...!!!\n");
    }

    DeleteHashChaini(p_Hash_map,6);

    DeleteHashChaini(p_Hash_map,15);

    DisplayHashChain(p_Hash_map);

    if (NULL != p_Hash_map)
    {
        free(p_Hash_map);
        p_Hash_map = NULL;
    }
}
