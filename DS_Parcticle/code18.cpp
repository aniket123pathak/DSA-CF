#include <iostream>
#include <string>
#include <vector>      // For dynamic array of employees
#include <algorithm>   // For std::sort
#include <iomanip>     // For std::setprecision

using namespace std;

// Define the structure for an Employee record
struct Employee {
    int id;
    string name;
    string department;
    double salary;
};

// Function to display a single employee's details
void displayEmployee(const Employee& emp) {
    cout << "---------------------------------" << endl;
    cout << "ID        : " << emp.id << endl;
    cout << "Name      : " << emp.name << endl;
    cout << "Department: " << emp.department << endl;
    cout << "Salary    : $" << emp.salary << endl;
}

int main() {
    vector<Employee> employees;
    int choice;

    // Set floating point output format for currency
    cout << fixed << setprecision(2);

    while (true) {
        cout << "\n--- Employee Management System ---" << endl;
        cout << "1. Add Employee" << endl;
        cout << "2. Display All Employees" << endl;
        cout << "3. Sort by ID (Ascending)" << endl;
        cout << "4. Sort by Name (Alphabetical)" << endl;
        cout << "5. Sort by Salary (Descending)" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        
        cin >> choice;

        switch (choice) {
            case 1: { // Enter and store records
                Employee newEmployee;
                cout << "Enter Employee ID: ";
                cin >> newEmployee.id;

                // Consume the newline character left in the buffer by cin
                cin.ignore(); 

                cout << "Enter Name: ";
                getline(cin, newEmployee.name);

                cout << "Enter Department: ";
                getline(cin, newEmployee.department);

                cout << "Enter Salary: $";
                cin >> newEmployee.salary;

                employees.push_back(newEmployee);
                cout << "Employee added successfully." << endl;
                break;
            }
            case 2: { // Display all records
                if (employees.empty()) {
                    cout << "No employee records found." << endl;
                } else {
                    cout << "\n--- All Employee Records ---" << endl;
                    for (const auto& emp : employees) {
                        displayEmployee(emp);
                    }
                    cout << "---------------------------------" << endl;
                }
                break;
            }
            case 3: { // Sort by Employee ID (Ascending)
                if (employees.empty()) {
                    cout << "No employees to sort." << endl;
                } else {
                    sort(employees.begin(), employees.end(), 
                         [](const Employee& a, const Employee& b) {
                        return a.id < b.id;
                    });
                    cout << "Employees sorted by ID (Ascending)." << endl;
                }
                break;
            }
            case 4: { // Sort by Name (Alphabetical)
                if (employees.empty()) {
                    cout << "No employees to sort." << endl;
                } else {
                    sort(employees.begin(), employees.end(), 
                         [](const Employee& a, const Employee& b) {
                        return a.name < b.name;
                    });
                    cout << "Employees sorted by Name (Alphabetical)." << endl;
                }
                break;
            }
            case 5: { // Sort by Salary (Descending)
                if (employees.empty()) {
                    cout << "No employees to sort." << endl;
                } else {
                    sort(employees.begin(), employees.end(), 
                         [](const Employee& a, const Employee& b) {
                        return a.salary > b.salary; // Note: > for descending
                    });
                    cout << "Employees sorted by Salary (Descending)." << endl;
                }
                break;
            }
            case 6: { // Exit
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