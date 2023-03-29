#include <iostream>
#include <vector>

#define MAX 100001

using namespace std;

int n;
vector<vector<char>> a;

void print()
{
    for(int i = 0; i < 2 * n; i++){
            for(int j = 0; j < 2 * n; j++)
                cout << a[i][j] << ' ';
            cout << endl;
        }
}

void reverseV(vector<vector<char>> b)
{
    for(int i = 0; i < b.size(); i++){
        for(int j = 0; j < b[i].size(); i++)
            if(b[i][j] == '.') b[i][j] = 'o';
            else b[i][j] = '.';
    }
}

void hadaMard(int x)
{
    if(x == 1){
        // . .
        // . o
        vector<char> c1;
        c1.push_back('.');
        c1.push_back('.');
        vector<char> c2;
        c2.push_back('.');
        c2.push_back('o');
        a.push_back(c2);
        a.push_back(c1);
    }
    if(x == n) {
        print();
        return;
    }
    vector<vector<char>> b = a;
    
    hadaMard(x + 1);
}

int main()
{
    cin >> n;
    hadaMard(1);
    return 0;
}