#include <iostream>
using namespace std ;
int main(){
    int number;
    cout<<"ENTER THE NUMBER TO GET THE FACTORIAL VALUE :";
    cin>>number;
    int fact = 1;
    for(int i = 1; i<=number;i++){
        fact = fact*i;
    }
    cout<<"factoraial of a given number is: "<<fact<<endl;
    return 0;
}