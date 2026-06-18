// SORTING ARRAY IN DECENDING ORDER

#include <iostream>
using namespace std ;
void shorted_arr (int arr[],int size){
    for(int i = 0 ; i<size -1;i++){
       int max = i;
        for(int j = i + 1 ; j<size  ; j++){
           if(arr[j] > arr[max]){
           max = j;
           }
    }  
    if(max != i){
        int temp = arr[i];
        arr[i] = arr[max];
        arr[max] = temp;
    }
    }
}


int main(){
    cout<<" ENTER THE ARRAY SIZE : ";
    int size ;
    cin>>size;
    int arr[size];
    for (int i = 0 ; i<size;i++){
        cout<<"ENTER THE ELEMENT HAVING INDEX "<< i<<" : ";
        int n;cin>>n;
        arr[i] = n;
    }

    cout<<endl<<" ====== ARRAY WITHOUT SHORTED ======"<<endl;
    for(int i = 0 ; i<size; i++){
        cout<<arr[i]<<" ";
    }
    shorted_arr(arr,size);
    cout<<endl<<" ======== ARRAY AFTER SORT IN DECENDING ORDER ======="<<endl;

    for(int i = 0 ; i < size; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;


    return 0;

}