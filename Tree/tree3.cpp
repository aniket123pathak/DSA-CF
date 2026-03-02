#include <iostream>
#include <string>

using namespace std;

class Book {
public:
    string title;
    string author;
    double price;
    int stock;

    Book() {
        title = "";
        author = "";
        price = 0.0;
        stock = 0;
    }

    Book(string t, string a, double p, int s) {
        title = t;
        author = a;
        price = p;
        stock = s;
    }
};

class TreeNode {
public:
    Book bookData;
    TreeNode* left;
    TreeNode* right;

    TreeNode(Book b) {
        bookData = b;
        left = nullptr;
        right = nullptr;
    }
};

class BookstoreBST {
private:
    TreeNode* root;

    TreeNode* insertHelper(TreeNode* node, Book newBook) {
        if (node == nullptr) {
            return new TreeNode(newBook);
        }

        if (newBook.title < node->bookData.title) {
            node->left = insertHelper(node->left, newBook);
        } else if (newBook.title > node->bookData.title) {
            node->right = insertHelper(node->right, newBook);
        } else {
            cout << "Book '" << newBook.title << "' already exists in the catalog.\n";
        }
        return node;
    }

    TreeNode* searchTitleHelper(TreeNode* node, string targetTitle) {
        if (node == nullptr || node->bookData.title == targetTitle) {
            return node;
        }

        if (targetTitle < node->bookData.title) {
            return searchTitleHelper(node->left, targetTitle);
        } else {
            return searchTitleHelper(node->right, targetTitle);
        }
    }

    void searchAuthorHelper(TreeNode* node, string targetAuthor, bool& found) {
        if (node != nullptr) {
            searchAuthorHelper(node->left, targetAuthor, found);
            
            if (node->bookData.author == targetAuthor) {
                cout << "- " << node->bookData.title << " ($" << node->bookData.price 
                     << ") | Stock: " << node->bookData.stock << "\n";
                found = true;
            }
            
            searchAuthorHelper(node->right, targetAuthor, found);
        }
    }

    void displayHelper(TreeNode* node) {
        if (node != nullptr) {
            displayHelper(node->left);
            cout << "Title: " << node->bookData.title 
                 << " | Author: " << node->bookData.author 
                 << " | Price: $" << node->bookData.price 
                 << " | Stock: " << node->bookData.stock << "\n";
            displayHelper(node->right);
        }
    }

public:
    BookstoreBST() {
        root = nullptr;
    }

    void addBook(string title, string author, double price, int stock) {
        Book newBook(title, author, price, stock);
        root = insertHelper(root, newBook);
        cout << "Added: " << title << "\n";
    }

    void searchByTitle(string title) {
        TreeNode* result = searchTitleHelper(root, title);
        if (result != nullptr) {
            cout << "Found Book: " << result->bookData.title 
                 << " by " << result->bookData.author 
                 << " | Price: $" << result->bookData.price 
                 << " | Stock: " << result->bookData.stock << "\n";
        } else {
            cout << "Book with title '" << title << "' not found.\n";
        }
    }

    void searchByAuthor(string author) {
        cout << "Books by " << author << ":\n";
        bool found = false;
        searchAuthorHelper(root, author, found);
        if (found == false) {
            cout << "No books found by this author.\n";
        }
    }

    void updateBook(string title, double newPrice, int newStock) {
        TreeNode* result = searchTitleHelper(root, title);
        if (result != nullptr) {
            result->bookData.price = newPrice;
            result->bookData.stock = newStock;
            cout << "Updated '" << title << "' successfully.\n";
        } else {
            cout << "Cannot update. Book '" << title << "' not found.\n";
        }
    }

    void displayCatalog() {
        cout << "\n--- Bookstore Catalog ---\n";
        if (root == nullptr) {
            cout << "The catalog is currently empty.\n";
        } else {
            displayHelper(root);
        }
        cout << "-------------------------\n";
    }
};

int main() {
    BookstoreBST catalog;

    catalog.addBook("Dune", "Frank Herbert", 15.99, 10);
    catalog.addBook("1984", "George Orwell", 12.50, 25);
    catalog.addBook("The Hobbit", "J.R.R. Tolkien", 14.20, 15);
    catalog.addBook("Animal Farm", "George Orwell", 9.99, 30);
    catalog.addBook("Foundation", "Isaac Asimov", 18.00, 5);

    catalog.displayCatalog();

    cout << "\n--- Searching by Title ---\n";
    catalog.searchByTitle("Dune");
    catalog.searchByTitle("Harry Potter"); 

    cout << "\n--- Searching by Author ---\n";
    catalog.searchByAuthor("George Orwell");

    cout << "\n--- Updating Book Info ---\n";
    catalog.updateBook("Dune", 14.99, 8); 
    
    catalog.searchByTitle("Dune");

    return 0;
}