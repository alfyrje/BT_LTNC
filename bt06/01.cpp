#include <iostream>

#define MAX 1001

using namespace std;

int n, queen[MAX];
bool mD[MAX], sD[MAX], Col[MAX];    //check main, sub diagon and collumn

void print()
{
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(queen[i] == j) cout << '*' << ' ';
            else cout << '.' << ' ';
        }
        cout << endl;
    }
    cout << endl;
}
//put queen at row x - col ...
void setUpQueen(int i)
{
    if(i == n + 1) print();
    else{
        for(int j = 1; j <= n; j++){
            if(!Col[j] && !sD[i + j - 1] && !mD[n - j + i]){
                queen[i] = j;
                Col[j] = sD[i + j - 1] = mD[n - j + i] = true;
                setUpQueen(i + 1);
                queen[i] = 0;
                Col[j] = sD[i + j - 1] = mD[n - j + i] = false;
            }
        }
    }
}

int main()
{
    cin >> n;
    for(int i = 1; i <= n; i++){
        queen[i] = 0;
        for(int j = 1; j <= n; j++){
            Col[j] = sD[i + j - 1] = mD[n - j + i] = false;
        }
    }
    setUpQueen(1);

    return 0;
}