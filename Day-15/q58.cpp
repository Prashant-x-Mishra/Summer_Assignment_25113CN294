// ROTATE ARRAY LEFT 

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

    int fst = arr[0];

    for (int i = 0 ; i < size  ;i++){
        arr[i -1] = arr[i];
    }
    arr[size -1] = fst;
   }
    for(int i = 0; i<size ;i++){
        cout<<arr[i];
        cout<<" ";

    }
    return 0;

}