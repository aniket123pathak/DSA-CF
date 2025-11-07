#include <iostream>
#include <string> 

using namespace std;

#define MAX_SIZE 10

class Stack {
private:
    char arr[MAX_SIZE]; 
    int top;            

public:
    Stack() {
        top = -1; 
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return top == -1;
    }

    bool push(char val) {
        if (isFull()) {
            return false; 
        }
        top++;
        arr[top] = val;
        return true;
    }

    char pop() {
        if (isEmpty()) {
            return '\0'; 
        }
        char val = arr[top];
        top--;
        return val;
    }

    void display() {
        if (isEmpty()) {
            cout << "\nStack is empty." << endl;
            return;
        }

        cout << "\n--- STACK STATUS ---";
        cout << "\nTop -> ";
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << "\n--------------------\n";
    }
};

void checkPalindrome() {
    string inputStr;
    cout << "\nEnter a string to check: ";
    getline(cin, inputStr);

    Stack palindromeStack;
    string reversedStr = "";

    for (int i = 0; i < inputStr.length(); i++) {
        if (!palindromeStack.push(inputStr[i])) {
            cout << "!! String is too long for the stack demo (max " << MAX_SIZE << ") !!\n";
            return; 
        }
    }

    while (!palindromeStack.isEmpty()) {
        reversedStr += palindromeStack.pop();
    }

    cout << "\n--- Palindrome Check ---" << endl;
    cout << "Original: " << inputStr << endl;
    cout << "Reversed: " << reversedStr << endl;
    
    if (inputStr == reversedStr) {
        cout << "Result: The string is a PALINDROME." << endl;
    } else {
        cout << "Result: The string is NOT a palindrome." << endl;
    }
    cout << "--------------------------" << endl;
}

int main() {
    Stack s; 
    int choice;

    while (true) {
        cout << "\n--- STACK MENU (Array Implementation) ---";
        cout << "\n1. Push an Element (a)";
        cout << "\n2. Pop an Element (b)";
        cout << "\n3. Check Palindrome (c)";
        cout << "\n4. Display Stack (e)";
        cout << "\n5. Exit (f)";
        cout << "\n(Overflow/Underflow (d) shown in 1 & 2)";
        cout << "\nEnter your choice: ";
        
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: { 
                char val;
                cout << "Enter character to push: ";
                cin >> val;
                cin.ignore(); 

                if (!s.push(val)) {
                    cout << "\n!! STACK OVERFLOW (d) !! Cannot push '" << val << "'\n";
                } else {
                    cout << "'" << val << "' pushed onto the stack." << endl;
                }
                break;
            }
            case 2: { 
                if (s.isEmpty()) {
                    cout << "\n!! STACK UNDERFLOW (d) !! Cannot pop.\n";
                } else {
                    char poppedVal = s.pop();
                    cout << "'" << poppedVal << "' was popped from the stack." << endl;
                }
                break;
            }
            case 3: { 
                checkPalindrome();
                break;
            }
            case 4: { 
                s.display();
                break;
            }
            case 5: { 
                cout << "Exiting." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return 0;
}