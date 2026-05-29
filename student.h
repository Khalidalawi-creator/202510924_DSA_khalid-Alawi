#ifndef STUDENT_h
#define STUDENT_h

#include <string>
using namespace std;

struct Student {
    int id;
    string name;
    int age;
    string course;

};


const int MAX_STUDENTS = 10;

// Function declarations
void addStudent();
void displayStudents();
void searchStudent();
void updateStudent();
void deleteStudent();

#endif
