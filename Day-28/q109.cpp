// LIBRARY MANAGEMENT SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Book {
private:
    string id;
    string title;
    string author;
    bool isIssued;

public:
    
    Book(string id, string title, string author) {
        this->id = id;
        this->title = title;
        this->author = author;
        this->isIssued = false; 
    }

   
    string getId() const { return id; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    bool getIssuedStatus() const { return isIssued; }

    
    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }

   
    void displayBookRow() const {
        cout << left << setw(10) << id 
             << setw(25) << title 
             << setw(20) << author 
             << (isIssued ? " Issued" : " Available") << endl;
    }
};


class Library {
private:
    vector<Book> books;

   
    int findBookIndex(const string& id) {
        for (size_t i = 0; i < books.size(); ++i) {
            if (books[i].getId() == id) return i;
        }
        return -1;
    }

   public:
   
    void addBook() {
        string id, title, author;
        cout << "\n--- Add New Book to Inventory ---\n";
        cout << "Enter Book ID/ISBN (Unique): ";
        cin >> id;
        cin.ignore();

        if (findBookIndex(id) != -1) {
            cout << " Error: A book with this ID already exists in the catalog!\n";
            return;
        }

        cout << "Enter Book Title: ";
        getline(cin, title);
        cout << "Enter Author Name: ";
        getline(cin, author);

        books.push_back(Book(id, title, author));
        cout << "  Book '" << title << "' successfully indexed into library records!\n";
    }

  
    void viewCatalog() {
        cout << "\n--- Complete Library Catalog ---\n";
        if (books.empty()) {
            cout << "The library inventory is currently empty.\n";
            return;
        }

        cout << left << setw(10) << "Book ID" 
             << setw(25) << "Title" 
             << setw(20) << "Author" 
             << "Status" << endl;
        cout << string(68, '-') << endl;

        for (const auto& book : books) {
            book.displayBookRow();
        }
    }

   
    void issueBookWorkflow() {
        string id;
        cout << "\n--- Book Issue / Check Out ---\n";
        cout << "Enter Book ID to issue: ";
        cin >> id;

        int idx = findBookIndex(id);
        if (idx == -1) {
            cout << " Error: Book ID not found in inventory.\n";
            return;
        }

        if (books[idx].getIssuedStatus()) {
            cout << " Sorry, this book is already issued to another reader.\n";
        } else {
            books[idx].issueBook();
            cout << " Success! '" << books[idx].getTitle() << "' has been checked out.\n";
        }
    }

   
    void returnBookWorkflow() {
        string id;
        cout << "\n--- Book Return / Check In ---\n";
        cout << "Enter Book ID to return: ";
        cin >> id;

        int idx = findBookIndex(id);
        if (idx == -1) {
            cout << " Error: Invalid Book ID. It does not belong to this library.\n";
            return;
        }

        if (!books[idx].getIssuedStatus()) {
            cout << " System Alert: This book is already sitting on our shelves!\n";
        } else {
            books[idx].returnBook();
            cout << " Success! '" << books[idx].getTitle() << "' returned safely back to inventory.\n";
        }
    }
};


int main() {
    Library centralLibrary;
    int choice;

    while (true) {
        cout << "\n==================================\n";
        cout << "    CAMPUS LIBRARY MANAGEMENT    \n";
        cout << "==================================\n";
        cout << "1. Add Book to Inventory\n";
        cout << "2. View Book Catalog\n";
        cout << "3. Issue a Book (Check Out)\n";
        cout << "4. Return a Book (Check In)\n";
        cout << "5. Exit System\n";
        cout << "\nEnter Choice (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid entry. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: centralLibrary.addBook(); break;
            case 2: centralLibrary.viewCatalog(); break;
            case 3: centralLibrary.issueBookWorkflow(); break;
            case 4: centralLibrary.returnBookWorkflow(); break;
            case 5: 
                cout << "\nClosing library terminal. Keep reading!\n";
                return 0;
            default: 
                cout << " Choice out of range. Pick between 1 and 5.\n";
        }
    }
    return 0;
}