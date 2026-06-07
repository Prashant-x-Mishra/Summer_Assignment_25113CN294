//RECURSIVE FIBONACCI
#include <iostream>
using namespace std;
int fibonacci(int n){
    if(n<=1){
        return n;
    }
    return fibonacci(n-1)+fibonacci(n-2);
    
}
int main(){
    cout<<"TO GET Nth TERM OF FIBONACCI ENTER THE NUMER N : ";
    int n;
    cin>>n;
    cout<<"FIBONACCI "<< n << "th TERM IS "<<fibonacci(n);
    return 0;

}