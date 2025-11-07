#include <iostream>

using namespace std;

// Class definition for a Node
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int val) {
        data = val;
        next = nullptr;
    }
};

// Class definition for the Circular Linked List
class CircularLinkedList {
private:
    Node* last; // Pointer to the last node

public:
    // Constructor
    CircularLinkedList() {
        last = nullptr;
    }

    // Helper function to check if the list is empty
    bool isEmpty() {
        return last == nullptr;
    }

    // a) Create List (populates the list with n nodes)
    void createList() {
        if (!isEmpty()) {
            cout << "List already created. Use 'Insert' to add more." << endl;
            return;
        }

        int n;
        cout << "Enter the number of nodes to create: ";
        cin >> n;

        if (n <= 0) {
            cout << "Invalid number of nodes." << endl;
            return;
        }

        for (int i = 0; i < n; i++) {
            int val;
            cout << "Enter data for node " << i + 1 << ": ";
            cin >> val;
            insertAtEnd(val); // Use insertAtEnd to build the list
        }
        cout << "List created successfully." << endl;
    }

    // b) Display List
    void displayList() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = last->next; // Start from the head

        cout << "Head -> ";
        do {
            cout << temp->data << " -> ";
            temp = temp->next;
        } while (temp != last->next); // Loop until back at the head
        
        cout << "(Back to " << last->next->data << ")" << endl;
    }

    // c) Insert (Helper: Insert at Beginning)
    void insertAtBeginning(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            last = newNode;
            newNode->next = last; // Point to itself
        } else {
            newNode->next = last->next; // New node points to old head
            last->next = newNode;       // Last node points to new head
        }
    }

    // c) Insert (Helper: Insert at End)
    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            last = newNode;
            newNode->next = last; // Point to itself
        } else {
            newNode->next = last->next; // New node points to head
            last->next = newNode;       // Old last points to new node
            last = newNode;             // Update last to be the new node
        }
    }

    // c) Insert (Main menu function)
    void insertNode() {
        int choice, val;
        cout << "\n--- Insert Menu ---" << endl;
        cout << "1. Insert at Beginning" << endl;
        cout << "2. Insert at End" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice != 1 && choice != 2) {
            cout << "Invalid choice." << endl;
            return;
        }

        cout << "Enter data for the new node: ";
        cin >> val;

        if (choice == 1) {
            insertAtBeginning(val);
        } else {
            insertAtEnd(val);
        }
        cout << "Node inserted successfully." << endl;
    }

    // d) Search for an element
    void searchNode() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        int key;
        cout << "Enter value to search for: ";
        cin >> key;

        Node* temp = last->next; // Start from head
        int pos = 1;
        bool found = false;

        do {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << "." << endl;
                found = true;
                break;
            }
            temp = temp->next;
            pos++;
        } while (temp != last->next); // Loop until back at the head

        if (!found) {
            cout << key << " was not found in the list." << endl;
        }
    }
};

// Main function to run the menu
int main() {
    CircularLinkedList cll;
    int choice;

    while (true) {
        cout << "\n--- Circular Linked List Menu ---" << endl;
        cout << "1. Create List" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Insert Node" << endl;
        cout << "4. Search Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cll.createList();
                break;
            case 2:
                cll.displayList();
                break;
            case 3:
                cll.insertNode();
                break;
            case 4:
                cll.searchNode();
                break;
            case 5:
                cout << "Exiting program." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}