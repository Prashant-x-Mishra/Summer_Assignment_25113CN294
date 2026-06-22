// REMOVE SPACES FROM STRING

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "ENTER A STRING WITH SPACES : ";
    getline(cin, str); 

    int count = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            str[count] = str[i];
            count++;}
    }

    str[count] = '\0'; 
    str.resize(count); 

    cout << endl << "=====================================" << endl;
    cout << "STRING AFTER REMOVING SPACES : " << str << endl;
    cout << "=====================================" << endl;

    return 0;
}