//  FINDING A LCM OF TWO NUMBER 
#include <iostream>
using namespace std ;
int main(){
    cout<<"TO FIND THE LCM OF TWO NUMBER "<<endl;
    cout<< " ENTERD NUMBER 1 : ";
    int num1,num2;
    cin>>num1;
    cout<<" ENTER NUMBER 2 : ";
    cin>>num2;
    int max = (num1>num2)? num1 : num2;
    while(1){
        if (max % num1 == 0 && max % num2 == 0){
            cout<<"THE LCM OF TWO NUMBER IS "<<max<<endl;
            break;
        }
        max++;
    }
    return 0;

}