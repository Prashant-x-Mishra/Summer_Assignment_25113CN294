#include <iostream>
using namespace std;
int main(){
    // SUM OF DIGITS OF A NUMBER 
    cout<<"CALCULATE THE SUM OF DIGIT OF A NUMBER \n "<<endl;
    cout<<"ENTER THE NUMBER : ";
    int number;
    cin>>number;
    int sum = 0;
    while(number!=0){
        int remainder = number%10;
        sum = sum + remainder;
        number = number/10;
    }
    cout<<"THE SUM OF A DIGIT OF A GIVEN NUMBER IS " <<sum<<endl;
    return 0;

}