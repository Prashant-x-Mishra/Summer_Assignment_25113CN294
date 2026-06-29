// MENU DRIVEN ARRAY OPERATION SYSTEM 


#include <iostream>

using namespace std;

const int MAX_SIZE = 100; 


int arr[MAX_SIZE];
int currentSize = 0;


void displayArray() {
    cout << "\n--- Current Array State ---\n";
    if (currentSize == 0) {
        cout << "[ Empty Array ]\n";
        return;
    }
    
    cout << "Elements: [ ";
    for (int i = 0; i < currentSize; ++i) {
        cout << arr[i] << (i == currentSize - 1 ? "" : ", ");
    }
    cout << " ]\n";
    cout << "Total Elements: " << currentSize << " / " << MAX_SIZE << "\n";
}


void insertElement() {
    cout << "\n--- Insert Element ---\n";
    if (currentSize >= MAX_SIZE) {
        cout << " Error: Array Overflow! Cannot add more elements.\n";
        return;
    }

    int element, position;
    cout << "Enter element to insert: ";
    cin >> element;
    cout << "Enter target position/index (0 to " << currentSize << "): ";
    cin >> position;

   
    if (position < 0 || position > currentSize) {
        cout << " Error: Invalid index position!\n";
        return;
    }

 
    for (int i = currentSize; i > position; --i) {
        arr[i] = arr[i - 1];
    }


    arr[position] = element;
    currentSize++;
    cout << " Element " << element << " inserted at index " << position << " successfully.\n";
}


void deleteElement() {
    cout << "\n--- Delete Element ---\n";
    if (currentSize == 0) {
        cout << " Error: Array Underflow! No items available to drop.\n";
        return;
    }

    int position;
    cout << "Enter index to delete (0 to " << currentSize - 1 << "): ";
    cin >> position;

   
    if (position < 0 || position >= currentSize) {
        cout << " Error: Invalid index position!\n";
        return;
    }

    int removedVal = arr[position];

  
    for (int i = position; i < currentSize - 1; ++i) {
        arr[i] = arr[i + 1];
    }

    currentSize--; 
    cout << " Element '" << removedVal << "' removed from index " << position << ".\n";
}


void searchElement() {
    cout << "\n--- Search Element ---\n";
    if (currentSize == 0) {
        cout << "Array is empty. Nothing to search.\n";
        return;
    }

    int target;
    cout << "Enter the value to find: ";
    cin >> target;

    // Sequential Check
    for (int i = 0; i < currentSize; ++i) {
        if (arr[i] == target) {
            cout << " Found: Value " << target << " sits at index position [" << i << "].\n";
            return;
        }
    }
    cout << " Value " << target << " was not located in the array.\n";
}


int main() {
    int choice;

    while (true) {
        cout << "\n==================================\n";
        cout << "     ARRAY OPERATIONS INTERFACE   \n";
        cout << "==================================\n";
        cout << "1. Display Array\n";
        cout << "2. Insert Element\n";
        cout << "3. Delete Element\n";
        cout << "4. Search Element\n";
        cout << "5. Exit\n";
        cout << "\nEnter Choice (1-5): ";
        cin >> choice;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << " Invalid entry type. Please select a correct numeric command.\n";
            continue;
        }

        switch (choice) {
            case 1: displayArray(); break;
            case 2: insertElement(); break;
            case 3: deleteElement(); break;
            case 4: searchElement(); break;
            case 5: 
                cout << "\nTerminating application routine. Goodbye!\n";
                return 0;
            default: 
                cout << " Out of scope. Choose an option ranging 1 through 5.\n";
        }
    }
    return 0;
}