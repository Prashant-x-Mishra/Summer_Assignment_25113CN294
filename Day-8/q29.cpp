// HALF PYRAMID PATTERN 
#include <iostream>
using namespace std;
int main(){
    cout<<"TO GET THE PYRAMID UPTO N ENTER THE NUMBER N : ";
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j =1;j<=i;j++){
            cout<<" * ";
        }
        cout<<endl;
    }
}