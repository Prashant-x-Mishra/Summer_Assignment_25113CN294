// ATM SIMULATION 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class BankAccount {
private:
    string accountHolder;
    int pin;
    double balance;
    vector<string> miniStatement;

public:
    BankAccount(string name, int initialPin, double initialBalance) {
        accountHolder = name;
        pin = initialPin;
        balance = initialBalance;
        miniStatement.push_back("Account opened with Rs. " + to_string((int)initialBalance));
    }

    string getName() { return accountHolder; }
    
  
    bool credentialsMatch(string enteredName, int enteredPin) {
        return (accountHolder == enteredName && pin == enteredPin);
    }

    void checkBalance() {
        cout << "\n CURRENT BALANCE : Rs. " << balance << endl;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            miniStatement.push_back("Deposited: +Rs. " + to_string((int)amount));
            cout << " Rs. " << amount << " Deposited Successfully!" << endl;
        } else {
            cout << " Invalid Deposit Amount!" << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > balance) {
            cout << " INSUFFICIENT BALANCE! Available: Rs. " << balance << endl;
        } else if (amount <= 0) {
            cout << " Invalid Withdrawal Amount!" << endl;
        } else {
            balance -= amount;
            miniStatement.push_back("Withdrawn: -Rs. " + to_string((int)amount));
            cout << " Please collect your cash: Rs. " << amount << endl;
        }
    }

    void printStatement() {
        cout << "\n ------- MINI STATEMENT -------" << endl;
        for (int i = 0; i < miniStatement.size(); i++) {
            cout << i + 1 << ". " << miniStatement[i] << endl;
        }
        cout << "--------------------------------" << endl;
    }
};

int main() {
  
    vector<BankAccount> bankDB;
    bankDB.push_back(BankAccount("Astha", 1234, 10000.0));
    bankDB.push_back(BankAccount("Ram", 1234, 2500.0)); 

    int mainChoice;

    while (true) {
        cout << "\n=========================================" << endl;
        cout << "     WELCOME TO CENTRAL BANK ATM     " << endl;
        cout << "=========================================" << endl;
        cout << "1. Existing User (Login)" << endl;
        cout << "2. New User (Open New Account)" << endl;
        cout << "3. Shut Down ATM Machine" << endl;
        cout << "----------------------------------------=" << endl;
        cout << "Enter your choice: ";
        cin >> mainChoice;
        cin.ignore(); 

        if (mainChoice == 3) {
            cout << "\nShutting down ATM... Goodbye!" << endl;
            break;
        }

        int userIndex = -1;

      
        if (mainChoice == 2) {
            string newName;
            int newPin, initialDeposit;

            cout << "\n ---- OPEN NEW ACCOUNT ----" << endl;
            cout << "Enter Full Name: ";
            getline(cin, newName);
            cout << "Create 4-Digit ATM PIN: ";
            cin >> newPin;
            cout << "Enter Initial Deposit Amount: Rs. ";
            cin >> initialDeposit;

            bankDB.push_back(BankAccount(newName, newPin, initialDeposit));
            
            cout << "\n Account Created Successfully for " << newName << "!" << endl;
            cout << "You can now login using your Name and PIN." << endl;
            continue; 
        }

        if (mainChoice == 1) {
            string enteredName;
            int enteredPin;

            cout << "\n ---- USER LOGIN ----" << endl;
            cout << "Enter your Registered Name: ";
            getline(cin, enteredName);
            cout << "Enter your 4-Digit ATM PIN: ";
            cin >> enteredPin;

            
            for (int i = 0; i < bankDB.size(); i++) {
                if (bankDB[i].credentialsMatch(enteredName, enteredPin)) {
                    userIndex = i; 
                    break;
                }
            }

            if (userIndex == -1) {
                cout << "\n ERROR: Name and PIN do not match any account!" << endl;
                continue; 
            }

            // LOGIN SUCCESSFUL MENU
            cout << "\n LOGIN SUCCESSFUL! Welcome back, " << bankDB[userIndex].getName() << "!" << endl;
            int choice;
            double amount;

            do {
                cout << "\n------------  ATM MENU ------------" << endl;
                cout << "1. Check Balance" << endl;
                cout << "2. Deposit Money" << endl;
                cout << "3. Withdraw Money" << endl;
                cout << "4. Print Mini Statement" << endl;
                cout << "5. Logout" << endl;
                cout << "-------------------------------------" << endl;
                cout << "Enter choice: ";
                cin >> choice;

                switch (choice) {
                    case 1:
                        bankDB[userIndex].checkBalance();
                        break;
                    case 2:
                        cout << "Enter deposit amount: Rs. ";
                        cin >> amount;
                        bankDB[userIndex].deposit(amount);
                        break;
                    case 3:
                        cout << "Enter withdrawal amount: Rs. ";
                        cin >> amount;
                        bankDB[userIndex].withdraw(amount);
                        break;
                    case 4:
                        bankDB[userIndex].printStatement();
                        break;
                    case 5:
                        cout << "\n Logged out successfully. Thank you, " << bankDB[userIndex].getName() << "!" << endl;
                        break;
                    default:
                        cout << " Invalid Choice!" << endl;
                }
            } while (choice != 5);
        }
    }

    return 0;
}