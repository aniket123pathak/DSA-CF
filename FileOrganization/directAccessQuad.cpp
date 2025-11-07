#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
using namespace std;

const int TABLE_SIZE = 10; // number of slots in the hash file

struct Student {
    int rollNo;
    char name[30];
    float marks;
    int flag; // 0 = empty, 1 = occupied, -1 = deleted
};

// Hash Function
int hashFunction(int key) {
    return key % TABLE_SIZE;
}

// Initialize file with blank records
void initializeFile(fstream &file) {
    Student blank = {0, "", 0.0, 0};
    for (int i = 0; i < TABLE_SIZE; i++)
        file.write(reinterpret_cast<char*>(&blank), sizeof(Student));
    cout << "\n? File initialized successfully.\n";
}

// Insert record using quadratic probing
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
        int newPos = (loc + i * i) % TABLE_SIZE;
        int pos = newPos * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&temp), sizeof(Student));

        if (temp.flag == 0 || temp.flag == -1) {
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "\n? Record inserted at position " << newPos << endl;
            return;
        }
    }
    cout << "\n? Hash table is full! Cannot insert record.\n";
}

// Display all records
void displayAll(fstream &file) {
    Student s;
    file.seekg(0, ios::beg);
    cout << "\n---- Student Records ----\n";
    cout << setw(10) << "Index" << setw(10) << "RollNo" 
         << setw(20) << "Name" << setw(10) << "Marks" << setw(10) << "Flag\n";

    for (int i = 0; i < TABLE_SIZE; i++) {
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));
        cout << setw(10) << i << setw(10) << s.rollNo 
             << setw(20) << s.name << setw(10) << s.marks << setw(10) << s.flag << endl;
    }
    file.clear(); // clear EOF flag
}

// Search a record using quadratic probing
void searchRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to search: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newPos = (loc + i * i) % TABLE_SIZE;
        int pos = newPos * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));

        if (s.flag == 1 && s.rollNo == key) {
            cout << "\n? Record found at position " << newPos << endl;
            cout << "RollNo: " << s.rollNo 
                 << "\nName: " << s.name 
                 << "\nMarks: " << s.marks << endl;
            return;
        }
    }
    cout << "\n? Record not found!\n";
}

// Modify an existing record
void modifyRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to modify: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newPos = (loc + i * i) % TABLE_SIZE;
        int pos = newPos * sizeof(Student);
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

// Delete a record logically (mark as deleted)
void deleteRecord(fstream &file) {
    int key;
    cout << "\nEnter Roll No to delete: ";
    cin >> key;

    int loc = hashFunction(key);
    Student s;

    for (int i = 0; i < TABLE_SIZE; i++) {
        int newPos = (loc + i * i) % TABLE_SIZE;
        int pos = newPos * sizeof(Student);
        file.seekg(pos, ios::beg);
        file.read(reinterpret_cast<char*>(&s), sizeof(Student));

        if (s.flag == 1 && s.rollNo == key) {
            s.flag = -1;
            file.seekp(pos, ios::beg);
            file.write(reinterpret_cast<char*>(&s), sizeof(Student));
            cout << "\n? Record deleted successfully.\n";
            return;
        }
    }
    cout << "\n? Record not found!\n";
}

int main() {
    fstream file("quadratic_hash.dat", ios::in | ios::out | ios::binary);
    if (!file) {
        file.open("quadratic_hash.dat", ios::out | ios::binary);
        initializeFile(file);
        file.close();
        file.open("quadratic_hash.dat", ios::in | ios::out | ios::binary);
    }

    int choice;
    do {
        cout << "\n===== Direct Access File (Quadratic Probing) =====";
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