// COMPRESS STRING 

#include <iostream>
using namespace std;
int main(){
    string str;
    cout<<" ENTER THE STRING TO COMPRESS : ";
    getline(cin,str);

    if(str.empty()){
        cout<<" STRING IS EMPTY!";
        return 0;
    }

    string compressed = "";
    int count = 1 ;

    for(int i = 0 ; str[i] != '\0';i++){
        if(str[i] == str[i + 1]){
            count ++;
        }
        else {
            compressed += str[i];
            compressed += to_string(count);
            count = 1;
        }
    }
    cout<< endl<<"========================"<<endl;
    cout<<" COMPRESSED STRING IS "<<compressed<< endl;

    return 0;
}