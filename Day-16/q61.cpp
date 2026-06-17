// FINDING MISSING NUMBER IN AN ARRAY 

#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER ARRAY SIZE : ";
    int size;
    cin>>size;
    int arr[size];
    cout<<"ENTER A NUMBER FROM 1 TO "<< size <<endl;
    for(int i = 0 ; i< size - 1 ; i++){
        cout<<"ENTER ELEMENT "<<i<<" : ";
        int n;
        cin>>n;
        arr[i] = n;
    }

    cout<<"====== ARRAY ELEMENTS ARE : ======== "<<endl;
    for(int i = 0 ; i< size - 1 ; i++){
        cout<<arr[i]<<" ";
    }

    int sum = (size*(size+1))/2;
    int actual_sum = 0;

    for(int i = 0 ; i< size -1 ; i++){
        actual_sum += arr[i];
    }

    int missing = sum - actual_sum;

    cout<<endl<<" ====== MISSING INTEGER NUMBER IS " <<missing<<" ==========";
    
    return 0 ;
}