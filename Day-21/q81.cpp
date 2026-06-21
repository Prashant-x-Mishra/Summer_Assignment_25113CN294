// FINDING STRING LENGTH WITHOUT STRLEN()

#include <iostream>
using namespace std;
int main(){
    string str;

    cout<<" ENTER THE STRING : ";
    getline(cin,str);

    int length = 0;

    while(str[length] != '\0' ){
        length ++;
    }

    cout<<"===================";
    cout<<endl<<"THE LENGTH OF THE STRING IS : "<<length<<endl;
    cout<<"===================";
    return 0;
}