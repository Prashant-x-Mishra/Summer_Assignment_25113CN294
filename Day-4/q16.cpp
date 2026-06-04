// PRINTING A ARMSTRONG NUMBERS IN A RANGE 
#include <iostream>
#include <cmath>
using namespace std;
void armstrong(int l , int u){
    int temp ,i;
    for( i = l+1;i<u;++i){
        int temp = i;int n =0;
        while(temp!=0){
            temp = temp/10;
            ++n;
        }
        int sum =0;
        temp =i;
        while(temp!=0){
            int digit = temp%10;
            sum = sum + round(pow(digit,n));
            temp=temp/10;
        }
        if (sum==i){
            cout<< i << " ";
        }
    }
;}
int main(){
cout<<"TO GET ARMSTONG NUMBER I A RANGE "<<endl;
cout<<"ENTER LOWER RANGE : ";
int l ; cin>>l;
cout<<"ENTER UPPER RANGE : ";
int u ; cin>>u;
armstrong(l,u);
cout<<" ";
return 0;

}