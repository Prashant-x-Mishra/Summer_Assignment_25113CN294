// MOVES ZERO TO END 

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
    int count = 0;
    cout<<endl<<"======  ARRAY AFTER MOVES ZERO TO END ======"<<endl;
    for(int i = 0 ; i<size;i++){
    
    if(arr[i] != 0){
        arr[count] = arr[i];
        count++;
    }
} 
    for(int i = count ; i < size;i++){
            arr[i] = 0;
        }
    for(int i = 0; i<size;i++){
        cout<<arr[i];
        cout<<" ";
    }
    return 0;
}