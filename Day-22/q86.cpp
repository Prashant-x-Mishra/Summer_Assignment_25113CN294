// COUNT WORD IN A SENTENCE 

#include <iostream>
using namespace std;
int main(){
    cout<<"ENTER THE STRING : ";
    string str;
    getline(cin,str);

    int word_count = 0;
    bool word = false;

    for(int i = 0 ; str[i] != '\0';i++){
        if ( str[i] != ' '){
            if(!word){
                word_count ++;
                word = true;
            }

        }
        else{
            word = false;
        }
    }

    cout<<endl<<"=========================="<<endl;
    cout<<" TOTAL NUMBER OF WORDS : "<<word_count<<endl;
    return 0;
}