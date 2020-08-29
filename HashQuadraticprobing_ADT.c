#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_STRING_LIMIT 1024

typedef struct
{
    char *chr;
    int length;
}String;

typedef struct
{
    String *Hash_function;
    int size;
    int *A;
    int key_num;
    double loading_factor;
}Hash_Quadratic_Probe_t;

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
void HashQuadraticProbeInit(Hash_Quadratic_Probe_t *ptr)
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
    fprintf(stdout,"Hash Function: %s, size = %d\n",ptr->Hash_function->chr,ptr->size);

    ptr->A = (int *)malloc(ptr->size *sizeof(int));
    if (NULL == ptr->A)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }
    /*Initializing all the key in hasmap with -1 i.e empty space*/
    memset(ptr->A,-1,ptr->size*sizeof(int));

}

/* Quadratic Probe Function H`(x) = [H(x) + f(i)]%size where f(i) = i*i*/
int FetchIndexQuadraticProbe(Hash_Quadratic_Probe_t *p_hash,int pos,int idx)
{
    int ret_val = 0;

    ret_val = (pos + idx*idx) % p_hash->size;

    return ret_val;
}

/* Loading Factor */
double LoadingFactorHashMap(Hash_Quadratic_Probe_t *p_hash_map)
{
    double ret_val ;

    ret_val = (double)p_hash_map->key_num / p_hash_map->size;

    fprintf(stdout," key_num = %d loading factor = %lf\n",p_hash_map->key_num,ret_val);
    return ret_val;
}

void InsertHashingQuadraticProbe(Hash_Quadratic_Probe_t *p_Hash, int key)
{
    int pos = 0;
    int idx = 0;

    if (0.5 >p_Hash->loading_factor)
    {
        pos = key % p_Hash->size;
        if (-1 == p_Hash->A[pos])
        {
            p_Hash->A[pos] = key;
            p_Hash->key_num++;
        }
        else
        {
            for (idx = 0;;idx++ )
            {
                if (-1 == p_Hash->A[FetchIndexQuadraticProbe(p_Hash,pos,idx)])
                {
                    p_Hash->A[FetchIndexQuadraticProbe(p_Hash,pos,idx)] = key;
                    p_Hash->key_num++;
                    break;
                }
            }
        }
    }
    else
    {
        fprintf(stderr,"Loading Factor Greater Than 0.5 is Not recommended in Linear Probe "
                "Insertion Failed\n");
    }
}

void DisplayHashQuadratic(Hash_Quadratic_Probe_t *p_hash)
{
    int idx = 0;

    for (idx = 0 ; idx < p_hash->size;idx++)
        printf("[%d] -> %d\n",idx,p_hash->A[idx]);
    printf("----------------------------------------------------\n");
}

int SearchHashQuadraticProb(Hash_Quadratic_Probe_t *p_hash,int key)
{
    int ret_val = 0;
    int pos     = 0;
    int idx     = 0;

    pos = key % p_hash->size;
    for (idx = 0;;idx++ )
    {
        if (key == p_hash->A[FetchIndexQuadraticProbe(p_hash,pos,idx)])
        {
            ret_val = 1;
            printf("Found At index [%d]\n", FetchIndexQuadraticProbe(p_hash,pos,idx));
            break;
        }
        else if (-1 == p_hash->A[FetchIndexQuadraticProbe(p_hash,pos,idx)])
        {
            ret_val = 0;
            break;
        }
    }

    return ret_val;
}

int main()
{
    Hash_Quadratic_Probe_t *p_hash  = NULL;

    p_hash = (Hash_Quadratic_Probe_t *) malloc(sizeof(Hash_Quadratic_Probe_t));
    if (NULL == p_hash)
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }

    memset(p_hash,0,sizeof(Hash_Quadratic_Probe_t));

    HashQuadraticProbeInit(p_hash);

    InsertHashingQuadraticProbe(p_hash,5);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,20);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,10);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,25);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,3);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,9);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);

    InsertHashingQuadraticProbe(p_hash,26);
    DisplayHashQuadratic(p_hash);
    p_hash->loading_factor = LoadingFactorHashMap(p_hash);


    if (!SearchHashQuadraticProb(p_hash,5))
    {
        printf("Not found\n");
    }

    if (!SearchHashQuadraticProb(p_hash,25))
    {
        printf("Not found\n");
    }

    if (!SearchHashQuadraticProb(p_hash,10))
    {
        printf("Not found\n");
    }
    if (!SearchHashQuadraticProb(p_hash,7))
    {
        printf("Not found\n");
    }

    /*Delete operation in Linear Probing causes Re-Hashing which is not feasable, so should be avoided*/
    if (NULL != p_hash)
    {
        free(p_hash);
        p_hash = NULL;
    }
}
