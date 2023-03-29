#include <iostream>
#include <cstdlib>
#include <time.h>
#include <cstring>

using namespace std;

const int MAX_BAD_GUESSES = 7;

string chooseWord();
void renderGame(string, int);
char readAGuess();
bool contains(string, char);
void update(string&, const string&, char);

int main()
{
    string word = chooseWord();
    string guessedWord = string(word.length(), '-');
    int badGuessCount = 0;

    while(badGuessCount < MAX_BAD_GUESSES && word != guessedWord){
        renderGame(guessedWord, badGuessCount);
        char guess = readAGuess();
        if(contains(word, guess))
            update(guessedWord, word, guess);
        else badGuessCount++;
    }

    renderGame(guessedWord, badGuessCount);
    if(badGuessCount < MAX_BAD_GUESSES) cout << "YOU WIN!!";
    else cout << "YOU LOST. The correct word is: " << word;

    return 0;
}
const string WORD_LIST[] = {"book", "human", "dog", "cat"};
const int WORD_COUNT = sizeof(WORD_LIST) / sizeof(string);
string chooseWord(){
    srand(time(0));
    int random_index = rand() % WORD_COUNT;
    return WORD_LIST[random_index];
}
const string FIGURE[] = {
"  ----------	\n"
"  |        	\n"
"  |        	\n"
"  |        	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        	\n"
"  |        	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |        	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |        |	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |       /|	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |       /|\\	\n"
"  |        	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |       /|\\	\n"
"  |       / 	\n"
"  |		\n"
"-----	    \n",
"  ----------	\n"
"  |        |	\n"
"  |        o	\n"
"  |       /|\\	\n"
"  |       / \\	\n"
"  |		\n"
"-----	    \n"
};
void renderGame(string guessedWord, int badGuessCount){
    cout << FIGURE[badGuessCount] << endl;
    cout << "Your guess: ";
    cout << guessedWord << endl;
    cout << "Number of wrong guesses: " << badGuessCount << endl;
}

void update(string& guessedWord, const string& word, char guess){
    for(int i = word.length() - 1; i >= 0; i--){
        if(word[i] == guess)
            guessedWord[i] = guess;
    }
}

bool contains(string word, char guess){
    if(word.find_first_of(guess) < word.length()) return true;
    return false;
}

char readAGuess(){
    char g;
    cout << "Guess a word: ";
    cin >> g;
    return g;
}
