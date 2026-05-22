#include <iostream>
#include <string>
using namespace std;

// Global variables
double balance = 0.0;
string transactions[100]; // transaction history
int transactionCount = 0;

// Function to authenticate user
bool authenticateUser() {
    const string defaultPin = "1234"; // predefined PIN
    string enteredPin;
    int attempts = 0;

    while (attempts < 3) {
        cout << "Enter PIN: ";
        cin >> enteredPin;

        if (enteredPin == defaultPin) {
            cout << "Login successful!\n";
            return true;
        } else {
            cout << "Incorrect PIN. Try again.\n";
            attempts++;
        }
    }
    cout << "Maximum attempts reached. Exiting...\n";
    return false;
}

// Function to check balance
void checkBalance() {
    cout << "Your current balance is: $" << balance << endl;
}

// Function to deposit money
void depositMoney() {
    double amount;
    cout << "Enter amount to deposit: ";
    cin >> amount;

    if (amount > 0) {
        balance += amount;
        transactions[transactionCount++] = "Deposited: $" + to_string(amount);
        cout << "Deposit successful!\n";
    } else {
        cout << "Invalid amount.\n";
    }
}

// Function to withdraw money
void withdrawMoney() {
    double amount;
    cout << "Enter amount to withdraw: ";
    cin >> amount;

    if (amount > 0 && amount <= balance) {
        balance -= amount;
        transactions[transactionCount++] = "Withdrew: $" + to_string(amount);
        cout << "Withdrawal successful!\n";
    } else {
        cout << "Insufficient balance or invalid amount.\n";
    }
}

// Function to view transactions
void viewTransactions() {
    cout << "Transaction History:\n";
    for (int i = 0; i < transactionCount; i++) {
        cout << i + 1 << ". " << transactions[i] << endl;
    }
}

// Main menu
void showMenu() {
    int choice;
    do {
        cout << "\n--- ATM Menu ---\n";
        cout << "1. Check Balance\n";
        cout << "2. Deposit Money\n";
        cout << "3. Withdraw Money\n";
        cout << "4. View Transactions\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: checkBalance(); break;
            case 2: depositMoney(); break;
            case 3: withdrawMoney(); break;
            case 4: viewTransactions(); break;
            case 5: cout << "Thank you for using our ATM!\n"; break;
            default: cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 5);
}

// Main function
int main() {
    if (authenticateUser()) {
        showMenu();
    }
    return 0;
}
