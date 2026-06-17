// PAIR WITH GIVEN SUM 

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

    cout<<endl<<"TO FIND THE PAIRS WITH  GIVEN SUM , ENTER SUM  =  ";
    int sum;
    cin>>sum;
    cout<<endl<<"========== PAIRS WITH GIVEN SUM "<< sum << " ARE ========="<<endl;

    for(int i = 0; i<size;i++){
        for(int j = i + 1 ; j<size;j++){
           
            if(sum ==  arr[i] + arr[j]){
                cout<<arr[i]<<" and "<< arr[j]<<"  , ";
            }
            
        }
    }
    return 0;


}