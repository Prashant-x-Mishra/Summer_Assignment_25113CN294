// SORTING NAMES ALPHABETICALLY ORDER 

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    cout <<"HOW MANY NAMES YOU WRITE ? ";
    int size;
    cin>>size;
    cin.ignore();
    string names[size];

    cout<<" ENTER " << size << " NAMES : "<< endl;
    for(int i = 0; i< size ; i++){
        cout<<" name  "<< i + 1<< " : ";
        getline(cin,names[i]);
    }

    sort(names,names + size);

    cout<<endl<<"======== NAMES IN ALPHABETICALLY ORDER ======="<<endl;

    for(int i = 0 ; i< size ; i++){
        cout<< i + 1 <<". "<<names[i]<<endl;
    }

    cout<<"======================================================"<<endl;
    return 0;

}