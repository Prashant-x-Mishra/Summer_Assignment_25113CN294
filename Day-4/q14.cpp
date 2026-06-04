//finding nth fibonacci term 
#include <iostream>
using namespace std;
int main(){
    cout<<"TO FINDING N th FIBONACCI TERM ENTER N : ";
    int n;
    cin>>n;
    if(n==0){
        return 0;
    }
    if(n==1){
        cout<<1;
    }
    unsigned long long f1 = 0;
    unsigned long long f2 = 1;
    int i =2;
    unsigned long long sum;
    while(i<n){
        sum = f1 + f2 ;
        f1 = f2;
        f2 = sum;
        i++;
    }
    cout<<sum<<endl;
    return 0;
}