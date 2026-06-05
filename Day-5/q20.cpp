//  FINDING LARGEST PRIME FACTOR 
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER NUMBER TO GET LARGEST PRIME FACTOR :";
    int number;
    cin>>number;
    int ans =0;
    for(int i = 2;i<=number;i++){
        while(number%i==0){
            
            number = number/i;
            ans = i;
        }
    }
    cout<<ans;
    return 0;

}