// CONVERT LOWERCASE TO UPPER CASE 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "ENTER THE STRING IN LOWERCASE : ";
    getline(cin, str); 

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = str[i] - 32;
        }
    }

    cout << endl << "=====================================" << endl;
    cout << "UPPERCASE STRING IS : " << str << endl;
    cout << "=====================================" << endl;

    return 0;
}