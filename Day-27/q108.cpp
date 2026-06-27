// Marksheet Generation System

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


struct Subject {
    string name;
    double marksObtained;
    double maxMarks;
};


class Marksheet {
private:
    string rollNo;
    string studentName;
    string className;
    vector<Subject> subjects;

public:

    Marksheet(string roll, string name, string cls) {
        this->rollNo = roll;
        this->studentName = name;
        this->className = cls;
    }

    string getRollNo() const { return rollNo; }
    string getStudentName() const { return studentName; }

  
    void addSubjectScore(string subName, double score, double maxScore = 100.0) {
        subjects.push_back({subName, score, maxScore});
    }

    
    double calculateTotalObtained() const {
        double total = 0;
        for (const auto& sub : subjects) total += sub.marksObtained;
        return total;
    }

    double calculateTotalMax() const {
        double total = 0;
        for (const auto& sub : subjects) total += sub.maxMarks;
        return total;
    }

    double calculatePercentage() const {
        if (calculateTotalMax() == 0) return 0;
        return (calculateTotalObtained() / calculateTotalMax()) * 100.0;
    }

    // Grading logic based on percentage brackets
    string calculateGrade(double pct) const {
        if (pct >= 90.0) return "A+";
        if (pct >= 80.0) return "A";
        if (pct >= 70.0) return "B";
        if (pct >= 60.0) return "C";
        if (pct >= 50.0) return "D";
        return "F (Fail)";
    }

    string getFinalResult(double pct) const {
        for (const auto& sub : subjects) {
         
            if ((sub.marksObtained / sub.maxMarks) * 100.0 < 40.0) {
                return "FAILED (Subject Backlog)";
            }
        }
        return (pct >= 40.0) ? "PASSED" : "FAILED";
    }


    void printReportCard() const {
        double percentage = calculatePercentage();
        string finalGrade = calculateGrade(percentage);
        string result = getFinalResult(percentage);

        cout << "\n==================================================\n";
        cout << "              OFFICIAL ACADEMIC MARKSHEET          \n";
        cout << "==================================================\n";
        cout << " Roll No      : " << rollNo << "\n";
        cout << " Student Name : " << studentName << "\n";
        cout << " Class/Grade  : " << className << "\n";
        cout << "--------------------------------------------------\n";
        cout << left << setw(25) << "SUBJECT" 
             << setw(15) << "OBTAINED" 
             << "MAX MARKS\n";
        cout << "--------------------------------------------------\n";

        for (const auto& sub : subjects) {
            cout << left << setw(25) << sub.name 
                 << setw(15) << fixed << setprecision(1) << sub.marksObtained 
                 << sub.maxMarks << "\n";
        }

        cout << "--------------------------------------------------\n";
        cout << left << setw(25) << "GRAND TOTAL:" 
             << setw(15) << calculateTotalObtained() << calculateTotalMax() << "\n";
        cout << left << setw(25) << "AGGREGATE PERCENTAGE:" 
             << fixed << setprecision(2) << percentage << "%\n";
        cout << left << setw(25) << "FINAL GRADE:" << finalGrade << "\n";
        cout << "--------------------------------------------------\n";
        cout << " STATUS       : **" << result << "**\n";
        cout << "==================================================\n";
    }
};


vector<Marksheet> marksheetDatabase;

int findStudentIndex(const string& roll) {
    for (size_t i = 0; i < marksheetDatabase.size(); ++i) {
        if (marksheetDatabase[i].getRollNo() == roll) return i;
    }
    return -1;
}


void createMarksheet() {
    string roll, name, cls;
    int numSubjects;

    cout << "\n--- Generate New Marksheet Profile ---\n";
    cout << "Enter Roll Number: ";
    cin >> roll;
    cin.ignore();

    if (findStudentIndex(roll) != -1) {
        cout << " Error: A marksheet for this roll number already exists!\n";
        return;
    }

    cout << "Enter Student Full Name: ";
    getline(cin, name);
    cout << "Enter Class/Standard: ";
    getline(cin, cls);

    Marksheet newSheet(roll, name, cls);

    cout << "How many subjects do you want to add? ";
    cin >> numSubjects;

    for (int i = 0; i < numSubjects; ++i) {
        string subName;
        double marks, maxMarks;

        cout << "\n  Subject #" << (i + 1) << " Name: ";
        cin.ignore();
        getline(cin, subName);
        cout << "  Marks Obtained: ";
        cin >> marks;
        cout << "  Maximum Marks (Default 100): ";
        cin >> maxMarks;

        if (marks > maxMarks) {
            cout << "   Warning: Obtained marks cannot exceed Max Marks. Re-entering this subject...\n";
            i--;
            continue;
        }

        newSheet.addSubjectScore(subName, marks, maxMarks);
    }

    marksheetDatabase.push_back(newSheet);
    cout << "\n  Marksheet database record compiled for " << name << "!\n";
}

void printReport() {
    string roll;
    cout << "\n--- View Student Report Card ---\n";
    cout << "Enter Roll Number: ";
    cin >> roll;

    int idx = findStudentIndex(roll);
    if (idx != -1) {
        marksheetDatabase[idx].printReportCard();
    } else {
        cout << " Roll Number not located in system records.\n";
    }
}


int main() {
    int choice;

    while (true) {
        cout << "\n==================================\n";
        cout << "    MARKSHEET GENERATION SYSTEM   \n";
        cout << "==================================\n";
        cout << "1. Create New Student Marksheet\n";
        cout << "2. Search & Print Report Card\n";
        cout << "3. Exit\n";
        cout << "\nEnter Selection (1-3): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid token. Input an accurate digit action.\n";
            continue;
        }

        switch (choice) {
            case 1: createMarksheet(); break;
            case 2: printReport(); break;
            case 3: 
                cout << "\nClosing assessment system. Records saved to memory.\n";
                return 0;
            default: 
                cout << " Choice invalid. Pick from options 1 through 3.\n";
        }
    }
    return 0;
}