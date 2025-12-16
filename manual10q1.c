#include <stdio.h>
#include <string.h>

int main()
{
    char product_name[100];
    float price;
    int quantity;

    FILE *file_ptr;
    printf("enter product name: ");
    scanf("%s", product_name);
    printf("enter price: ");
    scanf("%f", &price);
    printf("enter quantity: ");
    scanf("%d", &quantity);
    file_ptr = fopen("store_products.txt","a");
    if(file_ptr == NULL){
        printf("could not open file\n");
    }
    else{
        fprintf(file_ptr, "name: %s  price: %.2f  quantity: %d\n", product_name, price, quantity);
        fclose(file_ptr);
        printf("product saved successfully\n");
    }
    return 0;
}

