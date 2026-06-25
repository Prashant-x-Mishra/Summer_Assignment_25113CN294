// SORT WORD BY LENGTH

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> 
using namespace std;


bool compareLength(const string &a, const string &b) {
    int lenA = 0, lenB = 0;
    while (a[lenA] != '\0') lenA++; 
    while (b[lenB] != '\0') lenB++; 
    
    return lenA < lenB; 
}

int main() {
    string str;

    cout << "ENTER A SENTENCE : ";
    getline(cin, str);

    vector<string> words;
    string current_word = "";

   
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] != ' ') {
            current_word += str[i];
        } else {
            if (current_word != "") {
                words.push_back(current_word);
                current_word = "";
            }
        }
    }
   
    if (current_word != "") {
        words.push_back(current_word);
    }

    sort(words.begin(), words.end(), compareLength);

  
    cout << endl << "====== WORDS SORTED BY LENGTH ======" << endl;
    for (int i = 0; i < words.size(); i++) {
        cout << words[i] << " ";
    }
    cout << endl << "====================================" << endl;

    return 0;
}