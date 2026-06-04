// generating a fibonacci series 
#include <iostream>
using namespace std;
int main(){
    cout<<"TO GET A FIBONACCI SERIES UPTO N TERMS ENTER NUMBER FOR N : ";
    int n;
    cin>>n;
    if(n<=0){
        return 0;
    }
    if(n==1){
        cout<<0<<" ";
        return 0; 
    }
    unsigned long long f1 = 0;
    unsigned long long f2 = 1;
    int i =2;
    cout<<f1<<" ";
    cout<<f2<<" ";
    while( i < n){
        unsigned long long  sum = f1 + f2;
        cout<<sum;
        f1 = f2;
        f2 = sum;
        i++; 
        cout<<" ";  
    }
    return 0;
}