// RECURSIVE FACTORIAL
#include <iostream>
using namespace std ;

int fact_num(int number){
    if(number <= 1){
        return 1;
    }
    return  number*fact_num(number-1);
}
int main(){
    cout<<"ENTER A NUMBER TO GET THE FACTORIAL : ";
    int number;
    cin>>number;
    cout<<"FACTORIAL OF A NUMBER "<< number << " IS "<< fact_num(number);
    return 0;
}