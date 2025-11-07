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

    void findSum() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return;
        }

        long long sum = 0;
        for (int i = 0; i < currentSize; i++) {
            sum += arr[i];
        }
        cout << "Sum of all elements: " << sum << endl;
    }

    void findMax() {
        if (isEmpty()) {
            cout << "Array is empty." << endl;
            return;
        }

        int maxVal = arr[0];
        for (int i = 1; i < currentSize; i++) {
            if (arr[i] > maxVal) {
                maxVal = arr[i];
            }
        }
        cout << "Maximum element: " << maxVal << endl;
    }
};

int main() {
    ArrayOps myArr;
    int choice;

    while (true) {
        cout << "\n--- Array Menu (Sum/Max) ---" << endl;
        cout << "1. Create Array" << endl;
        cout << "2. Display Array" << endl;
        cout << "3. Find Sum of Elements" << endl;
        cout << "4. Find Max Element" << endl;
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
                myArr.findSum();
                break;
            case 4:
                myArr.findMax();
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