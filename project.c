#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NUM_PRODUCTS 100
typedef struct
{
    int id;
    char name[50];
    double price;
    int stock;
} Product;
Product products[MAX_NUM_PRODUCTS];
int numProducts = 0;
void addProduct()
{
    if (numProducts == MAX_NUM_PRODUCTS)
    {
        printf("Error: Cannot add more products. The maximum number of products has been reached.\n");
        return;
    }

    printf("Enter the product ID: ");
    int id;
    while (scanf("%d", &id) != 1)
    {
        printf("Error: Invalid input. Please enter a valid integer ID.\n");
        while (getchar() != '\n');
    }

    for (int i = 0; i < numProducts; i++)
    {
        if (products[i].id == id)
        {
            printf("Error: A product with this ID already exists.\n");
            return;
        }
    }

    printf("Enter the product name: ");
    char name[50];
    while (scanf("%s", name) != 1)
    {
        printf("Error: Invalid input. Please enter a valid string name.\n");
        while (getchar() != '\n');
    }

    printf("Enter the product price: ");
    double price;
    while (scanf("%lf", &price) != 1)
    {
        printf("Error: Invalid input. Please enter a valid double price.\n");
        while (getchar() != '\n');
    }

    printf("Enter the product stock: ");
    int stock;
    while (scanf("%d", &stock) != 1)
    {
        printf("Error: Invalid input. Please enter a valid integer stock.\n");
        while (getchar() != '\n');
    }

    Product product;
    product.id = id;
    strcpy(product.name, name);
    product.price = price;
    product.stock = stock;

    products[numProducts] = product;
    numProducts++;

    // Open the file in append mode
    FILE *file = fopen("products.txt", "a");
    if (file == NULL)
    {
        printf("Error: Could not open the file.\n");
        return;
    }

    // Write the product details to the file
    fprintf(file, "%d,%s,%.2f,%d\n", product.id, product.name, product.price, product.stock);

    // Close the file
    fclose(file);

    printf("Product added successfully.\n");
}          
void updateProduct()
{
    printf("Enter the product ID: ");
    int id;
    while (scanf("%d", &id) != 1)
    {
        printf("Error: Invalid input. Please enter a valid integer ID.\n");
        while (getchar() != '\n');
    }

    int productIndex = -1;
    for (int i = 0; i < numProducts; i++)
    {
        if (products[i].id == id)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1)
    {
        printf("Error: No product with this ID was found.\n");
        return;
    }

    printf("Enter the updated product name: ");
    char name[50];
    while (scanf("%s", name) != 1)
    {
        printf("Error: Invalid input. Please enter a valid string name.\n");
        while (getchar() != '\n');
    }

    printf("Enter the updated product price: ");
    double price;
    while (scanf("%lf", &price) != 1)
    {
        printf("Error: Invalid input. Please enter a valid double price.\n");
        while (getchar() != '\n');
    }

    printf("Enter the updated product stock: ");
    int stock;
    while (scanf("%d", &stock) != 1)
    {
        printf("Error: Invalid input. Please enter a valid integer stock.\n");
        while (getchar() != '\n');
    }

    strcpy(products[productIndex].name, name);
    products[productIndex].price = price;
    products[productIndex].stock = stock;

    // Open the file in write mode
    FILE *file = fopen("products.txt", "w");
    if (file == NULL)
    {
        printf("Error: Could not open the file.\n");
        return;
    }

    // Write the updated product details to the file
    fprintf(file, "%d,%s,%.2f,%d\n", products[productIndex].id, products[productIndex].name, products[productIndex].price, products[productIndex].stock);

    // Close the file
    fclose(file);

    printf("Product updated successfully.\n");
}
void displayProducts()
{
    if (numProducts == 0)
    {
        printf("No products to display.\n");
        return;
    }

    printf("ID\tName\t\tPrice\tStock\n");
    for (int i = 0; i < numProducts; i++)
    {
        Product product = products[i];
        printf("%d\t%s\t\t%.2f\t%d\n", product.id, product.name, product.price, product.stock);
    }
}
void deleteProduct()
{
    printf("Enter the product ID: ");
    int id;
    scanf("%d", &id);

    int productIndex = -1;
    for (int i = 0; i < numProducts; i++)
    {
        if (products[i].id == id)
        {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1)
    {
        printf("Error: No product with this ID was found.\n");
        return 0;
    }

    // Shift the products after the deleted product one position to the left
    for (int i = productIndex; i < numProducts - 1; i++)
    {
        products[i] = products[i + 1];
    }
    numProducts--;

    printf("Product deleted successfully.\n");
}
int main()
{
    printf("Welcome to the pharmacy store management system!\n");
    printf("Enter a command:\n");
    printf("1. Add a product\n");
    printf("2. Update a product\n");
    printf("3. Delete a product\n");
    printf("4. Display products\n");
    printf("5. Exit\n");

    while (1)
    {
        int command;
        scanf("%d", &command);

        if (command == 1)
        {
            addProduct();
        }
        else if (command == 2)
        {
            updateProduct();
        }
        else if (command == 3)
        {
            deleteProduct();
        }
        else if (command == 4)
        {
    displayProducts();
     }

        else if (command == 5)
        {
            
            break;
        }
        else
        {
            printf("Invalid command.\n");
        }
    }

    return 0;
}