#include <iostream>
using namespace std;
int main (){
    // counting the digit in a number 
    cout<<"ENTER NUMBER : ";
    int number;
    cin>>number;
    if (number ==0){
        cout<<"TOTAL NUMBER OF DIGIT = 1";
        return 0;
    }
    int count = 0;
    
    
    while(number!=0){
       number = number/10;
        count= count +1;
    }
   
    
    cout<<"TOTAL NUMBER OF DIGITS ="<<count;
    return 0;

}