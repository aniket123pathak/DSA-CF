#include <iostream>
#include <string>
#include <vector>      
#include <iomanip>     

using namespace std;

struct Product {
    int id;
    string name;
    double price;
    double rating;
};

void swapProducts(Product& a, Product& b) {
    Product temp = a;
    a = b;
    b = temp;
}

void bubbleSortByPrice(vector<Product>& catalog) {
    int n = catalog.size();
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (catalog[j].price > catalog[j + 1].price) {
                swapProducts(catalog[j], catalog[j + 1]);
            }
        }
    }
}

void bubbleSortByRating(vector<Product>& catalog) {
    int n = catalog.size();
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (catalog[j].rating < catalog[j + 1].rating) {
                swapProducts(catalog[j], catalog[j + 1]);
            }
        }
    }
}

void bubbleSortByName(vector<Product>& catalog) {
    int n = catalog.size();
    if (n == 0) return;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (catalog[j].name > catalog[j + 1].name) {
                swapProducts(catalog[j], catalog[j + 1]);
            }
        }
    }
}

void displayCatalog(const vector<Product>& catalog) {
    cout << "\n--- Current Product Catalog ---" << endl;
    if (catalog.empty()) {
        cout << "Catalog is empty." << endl;
        return;
    }
    
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
    
    catalog.push_back({101, "Laptop", 999.99, 4.7});
    catalog.push_back({102, "Smartphone", 699.50, 4.5});
    catalog.push_back({103, "Headphones", 149.00, 4.2});
    catalog.push_back({104, "Mouse", 49.99, 4.8});
    catalog.push_back({105, "Keyboard", 79.99, 4.6});

    cout << fixed << setprecision(2);
    
    int choice;

    while (true) {
        displayCatalog(catalog);

        cout << "\n--- Sort Options ---" << endl;
        cout << "1. Sort by Price (Low to High)" << endl;
        cout << "2. Sort by Rating (High to Low)" << endl;
        cout << "3. Sort by Name (Alphabetical)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        if (catalog.empty() && choice >= 1 && choice <= 3) {
            cout << "Catalog is empty, nothing to sort." << endl;
            continue;
        }

        switch (choice) {
            case 1: 
                bubbleSortByPrice(catalog);
                cout << "Catalog sorted by Price (Low to High)." << endl;
                break;

            case 2: 
                bubbleSortByRating(catalog);
                cout << "Catalog sorted by Rating (High to Low)." << endl;
                break;

            case 3: 
                bubbleSortByName(catalog);
                cout << "Catalog sorted by Name (Alphabetical)." << endl;
                break;

            case 4: 
                cout << "Exiting." << endl;
                return 0;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}