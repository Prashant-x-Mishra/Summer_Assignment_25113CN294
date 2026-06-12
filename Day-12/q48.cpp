// FUNCTION FOR A PERFECT NUMBER 
#include <iostream>
using namespace std;

int sum_fact(int number){
    int sum = 0;
    for(int i = 1 ;i<number;i++){
        if(number%i==0){
            sum = sum + i;
        }
            
    } return sum ;
}
int main(){
    cout<<"ENTER A NUMBRT TO CHECK PERFECT OR NOT : ";
    int number;
    cin>>number;
   if(number == sum_fact(number)){
    cout<<"ENTERD NUMBER  "<<number<<" IS A PERFECT NUMBER ";
   }
   else{
    cout<<"ENTERD NUMBER "<<number<<" IS NOT A PERFECT NUMBER ";
   }
    return 0;
}