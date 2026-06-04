// check armstrong number 
#include <iostream>
#include <cmath>
using namespace std  ;
int main(){
    cout<<"to check the armstrong enter the number : ";
    int number ;
    cin>>number ;
    int original_num = number;
    int digit;
    int sum = 0;
    int no_digit = 0;
     if (number ==0){
        cout<<"ENTERD NUMBER "<<number<< " IS ARMSTRONG NUMBER ."<<endl;
        return 0;
    }
    int temp = number;
    int count_digit = 0;
      while(temp!=0){
       temp = temp/10;
        count_digit= count_digit +1;
    }
    while(number>0){
        digit = number%10;
        sum = sum + round(pow(digit,count_digit));
        number = number/10;
    }
    if(original_num == sum){
        cout<<"ENTERED NUMBER "<<original_num<< " IS A ARMSTRONG NUMBER .";
        return 0;
    }
    else{
        cout<<"ENTERED NUMBER "<<original_num <<"  IS NOT A AMRSTRONG NUMBER .";
        return 0;
    }
    
}