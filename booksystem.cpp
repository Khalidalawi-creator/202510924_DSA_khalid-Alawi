#include <iostream>
#include <fstream>
#include <string>
using namespace std;

// Function to read chapter content from external file
void readChapterFromFile(const string &fileName) {
    ifstream file(fileName);
    if (file.is_open()) {
        string line;
        cout << "\n--- Chapter Content from " << fileName << " ---\n";
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cout << "⚠️ Error: Could not open file " << fileName << endl;
    }
}

// History menu
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
        case 1: readChapterFromFile("history_origin.txt"); break;
        case 2: readChapterFromFile("history_development.txt"); break;
        case 3: readChapterFromFile("history_evolution.txt"); break;
        case 4: return;
        default: cout << "Invalid choice.\n";
    }
}

// Learning menu
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
        case 1: readChapterFromFile("concept_dataTypes.txt"); break;
        case 2: readChapterFromFile("concept_controlFlow.txt"); break;
        case 3: readChapterFromFile("concept_loops.txt"); break;
        case 4: readChapterFromFile("concept_arrays.txt"); break;
        case 5: readChapterFromFile("concept_fileStreams.txt"); break;
        case 6: return;
        default: cout << "Invalid choice.\n";
    }
}

// Main program
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
