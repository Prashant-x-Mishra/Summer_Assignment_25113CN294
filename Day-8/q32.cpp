// REPEATED NUMBER PATTERN 
#include <iostream>
using namespace std;
int main(){
    cout<<"TO PRINT REPEATED NUMBER PATTERN UPTO N ENTER N : ";
    int n;
    cin>>n;
    for(int i =1 ;i<=n;i++){
        for(int j = 1 ; j<=i;j++){
            cout<<i;
            cout<<" ";
        }
        cout<<endl;
    }
}