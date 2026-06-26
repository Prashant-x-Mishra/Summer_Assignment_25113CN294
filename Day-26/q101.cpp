// NUMBER GUESSING GAME 

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <limits>

using namespace std;

int bestScore = 0;

void clearInput()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void playGame()
{
    int maxNumber, maxAttempts;

    cout << "\n========== SELECT DIFFICULTY ==========\n";
    cout << "1. Easy   (1-50, 10 Attempts)\n";
    cout << "2. Medium (1-100, 7 Attempts)\n";
    cout << "3. Hard   (1-200, 5 Attempts)\n";
    cout << "Choose: ";

    int choice;
    cin >> choice;

    switch(choice)
    {
        case 1:
            maxNumber = 50;
            maxAttempts = 10;
            break;

        case 2:
            maxNumber = 100;
            maxAttempts = 7;
            break;

        case 3:
            maxNumber = 200;
            maxAttempts = 5;
            break;

        default:
            cout << "\nInvalid Choice! Medium Difficulty Selected.\n";
            maxNumber = 100;
            maxAttempts = 7;
    }

    int secret = rand() % maxNumber + 1;
    int guess;
    int attempts = 0;

    time_t start = time(0);

    cout << "\n=====================================\n";
    cout << "Guess the number between 1 and "
         << maxNumber << endl;
    cout << "You have " << maxAttempts << " attempts.\n";
    cout << "=====================================\n";

    while(attempts < maxAttempts)
    {
        cout << "\nAttempt "
             << attempts + 1
             << "/" << maxAttempts
             << "\nEnter Guess : ";

        cin >> guess;

        if(cin.fail())
        {
            clearInput();
            cout << "Invalid Input! Enter Numbers Only.\n";
            continue;
        }

        if(guess < 1 || guess > maxNumber)
        {
            cout << "Please Enter Number Between 1 and "
                 << maxNumber << endl;
            continue;
        }

        attempts++;

        if(guess == secret)
        {
            time_t end = time(0);

            int timeTaken = end - start;

            int score = (maxAttempts - attempts + 1) * 100;

            cout << "\n==============================\n";
            cout << " CONGRATULATIONS!\n";
            cout << "Correct Number : " << secret << endl;
            cout << "Attempts Used  : " << attempts << endl;
            cout << "Time Taken     : " << timeTaken << " seconds\n";
            cout << "Score          : " << score << endl;

            if(score > bestScore)
            {
                bestScore = score;
                cout << " NEW BEST SCORE!\n";
            }

            cout << "Best Score     : " << bestScore << endl;
            cout << "==============================\n";

            return;
        }

        int diff = abs(secret - guess);

        if(diff <= 5)
            cout << "Very Close!\n";

        else if(diff <= 15)
            cout << "Getting Close.\n";

        else
            cout << "Far Away.\n";

        if(guess > secret)
            cout << "High guess!\n";

        else
            cout << "Low guess!\n";

        cout << "Attempts Left : "
             << maxAttempts - attempts
             << endl;
    }

    cout << "\n=====================================\n";
    cout << " GAME OVER!\n";
    cout << "Correct Number Was : "
         << secret << endl;
    cout << "Better Luck Next Time!\n";
    cout << "=====================================\n";
}

int main()
{
    srand(time(0));

    char again;

    cout << "==========================================\n";
    cout << "     NUMBER GUESSING GAME \n";
    cout << "==========================================\n";

    do
    {
        playGame();

        cout << "\nPlay Again? (Y/N): ";
        cin >> again;

    }while(again=='Y' || again=='y');

    cout << "\n=================================\n";
    cout << "Thanks For Playing!\n";
    cout << "Your Best Score : " << bestScore << endl;
    cout << "See You Again!\n";
    cout << "=================================\n";

    return 0;
}