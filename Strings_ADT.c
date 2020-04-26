#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_STRING_LIMIT 1024

typedef enum{False,True} MyBool;

int MyStringLen(char *ptr)
{
    int i = 0;
    char *temp = ptr;
    while(*temp!= '\0')
    {
        i++;
        temp++;
    }
    return i;
}

void Mytoupper(char *chr)
{
    char *temp = chr;
    while(*temp !='\0')
    {
        if ((*temp >= 97) && (*temp<=122))
        {
            *temp -=32;
        }
        temp++;
    }
     temp = chr;
    fprintf(stdout," %s\n",temp);
}

void Mytolower(char *chr)
{
    char *temp = chr;
    while(*temp !='\0')
    {
        if ((*temp >= 65) && (*temp<=90))
        {
            *temp +=32;
        }
        temp++;
    }
     temp = chr;
    fprintf(stdout," %s\n",temp);
}

void ToggleString(char *chr)
{
    char *temp = chr;
    while(*temp !='\0')
    {
        if ((*temp >= 65) && (*temp<=90))
        {
            *temp +=32;
        }
        else if ((*temp >= 97) && (*temp<=122))
        {
            *temp -=32;
        }

        temp++;
    }
     temp = chr;
    fprintf(stdout," %s\n",temp);
}

int word_count(char *ptr)
{
    int count = 0;
    char *temp = ptr;
    int i =0;
    while(temp[i] != '\0')
    {
        if ((temp[i] == ' ')&&(temp[i-1] != ' '))
            count++;
        i++;
    }
    return count+1;
}

int sentence_count(char *ptr)
{
    int count = 0;
    char *temp = ptr;
    while(*temp != '\0')
    {
        if (*temp == '.')
            count++;
        temp++;
    }
    return count;
}

int para_count(char *ptr)
{
    int count = 0;
    char *temp = ptr;
    while(*temp != '\0')
    {
        if (*temp == '\n')
            count++;
        temp++;
    }
    return count;
}

int isAlphaNumereic(char *ptr)
{
    char *temp = ptr;
    MyBool NumericFound = False;
    int count = 0;
    while(*temp != '\0')
    {
        if ((*temp >= 48) && (*temp <= 57))
        {
            NumericFound = True;
            count++;
        }
        temp++;
    }
    if(False != NumericFound)
    {
        return count;
    }

    return 0;
}

int isVowel(char *ptr)
{
    char *temp = ptr;
    int count  = 0;
    while(*temp !='\0')
    {
        if ((*temp >= 65) && (*temp<=90) || ((*temp >= 97) && (*temp<=122)))
        {
            switch(*temp)
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
        temp++;
    }
    if(0 != count)
    {
        return count;
    }
    return 0;
}

int isConsonent(char *ptr)
{
    char *temp = ptr;
    int count  = 0;
    while(*temp !='\0')
    {
        if ((*temp >= 65) && (*temp<=90) || ((*temp >= 97) && (*temp<=122)))
        {
            switch(*temp)
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
        temp++;
    }
    if(0 != count)
    {
        return count;
    }
    return 0;
}

char *MyStringRev(char *ptr)
{
    char *temp = ptr,aux;
    int i=0,len=0;
    len = MyStringLen(ptr)-1;
    while(*temp != '\0'){
        temp++;
    }
    temp--;

    //while(*ptr=*temp && *temp-- !='\0' && *ptr++ !='\0');
    i = 0;
    if(len%2==0)
    {
        while(i < len/2)
        {
            aux = *temp;
            *temp = *ptr;
            *ptr = aux;
            i++;
            temp--;ptr++;
        }
        ptr -= (len/2)-1; 
    }
    else
    {
        while(i < (len/2)+1)
        {
            aux = *temp;
            *temp = *ptr;
            *ptr = aux;
            i++;
            temp--;ptr++;
        }
        ptr -= (len/2); 
    }


    return ptr;
}

int main()
{
    char temp[MAX_STRING_LIMIT];
    char *string; 
    int choice = 0;
    int cont = 0;

    fprintf(stdout,"Enter the String :");
    fgets(temp,MAX_STRING_LIMIT,stdin);

    string = temp;

    fprintf(stdout,"Entered  String : %s\n",string);
    
    do
    {
        printf("Menue Option :\n");
        printf("1.String Length\n2.Lower to Upper case\n3.Upper to Lower\n4.Size of\n");
        printf("5.Toggle case\n6.No. of words,sentence,paragraph\n");
        printf("7.Is alpha numeric\n8.Vowel and Vowel count\n9.Consonent and consonent count\n");
        printf("10.String Reverse\n");
        printf("Enter choice:");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1 :
            {
                fprintf(stdout,
                        "String Length using Library function : %ld\n",strlen(string));

                fprintf(stdout,
                        "String Length using MyStringLen : %d\n",MyStringLen(string));
                break;
            }
            case 2:
            {
                int i = 0;
                char *temp = string;
                fprintf(stdout,
                        "Change Lower to Upper using Library function:");

                while(i <MyStringLen(temp))
                {
                    printf("%c",toupper(temp[i]));
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
                char *temp = string;
                fprintf(stdout,
                        "Change upper to lower using Library function:");

                while(i <MyStringLen(temp))
                {
                    printf("%c",tolower(temp[i]));
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
            default: printf("Wrong Choice\n");
        }
        printf("Do you want to continue (1/0): ");
        scanf("%d",&cont);
    }while(cont== 1 );
    return 0;
}
