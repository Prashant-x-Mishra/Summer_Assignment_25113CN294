#include <iostream>
using namespace std ;
int main(){
    // check the number is palindrome or not 
    cout<<"TO CHECK THE PALINDROME ENTER THE NUMBER : ";
    int number ;
    cin>>number ;
    int reverse =0 ;
    int original_num = number ;
    while (number != 0){
        int remainder = number%10;
        reverse = reverse*10 + remainder;
        number = number / 10;
    }
    if (original_num == reverse ){
        cout<<"ENTER NUMBER "<< original_num << " IS  PALINDROME "<<endl;
    }
    else {
        cout<<"ENTER NUMBER "<<original_num << " IS NOT A PALINDROME "<<endl;
    }
   

    return 0;

}