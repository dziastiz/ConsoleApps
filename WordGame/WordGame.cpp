#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    int score = 0;

    enum fields { WORD, HELP, NUM_FIELDS };
    const int NUM_WORDS = 7;
    const string WORDS[NUM_WORDS][NUM_FIELDS] =
    {
          {"student", "a person who goes to school"},
          {"kindergarten", "a school that prepares children for first grade" },
          {"passion", "a strong will" },
          {"hijacker", "a type of a criminal"},
          {"coward", "excessively afraid"},
          {"freedom", "the right and power to act"},
          {"schizophrenia", "mental disorder"},
    };

    srand(time(0));

    int choice = (rand() % NUM_WORDS);
    string theWord = WORDS[choice][WORD]; //word to guess
    string theHelp = WORDS[choice][HELP]; //help

    //generate puzzle

    string puzzle = theWord;
    int length = puzzle.size();
    for (int i = 0; i < length; ++i)
    {
        int index1 = (rand() % length);
        int index2 = (rand() % length);
        char temp = puzzle[index1];
        puzzle[index1] = puzzle[index2];
        puzzle[index2] = temp;
        score = length;   // score based on the length of the word


    }

    // instruction

    cout << "\t\tWelcome to Word Game\n\n";
    cout << "Guess a word from puzzle.\n";
    cout << "Enter 'help' for a help.\n";
    cout << "Enter 'quit' to quit the game\n\n";
    cout << "The puzzle is " << puzzle;

    string guess;
    cout << "\n\nYour guess: ";
    cin >> guess;

    //game loop

    while ((guess != theWord) && (guess != "quit"))
    {

        if (guess == "help")
            cout << theHelp;



        else
            cout << "Try again!";
        --score;  //reduce experience points for help or if you guess wrong

        cout << "\n\nYour guess: ";
        cin >> guess;

    }

    if (guess == theWord)
        cout << "\nCorrect! You got " << score << " experience points" << endl;

    cout << "\nThanks for playing!\n";


    system("pause");

    return 0;

}