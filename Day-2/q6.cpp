#include <iostream>
using namespace std;
int main(){
    // REVERSE A NUMBER 
    cout<<" TO GET A REVERSE OF A NUMBER \n"<<endl;
    cout<<"ENTER A NUMBER : ";
    int number ;
    int reverseNum = 0; 
    cin>>number;
    while(number!=0){
      int  remainder = number%10;
      reverseNum = reverseNum*10 +remainder;
      number = number/10;

    }
    cout<<"REVERSE NUMBER IS "<<reverseNum<<endl;
     return 0;

    

}