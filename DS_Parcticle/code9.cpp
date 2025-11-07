#include <iostream>

using namespace std;

#define MAX_SIZE 10

class Queue {
private:
    int arr[MAX_SIZE];
    int front;
    int rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return ((rear + 1) % MAX_SIZE == front);
    }

    bool isEmpty() {
        return (front == -1);
    }

    void enqueue(int val) {
        if (isFull()) {
            cout << "Queue Overflow: Cannot enqueue " << val << endl;
            return;
        }
        
        if (isEmpty()) {
            front = 0; 
        }
        
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
        cout << val << " enqueued to queue." << endl;
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue Underflow: Cannot dequeue." << endl;
            return;
        }

        int val = arr[front];
        
        if (front == rear) {
            front = -1;
            rear = -1;
        } else {
            front = (front + 1) % MAX_SIZE;
        }
        
        cout << val << " dequeued from queue." << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        } else {
            cout << "Front element is: " << arr[front] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        
        cout << "Queue elements: Front -> ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) {
                break;
            }
            i = (i + 1) % MAX_SIZE;
        }
        cout << "<- Rear" << endl;
    }
};

int main() {
    Queue q;
    int choice, value;

    cout << "Queue Operations (Size " << MAX_SIZE << ")" << endl;

    while (true) {
        cout << "\n--- MENU ---" << endl;
        cout << "1. Enqueue (Add)" << endl;
        cout << "2. Dequeue (Remove)" << endl;
        cout << "3. Peek (See Front)" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Display Queue" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.peek();
                break;
            case 4:
                if (q.isEmpty()) {
                    cout << "Queue is empty." << endl;
                } else {
                    cout << "Queue is not empty." << endl;
                }
                break;
            case 5:
                q.display();
                break;
            case 6:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}