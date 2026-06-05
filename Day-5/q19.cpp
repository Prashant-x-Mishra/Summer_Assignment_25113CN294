// printing factors of a number 
#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER A NUMBER TO GET THE FACTORS :  ";
    int number;
    cin>>number;
    cout<<"====== FACTORS OF A NUMBER ARE ======"<<endl;
    for(int i = 1 ; i<=number;i++){
        if(number%i==0){
            cout<<i<<" ";
        }
    }
    return 0;

}