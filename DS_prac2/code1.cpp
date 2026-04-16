#include <iostream>
using namespace std;

// Book Node
struct Book {
    string title, author;
    float price;
    Book* left;
    Book* right;
};

// Create new book
Book* createBook(string title, string author, float price) {
    Book* newBook = new Book();
    newBook->title = title;
    newBook->author = author;
    newBook->price = price;
    newBook->left = newBook->right = NULL;
    return newBook;
}

// Insert into BST
Book* insert(Book* root, string title, string author, float price) {
    if (root == NULL)
        return createBook(title, author, price);

    if (title < root->title)
        root->left = insert(root->left, title, author, price);
    else if (title > root->title)
        root->right = insert(root->right, title, author, price);

    return root;
}

// Search book by title
Book* search(Book* root, string title) {
    if (root == NULL || root->title == title)
        return root;

    if (title < root->title)
        return search(root->left, title);
    else
        return search(root->right, title);
}

// Find minimum node
Book* findMin(Book* root) {
    while (root->left != NULL)
        root = root->left;
    return root;
}

// Delete book
Book* deleteBook(Book* root, string title) {
    if (root == NULL)
        return NULL;

    if (title < root->title)
        root->left = deleteBook(root->left, title);
    else if (title > root->title)
        root->right = deleteBook(root->right, title);
    else {
        // Node found
        if (root->left == NULL)
            return root->right;
        else if (root->right == NULL)
            return root->left;

        Book* temp = findMin(root->right);

        root->title = temp->title;
        root->author = temp->author;
        root->price = temp->price;

        root->right = deleteBook(root->right, temp->title);
    }
    return root;
}

// Update book
void update(Book* root, string title) {
    Book* book = search(root, title);

    if (book == NULL) {
        cout << "Book not found!\n";
        return;
    }

    cout << "Enter new author: ";
    cin >> book->author;

    cout << "Enter new price: ";
    cin >> book->price;

    cout << "Book updated successfully!\n";
}

// Display (Inorder Traversal)
void display(Book* root) {
    if (root != NULL) {
        display(root->left);
        cout << "Title: " << root->title
             << ", Author: " << root->author
             << ", Price: " << root->price << endl;
        display(root->right);
    }
}

// Main
int main() {
    Book* root = NULL;
    int choice;
    string title, author;
    float price;

    do {
        cout << "\n--- Online Bookstore ---";
        cout << "\n1. Add Book";
        cout << "\n2. Search Book";
        cout << "\n3. Delete Book";
        cout << "\n4. Update Book";
        cout << "\n5. Display Catalog";
        cout << "\n6. Exit";
        cout << "\nEnter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin >> title;
                cout << "Enter author: ";
                cin >> author;
                cout << "Enter price: ";
                cin >> price;
                root = insert(root, title, author, price);
                break;

            case 2:
                cout << "Enter title to search: ";
                cin >> title;
                if (search(root, title))
                    cout << "Book found!\n";
                else
                    cout << "Book not found!\n";
                break;

            case 3:
                cout << "Enter title to delete: ";
                cin >> title;
                root = deleteBook(root, title);
                break;

            case 4:
                cout << "Enter title to update: ";
                cin >> title;
                update(root, title);
                break;

            case 5:
                cout << "\nCatalog:\n";
                display(root);
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}