// CHECK PRIME 
#include <iostream>
using namespace std;
bool is_prime(int n){
    bool prime = true;
    for(int i = 2 ;i<=n/2;i++){
        if(n%i==0){
            return false;
            break;
        }
    }
    return true;


}
int main(){
    cout<<"ENTER NUMBER TO DETREMINE PRIME OR NOT : ";
    int n ;
    cin>>n;
    if(n==0 || n ==1){
        cout<<"ENTERD NUMBER "<< n<< " IS NOT A PRIME NUMBER .";
        return 0;
        }
        if(is_prime(n)== true){
            cout<<"ENTERD NUMBER "<< n <<" IS PRIME NUMBER";
        }
        else{
            cout<<"ENTERD NUMBER "<< n<<" IS NOT A PRIME NUMBER";
        }
    return 0;
}