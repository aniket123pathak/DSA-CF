#include <iostream>

using namespace std;

#define MAX_SIZE 100

class ArrayOps {
private:
    int arr[MAX_SIZE];
    int currentSize;

public:
    ArrayOps() {
        currentSize = 0;
    }

    bool isFull() {
        return currentSize == MAX_SIZE;
    }

    bool isEmpty() {
        return currentSize == 0;
    }

    void create() {
        cout << "Enter number of elements (N): ";
        cin >> currentSize;

        if (currentSize > MAX_SIZE) {
            cout << "Error: Size exceeds maximum limit of " << MAX_SIZE << endl;
            currentSize = 0;
            return;
        }

        cout << "Enter " << currentSize << " integer elements:" << endl;
        for (int i = 0; i < currentSize; i++) {
            cin >> arr[i];
        }
        cout << "Array created successfully." << endl;
    }

    void display() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return;
        }

        cout << "Array elements: [ ";
        for (int i = 0; i < currentSize; i++) {
            cout << arr[i] << " ";
        }
        cout << "]" << endl;
    }

    void insert() {
        if (isFull()) {
            cout << "Array is full. Cannot insert." << endl;
            return;
        }

        int pos, val;
        cout << "Enter position to insert (1 to " << currentSize + 1 << "): ";
        cin >> pos;
        cout << "Enter value to insert: ";
        cin >> val;

        if (pos < 1 || pos > currentSize + 1) {
            cout << "Invalid position." << endl;
            return;
        }

        for (int i = currentSize; i >= pos; i--) {
            arr[i] = arr[i - 1];
        }

        arr[pos - 1] = val;
        currentSize++;
        cout << "Element inserted successfully." << endl;
    }

    void search() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return;
        }

        int key;
        cout << "Enter element to search for: ";
        cin >> key;

        for (int i = 0; i < currentSize; i++) {
            if (arr[i] == key) {
                cout << "Element " << key << " found at position " << i + 1 << "." << endl;
                return;
            }
        }
        cout << "Element " << key << " not found." << endl;
    }
};

int main() {
    ArrayOps myArr;
    int choice;

    while (true) {
        cout << "\n--- Array Menu (Insert) ---" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Insert Element" << endl;
        cout << "4. Search Element" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                myArr.create();
                break;
            case 2:
                myArr.display();
                break;
            case 3:
                myArr.insert();
                break;
            case 4:
                myArr.search();
                break;
            case 5:
                cout << "Exiting." << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

    return 0;
}