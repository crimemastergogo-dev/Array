#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_STRING_LIMIT 1024

typedef enum {False,True} MyBool;
typedef char    IntType_8;
typedef short   IntType_16;
typedef int     IntType_32;
typedef long    IntTypr_64;

typedef struct
{
    char *chr;
    int length;
}String;

void getString(String *ptr)
{
    char temp[MAX_STRING_LIMIT];
    int index =0;

    fgets(temp,MAX_STRING_LIMIT,stdin);
    int len = strlen(temp);

    if (0 < len )
    {
        ptr->chr = (char *)malloc(len);
    }
    else if ((0 >len) || (NULL == ptr->chr))
    {
        fprintf(stderr,"ERROR:Memory Allocation Failed\n");
        exit (1);
    }

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


int MyStringLen(String *ptr)
{
    int i = 0;
    while(ptr->chr[i]!= '\0')
    {
        i++;
    }
    return i;
}

void Mytoupper(String *ptr)
{
    int i = 0;
    while(ptr->chr[i] !='\0')
    {
        if ((ptr->chr[i] >= 97) && (ptr->chr[i]<=122))
        {
            ptr->chr[i] -=32;
        }
        i++;
    }
    fprintf(stdout," %s\n",DisplayString(ptr));
}

void Mytolower(String *ptr)
{ 
    int i = 0;
    while(ptr->chr[i] !='\0')
    {
        if ((ptr->chr[i] >= 65) && (ptr->chr[i]<=90))
        {
            ptr->chr[i] +=32;
        }
        i++;
    }
    fprintf(stdout," %s\n",DisplayString(ptr));
}

void ToggleString(String *ptr)
{
    int i=0;
    while(ptr->chr[i] !='\0')
    {
        if ((ptr->chr[i] >= 65) && (ptr->chr[i]<=90))
        {
            ptr->chr[i] +=32;
        }
        else if ((ptr->chr[i] >= 97) && (ptr->chr[i]<=122))
        {
            ptr->chr[i] -=32;
        }
        i++;
    }
    fprintf(stdout," %s\n",DisplayString(ptr));
}

int word_count(String *ptr)
{
    int count = 0;
    int i =0;
    while(ptr->chr[i] != '\0')
    {
        if ((ptr->chr[i] == ' ')&&(ptr->chr[i-1] != ' '))
            count++;
        i++;
    }
    return count+1;
}

int sentence_count(String *ptr)
{
    int i = 0;
    int count = 0;
    while(ptr->chr[i] != '\0')
    {
        if (ptr->chr[i] == '.')
            count++;
        i++;
    }
    return count;
}

int para_count(String *ptr)
{
    int count = 0;
    int i = 0;
    while(ptr->chr[i] != '\0')
    {
        if (ptr->chr[i] == '\n')
            count++;
        i++;
    }
    return count;
}

int isAlphaNumereic(String *ptr)
{
    MyBool NumericFound = False;
    int count = 0;
    int i = 0;
    while(ptr->chr[i] != '\0')
    {
        if ((ptr->chr[i] >= 48) && (ptr->chr[i] <= 57))
        {
            NumericFound = True;
            count++;
        }
        i++;
    }
    if(False != NumericFound)
    {
        return count;
    }

    return 0;
}

int isVowel(String *ptr)
{
    int count  = 0;
    int i=0;
    while(ptr->chr[i] !='\0')
    {
        if ((ptr->chr[i] >= 65) && (ptr->chr[i]<=90) ||
                ((ptr->chr[i] >= 97) && (ptr->chr[i]<=122)))
        {
            switch(ptr->chr[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':count++;
                         break;
                default:
                         break;
            }
        }
        i++;
    }
    if(0 != count)
    {
        return count;
    }
    return 0;
}

int isConsonent(String *ptr)
{
    int count  = 0;
    int i=0;
    while(ptr->chr[i] !='\0')
    {
        if ((ptr->chr[i] >= 65) && (ptr->chr[i]<=90) ||
                ((ptr->chr[i] >= 97) && (ptr->chr[i] <= 122)))
        {
            switch(ptr->chr[i])
            {
                case 'a':
                case 'e':
                case 'i':
                case 'o':
                case 'u':
                case 'A':
                case 'E':
                case 'I':
                case 'O':
                case 'U':
                break;
                default:
                count++;
            }
        }
        i++;
    }
    if(0 != count)
    {
        return count;
    }
    return 0;
}

void MyStringRev(String *ptr)
{
    int len=0,i=0;
    char aux;
    len = MyStringLen(ptr)-1;

    for (i = 0 ;i<len;i++,len--)
    {
        aux = ptr->chr[i];
        ptr->chr[i] = ptr->chr[len];
        ptr->chr[len] = aux;
    }
}

int MyStringcmp(String *str1,String *str2)
{
    int i =0;
    MyBool isequal = True;
    if (str1->length != str2->length)
        isequal = False;
    else
    {
        for(i = 0 ;i<str1->length;i++)
        {
            if (str1->chr[i] != str2->chr[i])
            {
                isequal = False;
                break;
            }
        }
    }
    if (False == isequal)
    {
        return 1;
    }
    return 0;
}

int MyStringcmpi(String *str1,String *str2)
{
    int i =0;
    MyBool isequal = True;
    if (str1->length != str2->length)
        isequal = False;
    else
    {
        Mytolower(str1);
        Mytolower(str2);
        for(i = 0 ;i<str1->length;i++)
        {
            if (str1->chr[i] != str2->chr[i])
            {
                isequal = False;
                break;
            }
        }
    }
    if (False == isequal)
    {
        return 1;
    }
    return 0;
}

void duplicateInString(String *ptr)
{
    int Hash[26]= {0};
    int i=0,j=0;
    MyBool isDuplicate = False ;

    for (i = 0 ;ptr->chr[i]!='\0';i++)
    {
        Hash[ptr->chr[i]-97]+=1;
    }
    for (j= 0 ;j<26;j++)
    {
        if (Hash[j]>1)
        {
            printf("Character repeadted :%c[%d]\n",j+97,Hash[j]);
            isDuplicate = True;
        }
    }
    if(False == isDuplicate)
    {
        printf("No Duplicate char\n");
    }
}
void duplicateInStringBitwise(String *ptr)
{
    IntType_32 bitmask=0,bitmerge = 0,i=0;
    MyBool isDuplicate = False ;

    for (i = 0; ptr->chr[i]!='\0';i++)
    {
        bitmask = 1;
        bitmask = bitmask<<ptr->chr[i]-97;

        if (bitmask & bitmerge )
        {
            printf("Character repeadted :%c\n",ptr->chr[i]);
            MyBool isDuplicate = True ;
        }
        else
        {
            bitmerge = bitmask | bitmerge;
        }
    }
    if(False == isDuplicate)
    {
        printf("No Duplicate char\n");
    }
}

int  AnagramString(String *ptr,String *ptr1)
{
    int Hash[26]= {0};
    int i=0,j=0;

    int len = MyStringLen(ptr);
    int len1 = MyStringLen(ptr1);

    if (len !=len1)
    {
        return 0;
    }

    for (i = 0 ;ptr->chr[i]!='\0';i++)
    {
        Hash[ptr->chr[i]-97]+=1;
    }

    for (i = 0; ptr1->chr[i]!='\0'; i++)
    {
        Hash[ptr1->chr[i]-97]-=1;
    }

    for (j =0 ;j<26;j++)
    {
        if (Hash[j]<0)
        {
            return 0;
            break;
        }
    }

    return 1;
}

void PermutationString(String *ptr,int strlen)
{
    static int []

}

int main()
{
    String *string     = NULL; 
    unsigned char cont = '0';
    int choice         = 0;

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

    do
    {
        fprintf(stdout,"Menue Option :\n");
        fprintf(stdout,"1.String Length\n2.Lower to Upper case\n3.Upper to Lower\n4.Size of\n");
        fprintf(stdout,"5.Toggle case\n6.No. of words,sentence,paragraph\n");
        fprintf(stdout,"7.Is alpha numeric\n8.Vowel and Vowel count\n9.Consonent and consonent count\n");
        fprintf(stdout,"10.String Reverse\n11.Comparing to string\n12.Palindrome String\n");
        fprintf(stdout,"13.Duplicate in a String\n14.Anagram\n");
        fprintf(stdout,"Enter choice:");
        scanf("%d",&choice);
        getchar();
        switch(choice)
        {
            case 1 :
            {
                fprintf(stdout,
                        "String Length using Library function : %ld\n",strlen(string->chr));

                fprintf(stdout,
                        "String Length using MyStringLen : %d\n",MyStringLen(string));
                break;
            }
            case 2:
            {
                int i = 0;
                fprintf(stdout,
                        "Change Lower to Upper using Library function:");

                while(i <MyStringLen(string))
                {
                    printf("%c",toupper(string->chr[i]));
                    i++;
                }
                printf("\n");

                fprintf(stdout,
                        "Change Lower to Upper using Mytoupper :");

                Mytoupper(string);

                break;
            }
            case 3:
            {
                int i = 0;
                fprintf(stdout,
                        "Change upper to lower using Library function:");

                while(i <MyStringLen(string))
                {
                    printf("%c",tolower(string->chr[i]));
                    i++;
                }

                printf("\n");

                fprintf(stdout,
                        "Change Lower to Upper using Mytoupper :");

                Mytolower(string);
                break;
            }

            case 4:
            {
                fprintf(stdout,
                        "Size of string using Library function : %ld\n",sizeof(string));
                break;
            }
            case 5:
            {
                printf("Toggled String : ");
                ToggleString(string);
                break;
            }
            case 6:
            {
                printf("No. of words in the string = %d\n",word_count(string));
                printf("No. of sentence in the string = %d\n",sentence_count(string));
                printf("No. of paragraph in the string = %d\n",para_count(string));
                break;
            }
            case 7:
            {
                if (0 == isAlphaNumereic(string))
                {
                    printf("Not Alpha-Numeric\n");
                }
                else
                {
                    printf("String is Alpha Numeric and count = %d\n",isAlphaNumereic(string));
                }
                break;
            }
            case 8:
            {
                if(0 == isVowel(string))
                {
                    printf("No vowel present\n");
                }
                else
                {
                    printf("vowel present and count = %d\n",isVowel(string));
                }
                break;
            }
            case 9:
            {
                if(0 == isConsonent(string))
                {
                    printf("No consonent present\n");
                }
                else
                {
                    printf("consonent present and count = %d\n",isConsonent(string));
                }
                break;

            }
            case 10:
            {
                MyStringRev(string);
                fprintf(stdout,"Reversed String : %s\n",DisplayString(string));
                break;
            }
            case 11:
            {
                String *string2 = NULL;
                string2 = (String *)malloc(sizeof(String));
                if (NULL == string2)
                {
                    fprintf(stderr,"ERROR:Memory Allocation Failed\n");
                    exit (1);
                }
                memset(string2,0,sizeof(String));

                fprintf(stdout,"Enter String to compare :");
                getString(string2);

                fprintf(stdout,"Entered  String1 : %s\n",DisplayString(string2));

                fprintf(stdout,"String compare using Library function \n");
                if (strcmp(string->chr,string2->chr)==0)
                {
                    fprintf(stdout,"String %s and %s are equal \n",DisplayString(string),DisplayString(string2));
                }
                else
                {
                    fprintf(stdout,"String %s and %s are not equal \n",DisplayString(string),DisplayString(string2));
                }

                fprintf(stdout,"String compare using MyStringcmp \n");
                if (MyStringcmp(string,string2)==0)
                {
                    fprintf(stdout,"String %s and %s are equal \n",DisplayString(string),DisplayString(string2));
                }
                else
                {
                    fprintf(stdout,"String %s and %s are not equal \n",DisplayString(string),DisplayString(string2));
                }

                fprintf(stdout,"String compare(ignore case) using MyStringcmpi \n");
                if (MyStringcmpi(string,string2)==0)
                {
                    fprintf(stdout,"String %s and %s are not equal \n",DisplayString(string),DisplayString(string2));
                }
                else
                {
                    fprintf(stdout,"String %s and %s are not  equal \n",DisplayString(string),DisplayString(string2));
                }

                if ((NULL != string2->chr) &&
                        (NULL != string2))
                {
                    free(string2->chr);
                    string2->chr = NULL;
                    free(string2);
                    string2 = NULL;
                }
                break; 
            }
            case 12:
            {
                String *string3 = NULL;
                string3 = (String *)malloc(sizeof(String));
                if (NULL == string3)
                {
                    fprintf(stderr,"ERROR:Memory Allocation Failed\n");
                    exit (1);
                }
                memset(string3,0,sizeof(String));

                fprintf(stdout,"Enter String to compare :");
                getString(string3);

                fprintf(stdout,"Entered  String1 : %s\n",DisplayString(string3));

                MyStringRev(string3);

                if (MyStringcmp(string,string3)==0)
                {
                    fprintf(stdout,"String %s and %s palindrome \n",
                            DisplayString(string),DisplayString(string3));
                }
                else
                {
                    fprintf(stdout,"String %s and %s are not palindrome \n",
                            DisplayString(string),DisplayString(string3));
                }

                if ((NULL != string3->chr) &&
                        (NULL != string3))
                {
                    free(string3->chr);
                    string3->chr = NULL;
                    free(string3);
                    string3 = NULL;
                }
                break;
            }
            case 13:
            {
                fprintf(stdout,"Duplicate String Using Hashmap \n");
                duplicateInString(string);
                fprintf(stdout,"Duplicate String Using Bitwise Operator \n");
                duplicateInStringBitwise(string);
                break;
            }
            case 14:
            {
                String *string4 = NULL;
                string4 = (String *)malloc(sizeof(String));
                if (NULL == string4)
                {
                    fprintf(stderr,"ERROR:Memory Allocation Failed\n");
                    exit (1);
                }
                memset(string4,0,sizeof(String));

                fprintf(stdout,"Enter String to compare :");
                getString(string4);

                fprintf(stdout,"Entered  String1 : %s\n",DisplayString(string4));

                if (0 == AnagramString(string,string4))
                {
                    fprintf(stdout,"String %s and %s is not an Anagram \n",
                            DisplayString(string),DisplayString(string4));
                }
                else
                {
                    fprintf(stdout,"String %s and %s is an Anagram \n",
                            DisplayString(string),DisplayString(string4));
                }

                if ((NULL != string4->chr) &&
                        (NULL != string4))
                {
                    free(string4->chr);
                    string4->chr = NULL;
                    free(string4);
                    string4 = NULL;
                }
                break;
            }
            default: printf("Wrong Choice\n");
        }
        printf("Do you want to continue (1/0): ");
        scanf("%c",&cont);
    }while(cont== '1' );

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
