// INVENTORY MANAGEMENT SYSTEM 

#include <iostream>
#include <string>
#include <vector>
#include <iomanip> // Matrix style table print karne ke liye
using namespace std;

// Product ka blueprint
class Product {
private:
    int id;
    string name;
    double price;
    int quantity;

public:
    // Constructor
    Product(int p_id, string p_name, double p_price, int p_qty) {
        id = p_id;
        name = p_name;
        price = p_price;
        quantity = p_qty;
    }

    // Getter functions data read karne ke liye
    int getId() { return id; }
    string getName() { return name; }
    double getPrice() { return price; }
    int getQuantity() { return quantity; }

    // Stock update karne ke liye setter function
    void updateQuantity(int new_qty) {
        quantity = new_qty;
    }
};

int main() {
    vector<Product> inventory;
    int choice;

   
    inventory.push_back(Product(101, "Laptop", 45000.0, 10));
    inventory.push_back(Product(102, "Mouse", 450.0, 50));
    inventory.push_back(Product(103, "Keyboard", 950.0, 30));

    do {
        cout << "\n=============================================" << endl;
        cout << "     INVENTORY MANAGEMENT SYSTEM (IMS)    " << endl;
        cout << "=============================================" << endl;
        cout << "1. Add New Product" << endl;
        cout << "2. View All Products" << endl;
        cout << "3. Update Product Stock" << endl;
        cout << "4. Delete a Product" << endl;
        cout << "5. Exit" << endl;
        cout << "---------------------------------------------" << endl;
        cout << "Enter your choice (1-5): ";
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {
                // 1. ADD NEW PRODUCT
                int id, qty;
                string name;
                double price;
                bool idExists = false;

                cout << "\n ---- ADD NEW PRODUCT ----" << endl;
                cout << "Enter Product ID  : ";
                cin >> id;
                cin.ignore();

                // Check karna ki yeh ID pehle se toh nahi hai
                for (int i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getId() == id) {
                        idExists = true;
                        break;
                    }
                }

                if (idExists) {
                    cout << " ERROR: Product ID already exists!" << endl;
                } else {
                    cout << "Enter Product Name: ";
                    getline(cin, name);
                    cout << "Enter Price (Rs.) : ";
                    cin >> price;
                    cout << "Enter Quantity    : ";
                    cin >> qty;

                    inventory.push_back(Product(id, name, price, qty));
                    cout << " Product Added Successfully!" << endl;
                }
                break;
            }

            case 2: {
                // 2. VIEW ALL PRODUCTS (TABLE FORMAT)
                if (inventory.empty()) {
                    cout << "\n Inventory is empty!" << endl;
                    break;
                }

                cout << "\n ------------------ CURRENT INVENTORY ------------------" << endl;
                // left aur setw() se table columns ekdam seedhe line me aate hain
                cout << left << setw(10) << "ID" << setw(20) << "Name" << setw(12) << "Price (Rs.)" << "Quantity" << endl;
                cout << "----------------------------------------------------------" << endl;

                for (int i = 0; i < inventory.size(); i++) {
                    cout << left << setw(10) << inventory[i].getId() 
                         << setw(20) << inventory[i].getName() 
                         << setw(12) << inventory[i].getPrice() 
                         << inventory[i].getQuantity() << endl;
                }
                cout << "----------------------------------------------------------" << endl;
                break;
            }

            case 3: {
                // 3. UPDATE PRODUCT STOCK
                int id, new_qty;
                bool found = false;

                cout << "\n ---- UPDATE PRODUCT STOCK ----" << endl;
                cout << "Enter Product ID: ";
                cin >> id;

                for (int i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getId() == id) {
                        cout << "Current Quantity of " << inventory[i].getName() << " is: " << inventory[i].getQuantity() << endl;
                        cout << "Enter New Total Quantity: ";
                        cin >> new_qty;
                        
                        if(new_qty >= 0) {
                            inventory[i].updateQuantity(new_qty);
                            cout << " Stock Updated Successfully!" << endl;
                        } else {
                            cout << " Invalid Quantity!" << endl;
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << " Product ID not found!" << endl;
                break;
            }

            case 4: {
                // 4. DELETE A PRODUCT
                int id;
                bool found = false;

                cout << "\n ---- DELETE A PRODUCT ----" << endl;
                cout << "Enter Product ID to delete: ";
                cin >> id;

                for (int i = 0; i < inventory.size(); i++) {
                    if (inventory[i].getId() == id) {
                        cout << " Deleting product: " << inventory[i].getName() << endl;
                        // Vector se element delete karne ke liye .erase() ka use
                        inventory.erase(inventory.begin() + i);
                        cout << " Product Deleted Successfully!" << endl;
                        found = true;
                        break;
                    }
                }
                if (!found) cout << " Product ID not found!" << endl;
                break;
            }

            case 5:
                cout << "\nExiting Inventory System. Goodbye! " << endl;
                break;

            default:
                cout << "\n Invalid Choice! Enter a number between 1 and 5." << endl;
        }

    } while (choice != 5);

    return 0;
}