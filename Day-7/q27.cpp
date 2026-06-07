//RECURSIVE SUM OF DIGIT 
#include <iostream>
using namespace std;
int sum_digit(int n){
    if(n==0){
        return 0;
    }
    return n%10 + sum_digit(n/10);
}
int main(){
    cout<<"ENTER THE NUMBER TO GET THE SUM OF DIGIT : ";
    int n;
    cin>>n;
    cout<<"SUM OF DIGIT OF A NUMBER "<< n << " IS "<<sum_digit(n);
    return 0;
}