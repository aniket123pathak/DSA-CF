#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

struct Student {
    int rollNo;
    char name[30];
    float marks;
};

void addRecord(fstream &file) {
    Student s;
    cout << "\nEnter Roll No: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(s.name, 30);
    cout << "Enter Marks: ";
    cin >> s.marks;

    int pos = (s.rollNo - 1) * sizeof(Student);
    file.seekp(pos, ios::beg);
    file.write(reinterpret_cast<char*>(&s), sizeof(Student));
    cout << "\n? Record added successfully.\n";
}

void displayAll(fstream &file) {
    Student s;
    file.seekg(0, ios::beg);
    cout << "\n---- Student Records ----\n";
    cout << setw(10) << "RollNo" << setw(20) << "Name" << setw(10) << "Marks\n";
    while (file.read(reinterpret_cast<char*>(&s), sizeof(Student))) {
        if (s.rollNo != 0)  // skip deleted records
            cout << setw(10) << s.rollNo << setw(20) << s.name << setw(10) << s.marks << endl;
    }
    file.clear();  // clear EOF flag
}

void searchRecord(fstream &file) {
    int roll;
    cout << "\nEnter Roll No to search: ";
    cin >> roll;
    int pos = (roll - 1) * sizeof(Student);
    Student s;
    file.seekg(pos, ios::beg);
    file.read(reinterpret_cast<char*>(&s), sizeof(Student));

    if (s.rollNo == roll && s.rollNo != 0)
        cout << "\nRecord Found:\nRollNo: " << s.rollNo << "\nName: " << s.name << "\nMarks: " << s.marks << endl;
    else
        cout << "\n? Record not found!\n";
}

void modifyRecord(fstream &file) {
    int roll;
    cout << "\nEnter Roll No to modify: ";
    cin >> roll;
    int pos = (roll - 1) * sizeof(Student);
    Student s;
    file.seekg(pos, ios::beg);
    file.read(reinterpret_cast<char*>(&s), sizeof(Student));

    if (s.rollNo == roll && s.rollNo != 0) {
        cout << "\nEnter new name: ";
        cin.ignore();
        cin.getline(s.name, 30);
        cout << "Enter new marks: ";
        cin >> s.marks;

        file.seekp(pos, ios::beg);
        file.write(reinterpret_cast<char*>(&s), sizeof(Student));
        cout << "\n? Record updated successfully.\n";
    } else {
        cout << "\n? Record not found!\n";
    }
}

void deleteRecord(fstream &file) {
    int roll;
    cout << "\nEnter Roll No to delete: ";
    cin >> roll;
    int pos = (roll - 1) * sizeof(Student);
    Student s;
    file.seekg(pos, ios::beg);
    file.read(reinterpret_cast<char*>(&s), sizeof(Student));

    if (s.rollNo == roll && s.rollNo != 0) {
        Student blank = {0, "", 0.0};
        file.seekp(pos, ios::beg);
        file.write(reinterpret_cast<char*>(&blank), sizeof(Student));
        cout << "\n? Record deleted successfully.\n";
    } else {
        cout << "\n? Record not found!\n";
    }
}

int main() {
    fstream file("students.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        // Create file if not exists
        file.open("students.dat", ios::out | ios::binary);
        file.close();
        file.open("students.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "\n===== Direct Access File Menu =====";
        cout << "\n1. Add Record";
        cout << "\n2. Display All Records";
        cout << "\n3. Search Record";
        cout << "\n4. Modify Record";
        cout << "\n5. Delete Record";
        cout << "\n6. Exit";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addRecord(file); break;
            case 2: displayAll(file); break;
            case 3: searchRecord(file); break;
            case 4: modifyRecord(file); break;
            case 5: deleteRecord(file); break;
            case 6: cout << "\nExiting..."; break;
            default: cout << "\nInvalid choice!";
        }
    } while (choice != 6);

    file.close();
    return 0;
}