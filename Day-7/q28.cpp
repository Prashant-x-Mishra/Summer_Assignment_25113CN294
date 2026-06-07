// RECURSIVE REVERSE NUMBER 
#include <iostream>
using namespace std ;
int reverse_num(int number,int answer = 0){
    if(number<=0){
        return answer;
    }

   
    return reverse_num(number/10,answer*10 + (number %10));
}
int main(){
    cout<<"ENTER THE NUMBER TO GET REVERSE : ";
    int number ;
    cin>>number;
    cout<<"REVERSE NUMBER IS "<<reverse_num(number);
    return 0;
}