// MAXIMUM FREQUENCY ELEMENT 

#include <iostream>
using namespace std;

int main() {
cout << " ENTER ARRAY SIZE : ";
int size;
cin >> size;
    
int arr[size];
for(int i = 0; i < size; i++) {
    cout << "ENTER NUMBER HAVING INDEX " << i << " : ";
    cin >> arr[i]; 
    }
    
cout << "======== ARRAY ELEMENTS ARE =========" << endl;
    for(int i = 0; i < size; i++) {
        cout << arr[i] << "  ";
    }
cout << endl;
int max_freq = 0;
for(int i = 0; i < size; i++) {
    int count = 0;
    for(int j = 0; j < size; j++) {
        if(arr[i] == arr[j]) {
            count++;
            }
        }
    if(count > max_freq) {
         max_freq = count;
        }
    }

cout << "\n================ RESULT ================" << endl;
cout << "MAXIMUM FREQUENCY IS: " << max_freq << " TIMES" << endl;
cout << "ELEMENTS WITH THIS FREQUENCY ARE: ";
 for(int i = 0; i < size; i++) {
    if(arr[i] == -1) {
        continue;
        }

    int count = 0;
    for(int j = 0; j < size; j++) {
        if(arr[i] == arr[j]) {
            count++;
            }
        }
    if(count == max_freq) {
        cout << arr[i] << " ";
        for(int k = i + 1; k < size; k++) {
             if(arr[k] == arr[i]) {
                 arr[k] = -1; 
                }
            }
        }
    }
    cout << "\n========================================" << endl;

    return 0;
}