// REMOVE DUPLICATE FROM ARRAY 

#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER ARRAY SIZE : ";
    int size;
    cin>>size;
    int arr[size];
    for(int i = 0 ; i< size ; i++){
        cout<<"ENTER ELEMENT HAVING INDEX "<<i<<" : ";
        int n;
        cin>>n;
        arr[i] = n;
    }
    cout<<endl<<"====== ARRAY ELEMENTS ARE ======"<<endl;
    for(int i = 0 ; i< size; i++){
        cout<<arr[i]<<" ";
    }

    cout<<endl<<"====== ARRAY AFTER REMOVING DUPLIACTES ======"<<endl;

    for(int i = 0; i<size; i++){
        if(arr[i] == -1 ){
            continue;
        }
        for(int j = i + 1 ;j<size;j++){
            if(arr[i] == arr[j]){
                arr[j] = -1;
            }
        }
    }
    for(int i = 0 ; i<size;i++){
    if(arr[i] != -1){
        cout<<arr[i]<<" ";
    }
    }
    return 0;
}