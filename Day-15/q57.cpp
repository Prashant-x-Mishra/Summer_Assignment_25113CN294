// REVERSE ARRAY 

#include <iostream>
using namespace std;
int main(){
    int size;
    cout<<"ENTER THE SIZE OF AN ARRAY : ";
    cin>>size;
    int arr[size];
    for(int i = 0 ; i<size;i++){
        int n ;
        cout<<"ENTER ELEMENT HAVING INDEX "<<i<<" : ";
        cin>>n;
        arr[i] = n ;
    }

    cout<<"===== ARRAY ELEMENTS ====="<<endl;
    for(int i = 0 ; i<size;i++){
        cout<<arr[i];
        cout<<" ";
    }

    cout<<endl<<"======= AFTER REVERSING ARRAY BECOMES ========"<<endl;
    int start = 0;
    int end = size - 1;
    while (start <end){
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start ++;
        end --;
    }
    for(int i = 0; i<size;i++){
        cout<<arr[i];
        cout<<" ";
    }
    
    return 0;
}