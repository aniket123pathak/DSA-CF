#include <iostream>
#include <string>
#include <vector>      // For storing the catalog
#include <algorithm>   // For std::sort
#include <iomanip>     // For std::setprecision

using namespace std;

// Structure to define a Product
struct Product {
    int id;
    string name;
    double price;
    double rating;
};

// Helper function to display the catalog's current state
void displayCatalog(const vector<Product>& catalog) {
    cout << "\n--- Current Product Catalog ---" << endl;
    if (catalog.empty()) {
        cout << "Catalog is empty." << endl;
        return;
    }
    
    // Loop through and print each product
    for (const auto& product : catalog) {
        cout << "--------------------" << endl;
        cout << "ID    : " << product.id << endl;
        cout << "Name  : " << product.name << endl;
        cout << "Price : $" << product.price << endl;
        cout << "Rating: " << product.rating << "/5.0" << endl;
    }
    cout << "--------------------" << endl;
}

int main() {
    vector<Product> catalog;
    
    // Pre-populate with sample data to demonstrate sorting
    catalog.push_back({101, "Laptop", 999.99, 4.7});
    catalog.push_back({102, "Smartphone", 699.50, 4.5});
    catalog.push_back({103, "Headphones", 149.00, 4.2});
    catalog.push_back({104, "Mouse", 49.99, 4.8});
    catalog.push_back({105, "Keyboard", 79.99, 4.6});

    // Set cout to always show two decimal places for currency
    cout << fixed << setprecision(2);
    
    int choice;

    while (true) {
        // Show the catalog in its current (potentially sorted) state
        displayCatalog(catalog);

        cout << "\n--- Sort Options ---" << endl;
        cout << "1. Sort by Price (Low to High)" << endl;
        cout << "2. Sort by Rating (High to Low)" << endl;
        cout << "3. Sort by Name (Alphabetical)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1: // Sort by Price (low to high)
                sort(catalog.begin(), catalog.end(), 
                     [](const Product& a, const Product& b) {
                    return a.price < b.price;
                });
                cout << "Catalog sorted by Price (Low to High)." << endl;
                break;

            case 2: // Sort by Ratings (high to low)
                sort(catalog.begin(), catalog.end(), 
                     [](const Product& a, const Product& b) {
                    return a.rating > b.rating; // Note: > for descending
                });
                cout << "Catalog sorted by Rating (High to Low)." << endl;
                break;

            case 3: // Sort by Name (alphabetically)
                sort(catalog.begin(), catalog.end(), 
                     [](const Product& a, const Product& b) {
                    return a.name < b.name;
                });
                cout << "Catalog sorted by Name (Alphabetical)." << endl;
                break;

            case 4: // Exit
                cout << "Exiting." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}