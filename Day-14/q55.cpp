// FINDING SECOND LARGEST ELEMENT OF AN ARRAY 

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

int sec_large(int arr[],int size,int max){
    int secLarg = -1;
    for(int i = 0 ; i < size ; i++){
            if(secLarg<arr[i] && arr[i]<max){
                secLarg = arr[i];
            }
        
    }
    return secLarg;

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

    cout<<endl<<"LARGEST ELEMENT OF AN ARRAY = "<<large(arr,size);
    int max = large(arr,size);
    cout<<endl<<"SECOND LARGEST ELEMENT OF AN ARRAY = "<<sec_large(arr,size,max);
    return 0;
}