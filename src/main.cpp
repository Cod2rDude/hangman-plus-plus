#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <algorithm>
#include <unistd.h>
#include <cstring>
#include "./words.hpp"

using namespace std;

string chooseRandomWord()
{
    srand(static_cast<unsigned int>(time(0)));
    int i = rand() % strings.size(); // getting random;

    return strings[i];
}

string displayWord(const string &word, const vector<char> &chars)
{
    string result;
    for (char c : word)
    {
        if (find(chars.begin(), chars.end(), c) != chars.end())
        {
            result += c;
        }
        else
        {
            result += "_";
        }
    }
    return result;
}

class game
{
private:
    string word;
    vector<char> chars;
    int left = 7;

public:
    bool start()
    {
        word = chooseRandomWord();
        cout << "\n" << endl;
        cout << "Welcome to Hangman++" << endl;
        while (left > 0)
        {
            cout << "Current word: " << displayWord(word, chars) << endl;
            cout << "Attempts left: " << left << endl;

            cout << "New guess: ";
            string guess;
            cin >> guess;
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            char guessChar;

            if (word == guess && guess.length() > 1)
            {
                cout << "WHAATTT!! NICEEE! You guessed the whole word!";
                sleep(5);
                return true;
            }
            else if (word != guess && guess.length() > 1)
            {
                cout << "False :/" << endl;
                left--;
                continue;
            }
            else
            {
                guessChar = guess[0];
            }

            if (find(chars.begin(), chars.end(), guessChar) != chars.end())
            {
                cout << "You already tried this, try again!" << endl;
                continue;
            }

            chars.push_back(guessChar); // adding to end of vector

            if (word.find(guessChar) != string::npos)
            {
                cout << "Good guess!" << endl;
            }
            else
            {
                cout << "False :/" << endl;
                ;
                left--;
                continue;
            }

            if (displayWord(word, chars) == word)
            {
                cout << "You win! Word was: " << word << endl;
                sleep(5);
                return true;
            }
        }

        if (left == 0)
        {
            cout << "You lost :/ Word was: " << word << endl;
            sleep(5);
        }

        return true;
    }
};

int main()
{
    /*
    cout << chooseRandomWord() << endl;

    cout << "    +------+  " << endl;
    cout << "    |      |  " << endl;
    cout << "    |    \\ O /" << endl;
    cout << "    |      |  " << endl;
    cout << "    |     / \\ " << endl;
    cout << "    |         " << endl;
    */

    while (true)
    {
        game newGame;

        bool i = newGame.start();

        if (i)
        {
            cout << "\n" << endl;
            cout << "Do you want to continue [Y/N]: ";
            string result;
            cin >> result;

            if (result[0] == 'y' || result[0] == 'Y')
            {
                continue;
            } else {
                break;
            }
        }
    }
    
    return 0;
}