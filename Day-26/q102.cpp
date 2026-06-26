// VOTING ELIGIBILITY SYSTEM (MULTIPLE USER ) UPGRADED VERSION 

#include <iostream>
#include <string>
#include <vector> 
using namespace std;


struct Voter {
    string name;
    int age;
    bool isEligible;
};

int main() {
    int total_voters;
    cout << "=========================================" << endl;
    cout << "    MULTIPLE VOTER ELIGIBILITY SYSTEM  " << endl;
    cout << "=========================================" << endl;
    
    cout << "How many voters do you want to enter? ";
    cin >> total_voters;
    cin.ignore(); 

   
    vector<Voter> voter_list;

   
    for (int i = 0; i < total_voters; i++) {
        Voter v;
        cout << endl << "--- Enter Details for Voter " << i + 1 << " ---" << endl;
        
        cout << "Name: ";
        getline(cin, v.name);
        
        cout << "Age : ";
        cin >> v.age;
        cin.ignore(); 

       
        if (v.age >= 18) {
            v.isEligible = true;
        } else {
            v.isEligible = false;
        }

        
        voter_list.push_back(v);
    }

   
    cout << endl << "=====================================================" << endl;
    cout << "                 FINAL VOTING LIST                  " << endl;
    cout << "=====================================================" << endl;
    cout << "S.No.\tName\t\tAge\tStatus" << endl;
    cout << "-----------------------------------------------------" << endl;

    for (int i = 0; i < total_voters; i++) {
        cout << i + 1 << "\t" << voter_list[i].name << "\t   " << voter_list[i].age << "\t";
        
        if (voter_list[i].isEligible) {
            cout << " ELIGIBLE" << endl;
        } else {
            int years_left = 18 - voter_list[i].age;
            cout << " NOT ELIGIBLE (Wait " << years_left << " year/s)" << endl;
        }
    }
    cout << "=====================================================" << endl;

    return 0;
}