//  FINDING LONGEST WORD 

#include <iostream>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "ENTER A SENTENCE : ";
    getline(cin, str);

    string current_word = "";
    string longest_word = "";
    int max_length = 0;

    for (int i = 0; str[i] != '\0'; i++) {
        
        if (str[i] != ' ') {
            current_word += str[i];
        } 
        
        else {
            int current_length = 0;
            while (current_word[current_length] != '\0') {
                current_length++;
            }

            if (current_length > max_length) {
                max_length = current_length;
                longest_word = current_word;
            }
            current_word = ""; 
        }
    }
    int current_length = 0;
    while (current_word[current_length] != '\0') {
        current_length++;
    }
    if (current_length > max_length) {
        max_length = current_length;
        longest_word = current_word;
    }

    cout << endl << "=====================================" << endl;
    cout << "THE LONGEST WORD IS : " << longest_word << endl;
    cout << "ITS LENGTH IS       : " << max_length << endl;
    cout << "=====================================" << endl;

    return 0;
}