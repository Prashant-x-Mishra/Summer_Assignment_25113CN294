// COMPUTER QUIZ GAME 

#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct QuizQuestion {
    string question;
    string options[4];
    char correctOption; 
};

void play_quiz() {
    cout << "\n========== COMPUTER QUIZ GAME ==========\n";
    
    string name;
    cout << "Enter Your Name: ";
    getline(cin, name);

    cout << "\nWelcome " << name << "!\n";
    cout << "Rules: 5 Questions | +10 Points Each\n\n";

    
    vector<QuizQuestion> questions = {
        {"What is the full form of CPU?", {"A. Central Processing Unit", "B. Computer Process Unit", "C. Core Processing Unit", "D. None"}, 'A'},
        {"What is the full form of RAM?", {"A. Read Access Memory", "B. Read Alternative Memory", "C. Random Access Memory", "D. Run Action Memory"}, 'C'},
        {"What is the full form of IP?", {"A. Intranet Protocol", "B. Internet Protocol", "C. Internal Post", "D. Instant Process"}, 'B'},
        {"What is the full form of ROM?", {"A. Read Only Memory", "B. Real Online Mode", "C. Random Only Memory", "D. None"}, 'A'},
        {"What is the full form of HDD?", {"A. Hard Data Drive", "B. High Density Disk", "C. Hot Disk Drive", "D. Hard Disk Drive"}, 'D'}
    };

    int score = 0;
    int correct_answers = 0;

    cout << "========== QUIZ START ==========\n\n";

    for (int i = 0; i < questions.size(); i++) {
        cout << "Question " << i + 1 << ": " << questions[i].question << endl;
        
       
        for (int j = 0; j < 4; j++) {
            cout << questions[i].options[j] << endl;
        }

        char user_answer;
        cout << "Your Answer (A/B/C/D): ";
        cin >> user_answer;
        cin.ignore(); 

        
        user_answer = toupper(user_answer);

        if (user_answer == questions[i].correctOption) {
            cout << " Correct!\n\n";
            score += 10;
            correct_answers++;
        } else {
            cout << " Incorrect!\n";
            cout << "Correct Answer was: " << questions[i].correctOption << "\n\n";
        }
    }

    // Result Calculations
    double percentage = (score / 50.0) * 100;

    cout << "========== RESULT ==========\n";
    cout << "Player Name      : " << name << endl;
    cout << "Correct Answers  : " << correct_answers << "/5" << endl;
    cout << "Score            : " << score << "/50" << endl;
    cout << "Percentage       : " << percentage << "%" << endl;

    if (percentage == 100) cout << "Performance      :  Excellent\n";
    else if (percentage >= 80) cout << "Performance      :  Very Good\n";
    else if (percentage >= 60) cout << "Performance      :  Good\n";
    else cout << "Performance      :  Needs Improvement\n";
}

int main() {
    cout << "WELCOME TO THE COMPUTER QUIZ GAME\n";

    while (true) {
        string play;
        cout << "\nDo you want to play? (yes/no): ";
        cin >> play;
        cin.ignore(); 

        if (play != "yes" && play != "YES" && play != "Yes") {
            cout << "\nThanks for playing! \n";
            break;
        }

        play_quiz();
    }
    return 0;
}