#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int val) {
        data = val;
        next = nullptr;
    }
};

class SinglyLinkedList {
private:
    Node* head;

public:
    SinglyLinkedList() {
        head = nullptr;
    }

    ~SinglyLinkedList() {
        Node* current = head;
        Node* nextNode = nullptr;
        while (current != nullptr) {
            nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }

    bool isEmpty() {
        return head == nullptr;
    }

    void insertAtEnd(int val) {
        Node* newNode = new Node(val);
        if (isEmpty()) {
            head = newNode;
            return;
        }
        Node* temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

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
            insertAtEnd(val);
        }
        cout << "List created successfully." << endl;
    }

    void displayList() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = head;
        cout << "Head -> ";
        while (temp != nullptr) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }

    void deleteNode() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        int key;
        cout << "Enter value to delete: ";
        cin >> key;

        Node* temp = head;
        Node* prev = nullptr;

        if (temp != nullptr && temp->data == key) {
            head = temp->next;
            delete temp;
            cout << key << " deleted successfully." << endl;
            return;
        }

        while (temp != nullptr && temp->data != key) {
            prev = temp;
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << key << " not found in the list." << endl;
            return;
        }

        prev->next = temp->next;
        delete temp;
        cout << key << " deleted successfully." << endl;
    }

    void searchNode() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        int key;
        cout << "Enter value to search for: ";
        cin >> key;

        Node* temp = head;
        int pos = 1;
        bool found = false;

        while (temp != nullptr) {
            if (temp->data == key) {
                cout << "Found " << key << " at position " << pos << "." << endl;
                found = true;
                break;
            }
            temp = temp->next;
            pos++;
        }

        if (!found) {
            cout << key << " was not found in the list." << endl;
        }
    }
};

int main() {
    SinglyLinkedList sll;
    int choice;

    while (true) {
        cout << "\n--- Singly Linked List Menu ---" << endl;
        cout << "1. Create List" << endl;
        cout << "2. Display List" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Search Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sll.createList();
                break;
            case 2:
                sll.displayList();
                break;
            case 3:
                sll.deleteNode();
                break;
            case 4:
                sll.searchNode();
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