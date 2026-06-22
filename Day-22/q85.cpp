// PALINDROME STRING CHECK 

#include <iostream>
using namespace std;
int main(){
    cout<<" ENTER THE STRING : ";
    string str;
    getline(cin,str);
    string original = str;

    int length = 0;
    while(str[length] != '\0'){
        length ++;
    }

    int start = 0 ;
    int last = length - 1;
    while(start < last){
        char temp = str[start];
        str[start] = str[last];
        str[last] = temp;

        start++;
        last--;
    }

    if(str == original){
        cout<<endl<<" ======= ENTER THE STRING IS PALINDROME . ======";
    }
    else {
        cout<< endl<< "=======  ENTER THE STRING  IS NOT PALINDROME . ======";
        
    }
 return 0;

}