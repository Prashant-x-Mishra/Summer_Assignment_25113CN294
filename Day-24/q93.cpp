// CHECK STRING ROTATION 


#include <iostream>
using namespace std;

int main(){
    string str1,str2;

    cout<<"enter first string : ";
    getline(cin,str1);
    cout<<"enter second string : ";
    getline(cin,str2);

    int len1 = 0 , len2 = 0;

    while(str1[len1] != '\0'){
        len1++;

    }
    while(str2[len2] != 0 ){
        len2++;
    }

    if(len1 != len2){
        cout<<endl<<"======================="<<endl;
        cout<<" STRINGS ARE NOT ROTATION OF EACH OTHER . ";
        return 0;
    }

    string combined = str1 + str2;

    if(combined.find(str2) != string::npos){
        cout<<endl<<"======================="<<endl;
        cout<<" STRINGS ARE ROTATION OF EACH OTHER . ";
    }

    else{
        cout<<endl<<"======================"<<endl;
        cout<<"STRINGS ARE NOT ROTATION OF EACH OTHER .";

    }

    return 0;


}