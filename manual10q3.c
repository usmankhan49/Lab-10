#include <stdio.h>
#include <string.h>

int main() {
    char city_names[5][20], hottest_city[20];
    float temps[5], max_temp = -1000.0;
    int i;
    FILE *file_ptr;
    file_ptr = fopen("temperature.txt", "w");
    for (i = 0; i < 5; i++) {
        printf("Enter city name: ");
        scanf("%s", city_names[i]);
        printf("Enter temperature for %s: ", city_names[i]);
        scanf("%f", &temps[i]);

        fprintf(file_ptr, "%s %.2f\n", city_names[i], temps[i]);
    }
    fclose(file_ptr);
    file_ptr = fopen("temperature.txt", "r");
    for (i = 0; i < 5; i++) {
        fscanf(file_ptr, "%s %f", city_names[i], &temps[i]);
        if (temps[i] > max_temp) {
            max_temp = temps[i];
            strcpy(hottest_city, city_names[i]);
        }
    }
    printf("City with the highest temperature: %s (%.2f°C)\n", hottest_city, max_temp);
    fclose(file_ptr);

    return 0;
}

