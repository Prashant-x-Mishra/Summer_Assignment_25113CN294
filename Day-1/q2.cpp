#include <iostream>
using namespace std;
int main(){
    // MULTIPLICATION TABLE  
     int number,n;
    cout<<"ENTER ANY NATURAL NUMBER TO GET MULTIPLICATION TABLE : "; 
    cin>>number;
    cout<<"TO GET TABLE UPTO N ENTER THE NUMBER N : ";
    cin>>n;
    cout<<"REQIURED TABLE "<<endl;
    for(int i = 1;i<=n;i++){
        cout<< number<<"x"<<i<<"="<<number*i<<endl;
    }
    return 0;

}