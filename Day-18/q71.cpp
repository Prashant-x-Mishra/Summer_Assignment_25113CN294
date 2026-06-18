// BINARY SEARCH


#include <iostream>
using namespace std;

using namespace std ;
void shorted_arr (int arr[],int size){
    for(int i = 0 ; i<size;i++){
       int min = i;
        for(int j = i + 1 ; j<size  ; j++){
           if(arr[j] < arr[min]){
           min = j;
           }
    }  
    if(min != i){
        int temp = arr[i];
        arr[i] = arr[min];
        arr[min] = temp;
    }
    }
}


int binary_search(int arr[], int size, int target) {
    int low = 0;
    int high = size - 1;

    while (low <= high) {
        int mid =(low + high)  / 2; 
        if (arr[mid] == target) {
            return mid; 
        }
        if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

int main() {
  
cout<<"ENTER ARRAY  SIZE : ";
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0 ; i< size  ; i++){
        cout<<"ENTER ELEMENT HAVING INDEX "<<i<<" : ";
        int n;
        cin>>n;
        arr[i] = n;
    }

    cout<<"====== ARRAY ELEMENTS ARE : ======== "<<endl;
    for(int i = 0 ; i < size  ; i++){
        cout<<arr[i]<<" ";
    }

    shorted_arr(arr,size);
    cout<<endl<<" ======== SORTED ARRAY  ======="<<endl;

    for(int i = 0 ; i < size; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;

    int target ;
    cout << "Enter the number you want to search for: ";
    cin >> target;

    int result = binary_search(arr, size, target);

    if (result != -1) {
        cout << "Element found at index: "  << endl;

        int left = result;
        while(left>=0 && arr[left] == target){
            left--;
        }

        int right = left + 1;
        while(right<size && arr[right] == target){
            cout<<right<<" ";
            right++;
        }
    }

    else {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}