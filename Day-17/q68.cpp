// // FIND COMMON ELEMENTS BETWEEN TWO ARRAYS

#include <iostream>
using namespace std;

int main() {
    cout << "ENTER SIZE OF FIRST ARRAY : ";
    int size1;
    cin >> size1;
    
    int arr1[size1];
    for(int i = 0; i < size1; i++) {
        cout << "ENTER  ELEMENT HAVING INDEX " << i << " : ";
        cin >> arr1[i];
    }
    cout << "\nENTER SIZE OF SECOND ARRAY : ";
    int size2;
    cin >> size2;
    
    int arr2[size2];
    for(int i = 0; i < size2; i++) {
        cout << "ENTER  ELEMENT HAVING INDEX " << i << " : ";
        cin >> arr2[i];
    }
    cout << "\n======== FIRST ARRAY ELEMENTS =========" << endl;
    for(int i = 0; i < size1; i++) {
        cout << arr1[i] << " ";
    }
    cout << endl;
    
    cout << "======== SECOND ARRAY ELEMENTS ========" << endl;
    for(int i = 0; i < size2; i++) {
        cout << arr2[i] << " ";
    }
    cout << endl;
    cout << "========== COMMON ELEMENTS ARE ==========" << endl;
    
    bool common_found = false;

    for(int i = 0; i < size1; i++) {
        if(arr1[i] == -1) {
            continue;
        }
        for(int k = i + 1; k < size1; k++) {
            if(arr1[i] == arr1[k]) {
                arr1[k] = -1; 
            }
        }
        for(int j = 0; j < size2; j++) {
            if(arr1[i] == arr2[j]) {
                cout << arr1[i] << " ";
                common_found = true;
                break; 
            }
        }
    }

    if(!common_found) {
        cout << "NO COMMON ELEMENTS FOUND.";
    }
    cout << endl << "=========================================" << endl;
    
    return 0;
}