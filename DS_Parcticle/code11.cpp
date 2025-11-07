#include <iostream>
#include <cstdlib> 

using namespace std;

#define MAX_SIZE 5

class CircularQueue {
private:
    char queue[MAX_SIZE];
    int front;
    int rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void insertElement() {
        char item;

        if (isFull()) {
            cout << "\n!! QUEUE OVERFLOW !!\n";
            cout << "Cannot insert more elements.\n";
            return; 
        }

        cout << "Enter the character to insert: ";
        cin >> item;

        if (isEmpty()) {
            front = 0;
        }

        rear = (rear + 1) % MAX_SIZE;
        queue[rear] = item;
        
        cout << "'" << item << "' was inserted successfully.\n";
    }

    void deleteElement() {
        char item;

        if (isEmpty()) {
            cout << "\n!! QUEUE UNDERFLOW !!\n";
            cout << "Cannot delete from an empty queue.\n";
            return; 
        }

        item = queue[front];

        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }

        cout << "'" << item << "' was deleted successfully.\n";
    }

    void displayQueue() {
        if (isEmpty()) {
            cout << "\nQueue is Empty.\n";
            return;
        }

        cout << "\n--- QUEUE STATUS ---";
        cout << "\n(Front is at index " << front << ")";
        cout << "\n(Rear is at index " << rear << ")\n";
        
        cout << "Front -> ";

        for (int i = front; ; i = (i + 1) % MAX_SIZE) {
            cout << queue[i] << " ";
            if (i == rear) {
                break; 
            }
        }
        
        cout << "<- Rear\n";
    }
};

int main() {
    int choice;
    CircularQueue q;

    cout << "--- C++ Program for Circular Queue Operations ---\n";
    cout << "Queue size is set to " << MAX_SIZE << "\n";

    while (true) {
        cout << "\n--- MENU ---";
        cout << "\n1. Insert an Element (Enqueue)";
        cout << "\n2. Delete an Element (Dequeue)";
        cout << "\n3. Display Queue Status";
        cout << "\n4. Exit";
        cout << "\nEnter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1:
                q.insertElement(); 
                break;
            case 2:
                q.deleteElement(); 
                break;
            case 3:
                q.displayQueue(); 
                break;
            case 4:
                cout << "Exiting program.\n";
                return 0; 
            default:
                cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}