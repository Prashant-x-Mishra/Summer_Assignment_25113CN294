// mini library system 

#include <iostream>
#include <string>

using namespace std;


const int MAX_BOOKS = 100;

int main() {
   
    int bookIDs[MAX_BOOKS];
    string titles[MAX_BOOKS];
    string authors[MAX_BOOKS];
    bool isIssued[MAX_BOOKS]; 

    int bookCount = 0; // Tracks the total number of books in the library
    int choice;

    cout << "===== Welcome to the Mini Library System =====" << endl;

    do {
        // Display Menu
        cout << "\n-----------------------------" << endl;
        cout << "1. Add New Book" << endl;
        cout << "2. Display All Books" << endl;
        cout << "3. Search Book by ID" << endl;
        cout << "4. Issue / Check Out Book" << endl;
        cout << "5. Return Book" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice (1-6): ";
        cin >> choice;
        cout << "-----------------------------" << endl;

        switch (choice) {
            case 1: // Add New Book
                if (bookCount >= MAX_BOOKS) {
                    cout << "Error: Library catalog is full!" << endl;
                } else {
                    cout << "Enter Book ID (integer): ";
                    cin >> bookIDs[bookCount];
                    cin.ignore(); 

                    cout << "Enter Book Title: ";
                    getline(cin, titles[bookCount]);

                    cout << "Enter Author Name: ";
                    getline(cin, authors[bookCount]);

                    isIssued[bookCount] = false;

                    bookCount++;
                    cout << "\nBook successfully added to the library!" << endl;
                }
                break;

            case 2: // Display All Books
                if (bookCount == 0) {
                    cout << "The library is currently empty." << endl;
                } else {
                    cout << "\n--- Library Catalog ---" << endl;
                    for (int i = 0; i < bookCount; i++) {
                        cout << "ID: " << bookIDs[i] 
                             << " | Title: \"" << titles[i] << "\""
                             << " | Author: " << authors[i] 
                             << " | Status: " << (isIssued[i] ? "Issued " : "Available  ") 
                             << endl;
                    }
                }
                break;

            case 3: // Search Book by ID
                if (bookCount == 0) {
                    cout << "No books available to search." << endl;
                } else {
                    int searchID;
                    bool found = false;
                    cout << "Enter Book ID to search: ";
                    cin >> searchID;

                    for (int i = 0; i < bookCount; i++) {
                        if (bookIDs[i] == searchID) {
                            cout << "\n--- Book Found ---" << endl;
                            cout << "ID: " << bookIDs[i] << endl;
                            cout << "Title: " << titles[i] << endl;
                            cout << "Author: " << authors[i] << endl;
                            cout << "Status: " << (isIssued[i] ? "Issued" : "Available") << endl;
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        cout << "Book with ID " << searchID << " not found." << endl;
                    }
                }
                break;

            case 4: // Issue a Book
                if (bookCount == 0) {
                    cout << "No books available to issue." << endl;
                } else {
                    int issueID;
                    bool found = false;
                    cout << "Enter Book ID to issue: ";
                    cin >> issueID;

                    for (int i = 0; i < bookCount; i++) {
                        if (bookIDs[i] == issueID) {
                            found = true;
                            if (isIssued[i]) {
                                cout << "Sorry, this book is already issued to someone else." << endl;
                            } else {
                                isIssued[i] = true;
                                cout << "Success! \"" << titles[i] << "\" has been issued to you." << endl;
                            }
                            break;
                        }
                    }
                    if (!found) cout << "Book ID not found." << endl;
                }
                break;

            case 5: // Return a Book
                if (bookCount == 0) {
                    cout << "No books to return." << endl;
                } else {
                    int returnID;
                    bool found = false;
                    cout << "Enter Book ID to return: ";
                    cin >> returnID;

                    for (int i = 0; i < bookCount; i++) {
                        if (bookIDs[i] == returnID) {
                            found = true;
                            if (!isIssued[i]) {
                                cout << "This book is already in the library inventory." << endl;
                            } else {
                                isIssued[i] = false;
                                cout << "Thank you! \"" << titles[i] << "\" has been successfully returned." << endl;
                            }
                            break;
                        }
                    }
                    if (!found) cout << "Book ID not found." << endl;
                }
                break;

            case 6: // Exit
                cout << "Exiting system. Have a great day!" << endl;
                break;

            default:
                cout << "Invalid choice! Please pick an option between 1 and 6." << endl;
        }

    } while (choice != 6);

    return 0;
}