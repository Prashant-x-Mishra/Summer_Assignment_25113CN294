// FREQUENCY OF AN ELEMENT 

#include <iostream>
using namespace std ;
int main(){
     
    cout<<" ENTER ARRAY SIZE : ";
    int size;
    cin>>size;
    int i = 0;
    int arr[size] = {};
    for(int i = 0 ;i<size;i++){
        cout<<"ENTER NUMBER HAVING INDEX "<<i<<" : ";
        int n;
        cin>>n;
        arr[i] = n; 
    }
    cout<<"======== ARRAY ELEMENTS ARE ========="<<endl;
    for(int i = 0;i<size;i++){
        cout<<arr[i]<<"  ";
    }
    cout<<endl<<"ENTER AN ELEMENT OF AN ARRAY  TO CHECK THE FREQUENCY : ";
    int element ;
    cin>>element;
    int count = 0;
    for(int i = 0 ; i<size;i++){
        if(arr[i]==element){
            count ++;
        }
    }
    cout<<"FREQUENCY OF AN ELEMENT "<<element<< " IS "<<count;
    return 0; 
}