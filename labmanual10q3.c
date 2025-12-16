#include <stdio.h>
#include <string.h>

int main()
{
    char email[5][100];
    char domain[5][100];
    char *ptr;
    int i;

    printf("Enter email addresses of 5 employees:\n");
    for(i = 0; i < 5; i++)
    {
        printf("Employee %d: ", i + 1);
        scanf("%s", email[i]);
    }
    for(i = 0; i < 5; i++)
    {
        
        ptr = strchr(email[i], '@');

        if(ptr != NULL)
        {
            
            strcpy(domain[i], ptr + 1);
            printf("Domain of %s is: %s\n", email[i], domain[i]);
        }
        else
        {
            printf("Invalid email: %s\n", email[i]);
        }
    }
    return 0;
}

