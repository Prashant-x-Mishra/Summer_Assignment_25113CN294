// LARGEST AND SMALLEST ELEMENT OF AN ARRAY


#include <iostream>
using namespace std;
int large(int arr[],int size){
    int max  = arr[0];
    for(int i = 1 ;i<=size;i++){
        if(arr[i-1]>max){
             max = arr[i-1];
        }
    }
    return max;
}
int small(int arr[],int size){
    int min = arr[0];
    for(int i = 1;i<=size;i++){
        if(arr[i-1]<min){
            min = arr[i-1];
        }
    }
    return min;
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

    cout<<endl<<"===== LARGEST AND SMALLEST ELEMENT OF AN ARRAY ====="<<endl;
    cout<<"LARGEST ELEMENT IS "<<large(arr,size)<<endl;
    cout<<"SMAllest ELEMENT IS "<<small(arr,size)<<endl;
    return 0;
}