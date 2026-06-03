// FINDING A GCD OF 2 NUMBERS 
#include <iostream>
using namespace std ;
int main(){
    cout<<"TO FIND A GCD OF A TWO NUMBERS "<<endl;
    cout<<"ENTER A NUMBER1:  ";
    int num1;cin>>num1;
    cout<<"ENTER A NUMBER2:  ";
    int num2;cin>>num2;
    int value1,value2;
    if (num1>=num2){
         value1 = num1;
         value2 = num2;
    }
    else {
        value2 = num1;
        value1 =num2;   
    }
    
    while(value2!=0){
        int remaider = value1%value2;
        value1 = value2;
        value2 = remaider;
    }
    cout<<"GCD OF TWO NUMBER IS "<<value1<<endl;
    return 0;
}