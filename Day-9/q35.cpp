//REPEATED CHARACTER PATTERN 
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER N TO GET REPEATED CHAR PATTERN UPTO N ROWS : ";
    int n ;
    cin>>n;
    int val = 65;
    for(int i = 1 ; i<=n;i++){
        for(int j =1 ;j<=i;j++){
            cout<<char(val);
            cout<<" ";
        }
        cout<<endl;
        val++;
    }
    return 0;
}