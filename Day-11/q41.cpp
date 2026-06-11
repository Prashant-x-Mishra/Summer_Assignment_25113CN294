// FUNCTION SUM OF TWO NUMBERS
#include <iostream>
using namespace std;
int sum(int n1,int n2){
   int  total = n1 + n2;
   return total;

}
int main(){
    cout<<"ENTER TWO NUMBERS TO GET SUM "<<endl;
    cout<<"ENTER NUMBER1 : ";
    int n1;
    cin>>n1;
    cout<<"ENTER NUMBER2 : ";
    int n2;
    cin>>n2;
    cout<<"SUM OF TWO NUMBER "<< n1 << " and "<< n2<< " IS "<<sum(n1,n2);
    return 0;

}