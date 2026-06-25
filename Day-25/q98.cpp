// FINDING COMMON CHARACTER IN STRINGS 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str1, str2;

    cout << "ENTER FIRST STRING  : ";
    getline(cin, str1);
    cout << "ENTER SECOND STRING : ";
    getline(cin, str2);

    
    bool visit1[256] = {false};
    bool visit2[256] = {false};

 
    for (int i = 0; str1[i] != '\0'; i++) {
        if (str1[i] != ' ') { 
            visit1[(unsigned char)str1[i]] = true;
        }
    }

    
    for (int i = 0; str2[i] != '\0'; i++) {
        if (str2[i] != ' ') { 
            visit2[(unsigned char)str2[i]] = true;
        }
    }

    cout << endl << "=====================================" << endl;
    cout << "COMMON CHARACTERS ARE : ";
    
    bool foundCommon = false;

    
    for (int i = 0; i < 256; i++) {
        if (visit1[i] && visit2[i]) {
            cout << "'" << (char)i << "' ";
            foundCommon = true;
        }
    }

    if (!foundCommon) {
        cout << "NONE";
    }
    
    cout << endl << "=====================================" << endl;

    return 0;
}