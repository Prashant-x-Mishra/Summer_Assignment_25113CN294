// FINDING MAXIMUM OCCURING CHARACTER 

#include <iostream>
using namespace std;

int main() {
    string str;

    cout << "ENTER THE STRING : ";
    getline(cin, str);

    int freq[256] = {0};

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') { 
            freq[(unsigned char)str[i]]++;
        }
    }

    int max_count = 0;
    char max_char = '\0';

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ' && freq[(unsigned char)str[i]] > max_count) {
            max_count = freq[(unsigned char)str[i]];
            max_char = str[i];
        }
    }

    cout << endl << "=====================================" << endl;
    if (max_count > 0) {
        cout << "MAX OCCURRING CHARACTER IS : '" << max_char << "'" << endl;
        cout << "IT APPEARS " << max_count << " TIMES." << endl;
    } else {
        cout << "EMPTY STRING OR ONLY SPACES ENTERED!" << endl;
    }
    cout << "=====================================" << endl;

    return 0;
}