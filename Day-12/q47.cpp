// FUNCTION FOR FIBONACICI
#include <iostream>
using namespace std;
int fibonacci(int n){
    int f1 = 0;
    int f2 = 1;
    int sum = 0;
    for(int i = 3 ; i<=n;i++){
        sum = f1 + f2;
        f1 = f2;
        f2 = sum;
    }
    return sum ;
}
int main(){
    cout<<"ENTER NUMBER N to FIND Nth TERM : ";
    int n;
    cin>>n;
    cout<<n<<"th TERM OF FIBONACCI SERIES IS "<<fibonacci(n);
    return 0;
}