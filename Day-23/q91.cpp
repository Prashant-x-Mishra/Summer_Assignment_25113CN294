// ANARGRAM CHECK

#include <iostream>
using namespace std;
int main(){
    string str1, str2;

    cout<<"ENTER FIRST STRING : ";
    getline(cin,str1);
    cout<<"ENTER SECOND STRING : ";
    getline(cin,str2);

    int len1 = 0 ,len2 = 0;
    while(str1[len1] != '\0'){
        len1++;
    }
    while(str2[len2] != '\0'){
        len2++;
    }

    if(len1 != len2){
        cout<<endl<<" ======================="<<endl;
        cout<<" STRINGS ARE NOT ANARGRAMS "<<endl;
        cout<<"============================="<<endl;
        return 0;
    }

    int freq[256] = {0};

    for(int i = 0; i<len1; i++){
        freq[(unsigned char)str1[i]]++;
        freq[(unsigned char)str2[i]]--;
    }

    bool isAnargram = true;
    for(int i = 0 ; i< 256;i++){
        if(freq[i] != 0){
            isAnargram = false;
            break;
        }
    }

    cout<<endl<<"=================================="<<endl;
    if(isAnargram){
        cout<< "RESULT : STRINGS ARE ANARGRAMS!"<<endl;

    }
    else{
        cout<<"RESULT : STRINS ARE NOT ANARGRAM!"<<endl;
    }
    cout<<"==========================================="<<endl;
    return 0;

}