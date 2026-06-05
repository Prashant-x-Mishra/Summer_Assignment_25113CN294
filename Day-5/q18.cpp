#include <iostream>
using namespace std;
int strong_check(int number){
    int sum = 0;
    
    while(number>0){
        int digit = number%10;
        int fact = 1;
        for(int i =1;i<=digit;i++){
        fact = fact*i;
    }
    sum = sum + fact;
    number = number/10;
    }
    return sum;
}
int main(){
    cout<<"ENTER A NUMBER TO CHECK STRONG NUMBER OR NOT : ";
    int number;
    cin>>number;
    if(number==strong_check(number)){
        cout<<number<<" is a strong number .";
        
    }
    else {
        cout<<number<<" is not a strong number .";
    }
    return 0;
}