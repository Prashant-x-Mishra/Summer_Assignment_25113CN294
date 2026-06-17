#include <iostream>
using namespace std;

int main(){
    cout << " enter array1 size  : ";
    int size1;
    cin >> size1;
    int arr[size1];
    for(int i = 0 ; i < size1; i++){
        cout << "ENTER ELEMENT " << i << " : ";
        int n; cin >> n;
        arr[i] = n;
    }

    cout << endl << "enter array2 size :  ";
    int size2;
    cin >> size2;
    int arr2[size2];
    for(int i = 0 ; i < size2 ; i++){
        cout << "ENTER ELEMENT " << i << " : ";
        int n; cin >> n;
        arr2[i] = n;
    }
    
    int arr3[size1]; 
    int size3 = 0;

    for (int i = 0 ; i < size1; i++){
        for(int j = 0 ; j < size2; j++){
            if(arr[i] == arr2[j]){
                arr3[size3] = arr[i];
                size3++;
                break; 
            }
        }
    }

    cout << endl << "======= INTERSECTION OF ARRAY ========" << endl;
    for(int i = 0; i < size3; i++){
        if(arr3[i] == -1){
            continue;
        }
        cout << arr3[i] << " ";
        for(int j = i + 1 ; j < size3; j++){
            if(arr3[i] == arr3[j]){
                arr3[j] = -1;
            }
        }
    }
    cout << endl;
    
    return 0;
}