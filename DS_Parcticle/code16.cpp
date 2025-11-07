#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // For std::setprecision

using namespace std;

// Define the structure for a Student record
struct Student {
    int rollNumber;
    string name;
    float marks;
};

// Helper function to swap two Student objects
void swapStudents(Student& a, Student& b) {
    Student temp = a;
    a = b;
    b = temp;
}

// --- 1. Bubble Sort by Roll Number (Ascending) ---
void bubbleSortByRoll(vector<Student>& records) {
    int n = records.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (records[j].rollNumber > records[j + 1].rollNumber) {
                swapStudents(records[j], records[j + 1]);
            }
        }
    }
}

// --- 2. Bubble Sort by Name (Alphabetical) ---
void bubbleSortByName(vector<Student>& records) {
    int n = records.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (records[j].name > records[j + 1].name) {
                swapStudents(records[j], records[j + 1]);
            }
        }
    }
}

// --- 3. Bubble Sort by Marks (Descending) ---
void bubbleSortByMarks(vector<Student>& records) {
    int n = records.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (records[j].marks < records[j + 1].marks) { // < for descending
                swapStudents(records[j], records[j + 1]);
            }
        }
    }
}

// Function to display the list of students
void displayRecords(const vector<Student>& students) {
    if (students.empty()) {
        cout << "\nNo records to display." << endl;
        return;
    }

    cout << "\n--- Student Records ---" << endl;
    for (const auto& s : students) {
        cout << "------------------------" << endl;
        cout << "Roll Number: " << s.rollNumber << endl;
        cout << "Name       : " << s.name << endl;
        cout << "Marks      : " << s.marks << endl;
    }
    cout << "------------------------" << endl;
}

int main() {
    vector<Student> records;
    int choice;

    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n--- Student Record Management ---" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display All Records" << endl;
        cout << "3. Sort by Roll Number (Ascending)" << endl;
        cout << "4. Sort by Name (Alphabetical)" << endl;
        cout << "5. Sort by Marks (Descending)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";

        cin >> choice;

        switch (choice) {
            case 1: {
                if (records.size() >= 100) {
                    cout << "Cannot add more records. Limit of 100 reached." << endl;
                    break;
                }

                Student newStudent;
                cout << "Enter Roll Number: ";
                cin >> newStudent.rollNumber;
                cin.ignore();
                cout << "Enter Name: ";
                getline(cin, newStudent.name);
                cout << "Enter Marks: ";
                cin >> newStudent.marks;

                records.push_back(newStudent);
                cout << "Student record added successfully." << endl;
                break;
            }
            case 2: {
                displayRecords(records);
                break;
            }
            case 3: { // Sort by Roll Number (Ascending)
                if (records.empty()) {
                    cout << "No records to sort." << endl;
                } else {
                    bubbleSortByRoll(records);
                    cout << "Records sorted by Roll Number (Ascending)." << endl;
                }
                break;
            }
            case 4: { // Sort by Name (Lexicographical)
                if (records.empty()) {
                    cout << "No records to sort." << endl;
                } else {
                    bubbleSortByName(records);
                    cout << "Records sorted by Name (Alphabetical)." << endl;
                }
                break;
            }
            case 5: { // Sort by Marks (Descending)
                if (records.empty()) {
                    cout << "No records to sort." << endl;
                } else {
                    bubbleSortByMarks(records);
                    cout << "Records sorted by Marks (Descending)." << endl;
                }
                break;
            }
            case 6: {
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