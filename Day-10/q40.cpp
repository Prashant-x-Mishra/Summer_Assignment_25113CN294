// CHARACTER PYRAMID
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER NUMBER OF ROWS TO GET CHARACTER PYRAMID : ";
    int n;
    cin>>n;
    
    for(int i =1 ;i<=n;i++){
        int val = 65;
        for(int j =1;j<=n-i;j++){
            cout<<"  ";

        }
        for(int j = 1;j<=i;j++){
            cout<<char(val)<<" ";
            val++;
        }
        for(int j = i-1;j>=1;j--){
            cout<<char(val-2)<<" ";
            val--;
        }

        cout<<endl;
    
    }
    return 0;
}