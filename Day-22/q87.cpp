// WRITE A PROGRAM TO CHARACTER FREQUENCY 

#include <iostream>
using namespace std;
int main(){
    cout<<" ENTER THE STRING : ";
    string str;
    getline(cin,str);

    cout<<" ENTER THE CHARACTER TO CHECK THE FREQUENCY : ";
    char ch;
    cin>>ch;

    int count = 0 ;
    for(int i = 0 ; str[i] != '\0';i++){
        if(str[i] == ch){
            count++;
        }
    }

    cout<<endl<<" ========================"<<endl;
    cout<<" FREQUENCY OF A CHARACTER "<<ch<<" IS "<< count<<endl;
    

    int freq[256] = {0};

    for(int i = 0 ; str[i] != '\0';i++){
        if(str[i] != ' '){
            freq[(unsigned char)str[i]]++;
        }
    }

    cout<<endl<< "=========== CHARACTER FREQUENCY ========="<<endl;

    for(int i = 0 ; str[i] != '\0';i++){
        if(str[i] != ' ' && freq[(unsigned char)str[i]] != 0){
            cout<<"'"<<str[i] <<"' comes "<< freq[(unsigned char)str[i]] <<" times."<<endl;
            freq[(unsigned char)str[i]] = 0;
        }
    }
    cout<<" ==================================="<<endl;

    return 0;
}