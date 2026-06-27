// EMPLOYEE MANAGEMENT SYSYTEM

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Employee {
private:
    string id;
    string name;
    string department;
    string role;
    double salary;

public:
   
    Employee(string id, string name, string department, string role, double salary) {
        this->id = id;
        this->name = name;
        this->department = department;
        this->role = role;
        this->salary = salary;
    }

    
    string getId() const { return id; }
    string getName() const { return name; }
    string getDepartment() const { return department; }
    string getRole() const { return role; }
    double getSalary() const { return salary; }

  
    void setRole(string newRole) { role = newRole; }
    void setSalary(double newSalary) { salary = newSalary; }

  
    void displayEmployee() const {
        cout << left << setw(10) << id 
             << setw(20) << name 
             << setw(15) << department 
             << setw(15) << role 
             << "$" << fixed << setprecision(2) << salary << endl;
    }
};


vector<Employee> employeeDatabase;


bool idExists(const string& id) {
    for (const auto& emp : employeeDatabase) {
        if (emp.getId() == id) return true;
    }
    return false;
}


void addEmployee() {
    string id, name, dept, role;
    double salary;

    cout << "\n--- Add New Employee ---\n";
    cout << "Enter Employee ID (Unique): ";
    cin >> id;
    cin.ignore(); 

    if (idExists(id)) {
        cout << " Error: Employee ID already exists!\n";
        return;
    }

    cout << "Enter Full Name: ";
    getline(cin, name);
    
    cout << "Enter Department: ";
    getline(cin, dept);
    
    cout << "Enter Job Role/Title: ";
    getline(cin, role);
    
    cout << "Enter Monthly Salary ($): ";
    cin >> salary;

    employeeDatabase.push_back(Employee(id, name, dept, role, salary));
    cout << " Employee '" << name << "' added successfully!\n";
}


void viewEmployees() {
    cout << "\n--- Employee Directory ---\n";
    if (employeeDatabase.empty()) {
        cout << "No employee records found.\n";
        return;
    }


    cout << left << setw(10) << "ID" 
         << setw(20) << "Name" 
         << setw(15) << "Dept" 
         << setw(15) << "Role" 
         << "Salary" << endl;
    cout << string(68, '-') << endl;

    for (const auto& emp : employeeDatabase) {
        emp.displayEmployee();
    }
}


void searchEmployee() {
    string id;
    cout << "\n--- Search Employee Record ---\n";
    cout << "Enter Employee ID: ";
    cin >> id;

    for (const auto& emp : employeeDatabase) {
        if (emp.getId() == id) {
            cout << "\n Record Found:\n";
            cout << "ID:         " << emp.getId() << "\n";
            cout << "Name:       " << emp.getName() << "\n";
            cout << "Department: " << emp.getDepartment() << "\n";
            cout << "Job Role:   " << emp.getRole() << "\n";
            cout << "Salary:     $" << fixed << setprecision(2) << emp.getSalary() << "\n";
            return;
        }
    }
    cout << " Employee ID not found.\n";
}


void updateEmployee() {
    string id;
    cout << "\n--- Update Employee Record ---\n";
    cout << "Enter Employee ID to modify: ";
    cin >> id;

    for (auto& emp : employeeDatabase) {
        if (emp.getId() == id) {
            string newRole;
            double newSalary;
            cin.ignore();

            cout << "Current Role: " << emp.getRole() << " -> Enter New Role: ";
            getline(cin, newRole);
            
            cout << "Current Salary: $" << emp.getSalary() << " -> Enter New Salary: ";
            cin >> newSalary;

            emp.setRole(newRole);
            emp.setSalary(newSalary);
            cout << " Employee profile updated successfully!\n";
            return;
        }
    }
    cout << " Employee ID not found.\n";
}


void deleteEmployee() {
    string id;
    cout << "\n--- Terminate/Delete Employee Record ---\n";
    cout << "Enter Employee ID to delete: ";
    cin >> id;

    for (auto it = employeeDatabase.begin(); it != employeeDatabase.end(); ++it) {
        if (it->getId() == id) {
            cout << " Employee '" << it->getName() << "' removed from the system.\n";
            employeeDatabase.erase(it);
            return;
        }
    }
    cout << " Employee ID not found.\n";
}


int main() {
    int choice;

    while (true) {
        cout << "\n==================================\n";
        cout << "   EMPLOYEE MANAGEMENT SYSTEM\n";
        cout << "==================================\n";
        cout << "1. Add Employee\n";
        cout << "2. View Employee Directory\n";
        cout << "3. Search Employee by ID\n";
        cout << "4. Update Employee (Role/Salary)\n";
        cout << "5. Remove Employee\n";
        cout << "6. Exit\n";
        cout << "\nEnter choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid input! Please input a valid menu number.\n";
            continue;
        }

        switch (choice) {
            case 1: addEmployee(); break;
            case 2: viewEmployees(); break;
            case 3: searchEmployee(); break;
            case 4: updateEmployee(); break;
            case 5: deleteEmployee(); break;
            case 6: 
                cout << "\nExiting System. Have a productive day!\n";
                return 0;
            default: 
                cout << " Out of range! Choose a number between 1 and 6.\n";
        }
    }
    return 0;
}