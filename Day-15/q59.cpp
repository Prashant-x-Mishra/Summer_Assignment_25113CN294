// ROTATE ARRAY RIGHT 

#include <iostream>
using namespace std ;
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
    int r;
    cout<<endl<<"ENTER  NUMBER OF TIMES TO ROTATE LEFT : ";
    cin>>r;

    cout<<endl<<" ===== AFTER ROTATING ARRAY LEFT ====="<<endl;
    for(int rot = 0 ; rot< r; rot++){

    int lst = arr[size - 1];

    for (int i = size - 1; i >= 1  ;i--){
        arr[i] = arr[i-1];
    }
    arr[0] = lst;
   }
    for(int i = 0; i<size ;i++){
        cout<<arr[i];
        cout<<" ";

    }
    return 0;

}