// COUNTING SET BITS IN A NUMBER 
#include <iostream>
#include <cmath>
using namespace std;
int main(){
     cout<<"ENTER A DECIMAL NUMBER : ";
    int number;
    cin>>number;
    int digit ;
    int count = 0 ;
    int original_num = number;
    while(number>0){
        digit = number%2;
        if(digit==1){
            count = count + 1 ;
        }
        number = number/2;
    }
    cout<<"BITS IN A NUMBER "<< original_num << " IS "<< count << endl;
    return 0;
}