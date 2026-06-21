// COUNT VOWELS AND CONSTANT 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;
    
    cout << "ENTER THE STRING : ";
    getline(cin, str);

    int vowel = 0;
    int consonant = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' ||
                ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') {
                vowel++;}
            else {
                consonant++;
            }
        }
    }

    cout << endl << "=====================================" << endl;
    cout << "TOTAL VOWELS     : " << vowel << endl;
    cout << "TOTAL CONSONANTS : " << consonant << endl;
    cout << "=====================================" << endl;

    return 0;
}