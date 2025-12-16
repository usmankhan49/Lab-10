#include <stdio.h>
#include <string.h>

int main() {
    char guest_names[20][50];
    int room_numbers[20];
    int i, total_guests = 0;
    FILE *file_ptr;
    file_ptr = fopen("hotel.txt", "w");
    if (file_ptr == NULL) {
        printf("Error opening file.\n");
        return 0;
    }
    for (i = 0; i < 20; i++) {
        printf("Enter guest name for room %d (or type 'exit' to stop): ", i + 1);
        fgets(guest_names[i], sizeof(guest_names[i]), stdin);
        guest_names[i][strcspn(guest_names[i], "\n")] = 0;
        if (strcmp(guest_names[i], "exit") == 0) {
            break;
        }
        room_numbers[i] = i + 1;
        fprintf(file_ptr, "Room %d: %s\n", room_numbers[i], guest_names[i]);
        total_guests++;
    }
    fclose(file_ptr);
    char search_name[50];
    int found;
    char line[100];
    while (1) {
        int choice;
        printf("Do you want to search for a guest? (1 for yes, 0 for no): ");
        fgets(line, sizeof(line), stdin);
        sscanf(line, "%d", &choice);
        if (choice != 1) break;
        printf("Enter guest name to search: ");
        fgets(search_name, sizeof(search_name), stdin);
        search_name[strcspn(search_name, "\n")] = 0;

        file_ptr = fopen("hotel.txt", "r");
        if (file_ptr == NULL) {
            printf("Error opening file.\n");
            break;
        }
        found = 0;
        while (fgets(line, sizeof(line), file_ptr) != NULL) {
            int room;
            char name[50];
            sscanf(line, "Room %d: %[^\n]", &room, name);
            if (strcmp(search_name, name) == 0) {
                printf("%s is in room %d\n", name, room);
                found = 1;
                break;
            }
        }
        if (!found) {
            printf("Guest not found.\n");
        }
        fclose(file_ptr);
    }
    printf("Thank you!\n");
    return 0;
}

