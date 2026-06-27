// STUDENT RECORD MANANGEMENT SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Student {
private:
    string id;
    string name;
    int age;
    string grade;

public:

    Student(string id, string name, int age, string grade) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->grade = grade;
    }


    string getId() const { return id; }
    string getName() const { return name; }
    int getAge() const { return age; }
    string getGrade() const { return grade; }


    void displayStudent() const {
        cout << left << setw(12) << id 
             << setw(22) << name 
             << setw(8) << age 
             << setw(10) << grade << endl;
    }
};


vector<Student> studentDatabase;

bool idExists(const string& id) {
    for (const auto& student : studentDatabase) {
        if (student.getId() == id) {
            return true;
        }
    }
    return false;
}


void addStudent() {
    string id, name, grade;
    int age;

    cout << "\n--- Add New Student ---\n";
    cout << "Enter Student ID (Unique): ";
    cin >> id;
    cin.ignore(); 

    if (idExists(id)) {
        cout << " Error: A student with this ID already exists!\n";
        return;
    }

    cout << "Enter Name: ";
    getline(cin, name);
    
    cout << "Enter Age: ";
    cin >> age;
    
    cout << "Enter Grade/Class: ";
    cin >> grade;

   
    studentDatabase.push_back(Student(id, name, age, grade));
    cout << "Student '" << name << "' added successfully!\n";
}


void viewStudents() {
    cout << "\n--- All Student Records ---\n";
    if (studentDatabase.empty()) {
        cout << "No records found.\n";
        return;
    }

    cout << left << setw(12) << "ID" 
         << setw(22) << "Name" 
         << setw(8) << "Age" 
         << setw(10) << "Grade" << endl;
    cout << string(52, '-') << endl;

    for (const auto& student : studentDatabase) {
        student.displayStudent();
    }
}


void searchStudent() {
    string id;
    cout << "\n--- Search Student ---\n";
    cout << "Enter Student ID to search: ";
    cin >> id;

    for (const auto& student : studentDatabase) {
        if (student.getId() == id) {
            cout << "\n  Record Found:\n";
            cout << "ID: " << student.getId() << "\n";
            cout << "Name: " << student.getName() << "\n";
            cout << "Age: " << student.getAge() << "\n";
            cout << "Grade: " << student.getGrade() << "\n";
            return;
        }
    }
    cout << " Student ID not found.\n";
}
 

void deleteStudent() {
    string id;
    cout << "\n--- Delete Student Record ---\n";
    cout << "Enter Student ID to delete: ";
    cin >> id;

    for (auto it = studentDatabase.begin(); it != studentDatabase.end(); ++it) {
        if (it->getId() == id) {
            cout << "  Student '" << it->getName() << "' removed successfully!\n";
            studentDatabase.erase(it);
            return;
        }
    }
    cout << "  Student ID not found.\n";
}


int main() {
    int choice;

    while (true) {
        cout << "\n==============================\n";
        cout << "    STUDENT RECORD SYSTEM \n";
        cout << "==============================\n";
        cout << "1. Add Student\n";
        cout << "2. View All Students\n";
        cout << "3. Search Student\n";
        cout << "4. Delete Student\n";
        cout << "5. Exit\n";
        cout << "\nEnter your choice (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear(); 
            cin.ignore(1000, '\n');
            cout << " Invalid input! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: deleteStudent(); break;
            case 5: 
                cout << "\nExiting program. Goodbye!\n";
                return 0;
            default: 
                cout << " Invalid choice! Please enter a number between 1 and 5.\n";
        }
    }
    return 0;
}