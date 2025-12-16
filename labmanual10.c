#include <stdio.h>
#include <string.h>
int main()
{
    char message[200];
    char new_message[300];
    char temp[200];
    char *ptr;

    printf("Enter customer feedback message:\n");
    gets(message);  
    printf("\nTotal characters in message: %lu\n", strlen(message));

    if(strstr(message, "good") != NULL)
    {
        printf("The word 'good' exists in the message.\n");
    }
    if(strstr(message, "bad") != NULL)
    {
        printf("The word 'bad' exists in the message.\n");  
        ptr = strstr(message, "bad");
        strcpy(temp, ptr + 3);
        strcpy(new_message, message);
        *ptr = '\0';

        strcat(new_message, "not good");
        strcat(new_message, temp);

        printf("\nUpdated feedback message:\n%s\n", new_message);
    }
    else
    {
        printf("\nNo 'bad' found, no replacement needed.\n");
    }

    return 0;
}

