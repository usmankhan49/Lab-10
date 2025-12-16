#include <stdio.h>
int main()
{
    char name[50];
    int count = 0;
    FILE *file;
    file = fopen("attendance.txt", "r");
    if(file == NULL)
    {
        printf("Error opening file.\n");
        return 1;
    }
    while(fscanf(file, " %[^\n]", name) != EOF)
    {
        printf("%s\n", name);
        count = count + 1;
    }
    fclose(file);
    printf("Total students: %d\n", count);
    return 0;
}

