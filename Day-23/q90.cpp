//  FINDING FIRST  REPEATING CHARACTER 

#include <iostream>
using namespace std;
int main(){
    string str;

    cout<<" ENTER THE STRING : ";
    getline(cin,str);

    int freq[256] = {0};
    for(int i = 0 ; str[i] != 0;i++){
        freq[(unsigned char)str[i]]++;
    }

    char result = '\0';
    
    for(int i = 0 ; str[i] != 0;i++){
        if(str[i] != ' ' && freq[(unsigned char)str[i]] > 1){
            result = str[i];
            break;
        }
    }

    cout<<endl<<" ==========================="<<endl;
    if(result != '\0'){
        cout<<"FIRST REPEATING CHARACTER IS : '"<<result<<"'"<<endl;
    }
    else{
        cout<<" NO REPEATING CHARACTER FOUND "<<endl;
    }
    cout<<"==================================="<<endl;
}