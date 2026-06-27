// SALARY MANAGEMENT SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Payroll {
private:
    string empId;
    string name;
    double baseSalary;
    double bonus;
    double taxRate;    
    double pfDeduction;

public:
    // Constructor
    Payroll(string id, string name, double base, double bonusAmt, double tax, double pf) {
        this->empId = id;
        this->name = name;
        this->baseSalary = base;
        this->bonus = bonusAmt;
        this->taxRate = tax;
        this->pfDeduction = pf;
    }

    // Getters
    string getEmpId() const { return empId; }
    string getName() const { return name; }

    double calculateTaxAmount() const {
        return baseSalary * (taxRate / 100.0);
    }

    double calculateGrossPay() const {
        return baseSalary + bonus;
    }

    double calculateNetPay() const {
        return calculateGrossPay() - calculateTaxAmount() - pfDeduction;
    }

    void updateSalaryStructure(double base, double bonusAmt, double tax, double pf) {
        this->baseSalary = base;
        this->bonus = bonusAmt;
        this->taxRate = tax;
        this->pfDeduction = pf;
    }

    void displayLedgerRow() const {
        cout << left << setw(10) << empId 
             << setw(20) << name 
             << "$" << setw(12) << fixed << setprecision(2) << baseSalary 
             << "$" << setw(10) << bonus 
             << "$" << setw(12) << calculateNetPay() << endl;
    }


    void generatePaySlip() const {
        cout << "\n============================================\n";
        cout << "              PAYSLIP - JUNE 2026           \n";
        cout << "============================================\n";
        cout << " Employee ID   : " << empId << "\n";
        cout << " Employee Name : " << name << "\n";
        cout << "--------------------------------------------\n";
        cout << left << setw(25) << " EARNINGS" << "AMOUNT\n";
        cout << left << setw(25) << " Base Monthly Salary:" << "$" << baseSalary << "\n";
        cout << left << setw(25) << " Performance Bonus:" << "$" << bonus << "\n";
        cout << "--------------------------------------------\n";
        cout << left << setw(25) << " DEDUCTIONS" << "AMOUNT\n";
        cout << left << setw(25) << " Income Tax (" + to_string((int)taxRate) + "%):" << "$" << calculateTaxAmount() << "\n";
        cout << left << setw(25) << " Provident Fund (PF):" << "$" << pfDeduction << "\n";
        cout << "--------------------------------------------\n";
        cout << left << setw(25) << " GROSS PAY:" << "$" << calculateGrossPay() << "\n";
        cout << left << setw(25) << " TOTAL DEDUCTIONS:" << "$" << (calculateTaxAmount() + pfDeduction) << "\n";
        cout << "--------------------------------------------\n";
        cout << left << setw(25) << " NET TAKE-HOME PAY:" << "**$" << calculateNetPay() << "**\n";
        cout << "============================================\n";
    }
};


vector<Payroll> payrollDatabase;


int findEmployeeIndex(const string& id) {
    for (size_t i = 0; i < payrollDatabase.size(); ++i) {
        if (payrollDatabase[i].getEmpId() == id) return i;
    }
    return -1; 
}


void addEmployeePayroll() {
    string id, name;
    double base, bonus, tax, pf;

    cout << "\n--- Setup New Employee Payroll ---\n";
    cout << "Enter Employee ID: ";
    cin >> id;
    cin.ignore();

    if (findEmployeeIndex(id) != -1) {
        cout << " Error: this employee already has a payroll record!\n";
        return;
    }

    cout << "Enter Employee Name: ";
    getline(cin, name);
    cout << "Enter Base Monthly Salary ($): ";
    cin >> base;
    cout << "Enter Performance Bonus ($): ";
    cin >> bonus;
    cout << "Enter Tax Rate (%): ";
    cin >> tax;
    cout << "Enter Fixed PF Deduction ($): ";
    cin >> pf;

    payrollDatabase.push_back(Payroll(id, name, base, bonus, tax, pf));
    cout << " Payroll ledger profile initialized for " << name << ".\n";
}

void viewMasterLedger() {
    cout << "\n--- Company Payroll Master Ledger ---\n";
    if (payrollDatabase.empty()) {
        cout << "The payroll database is currently empty.\n";
        return;
    }

    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(13) << "Base Salary" 
         << setw(11) << "Bonus" 
         << "Net Pay" << endl;
    cout << string(68, '-') << endl;

    for (const auto& record : payrollDatabase) {
        record.displayLedgerRow();
    }
}


void updateSalary() {
    string id;
    cout << "\n--- Revise Salary Parameters ---\n";
    cout << "Enter Employee ID to update: ";
    cin >> id;

    int idx = findEmployeeIndex(id);
    if (idx == -1) {
        cout << " Employee profile not found.\n";
        return;
    }

    double base, bonus, tax, pf;
    cout << "Enter New Base Salary ($): ";
    cin >> base;
    cout << "Enter New Monthly Bonus ($): ";
    cin >> bonus;
    cout << "Enter Adjusted Tax Rate (%): ";
    cin >> tax;
    cout << "Enter New PF Deduction ($): ";
    cin >> pf;

    payrollDatabase[idx].updateSalaryStructure(base, bonus, tax, pf);
    cout << " Payroll parameters recalculated successfully!\n";
}

// 4. Print Specific Pay Slip
void printPaySlip() {
    string id;
    cout << "\n--- Generate Employee Pay Slip ---\n";
    cout << "Enter Employee ID: ";
    cin >> id;

    int idx = findEmployeeIndex(id);
    if (idx != -1) {
        payrollDatabase[idx].generatePaySlip();
    } else {
        cout << " Employee ID not found.\n";
    }
}

// Main Menu Module
int main() {
    int choice;

    while (true) {
        cout << "\n==================================\n";
        cout << "     SALARY & PAYROLL SYSTEM\n";
        cout << "==================================\n";
        cout << "1. Setup Employee Payroll Profile\n";
        cout << "2. View Company Master Ledger\n";
        cout << "3. Revise Salary/Tax Parameters\n";
        cout << "4. Generate Itemized Pay Slip\n";
        cout << "5. Exit\n";
        cout << "\nEnter decision (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Please select an active option via numerical value.\n";
            continue;
        }

        switch (choice) {
            case 1: addEmployeePayroll(); break;
            case 2: viewMasterLedger(); break;
            case 3: updateSalary(); break;
            case 4: printPaySlip(); break;
            case 5: 
                cout << "\nPayroll session closed. Disbursing reports...\n";
                return 0;
            default: 
                cout << "  Selection out of scope. Pick a valid number.\n";
        }
    }
    return 0;
}