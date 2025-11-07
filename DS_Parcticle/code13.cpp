#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::setprecision

using namespace std;

// Define the structure for a Book
struct Book {
    string title;
    string author;
    double price;
};

// Helper function to swap two Book objects
void swapBooks(Book& a, Book& b) {
    Book temp = a;
    a = b;
    b = temp;
}

// Bubble Sort to sort books by title (alphabetically)
void bubbleSortByTitle(vector<Book>& books) {
    int n = books.size();
    if (n == 0) return;

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            // Compare titles for alphabetical order
            if (books[j].title > books[j + 1].title) {
                swapBooks(books[j], books[j + 1]);
            }
        }
    }
}

// Function to display the book catalog
void displayCatalog(const vector<Book>& books) {
    if (books.empty()) {
        cout << "\nThe catalog is empty." << endl;
        return;
    }

    cout << "\n--- Book Catalog ---" << endl;
    for (const auto& book : books) {
        cout << "----------------------" << endl;
        cout << "Title  : " << book.title << endl;
        cout << "Author : " << book.author << endl;
        cout << "Price  : $" << book.price << endl;
    }
    cout << "----------------------" << endl;
}

int main() {
    vector<Book> catalog;
    int choice;

    // Set floating point output format for price
    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n--- Online Bookstore ---" << endl;
        cout << "1. Add Book" << endl;
        cout << "2. Display Catalog" << endl;
        cout << "3. Sort by Title (Alphabetical)" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: { // Add Book
                Book newBook;
                cin.ignore(); // Consume newline left by cin
                
                cout << "Enter Title: ";
                getline(cin, newBook.title);

                cout << "Enter Author: ";
                getline(cin, newBook.author);

                cout << "Enter Price: $";
                cin >> newBook.price;

                catalog.push_back(newBook);
                cout << "Book added to catalog." << endl;
                break;
            }
            case 2: { // Display Catalog
                displayCatalog(catalog);
                break;
            }
            case 3: { // Sort by Title
                if (catalog.empty()) {
                    cout << "No books to sort." << endl;
                } else {
                    bubbleSortByTitle(catalog);
                    cout << "Catalog sorted by title." << endl;
                }
                break;
            }
            case 4: { // Exit
                cout << "Exiting." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}