// FUNCTION FOR ARMSTRONG 
#include <iostream>
#include <cmath>
using namespace std;
int is_armstrong(int number){
    int digit_count = 0 ;
    int t = number;
    int p = number;
    while(t>0){
        t = t/10;
        digit_count =digit_count + 1;
    }
    int sum = 0;
    while(p>0){
        int remainder = p%10;
        sum = sum + round(pow(remainder,digit_count));
        p = p/10;
    }

    return sum;

}
int main(){
    cout<<"ENTER A NUMBER TO CHECK ARMSTRONG : ";
    int number ;
    cin>>number;
    if(is_armstrong(number) == number){
        cout<<number<<" IS ARMSTRONG NUMBER.";
        return 0;
    }
    else{
        cout<<number<<" IS NOT A ARMSTRONG NUMBER.";
        return 0;
    }

}