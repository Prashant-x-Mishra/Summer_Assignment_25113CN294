//SUM AND AVERAGE OF ARRAY

#include <iostream>
using namespace std;
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
    cout<<endl;
    cout<<"==== SUM AND AVERAGE OF AN ARRAY ===== ";
    int sum = 0;
    for(int i = 0; i<size;i++){
        sum = sum + arr[i];
    }
    float average = sum/size;
    cout<<endl;
    cout<<"SUM = "<< sum <<" AVERAGE = "<< average;

    return 0;
}