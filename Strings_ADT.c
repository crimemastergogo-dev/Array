#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAX_STRING_LIMIT 1024

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
    int count = 1;
    char *temp = ptr;
    while(*temp != '\0')
    {
        if (*temp == ' ')
            count++;
        temp++;
    }
    return count;
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
            default: printf("Wrong Choice\n");
        }
        printf("Do you want to continue (1/0): ");
        scanf("%d",&cont);
    }while(cont== 1 );
    return 0;
}
