// CHARACTER TRIANLE 
#include <iostream>
using namespace std;
int main(){
    cout<<"TO GET CHARACTER TRIANLE UPTO N ROWS ENTER THE NUMBER N : ";
    int n;
    cin>>n;
    
    for(int i =1;i<=n;i++){
        int val = 65;
        for(int j =1 ; j<=i;j++){
           cout<<(char)val;
           val++;
           cout<<" ";

        }
        cout<<endl;
    }
}