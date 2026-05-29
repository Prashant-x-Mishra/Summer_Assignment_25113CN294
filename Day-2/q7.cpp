#include <iostream>
using namespace std;
int main(){
    // PRODUCT OF DIGITS OF A NUMBER 
    cout<<"ENTER THE NUMBER TO GET THE PRODUCT OF DIGITS : ";
    int number ;
    cin>>number;
    int product = 1;
    while(number!=0){
        int digit = number%10;
        product = product*digit;
        number = number/10;

    }
    cout<<"REQUIRED PRODUCT OF DIGIT OF A  NUMBER IS "<<product;
    return 0;
}