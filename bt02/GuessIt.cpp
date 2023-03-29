#include <iostream>
#include <ctime>
#include <windows.h>

using namespace std;

int range;
int ans;
bool gameOver, win;
int check;
int limitGuess, currentGuess;
bool bigger, smaller;

void setUp();
void Draw();
void Input();
void Logic();
void Over();

int main()
{
    setUp();
    while(!gameOver && !win){
        Draw();
        Input();
        Logic();
    }
    Over();
    return 0;
}

void setUp()
{
    gameOver = win = false;
    bigger = false;
    smaller = false;
    check = 0;
    srand(time(0));
    cout << "Enter range: ";
    cin >> range;
    ans = rand() % range + 1;
    cout << "Enter maximum number of guesses: ";
    cin >> limitGuess;
    currentGuess = 1;
}

void Draw()
{
    system("cls");
    cout << "RANGE: 1 to " << range << endl;
    cout << "Left guesses: " << limitGuess - currentGuess << endl;
    for(int i = 0; i < 50; i++) cout << "\xB1";
    cout << endl;
    if(check) cout << "Your last guess: " << check << endl;
    if(bigger) cout << "Try smaller one, ";
    else if(smaller) cout << "Try bigger one, ";
    cout << "Enter your guess: ";
}

void Input()
{
    int x; cin >> x;
    check = x;
    currentGuess++;
}

void Logic()
{
    bigger = smaller = false;
    if(check > ans) bigger = true;
    else if(check < ans) smaller = true;
    else cout << "BINGO" << endl;
    if(currentGuess == limitGuess) gameOver = true;
    if(check == ans) win = true;
}

void Over()
{
    for(int i = 0; i < 50; i++) cout << "\xB2";
    cout << endl;
    if(win){
        cout << "YOU WIN!!" << endl;
        cout << "The answer is: " << ans << endl;
        cout << "You guessed " << currentGuess << " time(s)";
    }
    else{
        cout << "YOU LOSE!!" << endl;
        cout << "The answer is: " << ans << endl;
    }
}


