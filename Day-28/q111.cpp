// TICKET BOOKING SYSTEM 

#include <iostream>
#include <vector>
#include <string>
#include <iomanip>

using namespace std;

class Show {
private:
    string showId;
    string title;
    int totalSeats;
    int availableSeats;
    double ticketPrice;

public:
    Show(string id, string showTitle, int seats, double price) {
        showId = id;
        title = showTitle;
        totalSeats = seats;
        availableSeats = seats;
        ticketPrice = price;
    }

    string getShowId() const { return showId; }
    string getTitle() const { return title; }
    int getAvailableSeats() const { return availableSeats; }
    double getTicketPrice() const { return ticketPrice; }

    bool bookSeats(int count) {
        if (count <= 0) {
            cout << " Error: Invalid number of tickets requested.\n";
            return false;
        }
        if (count > availableSeats) {
            cout << " Error: Sorry, only " << availableSeats << " seats are left.\n";
            return false;
        }
        
        availableSeats -= count;
        return true;
    }

    void displayShowRow() const {
        cout << left << setw(10) << showId 
             << setw(25) << title 
             << setw(15) << availableSeats << "/" << totalSeats 
             << "$" << fixed << setprecision(2) << ticketPrice << endl;
    }
};

vector<Show> showDatabase;

int findShowIndex(const string& id) {
    for (size_t i = 0; i < showDatabase.size(); ++i) {
        if (showDatabase[i].getShowId() == id) return i;
    }
    return -1;
}

void addNewShow() {
    string id, title;
    int seats;
    double price;

    cout << "\n--- Add New Show/Event ---\n";
    cout << "Enter Show ID (Unique): ";
    cin >> id;
    cin.ignore();

    if (findShowIndex(id) != -1) {
        cout << "  Error: This Show ID already exists!\n";
        return;
    }

    cout << "Enter Show/Movie Title: ";
    getline(cin, title);
    cout << "Enter Total Seat Capacity: ";
    cin >> seats;
    cout << "Enter Ticket Price ($): ";
    cin >> price;

    showDatabase.push_back(Show(id, title, seats, price));
    cout << " Show '" << title << "' added to the schedule successfully!\n";
}

void viewAvailableShows() {
    cout << "\n--- Current Show Schedule ---\n";
    if (showDatabase.empty()) {
        cout << "No shows currently scheduled.\n";
        return;
    }

    cout << left << setw(10) << "ID" 
         << setw(25) << "Title" 
         << setw(15) << "Available" 
         << "Price" << endl;
    cout << string(60, '-') << endl;

    for (const auto& show : showDatabase) {
        show.displayShowRow();
    }
}

void bookTickets() {
    cout << "\n--- Book Tickets ---\n";
    if (showDatabase.empty()) {
        cout << "No shows available for booking.\n";
        return;
    }

    string id;
    int ticketsToBook;
    
    cout << "Enter Show ID: ";
    cin >> id;

    int idx = findShowIndex(id);
    if (idx == -1) {
        cout << " Error: Show ID not found.\n";
        return;
    }

    cout << "Available Seats: " << showDatabase[idx].getAvailableSeats() << "\n";
    cout << "Enter number of tickets to buy: ";
    cin >> ticketsToBook;

    if (showDatabase[idx].bookSeats(ticketsToBook)) {
        double totalCost = ticketsToBook * showDatabase[idx].getTicketPrice();
        cout << "\n  BOOKING CONFIRMED! \n";
        cout << "-------------------------\n";
        cout << "Show:       " << showDatabase[idx].getTitle() << "\n";
        cout << "Tickets:    " << ticketsToBook << "\n";
        cout << "Total Cost: $" << fixed << setprecision(2) << totalCost << "\n";
        cout << "-------------------------\n";
    }
}

int main() {
    int choice;

   
    showDatabase.push_back(Show("M1", "Avatar 3", 100, 14.50));
    showDatabase.push_back(Show("M2", "The Batman II", 80, 12.00));

    while (true) {
        cout << "\n==================================\n";
        cout << "      TICKET BOOKING SYSTEM       \n";
        cout << "==================================\n";
        cout << "1. View Show Schedule\n";
        cout << "2. Book Tickets\n";
        cout << "3. Add New Show (Admin)\n";
        cout << "4. Exit\n";
        cout << "\nEnter Choice (1-4): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid entry! Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1: viewAvailableShows(); break;
            case 2: bookTickets(); break;
            case 3: addNewShow(); break;
            case 4: 
                cout << "\nExiting system. Enjoy your show!\n";
                return 0;
            default: 
                cout << " Out of scope. Choose a option from 1 to 4.\n";
        }
    }
    return 0;
}