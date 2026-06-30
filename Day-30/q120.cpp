//  (ENTROPY TRACKER ) MINI PROJECT 

#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

string studentName[MAX];
string subject[MAX];
int studyTime[MAX];
int productivity[MAX];

int totalRecords = 0;


void addSession();
void displaySessions();
void searchStudent();
void analytics();
void menu();

int main()
{
    menu();
    return 0;
}

void menu()
{
    int choice;

    do
    {
        cout << "\n=====================================\n";
        cout << "      ENTROPY TRACKER (Mini Project)\n";
        cout << "=====================================\n";
        cout << "1. Add Study Session\n";
        cout << "2. Display All Sessions\n";
        cout << "3. Search Student\n";
        cout << "4. Study Analytics\n";
        cout << "5. Exit\n";
        cout << "Enter Choice : ";
        cin >> choice;

        cin.ignore();

        switch(choice)
        {
            case 1:
                addSession();
                break;

            case 2:
                displaySessions();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                analytics();
                break;

            case 5:
                cout << "\nThank You for using Entropy Tracker.\n";
                break;

            default:
                cout << "\nInvalid Choice!\n";
        }

    } while(choice != 5);
}

void addSession()
{
    if(totalRecords == MAX)
    {
        cout << "\nStorage Full!\n";
        return;
    }

    cout << "\nStudent Name : ";
    getline(cin, studentName[totalRecords]);

    cout << "Subject : ";
    getline(cin, subject[totalRecords]);

    cout << "Study Time (minutes) : ";
    cin >> studyTime[totalRecords];

    cout << "Productivity (1-10) : ";
    cin >> productivity[totalRecords];

    cin.ignore();

    totalRecords++;

    cout << "\nSession Added Successfully!\n";
}

void displaySessions()
{
    if(totalRecords == 0)
    {
        cout << "\nNo Records Found.\n";
        return;
    }

    cout << "\n========== STUDY RECORDS ==========\n";

    for(int i = 0; i < totalRecords; i++)
    {
        cout << "\nRecord " << i + 1 << endl;
        cout << "Student      : " << studentName[i] << endl;
        cout << "Subject      : " << subject[i] << endl;
        cout << "Study Time   : " << studyTime[i] << " minutes" << endl;
        cout << "Productivity : " << productivity[i] << "/10\n";
    }
}

void searchStudent()
{
    if(totalRecords == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    string name;
    bool found = false;

    cout << "\nEnter Student Name : ";
    getline(cin, name);

    for(int i = 0; i < totalRecords; i++)
    {
        if(studentName[i] == name)
        {
            found = true;

            cout << "\nRecord Found\n";
            cout << "Subject      : " << subject[i] << endl;
            cout << "Study Time   : " << studyTime[i] << " minutes" << endl;
            cout << "Productivity : " << productivity[i] << "/10\n";
        }
    }

    if(!found)
    {
        cout << "\nStudent Not Found.\n";
    }
}

void analytics()
{
    if(totalRecords == 0)
    {
        cout << "\nNo Records Available.\n";
        return;
    }

    int totalTime = 0;
    int totalProductivity = 0;

    for(int i = 0; i < totalRecords; i++)
    {
        totalTime += studyTime[i];
        totalProductivity += productivity[i];
    }

    double average = (double)totalProductivity / totalRecords;

    cout << "\n========== ANALYTICS ==========\n";
    cout << "Total Sessions       : " << totalRecords << endl;
    cout << "Total Study Time     : " << totalTime << " minutes" << endl;
    cout << "Average Productivity : " << average << "/10" << endl;
}