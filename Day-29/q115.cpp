// MENU DRIVEN STRING OPERTAION SYSTEM 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;
    int choice;

    cout << "=========================================" << endl;
    cout << "      STRING OPERATIONS SYSTEM     " << endl;
    cout << "=========================================" << endl;

    cout << "Enter a String: ";
    getline(cin, str1);

    do {
        cout << "\n------------  STRING MENU ------------" << endl;
        cout << "1. Find Length of String" << endl;
        cout << "2. Reverse the String" << endl;
        cout << "3. Convert to Uppercase" << endl;
        cout << "4. Concatenate (Join) with another String" << endl;
        cout << "5. Exit" << endl;
        cout << "----------------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore(); 

        switch (choice) {
            case 1: {
                
                int len = str1.length(); 
                cout << "\n Length of \"" << str1 << "\" is: " << len << " characters." << endl;
                break;
            }
            case 2: {
                
                string rev = "";
                for (int i = str1.length() - 1; i >= 0; i--) {
                    rev += str1[i];
                }
                cout << "\n Reversed String: \"" << rev << "\"" << endl;
                break;
            }
            case 3: {
              
                string upper = str1;
                for (int i = 0; upper[i] != '\0'; i++) {
                    upper[i] = toupper(upper[i]);
                }
                cout << "\n Uppercase String: \"" << upper << "\"" << endl;
                break;
            }
            case 4: {
                
                cout << "\nEnter second string to join: ";
                getline(cin, str2);
                string joined = str1 + " " + str2;
                cout << "\n Joined String: \"" << joined << "\"" << endl;
                break;
            }
            case 5:
                cout << "\nExiting String Operations System. Goodbye! " << endl;
                break;
                
            default:
                cout << "\n Invalid Choice! Please enter a number between 1 and 5." << endl;
        }
    } while (choice != 5);

    return 0;
}