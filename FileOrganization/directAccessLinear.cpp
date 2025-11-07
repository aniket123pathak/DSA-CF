#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10;   // fixed file slots

struct Student {
    int rollNo;
    char name[30];
    float marks;
    int flag;   // 0 = empty, 1 = occupied, -1 = deleted
};

// Hash function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize empty file
void initializeFile(fstream &file) {
    Student blank = {0, "", 0.0, 0};
    for (int i = 0; i < TABLE_SIZE; i++)
        file.write(reinterpret_cast<char*>(&blank), sizeof(Student));
    cout << "\n? File initialized with empty records.\n";
}

// Add a new record using linear probing
void addRecord(fstream &file) {
    Student s;
    cout << "\nEnter Roll No: ";
    cin >> s.rollNo;
    cout << "Enter Name: ";
    cin.ignore();
    cin.getline(s.name, 30);
    cout << "Enter Marks: ";
    cin >> s.marks;
    s.flag = 1;

    int loc = hashFunction(s.rollNo);
    Student temp;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = ((loc + i) % TABLE_SIZE) * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&temp), sizeof(Student));

        if (temp.flag == 0 || temp.flag == -1) {
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "\n? Record inserted at position " << (loc + i) % TABLE_SIZE << endl;
            return;
        }
    }
    cout << "\n? Hash Table is Full! Record cannot be inserted.\n";
}

// Display all records
void displayAll(fstream &file) {
    Student s;
    file.seekg(0, ios::beg);
    cout << "\n---- Student Records ----\n";
    cout << setw(10) << "Index" << setw(10) << "RollNo" << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Flag\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));
        cout << setw(10) << i << setw(10) << s.rollNo << setw(20) << s.name 
             << setw(10) << s.marks << setw(10) << s.flag << endl;
    }
    file.clear();
}

// Search for a record
void searchRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to search: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = ((loc + i) % TABLE_SIZE) * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));

        if (s.flag == 1 && s.rollNo == key) {
            cout << "\n? Record Found at position " << (loc + i) % TABLE_SIZE << endl;
            cout << "RollNo: " << s.rollNo << "\nName: " << s.name << "\nMarks: " << s.marks << endl;
            return;
        }
    }
    cout << "\n? Record not found!\n";
}

// Modify record
void modifyRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to modify: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = ((loc + i) % TABLE_SIZE) * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));

        if (s.flag == 1 && s.rollNo == key) {
            cout << "\nEnter new name: ";
            cin.ignore();
            cin.getline(s.name, 30);
            cout << "Enter new marks: ";
            cin >> s.marks;

            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "\n? Record modified successfully.\n";
            return;
        }
    }
    cout << "\n? Record not found!\n";
}

// Delete record
void deleteRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to delete: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int pos = ((loc + i) % TABLE_SIZE) * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));

        if (s.flag == 1 && s.rollNo == key) {
            s.flag = -1;  // mark as deleted
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "\n? Record deleted successfully.\n";
            return;
        }
    }
    cout << "\n? Record not found!\n";
}

int main() {
    fstream file("hashfile.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        file.open("hashfile.dat", ios::out | ios::binary);
        initializeFile(file);
        file.close();
        file.open("hashfile.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "\n===== Direct Access File (Hashing with Linear Probing) =====";
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