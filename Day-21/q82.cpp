// REVERSE A STRING 

#include <iostream>
using namespace std;
int main(){
    string str;

    cout<<" ENTER THE STRING : ";
    getline(cin,str);
    int length = 0;

    while(str[length] != '\0'){
        length ++;
    }
    int start = 0;
    int end = length - 1;


    while( start<end){
       char temp =  str[start]; 
       str[start] = str[end ];
       str[end ] = temp;
       start++;
       end--;

     }

     cout<<" ====== REVERSE STRING ======="<<endl;
     cout<<str;
     return 0;
}