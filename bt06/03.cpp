#include <iostream>

#define MAX 10001

using namespace std;

int n, k;
bool used[MAX];
char c[MAX];    //mang to hop

void print()
{
    for(int i  = 1; i <= k; i++){
        cout << c[i] << ' ';
    }
    cout << endl;
}

void toHop(int x, int y)
{
    for(int i = 97 + y; i < 97 + n; i++){
            c[x] = char(i);
            if(x == k) print();
            else toHop(x + 1, y + 1);
            y++;
    }
}

int main()
{
    cin >> n >> k;
    toHop(1, 0);
    return 0;
}