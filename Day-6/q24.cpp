// FINDING X KI POWER  N WITHOUT pow
#include <iostream>
using namespace std ;
int main(){
    cout<<"TO FIND X^N enter number x : ";
    int x ;
    cin>>x;
    cout<<"ENTER power n : ";
    int n ;
    cin>>n;
    int answer = 1;
    for(int i = 1 ; i<=n; i++){
        answer = answer*x;
    }
    cout<<" ANSWER IS "<< answer<<endl;
}