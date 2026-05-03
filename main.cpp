#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

class Student {
public:
    int id;
    char name[50];
    int age;
    char course[50];

    void input() {
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter Name: ";
        cin.ignore();
        cin.getline(name, 50);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course: ";
        cin.ignore();
        cin.getline(course, 50);
    }

    void display() {
        cout << "\nID: " << id;
        cout << "\nName: " << name;
        cout << "\nAge: " << age;
        cout << "\nCourse: " << course << endl;
    }
};

// Add Student
void addStudent() {
    Student s;
    ofstream file("students.dat", ios::binary | ios::app);
    s.input();
    file.write((char*)&s, sizeof(s));
    file.close();
    cout << "Student added successfully!\n";
}

// Display All Students
void displayAll() {
    Student s;
    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        s.display();
        cout << "----------------------";
    }

    file.close();
}

// Search Student
void searchStudent() {
    int id;
    bool found = false;
    Student s;

    cout << "Enter ID to search: ";
    cin >> id;

    ifstream file("students.dat", ios::binary);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "\nStudent Found:\n";
            s.display();
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student not found!\n";
}

// Update Student
void updateStudent() {
    int id;
    bool found = false;
    Student s;

    cout << "Enter ID to update: ";
    cin >> id;

    fstream file("students.dat", ios::binary | ios::in | ios::out);

    while (file.read((char*)&s, sizeof(s))) {
        if (s.id == id) {
            cout << "Enter new details:\n";
            s.input();

            int pos = -1 * sizeof(s);
            file.seekp(pos, ios::cur);
            file.write((char*)&s, sizeof(s));

            cout << "Record updated!\n";
            found = true;
            break;
        }
    }

    file.close();

    if (!found)
        cout << "Student not found!\n";
}

// Delete Student
void deleteStudent() {
    int id;
    bool found = false;
    Student s;

    cout << "Enter ID to delete: ";
    cin >> id;

    ifstream infile("students.dat", ios::binary);
    ofstream outfile("temp.dat", ios::binary);

    while (infile.read((char*)&s, sizeof(s))) {
        if (s.id != id) {
            outfile.write((char*)&s, sizeof(s));
        } else {
            found = true;
        }
    }

    infile.close();
    outfile.close();

    remove("students.dat");
    rename("temp.dat", "students.dat");

    if (found)
        cout << "Record deleted!\n";
    else
        cout << "Student not found!\n";
}

// Main Menu
int main() {
    int choice;

    do {
        cout << "\n===== Student Management System =====\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Update Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayAll(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: cout << "Exiting...\n"; break;
            default: cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}