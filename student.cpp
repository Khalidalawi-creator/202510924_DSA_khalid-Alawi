#include "student.h"
#include <iostream>
using namespace std;

Student students[MAX_STUDENTS];
int studentCount = 0;

void addStudent() {
    if (studentCount >= MAX_STUDENTS) {
        cout << "Cannot add more students. Limit reached.\n";
        return;
    }

    Student s;
    cout << "Enter ID: ";
    cin >> s.id;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, s.name);
    cout << "Enter Age: ";
    cin >> s.age;
    cout << "Enter Course: ";
    cin.ignore();
    getline(cin, s.course);

    students[studentCount++] = s;
    cout << "Student added successfully!\n";
}

void displayStudents() {
    if (studentCount == 0) {
        cout << "No students available.\n";
        return;
    }
    for (int i = 0; i < studentCount; i++) {
        cout << "ID: " << students[i].id
             << ", Name: " << students[i].name
             << ", Age: " << students[i].age
             << ", Course: " << students[i].course << endl;
    }
}

void searchStudent() {
    int id;
    cout << "Enter ID to search: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Found: " << students[i].name
                 << " (" << students[i].course << ")\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void updateStudent() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            cout << "Enter new Name: ";
            cin.ignore();
            getline(cin, students[i].name);
            cout << "Enter new Age: ";
            cin >> students[i].age;
            cout << "Enter new Course: ";
            cin.ignore();
            getline(cin, students[i].course);
            cout << "Updated successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

void deleteStudent() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (int i = 0; i < studentCount; i++) {
        if (students[i].id == id) {
            // Shift elements left
            for (int j = i; j < studentCount - 1; j++) {
                students[j] = students[j + 1];
            }
            studentCount--;
            cout << "Deleted successfully!\n";
            return;
        }
    }
    cout << "Student not found.\n";
}
