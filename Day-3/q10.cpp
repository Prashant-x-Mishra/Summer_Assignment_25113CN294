// PRINTING A PRIME NUMBER IN A RANGE 
#include <iostream>
using namespace std ;
int main(){
    cout<<"TO GET A PRIME NUMBERS IN A RANGE "<<endl;
    cout<<"ENTER A lower number of RANGE : ";
    int n1 ,n2;
    cin>>n1;
    cout<<"ENTER A UPPER NUMBER OF RANGE : ";
    cin>>n2;
    int j,i;
    for ( int i = n1; i<=n2;i++){
        if(i<=1) continue;
        bool is_prime = true;

        for( j = 2; j *j <= i;j++ ){
            if(i%j==0){
                is_prime = false;
                break;
            }
        }
        if (is_prime){
            cout<< i << endl;
        }
    }
    return 0;
}