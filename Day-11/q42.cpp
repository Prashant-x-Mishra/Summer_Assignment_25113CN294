// FINDING MAXIMUM 
#include <iostream>
using namespace std;
int max(int n1,int n2){
    if (n1>n2){
        return n1;

    }
    else{
        return n2;
    }
}
int main(){
    cout<<"ENTER TWO NUMBER TO FIND MAXIMUM "<<endl;
    int n1,n2;
    cout<<"ENTER NUM1 :";
    cin>>n1;
    cout<<"ENTER NUM2 :";
    cin>>n2;
    cout<<"MAXIMUM NUMBER IS "<<max(n1,n2);
    return 0;
}
    

