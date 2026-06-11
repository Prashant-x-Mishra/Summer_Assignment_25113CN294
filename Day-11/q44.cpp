// FACTORIAL
#include <iostream>
using namespace std;
int fact(int n){
    int fact = 1 ;
    for(int i = 1; i<=n;i++){
        fact = fact*i;
    }
    return fact;
}
int main(){
    cout<<"ENTER NUMBER TO GET THE FACTORIAL : ";
    int n;
    cin>>n;
    cout<<"FACTORIAL OF A NUMBER "<< n <<" IS "<<fact(n);
    return 0;
}