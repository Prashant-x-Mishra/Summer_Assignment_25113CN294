//converting binary to decimal 
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cout<<"ENTER A BINARY NUMBER TO CONVERT INTO DECIMAL : ";
    int number;
    int remaider ;
    int sum = 0 ;
    int i = 0;
    cin>>number;
    while(number>0){
        remaider = number%10;
        sum = sum + remaider*round(pow(2,i));
        i = i+1;
        number = number/10;
    }
    cout<<"DECIMAL NUMBER : "<<sum;
    return 0;
}