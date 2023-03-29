#include <iostream>

#define MAX 10001

using namespace std;

int n, k;
bool used[MAX];
char c[MAX];    //mang hoan vi

void print()
{
    for(int i  = 1; i <= k; i++){
        cout << c[i] << ' ';
    }
    cout << endl;
}

void hoanVi(int x)
{
    for(int i = 97; i < 97 + n; i++){
        if(!used[i]){
            c[x] = char(i);
            used[i] = true;
            if(x == k) print();
            else hoanVi(x + 1);
            used[i] = false;
        }
    }
}

int main()
{
    cin >> n >> k;
    for(int i = 0; i < MAX; i++) used[i] = false;
    hoanVi(1);
    return 0;
}