// BANK ACCOUNT SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class BankAccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;

public:
    BankAccount(string accNum, string holder, double initialDeposit) {
        accountNumber = accNum;
        accountHolder = holder;
        balance = initialDeposit;
    }

    string getAccountNumber() const { return accountNumber; }
    string getAccountHolder() const { return accountHolder; }
    double getBalance() const { return balance; }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful. New Balance: $" << fixed << setprecision(2) << balance << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful. New Balance: $" << fixed << setprecision(2) << balance << endl;
        } else if (amount > balance) {
            cout << "Insufficient funds." << endl;
        } else {
            cout << "Invalid withdrawal amount." << endl;
        }
    }

    void displayAccount() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Account Holder: " << accountHolder << endl;
        cout << "Current Balance: $" << fixed << setprecision(2) << balance << endl;
    }
};

vector<BankAccount> accounts;

int findAccountIndex(const string& accNum) {
    for (size_t i = 0; i < accounts.size(); ++i) {
        if (accounts[i].getAccountNumber() == accNum) {
            return i;
        }
    }
    return -1;
}

void createAccount() {
    string accNum, holder;
    double initialDeposit;

    cout << "Enter Account Number: ";
    cin >> accNum;
    cin.ignore();

    if (findAccountIndex(accNum) != -1) {
        cout << "Error: Account number already exists." << endl;
        return;
    }

    cout << "Enter Account Holder Name: ";
    getline(cin, holder);
    cout << "Enter Initial Deposit Amount: ";
    cin >> initialDeposit;

    if (initialDeposit < 0) {
        cout << "Error: Initial deposit cannot be negative." << endl;
        return;
    }

    accounts.push_back(BankAccount(accNum, holder, initialDeposit));
    cout << "Account created successfully." << endl;
}

void performDeposit() {
    string accNum;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNum;

    int idx = findAccountIndex(accNum);
    if (idx != -1) {
        cout << "Enter Amount to Deposit: ";
        cin >> amount;
        accounts[idx].deposit(amount);
    } else {
        cout << "Error: Account not found." << endl;
    }
}

void performWithdrawal() {
    string accNum;
    double amount;
    cout << "Enter Account Number: ";
    cin >> accNum;

    int idx = findAccountIndex(accNum);
    if (idx != -1) {
        cout << "Enter Amount to Withdraw: ";
        cin >> amount;
        accounts[idx].withdraw(amount);
    } else {
        cout << "Error: Account not found." << endl;
    }
}

void checkBalance() {
    string accNum;
    cout << "Enter Account Number: ";
    cin >> accNum;

    int idx = findAccountIndex(accNum);
    if (idx != -1) {
        cout << endl << "--- Account Details ---" << endl;
        accounts[idx].displayAccount();
    } else {
        cout << "Error: Account not found." << endl;
    }
}

int main() {
    int choice;

    while (true) {
        cout << endl << "==============================" << endl;
        cout << "     BANK ACCOUNT SYSTEM" << endl;
        cout << "==============================" << endl;
        cout << "1. Create New Account" << endl;
        cout << "2. Deposit Money" << endl;
        cout << "3. Withdraw Money" << endl;
        cout << "4. Check Balance / Details" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter Choice (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input. Please enter a number." << endl;
            continue;
        }

        switch (choice) {
            case 1: createAccount(); break;
            case 2: performDeposit(); break;
            case 3: performWithdrawal(); break;
            case 4: checkBalance(); break;
            case 5: 
                cout << "Exiting system. Goodbye." << endl;
                return 0;
            default: 
                cout << "Invalid selection. Choose between 1 and 5." << endl;
        }
    }
    return 0;
}