#include <iostream>

using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int val) {
        data = val;
        next = nullptr;
        prev = nullptr;
    }
};

class DoublyLinkedList {
private:
    Node* head; 
    Node* tail; 

public:
    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }

    ~DoublyLinkedList() {
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

    void createList() {
        if (!isEmpty()) {
            cout << "List already exists. Use the 'Insert' menu (if available) to add more." << endl;
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
            
            Node* newNode = new Node(val);
            
            if (isEmpty()) {
                head = newNode;
                tail = newNode;
            } else {
                tail->next = newNode;
                newNode->prev = tail;
                tail = newNode;
            }
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
            cout << temp->data << " <-> ";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    
    void displayReverse() {
        if (isEmpty()) {
            cout << "List is empty." << endl;
            return;
        }

        Node* temp = tail;
        cout << "Tail -> ";
        while (temp != nullptr) {
            cout << temp->data << " <-> ";
            temp = temp->prev;
        }
        cout << "NULL (Head)" << endl;
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
        while (temp != nullptr && temp->data != key) {
            temp = temp->next;
        }

        if (temp == nullptr) {
            cout << key << " not found in the list." << endl;
            return;
        }

        if (temp->prev != nullptr) {
            temp->prev->next = temp->next;
        } else {
            head = temp->next;
        }

        if (temp->next != nullptr) {
            temp->next->prev = temp->prev;
        } else {
            tail = temp->prev;
        }

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
    DoublyLinkedList dll;
    int choice;

    while (true) {
        cout << "\n--- Doubly Linked List Menu ---" << endl;
        cout << "1. Create List" << endl;
        cout << "2. Display List (Forward & Reverse)" << endl;
        cout << "3. Delete Node" << endl;
        cout << "4. Search Node" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                dll.createList();
                break;
            case 2:
                dll.displayList();
                dll.displayReverse();
                break;
            case 3:
                dll.deleteNode();
                break;
            case 4:
                dll.searchNode();
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