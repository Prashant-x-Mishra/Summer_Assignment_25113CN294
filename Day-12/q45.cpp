// FUNCTION FOR PALINDROME 
#include <iostream>
using namespace std;
int  is_palindrome(int number){
    int original_num = number;
    int reverse_num = 0;
    while(number>0){
        int digit_num = number%10;
        reverse_num = reverse_num*10 + digit_num;
        number = number/10; 
    }
    
    return reverse_num;

}
int main(){
    cout<<"ENTER NUMBER TO CHECK PALINDROME : ";
    int number;
    cin>>number;
    if (is_palindrome(number) == number){
        cout<<"ENTER  NUMBER "<< number << " IS PALINDROME ";
        return 0;
    }
    else {
        cout<<"ENTER NUMBER "<< number << " IS NOT A PALINDROME .";
        return 0;
    }
    
}