// CHECK A PRIME NUMBER 
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER  A NATURAL NUMBER TO CHECK PRIME OR NOT : ";
    int number;
    cin>>number;
    int is_prime = 1;
    if (number==0 || number ==1){
        cout<<"ENTERED NUMBER "<<number<< " IS NOT A PRIME NUMBER ";
        return 0;
    }
    for(int i = 2;i<number;i++){
        if(number%i==0){
            is_prime = 0;
            break;
        }
    }
    if(is_prime == 0){
        cout<<"ENTERD NUMBER "<<number << " IS NOT A PRIME NUMBER "<<endl;
    }
    else {
        cout<<"ENTERD NUMBER "<<number << " IS A PRIME NUMBER "<<endl;
    }
    return 0;
}