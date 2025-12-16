#include <stdio.h>
#include <string.h>

int main()
{
    char student_names[10][50];
    char temp_name[50];
    int i, j;

    printf("Enter names of 10 students:\n");
    for(i = 0; i < 10; i++)
    {
        printf("Student %d: ", i + 1);
        scanf(" %[^\n]", student_names[i]); 
    }

    for(i = 0; i < 9; i++)
    {
        for(j = i + 1; j < 10; j++)
        {
            if(strcmp(student_names[i], student_names[j]) > 0)
            {
                
                strcpy(temp_name, student_names[i]);
                strcpy(student_names[i], student_names[j]);
                strcpy(student_names[j], temp_name);
            }
        }
    }
    printf("\nStudent names in alphabetical order:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d. %s\n", i + 1, student_names[i]);
    }

    return 0;
}

