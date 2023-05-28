#include <iostream>
#include <string>

#define MAX_NUM_PRODUCTS 100

struct Product {
    int id;
    std::string name;
    double price;
    int stock;
};

Product products[MAX_NUM_PRODUCTS];
int numProducts = 0;

void addProduct() {
    if (numProducts == MAX_NUM_PRODUCTS) {
        std::cout << "Error: Cannot add more products. The maximum number of products has been reached.\n";
        return;
    }

    std::cout << "Enter the product ID: ";
    int id;
    while (!(std::cin >> id)) {
        std::cout << "Error: Invalid input. Please enter a valid integer ID.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            std::cout << "Error: A product with this ID already exists.\n";
            return;
        }
    }

    std::cout << "Enter the product name: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter the product price: ";
    double price;
    while (!(std::cin >> price)) {
        std::cout << "Error: Invalid input. Please enter a valid double price.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the product stock: ";
    int stock;
    while (!(std::cin >> stock)) {
        std::cout << "Error: Invalid input. Please enter a valid integer stock.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    Product product;
    product.id = id;
    product.name = name;
    product.price = price;
    product.stock = stock;

    products[numProducts] = product;
    numProducts++;

    std::cout << "Product added successfully.\n";
}

void updateProduct() {
    std::cout << "Enter the product ID: ";
    int id;
    while (!(std::cin >> id)) {
        std::cout << "Error: Invalid input. Please enter a valid integer ID.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    int productIndex = -1;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        std::cout << "Error: No product with this ID was found.\n";
        return;
    }

    std::cout << "Enter the updated product name: ";
    std::string name;
    std::cin.ignore();
    std::getline(std::cin, name);

    std::cout << "Enter the updated product price: ";
    double price;
    while (!(std::cin >> price)) {
        std::cout << "Error: Invalid input. Please enter a valid double price.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    std::cout << "Enter the updated product stock: ";
    int stock;
    while (!(std::cin >> stock)) {
        std::cout << "Error: Invalid input. Please enter a valid integer stock.\n";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    products[productIndex].name = name;
    products[productIndex].price = price;
    products[productIndex].stock = stock;

    std::cout << "Product updated successfully.\n";
}

void displayProducts() {
    if (numProducts == 0) {
        std::cout << "No products to display.\n";
        return;
    }

    std::cout << "ID\tName\t\tPrice\tStock\n";
    for (int i = 0; i < numProducts; i++) {
        Product product = products[i];
        std::cout << product.id << "\t" << product.name << "\t\t" << product.price << "\t" << product.stock << "\n";
    }
}

void deleteProduct() {
    std::cout << "Enter the product ID: ";
    int id;
    std::cin >> id;

    int productIndex = -1;
    for (int i = 0; i < numProducts; i++) {
        if (products[i].id == id) {
            productIndex = i;
            break;
        }
    }

    if (productIndex == -1) {
        std::cout << "Error: No product with this ID was found.\n";
        return;
    }

    for (int i = productIndex; i < numProducts - 1; i++) {
        products[i] = products[i + 1];
    }
    numProducts--;

    std::cout << "Product deleted successfully.\n";
}

int main() {
    std::cout << "Welcome to the pharmacy store management system!\n";
    std::cout << "Enter a command:\n";
    std::cout << "1. Add a product\n";
    std::cout << "2. Update a product\n";
    std::cout << "3. Delete a product\n";
    std::cout << "4. Display products\n";
    std::cout << "5. Exit\n";

    while (true) {
        int command;
        std::cin >> command;

        if (command == 1) {
            addProduct();
        }
        else if (command == 2) {
            updateProduct();
        }
        else if (command == 3) {
            deleteProduct();
        }
        else if (command == 4) {
            displayProducts();
        }
        else if (command == 5) {
            break;
        }
        else {
            std::cout << "Invalid command.\n";
        }
    }

    return 0;
}
