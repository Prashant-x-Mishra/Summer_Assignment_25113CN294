// COUNT EVEN AND ODD 

#include <iostream>
using namespace std;
int count_odd(int arr[],int size){
    int count = 0;
    for(int i = 0 ; i<size; i++){
        if(arr[i]%2 != 0){
            count ++;
        }
    }
    return count;
}
int count_even(int arr[],int size){
    int count = 0;
    for(int i = 0; i<size;i++){
        if(arr[i]%2 == 0){
            count++;
        }
    }
    return count;

}
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
    cout<<endl<<"======== TOTAL NO OF EVEN AND ODD NUMBER IN AN ARRAY ====== "<<endl;
    cout<<"TOTAL ODD NUMBERS = "<<count_odd(arr,size)<<endl<<"TOTAL EVEN NUMBER = "<<count_even(arr,size);
    return 0;
}