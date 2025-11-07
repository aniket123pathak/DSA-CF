#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    stack<string> undoStack;
    stack<string> redoStack;
    string currentState = "";

    int choice;
    while (true) {
        cout << "\n--- Text Editor ---" << endl;
        cout << "Current Text: " << (currentState.empty() ? "[empty]" : currentState) << endl;
        cout << "1. Type" << endl;
        cout << "2. Undo" << endl;
        cout << "3. Redo" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;
        cin.ignore(); // To consume the newline character left by cin

        switch (choice) {
            case 1: { // Type
                cout << "Enter text to add: ";
                string textToAdd;
                getline(cin, textToAdd);

                // Save the current state to the undo stack
                undoStack.push(currentState);
                
                // Update the current state
                currentState += textToAdd;

                // Clear the redo stack, as a new action invalidates it
                while (!redoStack.empty()) {
                    redoStack.pop();
                }
                break;
            }
            case 2: { // Undo
                if (undoStack.empty()) {
                    cout << "Cannot undo. No actions to undo." << endl;
                } else {
                    // Save the current state to the redo stack
                    redoStack.push(currentState);
                    
                    // Revert to the previous state
                    currentState = undoStack.top();
                    undoStack.pop();
                    
                    cout << "Undo successful." << endl;
                }
                break;
            }
            case 3: { // Redo
                if (redoStack.empty()) {
                    cout << "Cannot redo. No actions to redo." << endl;
                } else {
                    // Save the current state back to the undo stack
                    undoStack.push(currentState);
                    
                    // Re-apply the "undone" state
                    currentState = redoStack.top();
                    redoStack.pop();
                    
                    cout << "Redo successful." << endl;
                }
                break;
            }
            case 4: { // Exit
                cout << "Exiting." << endl;
                return 0;
            }
            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    }

    return 0;
}