// REMOVE DUPLICATE CHARACTER 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "ENTER THE STRING : ";
    getline(cin, str);


    bool visited[256] = {false};

    int count = 0; 

    for (int i = 0; str[i] != '\0'; i++) {
        unsigned char ch = str[i];

        if (!visited[ch]) {
            visited[ch] = true;  
            str[count] = str[i];  
            count++;              
        }
    }

    
    str[count] = '\0';
    str.resize(count);

    cout << endl << "=====================================" << endl;
    cout << "STRING AFTER REMOVING DUPLICATES : " << str << endl;
    cout << "=====================================" << endl;

    return 0;
}