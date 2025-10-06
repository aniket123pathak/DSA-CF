#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class Queue {
private:
    Node *front, *rear;

public:
    Queue() {
        front = NULL;
        rear = NULL;
    }

    ~Queue() {
        while (!isEmpty()) {
            dequeue();
        }
    }

    void enqueue(int val) {
        Node* newNode = new Node();
        newNode->data = val;
        newNode->next = NULL;
        cout << "Enqueued " << val << endl;

        if (rear == NULL) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    int dequeue() {
        if (front == NULL) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return -1;
        }

        Node* temp = front;
        int dequeued_data = temp->data;
        front = front->next;

        if (front == NULL) {
            rear = NULL;
        }

        delete temp;
        cout << "Dequeued " << dequeued_data << endl;
        return dequeued_data;
    }

    int peek() {
        if (front == NULL) {
            cout << "Queue is empty." << endl;
            return -1;
        }
        return front->data;
    }

    bool isEmpty() {
        return (front == NULL);
    }

    void display() {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* temp = front;
        cout << "Queue elements: FRONT -> ";
        while (temp != NULL) {
            cout << temp->data << " -> ";
            temp = temp->next;
        }
        cout << "REAR" << endl;
    }
};

int main() {
    Queue q;

    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;
    
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    
    q.display();

    cout << "Front element is: " << q.peek() << endl;

    q.dequeue();
    q.display();
    
    cout << "Is queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;

    q.enqueue(40);
    q.display();

    q.dequeue();
    q.dequeue();
    q.display();

    q.dequeue();
    q.display();
    
    return 0;
}