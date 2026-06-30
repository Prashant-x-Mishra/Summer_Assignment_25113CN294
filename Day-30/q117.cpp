// Student record management system 

#include <iostream>
#include <string>

using namespace std;


const int MAX_STUDENTS = 100; 

int main() {
    
    string names[MAX_STUDENTS];
    int rollNumbers[MAX_STUDENTS];
    float gpas[MAX_STUDENTS];
    
    int currentCount = 0; // Tracks the number of registered students
    int choice;

    cout << "=== Welcome to the Student Record System ===" << endl;

    do {
        // Display Menu
        cout << "\n-----------------------------" << endl;
        cout << "1. Add Student Record" << endl;
        cout << "2. Display All Student Records" << endl;
        cout << "3. Search Student by Roll Number" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cout << "-----------------------------" << endl;

        switch (choice) {
            case 1: // Add Student Record
                if (currentCount >= MAX_STUDENTS) {
                    cout << "Error: Database is full! Cannot add more students." << endl;
                } else {
                    cin.ignore(); // Clear the input buffer
                    cout << "Enter Student's Full Name: ";
                    getline(cin, names[currentCount]);

                    cout << "Enter Roll Number: ";
                    cin >> rollNumbers[currentCount];

                    cout << "Enter GPA: ";
                    cin >> gpas[currentCount];

                    currentCount++;
                    cout << "\nRecord added successfully!" << endl;
                }
                break;

            case 2: // Display All Records
                if (currentCount == 0) {
                    cout << "No student records found." << endl;
                } else {
                    cout << "\n--- All Student Records ---" << endl;
                    for (int i = 0; i < currentCount; i++) {
                        cout << "ID: " << i + 1 
                             << " | Name: " << names[i] 
                             << " | Roll No: " << rollNumbers[i] 
                             << " | GPA: " << gpas[i] << endl;
                    }
                }
                break;

            case 3: // Search Student
                if (currentCount == 0) {
                    cout << "No student records available to search." << endl;
                } else {
                    int searchRoll;
                    bool found = false;
                    cout << "Enter Roll Number to search: ";
                    cin >> searchRoll;

                    for (int i = 0; i < currentCount; i++) {
                        if (rollNumbers[i] == searchRoll) {
                            cout << "\nRecord Found!" << endl;
                            cout << "Name: " << names[i] << endl;
                            cout << "Roll No: " << rollNumbers[i] << endl;
                            cout << "GPA: " << gpas[i] << endl;
                            found = true;
                            break; 
                        }
                    }
                    if (!found) {
                        cout << "Student with Roll Number " << searchRoll << " not found." << endl;
                    }
                }
                break;

            case 4: // Exit
                cout << "Exiting the system. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice! Please enter a number between 1 and 4." << endl;
        }

    } while (choice != 4);

    return 0;
}