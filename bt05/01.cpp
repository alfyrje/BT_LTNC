#include <iostream>
#include <ctime>
//#include <stdlib.h>
using namespace std;

int m, n, k;
bool gameOver;
int boom[1001][1001];
bool drawBoom[1001][1001];
int checkX, checkY;
bool win;
int countWin;//so o da check

void SetUpBoom();
void SetUpMatrix();
void Draw();
void Input();
void Logic();
void Spread(int, int);
void OriginalMap();

int main()
{
    SetUpBoom();
    SetUpMatrix();
    while(!gameOver && !win){
        Draw();
        Input();
        Logic();
    }
    system("cls");
    if(!win) cout << "YOU'RE DEAD!" << endl;
    else cout << "YOU WON!" << endl;
    OriginalMap();
    return 0;
}

void SetUpBoom()
{
    gameOver = false;
    srand(time(0));
    cout << "Enter number of row, collum and booms: ";
    cin >> m >> n >> k;
    win = false; countWin = 0;
    for(int i = 0; i < m + 2; i++){
        for(int j = 0; j < n + 2; j++){
            boom[i][j] = 0;
            drawBoom[i][j] = false;
        }
    }
    //cai dat k bom: boom[i][j] = -1
    for(int i = 0; i < k; i++){
        bool e = false;
        while(!e){
            int r = rand() % m + 1;
            int c = rand() % n + 1;
            if(boom[r][c] == 0){
                boom[r][c] = -1;
                e = true;
            }
        }
    }
}

void SetUpMatrix()
{
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(boom[i][j] >= 0){
                int BoomAround = 0;
                if(boom[i-1][j-1] < 0) BoomAround++;
                if(boom[i-1][j] < 0) BoomAround++;
                if(boom[i-1][j+1] < 0) BoomAround++;
                if(boom[i][j-1] < 0) BoomAround++;
                if(boom[i][j+1] < 0) BoomAround++;
                if(boom[i+1][j-1] < 0) BoomAround++;
                if(boom[i+1][j] < 0) BoomAround++;
                if(boom[i+1][j+1] < 0) BoomAround++;
                boom[i][j] = BoomAround;
            }

        }
    }
}

void OriginalMap()
{
    for(int i = 1; i <= m; i++){
        for(int j  = 1; j <= n; j++){
            if(boom[i][j] < 0) cout << "*" << ' ';
            else cout << boom[i][j] << ' ';
        }
        cout << endl << endl;
    }
}

void Draw()
{
    system("cls");
    for(int i = 1; i <= m; i++){
        for(int j = 1; j <= n; j++){
            if(drawBoom[i][j]){
                cout << boom[i][j] << ' ';
            }
            else{
                cout << "\xB2" << ' ';
            }
        }
        cout << endl << endl;
    }
}

void Input()
{
    cout << "Check Boom: ";
    int x, y;
    cin >> x >> y;
    checkX = x;
    checkY = y;
}

void Logic()
{
    if(boom[checkX][checkY] < 0){
        gameOver = true;
        drawBoom[checkX][checkY] = true;
        countWin++;
    }
    else if(boom[checkX][checkY] == 0){
        Spread(checkX, checkY);
    }
    else{
        drawBoom[checkX][checkY] = true;
        countWin++;
    }

    if(countWin + k == m * n)
        win  = true;
}

void Spread(int i, int j)
{
    if(i >= 1 && i <= m && j >= 1 && j <= n && boom[i][j] == 0 && !drawBoom[i][j]){
        drawBoom[i][j] = true;
        countWin++;
        Spread(i-1, j-1);
        Spread(i-1, j);
        Spread(i-1, j+1);
        Spread(i, j-1);
        Spread(i, j+1);
        Spread(i+1, j-1);
        Spread(i+1, j);
        Spread(i+1, j+1);
    }
    return;
}
