// LINEAR SEARCH
#include <iostream>
using namespace std;
int main(){
    int arr[10] ={23,45,67,90,10,65,89,45,83,42};
    cout<<"ENTER NUMBER TO FIND IN ARRAY LIST : ";
    int number;
    cin>>number;
    for(int i = 0;i<10;i++){
        if(arr[i]==number){
            cout<<i;
        }
        cout<<" ";
    }
    return 0;
}