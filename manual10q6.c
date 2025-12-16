#include <stdio.h>
#include <string.h>
int main() {
    char books[10][100];
    char search_title[100];
    int i, found;
    for (i = 0; i < 10; i++) {
        printf("Enter title of book %d: ", i + 1);
        fgets(books[i], sizeof(books[i]), stdin);
        books[i][strcspn(books[i], "\n")] = 0;
    }
    printf("Enter book title to search: ");
    fgets(search_title, sizeof(search_title), stdin);
    search_title[strcspn(search_title, "\n")] = 0;

    found = 0;
    for (i = 0; i < 10; i++) {
        if (strcmp(search_title, books[i]) == 0) {
            found = 1;
            break;
        }
    }
    if (found)
        printf("Book Found\n");
    else
        printf("Book Not Found\n");

    return 0;
}

