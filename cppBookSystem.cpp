#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to display history chapters
void showHistory() {
    int choice;
    cout << "\n--- History of C++ ---\n";
    cout << "1. Origin of C++\n";
    cout << "2. Development of C++\n";
    cout << "3. Evolution of C++\n";
    cout << "4. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: cout << "\nChapter: Origin of C++\n";
                cout << "C++ was developed by Bjarne Stroustrup in 1979...\n";
                break;
        case 2: cout << "\nChapter: Development of C++\n";
                cout << "It evolved from C with Classes into a full language...\n";
                break;
        case 3: cout << "\nChapter: Evolution of C++\n";
                cout << "C++ has gone through multiple standards: C++98, C++11, C++17, C++20...\n";
                break;
        case 4: return;
        default: cout << "Invalid choice.\n";
    }
}

// Function to display learning chapters
void learnCpp() {
    int choice;
    cout << "\n--- Learn about C++ ---\n";
    cout << "1. Data Types\n";
    cout << "2. Control Flow\n";
    cout << "3. Loops\n";
    cout << "4. Arrays\n";
    cout << "5. File Streams\n";
    cout << "6. Back to Main Menu\n";
    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice) {
        case 1: cout << "\nData Types: int, float, double, char, string...\n"; break;
        case 2: cout << "\nControl Flow: if-else, switch-case...\n"; break;
        case 3: cout << "\nLoops: for, while, do-while...\n"; break;
        case 4: cout << "\nArrays: collections of elements stored in contiguous memory...\n"; break;
        case 5: {
            cout << "\nFile Streams Example:\n";
            ifstream file("chapter_file.txt"); // external file
            if (file.is_open()) {
                string line;
                while (getline(file, line)) {
                    cout << line << endl;
                }
                file.close();
            } else {
                cout << "Error: Could not open file.\n";
            }
            break;
        }
        case 6: return;
        default: cout << "Invalid choice.\n";
    }
}

// Main menu
int main() {
    int choice;
    do {
        cout << "\n=== Foundations and History of C++ ===\n";
        cout << "1. View History of C++\n";
        cout << "2. Learn about C++ Concepts\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: showHistory(); break;
            case 2: learnCpp(); break;
            case 3: cout << "Exiting program. Goodbye!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 3);

    return 0;
}
