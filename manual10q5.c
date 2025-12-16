#include <stdio.h>
#include <string.h>

int main() {
    char password[100];
    int length;
    int has_upper = 0, has_lower = 0, has_digit = 0, has_special = 0;
    char special_chars[] = "!@#$%^&*()-_+=<>?/";
    printf("Enter your password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = 0;
    length = strlen(password);

    for (int i = 0; i < length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z')
            has_upper = 1;
        else if (password[i] >= 'a' && password[i] <= 'z')
            has_lower = 1;
        else if (password[i] >= '0' && password[i] <= '9')
            has_digit = 1;
        else if (strchr(special_chars, password[i]))
            has_special = 1;
    }

    if (length < 6 || (has_upper + has_lower + has_digit + has_special) < 2)
        printf("Password strength: Weak\n");
    else if (length >= 6 && length <= 10 && (has_upper + has_lower + has_digit + has_special) >= 2)
        printf("Password strength: Medium\n");
    else if (length > 10 && has_upper && has_lower && has_digit && has_special)
        printf("Password strength: Strong\n");
    else
        printf("Password strength: Medium\n");

    return 0;
}

