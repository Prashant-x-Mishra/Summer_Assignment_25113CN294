//C0NVERTING DECIMAL TO BINARY
#include <iostream>
#include <cmath>
using namespace std;
int main(){
    cout<<"ENTER A DECIMAL NUMBER : ";
    int number;
    cin>>number;
    int sum = 0;
    int remainder;
    int i = 0;
    while(number>0){
        remainder = number%2;
        sum = sum + remainder*round(pow(10,i));
        i = i + 1;
        number = number/2;
    }
    cout<<"BINARY NUMBER : "<< sum <<endl;
    return 0;

}