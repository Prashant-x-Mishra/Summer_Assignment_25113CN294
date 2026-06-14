// FINDING DUPLICATES IN AN ARRAY

#include <iostream>
using namespace std;

int main() {
    cout << "ENTER ARRAY SIZE : ";
    int size;
    cin >> size;
    
    int i = 0;
    int arr[size]; 
    
    for(int i = 0; i < size; i++) {
        cout << "ENTER NUMBER HAVING INDEX " << i << " : ";
        int n;
        cin >> n;
        arr[i] = n;
    }
    
    cout << "========  ARRAY ELEMENTS ARE ========" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    cout << "\n======== DUPLICATES ELEMENT IN AN ARRAY ========" << endl;
    
    for(int i = 0; i < size; i++) {
        if (arr[i] == -1) {
            continue;
        }
        
        bool isDuplicate = false;
        
        for(int j = i + 1; j < size; j++) {
            if(arr[i] == arr[j]) {
                isDuplicate = true;
                arr[j] = -1; 
            }
        }
        if (isDuplicate) {
            cout << arr[i] << " ";
        }
    }
    
    cout << endl;
    return 0;
}