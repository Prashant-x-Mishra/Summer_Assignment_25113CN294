#include <iostream>
using namespace std ;
int main(){
    cout<<"TO CALCULATE THE SUM OF FIRST N NATURAL NUMBER "<<endl;
    int n , sum;
    cout<<"ENTER THE NUMBER N : ";
    cin>>n;
    sum = 0;
    for(int i =1;i<=n;i++){
        sum=sum+i;
    }
    cout<<"SUM OF FIRST N NATURAL NUMBER IS :"<<sum;
    


    return 0;
}