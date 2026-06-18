// BUBBLE SHORT 


#include <iostream>
using namespace std ;
void shorted_arr (int arr[],int size){
    for(int i = 0 ; i<size -1;i++){
        for(int j = 0 ; j<size - i - 1  ; j++){
            if(arr[j] > arr[j + 1]){
                int temp = arr [j];
                arr[j] = arr [j + 1];
                arr[j + 1] = temp;
            }
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
    cout<<endl<<" ======== ARRAY AFTER BUBBLE SORT ======="<<endl;

    for(int i = 0 ; i < size; i++){
        cout<< arr[i]<< " ";
    }
    cout<< endl;


    return 0;

}