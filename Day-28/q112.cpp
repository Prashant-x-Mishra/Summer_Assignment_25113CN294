// CONTACT MANAGEMENT SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;


class Contact {
private:
    string name;
    string phoneNumber;
    string email;
    string groupLabel; 

public:
   
    Contact(string name, string phone, string email, string group) {
        this->name = name;
        this->phoneNumber = phone;
        this->email = email;
        this->groupLabel = group;
    }

   
    string getName() const { return name; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getGroupLabel() const { return groupLabel; }

   
    void updateDetails(string phone, string mail, string group) {
        this->phoneNumber = phone;
        this->email = mail;
        this->groupLabel = group;
    }

    void displayRow() const {
        cout << left << setw(20) << name 
             << setw(15) << phoneNumber 
             << setw(25) << email 
             << groupLabel << endl;
    }
};

vector<Contact> contactBook;

int findContactIndex(const string& lookupName) {
    for (size_t i = 0; i < contactBook.size(); ++i) {
        
        if (contactBook[i].getName() == lookupName) {
            return i;
        }
    }
    return -1;
}

void addContact() {
    string name, phone, email, group;
    cout << "\n--- Create New Contact ---\n";
    cin.ignore(); 
    
    cout << "Enter Full Name: ";
    getline(cin, name);

    if (findContactIndex(name) != -1) {
        cout << " Error: A contact with the name '" << name << "' already exists.\n";
        return;
    }

    cout << "Enter Phone Number: ";
    getline(cin, phone);
    cout << "Enter Email Address: ";
    getline(cin, email);
    cout << "Enter Designation Group (e.g., Family, Work, Friends): ";
    getline(cin, group);

    contactBook.push_back(Contact(name, phone, email, group));
    cout << " Contact card for '" << name << "' initialized successfully.\n";
}


void displayAllContacts() {
    cout << "\n--- Address Book Directory ---\n";
    if (contactBook.empty()) {
        cout << "Address book is completely empty.\n";
        return;
    }

    cout << left << setw(20) << "Name" 
         << setw(15) << "Phone Number" 
         << setw(25) << "Email Address" 
         << "Group Tag" << endl;
    cout << string(72, '-') << endl;

    for (const auto& contact : contactBook) {
        contact.displayRow();
    }
}


void searchContact() {
    string query;
    cout << "\n--- Query Contact Database ---\n";
    cin.ignore();
    cout << "Enter exact name to lookup: ";
    getline(cin, query);

    int idx = findContactIndex(query);
    if (idx != -1) {
        cout << "\n Contact Match Found:\n";
        cout << "------------------------------------\n";
        cout << "Name:    " << contactBook[idx].getName() << "\n";
        cout << "Phone:   " << contactBook[idx].getPhoneNumber() << "\n";
        cout << "Email:   " << contactBook[idx].getEmail() << "\n";
        cout << "Group:   " << contactBook[idx].getGroupLabel() << "\n";
        cout << "------------------------------------\n";
    } else {
        cout << " No matching contact profile found under '" << query << "'.\n";
    }
}


void editContact() {
    string query;
    cout << "\n--- Modify Existing Contact ---\n";
    cin.ignore();
    cout << "Enter the name of the profile to alter: ";
    getline(cin, query);

    int idx = findContactIndex(query);
    if (idx == -1) {
        cout << " Contact execution aborted: Name does not exist.\n";
        return;
    }

    string newPhone, newEmail, newGroup;
    cout << "Current Details: " << contactBook[idx].getPhoneNumber() << " | " << contactBook[idx].getEmail() << "\n";
    cout << "Enter New Phone: ";
    getline(cin, newPhone);
    cout << "Enter New Email: ";
    getline(cin, newEmail);
    cout << "Enter New Group: ";
    getline(cin, newGroup);

    contactBook[idx].updateDetails(newPhone, newEmail, newGroup);
    cout << " Contact profile updated successfully.\n";
}


void deleteContact() {
    string query;
    cout << "\n--- Erase Contact Profile ---\n";
    cin.ignore();
    cout << "Enter name to delete: ";
    getline(cin, query);

    for (auto it = contactBook.begin(); it != contactBook.end(); ++it) {
        if (it->getName() == query) {
            cout << " Contact entry for '" << it->getName() << "' permanently erased.\n";
            contactBook.erase(it);
            return;
        }
    }
    cout << " Error: Contact not found.\n";
}

int main() {
    int choice;


    contactBook.push_back(Contact("Bruce Wayne", "555-0199", "bruce@waynecorp.com", "Work"));
    contactBook.push_back(Contact("Clark Kent", "555-0144", "clark@dailyplanet.com", "Friends"));

    while (true) {
        cout << "\n==================================\n";
        cout << "        CONTACT BOOK MANAGER      \n";
        cout << "==================================\n";
        cout << "1. Add New Contact\n";
        cout << "2. View Directory\n";
        cout << "3. Find Contact by Name\n";
        cout << "4. Edit Contact Record\n";
        cout << "5. Delete Contact Record\n";
        cout << "6. Close Program\n";
        cout << "\nEnter Action Choice (1-6): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Type error. Please use numeric values corresponding to options.\n";
            continue;
        }

        switch (choice) {
            case 1: addContact(); break;
            case 2: displayAllContacts(); break;
            case 3: searchContact(); break;
            case 4: editContact(); break;
            case 5: deleteContact(); break;
            case 6: 
                cout << "\nTerminating instance loop. Address book secured.\n";
                return 0;
            default: 
                cout << " Choice out of range. Select an item index from 1 to 6.\n";
        }
    }
    return 0;
}