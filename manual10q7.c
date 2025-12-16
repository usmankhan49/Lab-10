#include <stdio.h>
#include <string.h>
int main() {
    char category[50];
    float amount;
    FILE *file_ptr;
    char line[100];
    int i, n;
    printf("How many expenses do you want to enter? ");
    scanf("%d", &n);
    getchar();  
    file_ptr = fopen("expenses.txt", "a");
    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    for (i = 0; i < n; i++) {
        printf("Enter expense category: ");
        fgets(category, sizeof(category), stdin);
        category[strcspn(category, "\n")] = 0;
        printf("Enter amount: ");
        scanf("%f", &amount);
        getchar();  
        fprintf(file_ptr, "%s %.2f\n", category, amount);
    }
    fclose(file_ptr);
    printf("\nAll recorded expenses:\n");
    file_ptr = fopen("expenses.txt", "r");
    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    while (fgets(line, sizeof(line), file_ptr) != NULL) {
        printf("%s", line);
    }
    fclose(file_ptr);
    return 0;
}

