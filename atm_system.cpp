#include <iostream>
#include <string>
using namespace std;

int main() {
    int defaultPIN = 12345;
    int maxAttempts = 3;
    int pin, choice, amount, balance = 0;

    string transactionHistory[100];
    int transCount = 0;

    cout << "\033[36m";
    cout << "\t\t==========================================\n";
    cout << "\t\t            BK ATM SYSTEM                 \n";
    cout << "\t\t==========================================\n";
    cout << "\033[0m\n";

    do {
        cout << "\tEnter your PIN : ";
        cin >> pin;
        maxAttempts--;

        if (pin == defaultPIN) {
            cout << "\033[32m\n\tLogin Successful\n\033[0m";
            cout << "\033[35m\tWelcome to BK ATM\n\033[0m";

            do {
                cout << "\n\033[34m=========== MAIN MENU =========== \033[0m\n";
                cout << "  [1] Check Balance\n";
                cout << "  [2] Deposit Money\n";
                cout << "  [3] Withdraw Money\n";
                cout << "  [4] Transaction History\n";
                cout << "  [5] Exit\n";
                cout << "\033[34m================================= \033[0m\n";

                cout << "\nEnter your choice : ";
                cin >> choice;

                if (choice == 1) {
                    cout << "\033[32m\nCurrent Balance : " << balance << " FRW\n\033[0m";
                }
                else if (choice == 2) {
                    cout << "\nEnter amount to deposit : ";
                    cin >> amount;
                    balance += amount;
                    cout << "\033[32m\nDeposit Successful\nNew Balance : " << balance << " FRW\n\033[0m";
                    transactionHistory[transCount++] = "Deposited : " + to_string(amount) + " FRW";
                }
                else if (choice == 3) {
                    cout << "\nEnter amount to withdraw : ";
                    cin >> amount;
                    if (amount > balance) {
                        cout << "\033[31m\nInsufficient Funds\n\033[0m";
                    } else {
                        balance -= amount;
                        cout << "\033[32m\nWithdrawal Successful\nWithdrawn Amount : " << amount 
                             << " FRW\nRemaining Balance : " << balance << " FRW\n\033[0m";
                        transactionHistory[transCount++] = "Withdrawn : " + to_string(amount) + " FRW";
                    }
                }
                else if (choice == 4) {
                    cout << "\n\033[36m====== TRANSACTION HISTORY ====== \033[0m\n";
                    if (transCount == 0) {
                        cout << "\033[31mNo Transactions Found\033[0m\n";
                    } else {
                        for (int i = 0; i < transCount; i++) {
                            cout << i + 1 << ". " << transactionHistory[i] << endl;
                        }
                    }
                }
                else if (choice == 5) {
                    cout << "\033[33m\nThank You For Using BK ATM\n\033[0m";
                }
                else {
                    cout << "\033[31m\nInvalid Choice\n\033[0m";
                }
            } while (choice != 5);
        }
        else {
            cout << "\033[31m\nWrong PIN\n\033[0m";
            if (maxAttempts > 0) {
                cout << "\033[33mRemaining Attempts : " << maxAttempts << "\033[0m\n";
            }
        }
    } while (pin != defaultPIN && maxAttempts > 0);

    if (maxAttempts == 0) {
        cout << "\033[31m\nATM BLOCKED\n\033[0m";
    }

    return 0;
}
