// STAR PYRAMID 
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER NUMBER OF ROWS TO GET STAR PYRAMID : ";
    int n;
    cin>>n;
    for(int i = 1;i<=n;i++){

        for(int j =1;j<=n-i;j++){
            cout<<"  ";
        }
        for(int j = 1;j<=2*i-1;j++){
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;

}