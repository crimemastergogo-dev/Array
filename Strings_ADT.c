#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX_STRING_LIMIT 1024

typedef enum{False,True} MyBool;

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

char *MyStringRev(String *ptr)
{
    int len=0,i=0;
    char aux;
    len = MyStringLen(ptr);

    for (i = 0 ; i<len/2;i++)
    {
        aux = ptr->chr[len-i];
        ptr->chr[len-i] = ptr->chr[i];
        ptr->chr[i] = aux;
    }

    return ptr->chr;
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
        fprintf(stdout,"10.String Reverse\n11.Comparing to string\n");
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
                printf("Reverse String :%s\n",MyStringRev(string));
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
